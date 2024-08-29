#include <iostream>
#include <vector>
using namespace std;

int brojDelioca(int a, int b, int c){
    vector<int> faktori = {1};
    int m  = max(a, max(b, c));
    for(int i=2; i<=m; i++){
        while(m%i==0){
            faktori.push_back(i);
            m/=i;
        }
    }
    int br = 0;
    for(int x: faktori)
        if(a%x==0 && b%x==0 && c%x==0)
            br++;
    return br;
}

int main(){
    int n, a, b, c;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        cout << brojDelioca(a, b, c) << '\n';
    }
    return 0;
}