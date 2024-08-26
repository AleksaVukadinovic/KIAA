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
    vector<int> minRastojanje;
    vector<bool> resen;
public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        minRastojanje.resize(n, numeric_limits<int>::max());
        resen.resize(n, false);
    }

    void dajkstra(int start){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> red;
        red.push({0, start});
        minRastojanje[start]=0;

        while(!red.empty()){
            auto [rastojanje, cvor] = red.top();
            red.pop();

            if(resen[cvor])
                continue;
            
            resen[cvor]=true;

            for(auto [sused, udaljenostDoSuseda]: listaSusedstva[cvor]){
                if(minRastojanje[cvor]+udaljenostDoSuseda<minRastojanje[sused]){
                    minRastojanje[sused] = minRastojanje[cvor]+udaljenostDoSuseda;
                    red.push({minRastojanje[sused], sused});
                }
            }
        }
    }
};

int main(){
    return 0;
}