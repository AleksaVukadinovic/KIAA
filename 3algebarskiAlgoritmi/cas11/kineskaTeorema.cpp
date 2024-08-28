#include <iostream>
#include <vector>
using namespace std;

const int n = 3;

int nzdProsireni(int a, int b, int& x, int& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    int x1, y1;
    int nzd = nzdProsireni(b, a%b, x1, y1);

    x=y1;
    y = x1-(a/b)*y1;
    return nzd;
}

int modularniInverz(int a, int n){
    int x, y;
    int d = nzdProsireni(a, n, x, y);
    if(d!=1)
        return -1;
    else 
        return (x%n+n)%n;
}

bool kto(const vector<int>& ostaci, const vector<int>& moduli, int& rezultat){
    int M = 1;
    for(int i=0;i<n;i++)
        M*=moduli[i];

    rezultat = 0;
    for(int i=0; i<n; i++){
        int pi = M/moduli[i]; // proizvod svih modula osim i-tog
        int inverzpi = modularniInverz(pi, moduli[i]);
        if(inverzpi==-1)
            return false;

        rezultat = (rezultat + (((pi*inverzpi)%M)*ostaci[i])%M)%M;
    }
    return true;
}

int main(){
    int rezultat;
    vector<int> ostaci(n);
    vector<int> moduli(n);
    for(int i=0;i<n;i++)
        cin >> ostaci[i] >> moduli[i];
    if(kto(ostaci, moduli, rezultat))
        cout << rezultat << '\n';
    else cout << "Nema resenja\n";
    return 0;
}