#include <iostream>
#include <vector>
using namespace std;

long long zm(long long a, long long b, long long m){
    return ((a%m)+(b%m))%m;
}
long long pm(long long a, long long b, long long m){
    return ((a%m)*(b%m))%m;
}
long long pm2(long long a, long long b, long long c, long long m){
    return ((((a%m)*(b%m))%m)*c)%m;
}
long long rm(long long a, long long b, long long m){
    return ((a%m)-(b%m)+m)%m;
}

long long nzdProsireni(long long a, long long b, long long& x, long long& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    long long x1, y1;
    long long nzd = nzdProsireni(b, a%b, x1, y1);

    x=y1;
    y=x1-(a/b)*y1;

    return nzd;
}
long long modularniInverz(long long a, long long n){
    long long x, y;
    long long d = nzdProsireni(a, n, x, y);
    if(d!=1)
        return -1;
    else
        return (x%n+n)%n;
}

bool kto(const vector<int>& r, const vector<int>& m, int n, int& rezultat){
    long long M = 1;
    for(int i=0; i<n; i++)
        M*=m[i];

    rezultat = 0;
    for(int i=0; i<n; i++){
        int pi = M/m[i];
        int pi_inverz = modularniInverz(pi, m[i]);

        if(pi_inverz==-1)
            return false;
        
        rezultat = zm(rezultat,pm2(r[i], pi_inverz, pi, M) ,M);
    }
    return true;
}

int main(){
    vector<int> ostaci = {3, 3, 4};
    vector<int> moduli = {7, 5, 12};
    int rezultat;
    kto(ostaci, moduli, 3, rezultat);
    cout << rezultat << '\n';
    return 0;
}