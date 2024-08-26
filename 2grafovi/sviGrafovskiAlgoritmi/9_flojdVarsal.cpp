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
    vector<vector<pair<int, int>>> matricaPovezanosti;
    vector<vector<int>> minRastojanje;
public:
    Graf(const int n){
        brojCvorova=n;
        matricaPovezanosti.resize(n);
        minRastojanje.resize(n, vector<int> (n, INF));
    }

    void dodajGranu(const int a, const int b, const int t){
        matricaPovezanosti[a].push_back({b, t});
    }

    void flojdVarsal(){
        for(int cvor = 0; cvor<brojCvorova; cvor++){
            minRastojanje[cvor][cvor]=0;
            for(auto [sused, udaljenostDoSuseda]: matricaPovezanosti[cvor])
                minRastojanje[cvor][sused]=udaljenostDoSuseda;
        }

        for(int k = 0; k<brojCvorova; k++)
            for(int cvor1 = 0; cvor1<brojCvorova; cvor1++)
                for(int cvor2=0; cvor2< brojCvorova; cvor2++)
                    if(minRastojanje[cvor1][k]!=INF && minRastojanje[k][cvor2]!= INF)
                        minRastojanje[cvor1][cvor2]=min(minRastojanje[cvor1][cvor2], minRastojanje[cvor1][k]+minRastojanje[k][cvor2]);

        for(int i = 0; i<brojCvorova; i++)
            if(minRastojanje[i][i]<0){
                cout << "Graf sadrzi ciklus negativne duzine" << '\n';
                return;
            }
    }
};

int main(){
    return 0;
}