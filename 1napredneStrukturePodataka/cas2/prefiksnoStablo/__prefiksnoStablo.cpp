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

int main(){

}