#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

typedef struct {
    double x, y;
} Tacka;

typedef struct {
    double x, y;
} Vektor;

enum Orijentacija {POZITIVNA, KOLINEARNE, NEGATIVNA};

int znak(long long x){
    return (x>0) - (x<0);
}

// Racuna rastojanje tacke C od prave odredjene tackama A i B. 
// Posto vektorski proizvod daje povrsinu paralelograma odredjenog vektorima AC i AB, udaljenost je zapravo visina tog paralelograma
// i dobijamo je tako sto povrsinu podelimo sa osnovicom.
double rastojanje(const Tacka& A, const Tacka& B, const Tacka& C){
    double dx = B.x - A.x;
    double dy = B.y - A.y;
    return abs(dx*(C.y-A.y)-dy*(C.x-A.x))/sqrt(dx*dx+dy*dy);
}

// Proverava orijentaciju trogula ABC
// vektorski proizvod vektora AB i AC odrejduje orijentaciju
Orijentacija orijentacija(const Tacka& A, const Tacka& B, const Tacka& C){
    int d = (B.x - A.x)*(C.y-A.y) - (C.x-A.x)*(B.y-A.y);
    if(d>0) return POZITIVNA;
    else if(d<0) return NEGATIVNA;
    else return KOLINEARNE;
}

// Proverava da li su tacke M i N sa iste strane prave odredjenje Tackama A i B
bool saIsteStrane(const Tacka& A, const Tacka& B, const Tacka& M, const Tacka& N){
    return orijentacija(A, B, M) == orijentacija(A, B, N);
}

// Proverava da li se tacka T nalazi unutar trougla odredjenim tackama A, B i C
bool tackaUTrouglu(const Tacka& T, const Tacka& A, const Tacka& B, const Tacka& C){
    Orijentacija o1 = orijentacija(A, B, T);
    Orijentacija o2 = orijentacija(B, C, T);
    Orijentacija o3 = orijentacija(A, C, T);
    return o1 == o2 && o2 == o3;
}

// Proverava da li prava odredjena tackama A i B sece duz CD
bool pravaSeceDuz(const Tacka& A, const Tacka& B, const Tacka& C, const Tacka& D){
    return orijentacija(A, B, C)* orijentacija(A, B, D)<=0;
}

// proverava presek intervala [a, b] i [c, d]
bool projekcijeSeSeku(long long a, long long b, long long c, long long d){
    return max(a, b) >= min(c, d) && max(c, d) >= min(a, c);
}

// Proverava da li se duzi AB i CD seku
bool duziSeSeku(const Tacka& A, const Tacka& B, const Tacka& C, const Tacka& D){
    return pravaSeceDuz(A, B, C, D) && pravaSeceDuz(C, D, A, B) && projekcijeSeSeku(A.x, B.x, C.x, D.x) && projekcijeSeSeku(A.y, B.y, C.y, D.y);
}

int main(){
    return 0;
}