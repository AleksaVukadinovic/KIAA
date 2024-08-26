#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

long long nzdProsireni(long long a, long long b, long long&x, long long&y){
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

bool modInverz(long long zi, long long mi, long long& yi){
    long long x, y;
    long long d = nzdProsireni(zi, mi, x, y);
    if(d!=1)
        return false;
    else {
        long long inverz = (x%mi+mi)%mi;
        yi = inverz;
        return true;
    }
    
}

long long zbirPoModulu(long long a, long long b, long long m){
    return ((a%m)+(b%m))%m;
}

long long proizvodPoModulu(long long a, long long b, long long m){
    return ((a%m)*(b%m))%m;
}

int main(){
    return 0; 
}

int KTO_grubaSila(const vector<int>& m, const vector<int>& r){
    int n = m.size();
    int x=1;
    while(true){
        int i;
        for(i=0; i<n; i++)
            if(x%m[i] != r[i])
                break;
        
        if(i==n)
            return x;
        x++;
    }
    return x;
}

int KTO_prosejavanje(const vector<int>& m, const vector<int>& r){
    int n = m.size();
    int x = r[0];
    while(true){
        int i;
        for(i=0;i<n;i++)
            if(x%m[i] != r[i])
                break;
        if(i==n)
            return x;
        
        x+=m[0];
    }
    return x;
}

// nisam siguran ali trebalo bi da je ovo optimalna
bool KTO_dobraSlozenost(vector<int>& m, vector<int>& r, int n, long long& rezultat){
    long long M = 1;
    for(int i=0; i<n; i++)
        M=m[i];

    rezultat = 0;

    for(int i=0; i<n; i++){
        long long zi = M/m[i];
        long long yi;

        if(!modInverz(zi, m[i], yi))
            return false;

        rezultat = zbirPoModulu(rezultat, proizvodPoModulu(proizvodPoModulu(r[i], yi, M),zi, M), M);
    }
    return true;
}

int main(){
    return 0;
}