#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova, ukupno = 0;
    vector<vector<pair<int, int>>> listaSusedstva;
    vector<bool> uDrvetu;
    vector<int> minRastojanje;
    vector<int> roditelj;

    void primovAlgoritam(int start){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> red;
        red.push({0, start});
        minRastojanje[start]=0;

        while(!red.empty()){
            auto [udaljenost, cvor] = red.top();
            red.pop();

            if(uDrvetu[cvor])
                continue;

            uDrvetu[cvor]=true;
            ukupno+=minRastojanje[cvor];

            for(const auto& [sused, udaljenostDoSuseda]: listaSusedstva[cvor]){
                if(!uDrvetu[sused]){
                    if(udaljenostDoSuseda<minRastojanje[sused]){
                        minRastojanje[sused]=udaljenostDoSuseda;
                        roditelj[sused]=cvor;
                        red.push({minRastojanje[sused], sused});
                    }
                }
            }
        }
    }
public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        uDrvetu.resize(n, false);
        minRastojanje.resize(n, numeric_limits<int>::max());
        roditelj.resize(n, -1);
    }

    void dodajGranu(const int a, const int b, const int tezina){
        listaSusedstva[a].push_back({b, tezina});
    }

    void izracunajCenu(){
        for(int cvor = 0; cvor<brojCvorova; cvor++)
            if(!uDrvetu[cvor])
                primovAlgoritam(cvor);
        cout << ukupno <<'\n';
    }
};

int main(){
    int n, m, a, b, t;
    cin >>n >> m;
    Graf* G = new Graf(n);
    while(m--){
        cin >> a >> b >> t;
        G->dodajGranu(a-1, b-1, t);
    }
    G->izracunajCenu();
    delete G;
    return 0;
}