#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int brojCvorova, vremeDolaska;
    vector<vector<int>> listaSusedstva;
    vector<bool> posecen;
    vector<int> dolazna;
    vector<int> lowlink;
    vector<int> roditelj;
    vector<pair<int, int>> mostovi;

    void pronadjiArtikulacioneTacke(int cvor){
        posecen[cvor]=true;
        dolazna[cvor]=vremeDolaska++;
        lowlink[cvor]=dolazna[cvor];

        for(int sused: listaSusedstva[cvor]){
            if(posecen[sused]){
                if(sused != roditelj[cvor])
                    if(dolazna[sused] < lowlink[cvor])
                        lowlink[cvor]=dolazna[sused];
            } else {
                roditelj[sused]=cvor;
                pronadjiArtikulacioneTacke(sused);

                if(lowlink[sused] < lowlink[cvor])
                    lowlink[cvor] = lowlink[sused];

                if(lowlink[sused]>dolazna[cvor])
                    mostovi.emplace_back(cvor, sused);
            }
        }
    }

public:
    Graf(const int n){
        brojCvorova=n;
        vremeDolaska = 0;
        listaSusedstva.resize(n);
        posecen.resize(n, false);
        dolazna.resize(n);
        lowlink.resize(n);
        roditelj.resize(n);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        // listaSusedstva[b].push_back(a);
    }

    void ispisiMostove(int cvor){
        pronadjiArtikulacioneTacke(cvor);
        for(pair<int, int> p: mostovi)
            cout << p.first << " " << p.second << '\n';
    }
};

int main(){
    return 0;
}