#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova, pocetniCvor, krajnjiCvor;
    vector<vector<int>> listaSusedstva;
    vector<int> ulazniStepen;
    vector<int> izlazniStepen;

public:
    Graf(const int n){
        brojCvorova =n;
        listaSusedstva.resize(n);
        ulazniStepen.resize(n, 0);
        izlazniStepen.resize(n, 0);
        pocetniCvor=-1;
        krajnjiCvor=-1;
    }
    
    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        ulazniStepen[b]++;
        izlazniStepen[a]++;
    }

    bool postojiPut(){
        for(int cvor = 0; cvor<brojCvorova; cvor++){
            if(izlazniStepen[cvor] == ulazniStepen[cvor]+1){
                if(pocetniCvor!=-1)
                    return false;
                pocetniCvor=cvor;
            } else if(ulazniStepen[cvor] == izlazniStepen[cvor]+1){
                if(krajnjiCvor!=-1)
                    return false;
                krajnjiCvor=cvor;
            } else if(ulazniStepen[cvor]!=ulazniStepen[cvor])
                return false;
        }
        return true;
    }

    void ispisiPut(){
        vector<int> ojlerovCiklus;
        stack<int> tekuciPut;
        tekuciPut.push(pocetniCvor);

        while(!tekuciPut.empty()){
            int trenutniCvor = tekuciPut.top();
            
            if(listaSusedstva[trenutniCvor].size()>0){
                int naredniCvor = listaSusedstva[trenutniCvor].back();
                listaSusedstva[trenutniCvor].pop_back();
                tekuciPut.push(naredniCvor);
            } else {
                ojlerovCiklus.push_back(trenutniCvor);
                tekuciPut.pop();
            }
        }

        reverse(ojlerovCiklus.begin(), ojlerovCiklus.end());
        for(int x: ojlerovCiklus)
            cout << x << " ";
        cout << '\n';
    }
};

int main(){
    int n, m, a, b;
    cin >> n >> m;
    Graf* G = new Graf(n);
    while(m--){
        cin >> a >> b;
        G->dodajGranu(a, b);
    }
    if(G->postojiPut())
        G->ispisiPut();
    else 
        cout << "Nemoguce\n";
    delete G;
    return 0;
}