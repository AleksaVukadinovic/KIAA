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
    vector<vector<int>> listaSusedstva;
    vector<bool> posecen;
    vector<bool> uDrvetu;
    vector<int> roditelj;
    vector<int> minRastojanje;
    vector<int> lowlink;
    vector<int> dolazna;
    vector<int> odlazna;
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
    }
};

int main(){
    return 0;
}