#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Graf{
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    vector<vector<int>> listaSusedstvaTransponovano;
    vector<bool> posecen;
    vector<int> odlazniRedosled;
    vector<int> komponenta;
    int brojac = 0;

    void dfs1(int cvor){
        posecen[cvor]=true;
        for(int sused: listaSusedstva[cvor])
            if(!posecen[sused])
                dfs1(sused);
        odlazniRedosled.push_back(cvor);
    }

    void dfs2(int cvor){
        posecen[cvor]=true;
        komponenta[cvor]=brojac;
        for(int sused: listaSusedstvaTransponovano[cvor])
            if(!posecen[sused])
                dfs2(sused);
    }

public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        listaSusedstvaTransponovano.resize(n);
        posecen.resize(n, false);
        odlazniRedosled.resize(n);
        komponenta.resize(n, -1);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstvaTransponovano[b].push_back(a);
    }

    int odrediBrojKomponentiPovezanosti(){
        for(int cvor = 0; cvor<brojCvorova; cvor++)
            if(!posecen[cvor])
                dfs1(cvor);
        
        fill(posecen.begin(), posecen.end(), false);

        for(int i=brojCvorova-1; i>=0; i--){
            int cvor=odlazniRedosled[i];
            if(!posecen[cvor]){
                dfs2(cvor);
                brojac++;
            }
        }

        return brojac+1; //nisam siguran za ovo
    }
};

int main(){
    int n, m, a, b;
    cin >> n >> m;
    Graf* G = new Graf(n);
    while(m--){
        cin >> a >> b;
        G->dodajGranu(a-1, b-1);
    }
    cout << G->odrediBrojKomponentiPovezanosti() << '\n';
    delete G;
    return 0;
}