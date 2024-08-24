#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Cvor {
    bool krajReci = false;
    string rec;
    unordered_map<char, Cvor*> grane;
};

void dodajRec(Cvor* stablo, string& rec){
    for(char c: rec){
        if(stablo->grane.find(c)== stablo->grane.end())
            stablo->grane[c]= new Cvor();
        stablo=stablo->grane[c];
    }
    stablo->krajReci = true;
    stablo->rec=rec;
}

void oslobodiMemoriju(Cvor* stablo){
    if(stablo==nullptr) 
        return;
    for(auto p:stablo->grane)
        oslobodiMemoriju(p.second);
    delete stablo;
}

void dfs(Cvor* stablo){
    if(stablo->krajReci)
        cout << stablo->rec << '\n';
    for(auto p:stablo->grane)
        dfs(p.second);
    return;
}

void autocomplete(Cvor* stablo, string& prefiks){
    for(char c: prefiks){
        if(stablo->grane.find(c)==stablo->grane.end()){
            cout << "-1\n";
            return;
        }
        stablo=stablo->grane[c];
    }
    dfs(stablo);
}

int main(){
    int n; string t;
    cin >> n;
    Cvor* stablo = new Cvor();
    while(n--){
        cin >> t;
        dodajRec(stablo, t);
    }
    cin >> t;
    autocomplete(stablo, t);
    oslobodiMemoriju(stablo);
    return 0;
}