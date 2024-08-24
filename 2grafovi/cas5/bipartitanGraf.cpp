#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int brojCvorova;
    bool jeste = true;
    vector<vector<int>> listaSusedstva;
    vector<int> boja;

    void dfs(int trenutni, int trenutnaBoja) {
        boja[trenutni] = trenutnaBoja;
        for(int sused : listaSusedstva[trenutni]) {
            if(boja[sused] == -1) {  
                dfs(sused, 1 - trenutnaBoja); 
            } else if(boja[sused] == boja[trenutni]) { 
                jeste = false;
                return;
            }
        }
    }

public:
    Graf(int n) {
        brojCvorova = n;
        listaSusedstva.resize(n);
        boja.resize(n, -1); 
    }

    void dodajGranu(int a, int b) {
        listaSusedstva[a].push_back(b);
        listaSusedstva[b].push_back(a);
    }

    bool jesteBipartitan() {
        dfs(0, 0); 
        return jeste;
    }

    void ispisiStudente() {
        for(int i = 0; i < brojCvorova; i++) {
            if(boja[i] == 0)
                cout << i << " ";
        }
        cout << '\n';
    }
};

int main() {
    int n, m, a, b;
    cin >> n >> m;
    Graf* G = new Graf(n);

    while(m--) {
        cin >> a >> b;
        G->dodajGranu(a, b);    
    }

    if(G->jesteBipartitan()) 
        G->ispisiStudente();
    else 
        cout << "-\n";

    delete G;
    return 0;
}
