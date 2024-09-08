#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void promeni(vector<int>& stablo, vector<int>& lenjo, int k, int x, int y, int a, int b, int v) {
    if (lenjo[k] != 0) {
        stablo[k] += (y - x + 1) * lenjo[k];
        if (x != y) {
            lenjo[2*k] += lenjo[k];
            lenjo[2*k+1] += lenjo[k];
        }
        lenjo[k] = 0;
    }
    if (b < x || y < a) return;

    if (a <= x && y <= b) {
        stablo[k] += (y - x + 1) * v;
        if (x != y) {
            lenjo[2*k] += v;
            lenjo[2*k+1] += v;
        }
    } 
    else {
        int s = (x + y) / 2;
        promeni(stablo, lenjo, 2*k, x, s, a, b, v);
        promeni(stablo, lenjo, 2*k+1, s+1, y, a, b, v);
        stablo[k] = stablo[2*k] + stablo[2*k+1];
    }
}

void promeni(vector<int>& stablo, vector<int>& lenjo, int n, int a, int b, int v) {
    promeni(stablo, lenjo, 1, 0, n-1, a, b, v);
}

int saberi(vector<int>& stablo, vector<int>& lenjo, int k, int x, int y, int a, int b) {
    if (lenjo[k] != 0) {
        stablo[k] += (y - x + 1) * lenjo[k];
        if (x != y) {
            lenjo[2*k] += lenjo[k];
            lenjo[2*k+1] += lenjo[k];
        }
        lenjo[k] = 0;
    }

    if (b < x || a > y) 
        return 0;

    if (a <= x && y <= b)
        return stablo[k];

    int s = (x + y) / 2;
    return saberi(stablo, lenjo, 2*k, x, s, a, b) + saberi(stablo, lenjo, 2*k+1, s+1, y, a, b);
}

int saberi(vector<int>& stablo, vector<int>& lenjo, int n, int a, int b) {
    return saberi(stablo, lenjo, 1, 0, n-1, a, b);
}

int main(){
    return 0;
}