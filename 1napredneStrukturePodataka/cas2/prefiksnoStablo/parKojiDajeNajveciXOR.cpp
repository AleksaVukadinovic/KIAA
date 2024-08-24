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
        if(stablo->grane.find(c)== stablo->grane.end())
            stablo->grane[c]= new Cvor();
        stablo=stablo->grane[c];
    }
    stablo->krajReci = true;
}

void oslobodiMemoriju(Cvor* stablo){
    if(stablo==nullptr) 
        return;
    for(auto p:stablo->grane)
        oslobodiMemoriju(p.second);
    delete stablo;
}

string najveciXOR(Cvor* stablo, string& trenutniBroj){
    string ret = "";
    for(char b: trenutniBroj){
        if(b=='0') {
            if(stablo->grane.find('1')!=stablo->grane.end()){
                ret+='1';
                stablo=stablo->grane['1'];
            } else {
                ret+='0';
                stablo=stablo->grane['0'];
            }
        } else {
            if(stablo->grane.find('1')!=stablo->grane.end()){
                ret+='0';
                stablo=stablo->grane['1'];
            } else {
                ret+='1';
                stablo=stablo->grane['0'];
            }
        }
    }
    return ret;
}

int main(){
    int n; string t; string najvecixor = "00000000000000000000";
    cin >> n;
    Cvor* stablo = new Cvor();
    while(n--){
        cin >> t;
        dodajRec(stablo, t);
        najvecixor = max(najvecixor, najveciXOR(stablo, t));
    }
    cout << najvecixor << '\n';
}