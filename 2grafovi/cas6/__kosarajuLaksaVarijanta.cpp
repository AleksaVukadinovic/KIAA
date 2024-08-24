#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    vector<vector<int>> listaSusedstvaTrasnponovano;
    vector<bool> posecen;
    vector<int> odlazniRedosled;
    vector<int> komponenta;
    int brojac = 0;

    void dfs1(int cvor){
        posecen[cvor]=true;
        for(int sused: listaSusedstva[cvor])
            if(!posecen[sused])
                dfs1(sused);
    }

    void transponuj(){
        listaSusedstvaTrasnponovano.resize(brojCvorova);
        for(int cvor = 0; cvor< brojCvorova; cvor++)
            for(int sused: listaSusedstva[cvor])
                listaSusedstvaTrasnponovano[sused].push_back(cvor);
    }

    void dfs2(int cvor){
        posecen[cvor]=true;
        for(int sused: listaSusedstvaTrasnponovano[cvor])
            if(!posecen[sused])
                dfs2(sused);
    }
    void odrediOdlaznuEnumeraciju(int cvor){
        posecen[cvor]=true;
        for(int sused: listaSusedstva[cvor])
            if(!posecen[cvor])
                odrediOdlaznuEnumeraciju(sused);
        odlazniRedosled.push_back(cvor);
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
    }

    bool kosaraju(int cvor){  // vraca da li je graf jako povezan
        dfs1(cvor);
        for(int i=0;i<brojCvorova;i++)
            if(!posecen[i])
                return false;

        fill(posecen.begin(), posecen.end(), false);
        transponuj();
        
        dfs2(cvor);
        for(int i=0;i<brojCvorova;i++)
            if(!posecen[i])
                return false;

        return true;

    }
};

int main(){
    return 0;
}