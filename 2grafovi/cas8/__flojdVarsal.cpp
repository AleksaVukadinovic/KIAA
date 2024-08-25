#include <iostream>
#include <vector>
#include <limits>

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
        minRastojanje.resize(n, vector<int>(n));
    }
    void dodajGranu(const int a, const int b, const int t){
        matricaPovezanosti[a].push_back({b, t});
    }
    void floydWarhsall(){
        for(int cvor = 0; cvor< brojCvorova; cvor++){
            minRastojanje[cvor][cvor]=0;
            for(auto [sused, udaljenostDoSuseda]: matricaPovezanosti[cvor])
                minRastojanje[cvor][sused]=udaljenostDoSuseda;
        }

        for(int k = 0; k<brojCvorova; k++)
            for(int cvor1 = 0; cvor1< brojCvorova; cvor1++)
                for(int cvor2 = 0; cvor2<brojCvorova; cvor2++)
                    if(minRastojanje[cvor1][k]!=INF && minRastojanje[k][cvor2]!=INF)
                        minRastojanje[cvor1][cvor2]=min(minRastojanje[cvor1][cvor2], minRastojanje[cvor1][k]+minRastojanje[k][cvor2]);

        bool imaNegativanCiklus = false;
        for(int i = 0; i<brojCvorova; i++)
            if(minRastojanje[i][i]<0){
                imaNegativanCiklus=true;
                cout << "Ima ciklus negativne duzine \n";
                break;
            }
    }
};

vector<vector<int>> floyd_warshall(vector< vector<pair<int, int>> >& graf) {
    int n = graf.size();
    vector< vector<int> > minRastojanje(n, vector<int>(n, numeric_limits<int>::max()));

    for(int cvor = 0; cvor < n; cvor++) {
        minRastojanje[cvor][cvor] = 0;
        for(auto [sused, udaljenostDoSuseda] : graf[cvor])
            minRastojanje[cvor][sused] = udaljenostDoSuseda;
    }

    for(int k = 0; k < n; k++)
        for(int cvor1 = 0; cvor1 < n; cvor1++)
            for(int cvor2 = 0; cvor2 < n; cvor2++)
                minRastojanje[cvor1][cvor2] = min(minRastojanje[cvor1][cvor2], minRastojanje[cvor1][k] + minRastojanje[k][cvor2]);

    return minRastojanje;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<pair<int, int>> > graf(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graf[u].push_back({v, w});
        graf[v].push_back({u, w});
    }

    vector< vector<int> > udaljenosti = floyd_warshall(graf);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << udaljenosti[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}