#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    vector<vector<int>> listaSusedstvaTransponovano;
    vector<bool> posecen;

    void dfs1(int cvor) {
        posecen[cvor] = true;
        for (int sused : listaSusedstva[cvor])
            if (!posecen[sused])
                dfs1(sused);
    }

    void dfs2(int cvor) {
        posecen[cvor] = true;
        for (int sused : listaSusedstvaTransponovano[cvor])
            if (!posecen[sused])
                dfs2(sused);
    }

    bool kosaraju(int cvor) {
        dfs1(cvor);
        for (bool x : posecen)
            if (!x) return false;

        fill(posecen.begin(), posecen.end(), false);

        dfs2(cvor);
        for (bool x : posecen)
            if (!x) return false;

        return true;
    }

public:
    Graf(const int n) {
        brojCvorova = n;
        listaSusedstva.resize(n);
        listaSusedstvaTransponovano.resize(n);
        posecen.resize(n, false);
    }

    void dodajGranu(const int a, const int b, bool jeDvosmerna) {
        listaSusedstva[a].push_back(b);
        listaSusedstvaTransponovano[b].push_back(a);
        if (jeDvosmerna) {
            listaSusedstva[b].push_back(a);
            listaSusedstvaTransponovano[a].push_back(b);
        }
    }

    bool jestePovezan() {
        return kosaraju(0);
    }
};

int main() {
    int q, n, m, a, b, p;
    cin >> q;
    while (q--) {
        cin >> n >> m;
        Graf* G = new Graf(n);
        for (int i = 0; i < m; i++) {
            cin >> p >> a >> b;
            if (p == 1) G->dodajGranu(a - 1, b - 1, false);
            else G->dodajGranu(a - 1, b - 1, true);
        }

        if (G->jestePovezan())
            cout << "Da" << '\n';
        else
            cout << "Ne" << '\n';

        delete G;
    }
    return 0;
}
