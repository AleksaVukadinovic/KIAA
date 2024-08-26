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
    int brojCvorova;
    vector<vector<pair<int, int>>> listaSusedstva;
    vector<bool> uDrvetu;
    vector<int> minRastojanje;
    vector<int> roditelj;

public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        uDrvetu.resize(n, false);
        minRastojanje.resize(n, INF);
        roditelj.resize(n, -1);
    }

    void dodajGranu(const int a, const int b, const int t){
        listaSusedstva[a].push_back({b, t});
    }

    void prim(){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> red;
        red.push({0, 0});
        minRastojanje[0]=0;

        while(!red.empty()){
            auto [cvor, udaljenost] = red.top();
            red.pop();

            if(uDrvetu[cvor])
                continue;

            uDrvetu[cvor]=true;
            for(auto [sused, udaljenostDoSuseda]: listaSusedstva[cvor]){
                if(!uDrvetu[sused]){
                    if(udaljenostDoSuseda < minRastojanje[sused]){
                        minRastojanje[sused]=udaljenostDoSuseda;
                        roditelj[sused]=cvor;
                        red.push({udaljenostDoSuseda, sused});
                    }
                }
            }
        }
    }
};

int main(){
    return 0;
}