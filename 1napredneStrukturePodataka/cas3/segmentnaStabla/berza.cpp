#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int zaokruziNaStepenDvojke(int n){
    if(n==0) return 1;
    return (int) pow(2, ceil(log2(n)));
}

vector<pair<int, int>> formirajStablo(vector<int>& originalniNiz){
    int n = zaokruziNaStepenDvojke(originalniNiz.size());
    originalniNiz.resize(n);
    vector<pair<int, int>> stablo(2*n, {0, 1});
    for(int i =n; i<2*n; i++)
        stablo[i]={originalniNiz[i-n],1};
    for(int i = n-1; i>0; i--){
        if(stablo[2*i].first>stablo[2*i+1].first)
            stablo[i] = stablo[2*i];
        else if(stablo[2*i].first<stablo[2*i+1].first)
            stablo[i] = stablo[2*i+1];
        else 
            stablo[i] = {stablo[2*i].first, stablo[2*i].second+stablo[2*i+1].second};
    }
    return stablo;
}

void promeniVrednost(vector<pair<int, int>>& stablo, int novaVrednost, int indeks){
    int n = stablo.size()/2;
    stablo[indeks+=n]={novaVrednost, 1};
    for(int i = indeks/2; i>0; i/=2){
        if(stablo[2*i].first>stablo[2*i+1].first)
            stablo[i] = stablo[2*i];
        else if(stablo[2*i].first<stablo[2*i+1].first)
            stablo[i] = stablo[2*i+1];
        else 
            stablo[i] = {stablo[2*i].first, stablo[2*i].second+stablo[2*i+1].second};
    }
}

pair<int, int> statiskaSegmenta(vector<pair<int, int>>& stablo, int levaGranica, int desnaGranica) {
    int n = stablo.size()/2; pair<int, int> ret = { numeric_limits<int>::min(), 1};
    levaGranica+=n; desnaGranica+=n;
    while(levaGranica<=desnaGranica){
        if(levaGranica%2==1){
            if(stablo[levaGranica].first==ret.first)
                ret.second+=stablo[levaGranica].second;
            else
                ret=max(ret, stablo[levaGranica]);
            levaGranica++;
        }
        if(desnaGranica%2==0){
            if(stablo[desnaGranica].first==ret.first)
                ret.second+=stablo[desnaGranica].second;
            else
                ret=max(ret, stablo[desnaGranica]);
            desnaGranica--;
        }
        levaGranica/=2;
        desnaGranica/=2;
    }

    return ret;
}

int main(){
    int n, q, a, b; char op;
    cin >> n >> q;
    vector<int> niz(n);
    for(int i=0;i<n;i++)
        cin >> niz[i];
    vector<pair<int, int>> stablo = formirajStablo(niz);
    while(q--){
        cin >> op >> a >> b;
        if(op=='m') {
            pair<int, int> tmp = statiskaSegmenta(stablo, a, b);
            cout << tmp.first << " " << tmp.second << '\n';
        } else promeniVrednost(stablo, b, a);
    }
    return 0;
}