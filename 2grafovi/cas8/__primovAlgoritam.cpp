#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<pair<int, int>>> listaSusedstva;
    vector<bool> uDrvetu;
    vector<int> minRastojanje;
    vector<int> roditelj;

    void minimalnoPovezujuceStablo(){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> red;
        int start = 0;
        red.push({0, start});
        minRastojanje[start]=0;

        int brojCvorovaUDrvetu = 0;
        while(brojCvorovaUDrvetu<brojCvorova){
            auto [rastojanje, cvor] = red.top();
            red.pop();

            if(uDrvetu[cvor])
                continue;
            
            uDrvetu[cvor]=true;
            brojCvorovaUDrvetu++;

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
        for(int cvor = 0; cvor<brojCvorova; cvor++)
            if(roditelj[cvor]!=-1)
                cout << roditelj[cvor] << " " << cvor << '\n';
    }
public:
    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
        uDrvetu.resize(n, false);
        minRastojanje.resize(n, numeric_limits<int>::max());
        roditelj.resize(n, -1);
    }

    void dodajGranu(const int a, const int b, const int tezina){
        listaSusedstva[a].push_back({b, tezina});
    }

};

int main(){
    return 0;
}