#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TODO

int kod(char a){
    return a-'a'+1;
}

int stepenPoModulu(int osnova, int stepen, int modul){
    int rez=1;
    while(stepen>0){
        if(stepen%2==1)
            rez=(rez*osnova)%modul;
        rez=(rez*rez)%modul;
        stepen/=2;
    }
    return rez;
}



bool rabinKarp(const string& tekst, const string& niska, int& pozicija){
    int N = tekst.size();
    int M = niska.size();
    
    int p = 31;
    int m = 1e9+9;

    int hesNiske = 0;
    for(int i=0; i<M; i++)
        hesNiske=(hesNiske*p+kod(niska[i]))%m;

    int hesSegmenta = 0;
    for(int i=0; i<M; i++)
        hesSegmenta=(hesSegmenta*p+kod(tekst[i]))%m;

    for(int i=0; i<N-M+1; i++){
        
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> slika(n);
    vector<string> deoSlike(m);
    for(int i=0; i<n; i++)
        cin >> slika[i];
    for(int i=0; i<m; i++)
        cin >> deoSlike[i];

    return 0;
}