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
    vector<pair<int, int>> mosotvi;
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
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstva[b].push_back(a);
    }

    void pronadjiMostove(int cvor){
        lowlink[cvor]=dolazna[cvor]=brojac++;
        posecen[cvor]=true;

        for(int sused: listaSusedstva[cvor]){
            if(posecen[sused]){
                if(roditelj[cvor]!=sused)
                    if(dolazna[sused]<lowlink[cvor])
                        lowlink[cvor]=dolazna[sused];
            } else {
                roditelj[sused]=cvor;
                pronadjiMostove(sused);

                lowlink[cvor]=min(lowlink[cvor], lowlink[sused]);

                if(dolazna[cvor]<lowlink[sused])
                    mosotvi.push_back({cvor, sused});
            }
        }
    }
};

int main(){
    return 0;
}