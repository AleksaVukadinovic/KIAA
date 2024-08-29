#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Cvor {
    bool krajReci = false;
    unordered_map<char, Cvor*> grane;
};

void dodajRec(Cvor* stablo, const string& rec){
    for(char c: rec){
        if(stablo->grane.find(c)==stablo->grane.end())
            stablo->grane[c] = new Cvor();
        stablo=stablo->grane[c];
    }
    stablo->krajReci = false;
}

bool pronadjiRec(Cvor* stablo, const string& rec){
    for(char c: rec){
        if(stablo->grane.find(c)==stablo->grane.end())
            return false;
        stablo=stablo->grane[c];
    }
    return stablo->krajReci;
}

void oslobodiMemoriju(Cvor* stablo){
    if(stablo!=nullptr)
        for(auto [_, cvor]: stablo->grane)
            oslobodiMemoriju(cvor);
    delete stablo;
}

string dopuniDoPalindroma(Cvor* stablo, const string& sufiks){
    string r_sufiks = sufiks;
    reverse(r_sufiks.begin(), r_sufiks.end());
    string ret = "";
    for(char c: r_sufiks){
        if(stablo->grane.find(c)==stablo->grane.end())
            return ret;
        ret+=c;
        stablo=stablo->grane[c];
    }
    return ret;
}

int main(){
    int n, m; string s;
    cin >> n;
    Cvor* stablo = new Cvor();
    while(n--){
        cin >> s;
        dodajRec(stablo, s);
    }
    cin >> m;
    while(m--){
        cin >> s;
        cout << dopuniDoPalindroma(stablo, s) <<  s <<'\n';
    }
    oslobodiMemoriju(stablo);
    return 0;
}