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
    vector<int> maxRastojanje;

public:
    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
        uDrvetu.resize(n, false);
        maxRastojanje.resize(n, numeric_limits<int>::min());
    }

    void dodajGranu(const int a, const int b, const int t){
        listaSusedstva[a].push_back({b, t});
        listaSusedstva[b].push_back({a, t});
    }

    int rekord(){
        priority_queue<pair<int, int>> red;
        red.push({0, 0});
        maxRastojanje[0]=0;

        while(!red.empty()){
            auto [udaljenost, cvor] = red.top();
            red.pop();

            if(uDrvetu[cvor])
                continue;

            uDrvetu[cvor]=true;

            for(auto [sused, udaljenostDoSuseda]: listaSusedstva[cvor]){
                if(udaljenostDoSuseda<0)
                    continue;      
                if(!uDrvetu[sused]){
                    if(maxRastojanje[sused]<udaljenostDoSuseda)
                    {
                        maxRastojanje[sused] = udaljenostDoSuseda;
                        ukupno+=udaljenostDoSuseda;
                        red.push({udaljenostDoSuseda, sused});
                    }
                }
            }
        }
        return ukupno;
    }
};

int main(){
    int n, m, a, b, t;
    cin >> n >> m;
    Graf* G = new Graf(n);
    while (m--) {
        cin >> a >> b >> t;
        G->dodajGranu(a, b, t);
    }
    std::cout << G->rekord() << '\n';
    delete G;
    return 0;
}