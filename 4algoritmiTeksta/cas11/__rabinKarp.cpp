#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long stepenPoModulu(long long a, long long b, long long m){
    long long rez = 1;
    a=a%m;

    while(b>0){
        if(b%2==1)
            rez=(rez*a)%m;
        b=b>>1;
        a=(a*a)%m;
    }
    return rez;
}

int kod(char a){
    return a-'a'+1;
}

vector<int> rabinKarp(const string& niska, const string& tekst){
    int M = niska.size();
    int N = tekst.size();
    vector<int> pozicije;

    if(M>N) return pozicije;

    int p = 31;
    int m = 1e9+9;

    long long pS = stepenPoModulu(p, M-1, m);

    long long hesNiske = 0;
    for(int i=0; i<M; i++)
        hesNiske = (hesNiske*p+kod(tekst[i]))%m;

    long long hesSegmenta = 0;
    for(int i=0; i<M; i++)
        hesSegmenta = (hesSegmenta*p+kod(tekst[i]))%m;

    for(int i=0; i<=N-M; i++){
        if(hesSegmenta==hesNiske)
            if(niska == tekst.substr(i, M));
                pozicije.push_back(i);
        if(i<N-M)
            hesSegmenta = ((hesSegmenta-kod(tekst[i])*pS+m)*p+kod(tekst[i+M]))%m;
    }
    return pozicije;
}

int main(){
    return 0;
}