#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int zaokruziNaStepenDvojke(int n) {
    if (n == 0) return 1;
    return (int) pow(2, ceil(log2(n)));
}

// slika vrednosti originalnog niza u pozicije na kojima se te vrednosti nalaze u sortiranom nizu
vector<int> kompresujKoordinate(vector<int>& niz) {
    vector<int> sortiraniNiz = niz;
    sort(sortiraniNiz.begin(), sortiraniNiz.end());
    sortiraniNiz.erase(unique(sortiraniNiz.begin(), sortiraniNiz.end()), sortiraniNiz.end());
    
    vector<int> kompresovani(niz.size());
    for (int i = 0; i < niz.size(); ++i) 
        kompresovani[i] = lower_bound(sortiraniNiz.begin(), sortiraniNiz.end(), niz[i]) - sortiraniNiz.begin();
    
    return kompresovani;
}

vector<int> formirajStablo(int n) {
    n = zaokruziNaStepenDvojke(n);
    return vector<int>(2 * n, 0);
}

void promeniVrednost(vector<int>& stablo, int indeks, int vrednost) {
    int n = stablo.size() / 2;
    stablo[indeks += n] += vrednost;
    for (indeks /= 2; indeks > 0; indeks /= 2) 
        stablo[indeks] = stablo[2 * indeks] + stablo[2 * indeks + 1];
}

int zbirSegmenta(vector<int>& stablo, int levaGranica, int desnaGranica) {
    int n = stablo.size() / 2, zbir=0;
    levaGranica += n; desnaGranica += n +1;
    while (levaGranica < desnaGranica) {
        if (levaGranica % 2 == 1) zbir += stablo[levaGranica++];
        if (desnaGranica % 2 == 1) zbir += stablo[--desnaGranica];
        levaGranica /= 2;
        desnaGranica /= 2;
    }
    return zbir;
}

int prebrojInverzije(vector<int>& niz) {
    vector<int> kompresovani = kompresujKoordinate(niz);
    int n = kompresovani.size();
    vector<int> stablo = formirajStablo(n);
    int brojInverzija = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        brojInverzija += zbirSegmenta(stablo, 0, kompresovani[i] - 1);
        promeniVrednost(stablo, kompresovani[i], 1);
    }
    
    return brojInverzija;
}

int main() {
    int n;
    cin >> n;
    vector<int> niz(n);
    for (int i = 0; i < n; ++i)
        cin >> niz[i];
    cout << prebrojInverzije(niz) << '\n';
    return 0;
}
