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
    int brojCvorova, brojac = 0;
    vector<vector<int>> listaSusedstva;
    vector<vector<int>> listaSusedstvaTransponovano;
    vector<int> odlazniRedosled;
    vector<bool> posecen;
    vector<int> komponenta;

    void dfs1(int cvor){
        posecen[cvor]=true;
        for(int sused: listaSusedstva[cvor])
            if(!posecen[sused])
                dfs1(sused);
        odlazniRedosled.push_back(cvor);
    }
    void dfs2(int cvor){
        komponenta[cvor]=brojac;
        posecen[cvor]=true;
        for(int sused: listaSusedstvaTransponovano[cvor])
            if(!posecen[sused])
                dfs2(sused);
    }

public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        posecen.resize(n, false);
        komponenta.resize(n, -1);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstvaTransponovano[b].push_back(a);
    }

    void kosaraju() {
        for(int cvor = 0; cvor < brojCvorova; cvor++)
            if(!posecen[cvor])
                dfs1(cvor);

        fill(posecen.begin(), posecen.end(), false);

        for(int i = brojCvorova-1; i>=0; i--){
            int cvor = odlazniRedosled[i];
            if(komponenta[cvor]==-1){
                dfs2(cvor);
                brojac++;
            }
        }
    }
};

int main(){
    return 0;
}