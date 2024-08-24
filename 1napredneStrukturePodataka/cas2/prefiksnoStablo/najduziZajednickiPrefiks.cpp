#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Cvor {
    bool krajReci = false;
    unordered_map<char, Cvor*> grane;
};

void dodajRec(Cvor* stablo, string& rec){
    for(char c: rec){
        if(stablo->grane.find(c)==stablo->grane.end())
            stablo->grane[c]= new Cvor;
        stablo = stablo->grane[c];
    }
    stablo->krajReci=true;
}

void oslobodiMemoriju(Cvor* stablo){
    if(stablo==nullptr)
        return;
    for(auto p:stablo->grane)
        oslobodiMemoriju(p.second);
    delete stablo;
}

string najduziZajednickiPrefiks(Cvor* stablo){
    string ret = "";
    while(stablo->grane.size()==1 && stablo->krajReci==false){
        auto it = stablo->grane.begin();
        ret+=((*it).first);
        stablo = ((*it).second);
    }
    return ret;
}

int main(){
    int n; string rec;
    cin >> n;
    Cvor* stablo = new Cvor();
    while(n--){
        cin >> rec;
        dodajRec(stablo, rec);
    }
    cout << najduziZajednickiPrefiks(stablo) << '\n';
    oslobodiMemoriju(stablo);
    return 0;
}