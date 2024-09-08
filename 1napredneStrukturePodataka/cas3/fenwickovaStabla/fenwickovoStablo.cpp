#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int zbirPrefiksa(const vector<int>& stablo, int k) {
    int zbir = 0;
    while (k > 0) {
        zbir += stablo[k];
        k -= k & -k; 
    }
}

void uvecaj(vector<int>& stablo, int n, int k, int x) {
    while (k <= n) {
        stablo[k] += x;
        k += k & -k;
    }
}

vector<int> formirajStablo(int n, const vector<int>& a) {
    vector<int> stablo(n+1, 0);
    stablo[1] = a[1];
    for (int k = 2; k <= n; k++)
        stablo[k] = stablo[k-1] + a[k];

    for (int k = n; k >= 1; k--){
        int f_k = k - (k & -k);
        if (f_k > 0) 
            stablo[k] -= stablo[f_k];
    }
    return stablo;
}

int main(){
    return 0;
}