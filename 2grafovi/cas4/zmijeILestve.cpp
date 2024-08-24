#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    const int pocetak = 0;
    int cilj;

public:
    Graf(const int n) {
        brojCvorova = n;
        listaSusedstva.resize(n);
        cilj = n - 1;
    }

    void dodajGranu(const int a, const int b) {
        listaSusedstva[a].push_back(b);
    }

    int najkraciPut() {
        queue<int> red;
        vector<int> udaljenost(brojCvorova, -1); 
        udaljenost[pocetak] = 0;
        red.push(pocetak);

        while (!red.empty()) {
            int trenutni = red.front(); red.pop();
            if (trenutni == cilj)
                return udaljenost[trenutni];
            for (int sused : listaSusedstva[trenutni]) {
                if (udaljenost[sused] == -1) {
                    udaljenost[sused] = udaljenost[trenutni] + 1;
                    red.push(sused);
                }
            }
        }
        return -1; 
    }
};

int main() {
    int n, maxKockice, m, a, b;
    cin >> n >> maxKockice >> m;
    Graf* G = new Graf(n);
    unordered_map<int, int> mapa;

    while (m--) {
        cin >> a >> b;
        mapa[a] = b; 
    }

    for (int i=0; i<n; i++) {
        if (mapa.find(i) == mapa.end()) {
            for (int j = 1; j <= maxKockice && i + j < n; j++) {
                int dest = i + j;
                if (mapa.find(dest) != mapa.end()) 
                    dest = mapa[dest]; 
                G->dodajGranu(i, dest);
            }
        } else G->dodajGranu(i, mapa[i]); 
    }

    std::cout << G->najkraciPut() << '\n';
    delete G;
    return 0;
}
