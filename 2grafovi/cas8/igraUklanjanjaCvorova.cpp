// TODO

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

class Graf {
private:
    int brojCvorova;
    vector<vector<pair<int, int>>> matricaPovezanosti;
    vector<vector<int>> minRastojanje;
public:
    Graf(const int n){
        brojCvorova = n;
        matricaPovezanosti.resize(n);
        minRastojanje.resize(n, vector<int> (n, INF));
    }

    void dodajGranu(const int a, const int b, const int t){
        matricaPovezanosti[a].push_back({b, t});
    }
};

int main(){
    int n, a, b, t;
    cin >> n;
    Graf* G = new Graf(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            
        }
    delete G;
    return 0;
}