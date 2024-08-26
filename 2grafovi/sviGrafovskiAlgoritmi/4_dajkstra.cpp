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
    vector<int> minRastojanje;
    vector<int> roditelj;
    vector<bool> resen;
    
public:
    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
        minRastojanje.resize(n, INF);
        roditelj.resize(n, -1);
        resen.resize(n, false);
    }

    void dodajGranu(const int a, const int b, const int t){
        listaSusedstva[a].push_back({b, t});
    }

    void dajkstra(int start){
        minRastojanje[start]=0;
        resen[start]=true;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> red;
        red.push({0, start});

        while(!red.empty()){
            auto [udaljenost, cvor] = red.top();
            red.pop();

            if(resen[cvor])
                continue;

            resen[cvor]=true;
            for(auto [sused, udaljenostDoSuseda]: listaSusedstva[cvor]){
                if(!resen[sused]){
                    if(minRastojanje[sused]>minRastojanje[cvor]+udaljenostDoSuseda){
                        minRastojanje[sused]=minRastojanje[cvor]+udaljenostDoSuseda;
                        red.push({minRastojanje[sused], sused});
                    }
                }
            }
        }
    }
};

int main(){
    return 0;
}