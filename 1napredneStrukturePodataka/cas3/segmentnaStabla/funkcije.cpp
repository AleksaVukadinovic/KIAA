#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

int zaokruziNaStepenDvojke(int n){
    if(n == 0) return 1;
    return (int) pow(2, ceil(log2(n)));
}

vector<pair<int, int>> formirajStablo(vector<pair<int, int>>& originalniNiz){
    int n = zaokruziNaStepenDvojke(originalniNiz.size());
    originalniNiz.resize(n, {1, 0});  
    vector<pair<int, int>> stablo(2 * n);
    for(int i = n; i < 2 * n; i++)
        stablo[i] = originalniNiz[i - n];
    for(int i = n - 1; i > 0; i--){
        stablo[i].first = stablo[2 * i].first * stablo[2 * i + 1].first;  // a * c
        stablo[i].second = stablo[2 * i].first * stablo[2 * i + 1].second + stablo[2 * i].second;  // a * d + b
    }
    
    return stablo;
}

void promeniVrednost(vector<pair<int, int>>& stablo, int indeks, int novaVrednost1, int novaVrednost2){
    int n = stablo.size() / 2;
    stablo[indeks += n] = {novaVrednost1, novaVrednost2};
    
    for(int i = indeks / 2; i > 0; i /= 2){
        stablo[i].first = stablo[2 * i].first * stablo[2 * i + 1].first;  // a * c
        stablo[i].second = stablo[2 * i].first * stablo[2 * i + 1].second + stablo[2 * i].second;  // a * d + b
    }
}

int zbirSegmenta(vector<pair<int, int>>& stablo, int levaGranica, int desnaGranica, int x){
    int n = stablo.size() / 2;
    levaGranica += n; desnaGranica += n;
    
    pair<int, int> leviResult = {1, 0};  
    pair<int, int> desniResult = {1, 0};  
    
    while(levaGranica <= desnaGranica){
        if(levaGranica % 2 == 1){
            leviResult = {leviResult.first * stablo[levaGranica].first, leviResult.first * stablo[levaGranica].second + leviResult.second};
            levaGranica++;
        }
        if(desnaGranica % 2 == 0){
            desniResult = {stablo[desnaGranica].first * desniResult.first, stablo[desnaGranica].first * desniResult.second + stablo[desnaGranica].second};
            desnaGranica--;
        }
        levaGranica /= 2;
        desnaGranica /= 2;
    }
    pair<int, int> finalResult = {leviResult.first * desniResult.first, leviResult.first * desniResult.second + leviResult.second};
    return finalResult.first * x + finalResult.second;
}

int main(){
    int n, q, a, b, c; char op;
    cin >> n >> q;
    vector<pair<int, int>> funkcije(n); 
    for(int i = 0; i < n; i++)
        cin >> funkcije[i].first >> funkcije[i].second;
    vector<pair<int, int>> stablo = formirajStablo(funkcije);
    while(q--){
        cin >> op >> a >> b >> c;
        if(op == '0') promeniVrednost(stablo, a, b, c);
        else cout << zbirSegmenta(stablo, a, b, c) << '\n';
    }
    return 0;
}
