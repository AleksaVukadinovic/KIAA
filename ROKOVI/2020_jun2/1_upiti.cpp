#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// NAPOMENA: njihov test primer na papiru je netacan

int novaDuzina(int n){
    if(n==0)
        return 1;
    return (int) pow(2, ceil(log2(n)));
}

vector<pair<int, int>> formirajStablo(vector<int>& originalniNiz, const int x){
    originalniNiz.resize(novaDuzina(originalniNiz.size()), 0);
    int n = originalniNiz.size();
    vector<pair<int, int>> stablo(2*n, {0, 0});
    for(int i = 0; i < n; i++)
        stablo[n + i] = originalniNiz[i] > x ? make_pair(originalniNiz[i], 1) : make_pair(originalniNiz[i], 0);
    for(int i = n - 1; i > 0; i--)
        stablo[i] = {stablo[2*i].first + stablo[2*i + 1].first, stablo[2*i].second + stablo[2*i + 1].second};
    return stablo;
}

void updateVrednost(vector<pair<int, int>>& stablo, int indeks, int novaVrednost, const int x){
    int n = stablo.size()/2;
    stablo[indeks+=n] = novaVrednost>x ? make_pair(novaVrednost, 1) : make_pair(novaVrednost, 0);
    for(indeks/=2; indeks>0; indeks/=2)
        stablo[indeks]= stablo[indeks]={stablo[2*indeks].first+stablo[2*indeks+1].first, stablo[2*indeks].second+stablo[2*indeks+1].second};
}

pair<int, int> upit(vector<pair<int, int>>& stablo, int indeks, int novaVrednost, int l, int d, const int x){
    updateVrednost(stablo, indeks, novaVrednost, x);
    int n = stablo.size()/2;
    l+=n; d+=n;
    pair<int, int> ret = {0, 0};
    while(l<=d){
        if(l%2==1){
            ret = {ret.first+stablo[l].first, ret.second+stablo[l].second};
            l++;
        }
        if(d%2==0){
            ret = {ret.first+stablo[d].first, ret.second+stablo[d].second};
            d--;
        }
        l/=2;
        d/=2;
    }
    return ret;
}

int main(){
    int n, q, x, a, b, k, v;
    cin >> n >> q >> x;
    vector<int> niz(n);
    for(int i=0;i<n;i++)
        cin >> niz[i];
    vector<pair<int, int>> stablo = formirajStablo(niz, x);

    while(q--){
        cin >> k >> v >> a >> b;
        auto [suma, broj] = upit(stablo, k, v, a, b, x);
        cout << suma << " " << broj << '\n';
    }
    return 0;
}