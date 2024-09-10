#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

typedef struct {
    double x, y;
} Tacka;

typedef struct {
    double x, y;
} Vektor;

enum Orijentacija {POZITIVNA, KOLINEARNE, NEGATIVNA};

Orijentacija orijentacija(const Tacka& A, const Tacka& B, const Tacka& C){
    int d = (B.x - A.x)*(C.y-A.y) - (C.x-A.x)*(B.y-A.y);
    if(d>0) return POZITIVNA;
    else if(d<0) return NEGATIVNA;
    else return KOLINEARNE;
}

bool tackaUTrouglu(const Tacka& T, const Tacka& A, const Tacka& B, const Tacka& C){
    Orijentacija o1 = orijentacija(A, B, T);
    Orijentacija o2 = orijentacija(B, C, T);
    Orijentacija o3 = orijentacija(A, C, T);
    return o1 == o2 && o2 == o3;
}

bool tackaUMnogougluGlupo(const vector<Tacka>& P, const Tacka& Q){
    int n = P.size();
    bool jeste = false;

    for(int i=0; i<n; i++){
        int j = (i+1)%n;
        Tacka Pi = P[i];
        Tacka Pj = P[j];

        if(Pi.x > Pj.x)
            swap (Pi, Pj);
        
        if(Pi.x < Q.x && Q.x < Pj.x && (Pi.y-Q.y)*(Pj.x-Pi.x)<=(Pj.y-Pi.y)*(Pi.x-Q.x));
            jeste = !jeste;
    }
    return jeste;
}

bool tackaUMnogougluPametno(const vector<Tacka>& poligon, const Tacka& Q, int l, int d){
    if(d-l==1)
        return tackaUTrouglu(Q, poligon[0], poligon[l], poligon[d]);
    int s = l +(d-l)/2;
    if(orijentacija(poligon[0], poligon[s], Q)==POZITIVNA)
        return tackaUMnogougluPametno(poligon, Q, s ,d);
    else return tackaUMnogougluPametno(poligon, Q, l, s);
}

bool funkcijaOmotac(const vector<Tacka>& poligon, const Tacka& Q){
    return tackaUMnogougluPametno(poligon, Q, 1, poligon.size()-1);
}

int main(){
    return 0;
}