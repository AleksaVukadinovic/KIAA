#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> tacke(n);
    for(int i=0; i<n; i++){
        cin >> a >> b;
        tacke[i]={a, b};
    }
    sort(tacke.begin(), tacke.end(), [&](pair<int, int> p1, pair<int, int> p2){
        if(p1.first==p2.first)
            return p1.second>p2.second;
        return p1.first>p2.first;
    });
    for(auto [x, y]: tacke){
        cout << x << " " << y << '\n';
    }
    return 0;
}