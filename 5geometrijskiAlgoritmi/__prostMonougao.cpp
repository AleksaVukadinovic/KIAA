#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;

const double EPS = 1e-5;

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

int kvadratRastojanja(double a, double b, double c, double d){
    return (a - c) * (a - c) + (b - d) * (b - d);
}

double ugao(double x0, double y0, double x, double y){
    return atan2(y - y0, x - x0);
}
bool suKolinearne(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return abs(ugao(t1.x, t1.y, t2.x, t2.y) - ugao(t1.x, t1.y, t3.x, t3.y)) < EPS;
}
void prostMnogougao(vector<Tacka> &tacke)
{
    int i = 2;
    while (suKolinearne(tacke[0], tacke[1], tacke[i]))
        i++;
    double x0 = (tacke[0].x + tacke[1].x + tacke[i].x) / 3.0;
    double y0 = (tacke[0].y + tacke[1].y + tacke[i].y) / 3.0;

    sort(tacke.begin(), tacke.end(), [x0, y0](const Tacka &t1, const Tacka &t2) {
             double ugao1 = ugao(x0, y0, t1.x, t1.y);
             double ugao2 = ugao(x0, y0, t2.x, t2.y);
             if (ugao1 < ugao2 - EPS)
                 return true;
             if (ugao2 < ugao1 - EPS)
                 return false;
             return kvadratRastojanja(x0, y0, t1.x, t1.y) < kvadratRastojanja(x0, y0, t2.x, t2.y);
         });
    auto it = prev(tacke.end());
    while (suKolinearne(*prev(it), *it, tacke[0]))
        it = prev(it);
    reverse(it, end(tacke));
}

int main(){
    return 0;
}