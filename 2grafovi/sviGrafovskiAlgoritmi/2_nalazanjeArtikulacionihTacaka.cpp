#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

class Graf {
private:
    int brojCvorova; int brojac = 0;
    vector<vector<int>> listaSusedstva;
    vector<bool> posecen;
    vector<bool> uDrvetu;
    vector<int> roditelj;
    vector<int> minRastojanje;
    vector<int> lowlink;
    vector<int> dolazna;
    vector<int> odlazna;
    vector<bool> artikulacionaTacka;
public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        posecen.resize(n, false);
        uDrvetu.resize(n, false);
        roditelj.resize(n, -1);
        minRastojanje.resize(n, INF);
        lowlink.resize(n);
        odlazna.resize(n);
        dolazna.resize(n);
        artikulacionaTacka.resize(n, false);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
    }

    void nadjiArtikulacioneTacke(int cvor){
        lowlink[cvor]=dolazna[cvor]=brojac++;
        posecen[cvor]=true;
        int brojDece = 0;

        for(int sused: listaSusedstva[cvor]){
            if(posecen[sused]){
                if(roditelj[cvor]!=sused)
                    lowlink[cvor]=min(lowlink[cvor], dolazna[sused]);
            } else {
                roditelj[sused]=cvor;
                brojDece++;
                nadjiArtikulacioneTacke(sused);

                lowlink[cvor]=min(lowlink[cvor], lowlink[sused]);

                if(roditelj[cvor]!=-1 && dolazna[cvor]<=lowlink[sused])
                    artikulacionaTacka[cvor]=true;
            }
        }
        if(brojDece>1 && roditelj[cvor]==-1)
            artikulacionaTacka[cvor]=true;
    }
};

int main(){
    return 0;
}
