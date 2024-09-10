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

bool tackaUMnogouglu(const vector<Tacka>& P, const Tacka& Q){
    int n = P.size();
    Orijentacija prva = orijentacija(P[0], P[1], Q);
    for(int i=0; i<n; i++){
        if(orijentacija(P[i], P[(i+1)%n], Q)!=prva)
            return false;
    }
    return true;;
}

int main(){
    return 0;
}