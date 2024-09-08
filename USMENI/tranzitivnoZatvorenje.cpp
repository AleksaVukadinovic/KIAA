#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    vector<vector<bool>> zatvorenje;
public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        zatvorenje.resize(n, vector<bool>(n, false));
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
    }

    void odrediTranzitivnoZatvorenje(){
        for (int k = 0; k < brojCvorova; k++)
            for (int cvor1 = 0; cvor1 < brojCvorova; cvor1++)
                if (zatvorenje[cvor1][k])
                    for (int cvor2 = 0; cvor2 < brojCvorova; cvor2++)
                        zatvorenje[cvor1][cvor2] = zatvorenje[cvor1][cvor2] | zatvorenje[k][cvor2];
    }
};

int main(){
    return 0;
}