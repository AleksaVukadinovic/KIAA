#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Cvor {
    bool krajReci = false;
    int duzinaReci = 0;
    unordered_map<char, Cvor*> grane;
};

void dodajRec(Cvor* stablo, const string& rec){
    for(char c: rec){
        if(stablo->grane.find(c)==stablo->grane.end())
            stablo->grane[c]= new Cvor();
        stablo=stablo->grane[c];
    }
    stablo->krajReci = true;
    stablo->duzinaReci =rec.size();
}

int najduzi;

void dfs(Cvor* stablo) {
    if(stablo==nullptr) return;
    if(stablo->grane.size()==0){
        najduzi = max(najduzi, stablo->duzinaReci);
        return;
    }
    for(auto [_, cvor]: stablo->grane)
        dfs(cvor);
}
int duzinaImena(Cvor* stablo, const string& prefiks){
    for(char c: prefiks){
        if(stablo->grane.find(c)==stablo->grane.end())
            return 0;
        stablo=stablo->grane[c];
    }
    najduzi = 0;
    for(auto [_, dete]: stablo->grane)
        dfs(dete);
    return najduzi;
}

void oslobodiMemoriju(Cvor* stablo){
    if(stablo!=nullptr)
        for(auto [_, sused]: stablo->grane)
            oslobodiMemoriju(sused);
    delete stablo;
}

int main(){
    int n; string s1, s2;
    cin >> n;
    Cvor* stablo = new Cvor();
    while(n--){
        cin >> s1 >> s2;
        if(s1=="add") 
            dodajRec(stablo, s2);
        else 
            cout << duzinaImena(stablo, s2) << '\n';
    }
    oslobodiMemoriju(stablo);
    return 0;
}