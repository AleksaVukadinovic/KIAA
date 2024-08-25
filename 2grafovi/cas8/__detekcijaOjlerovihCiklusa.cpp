#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    
public:
    vector<int> pronadjiOjlerovCiklus(){
        vector<int> ojlerovCiklus;
        stack<int> tekuciPut;
        tekuciPut.push(0);

        while(!tekuciPut.empty()){
            int tekuciCvor = tekuciPut.top();
            
            if(listaSusedstva[tekuciCvor].size()>0){
                int naredniCvor = listaSusedstva[tekuciCvor].back();
                listaSusedstva[tekuciCvor].pop_back();

                tekuciCvor = naredniCvor;
                tekuciPut.push(naredniCvor);
            } else {
                ojlerovCiklus.push_back(tekuciCvor);
                tekuciPut.pop();
            }
        }

        reverse(ojlerovCiklus.begin(), ojlerovCiklus.end());
        return ojlerovCiklus;
    }

    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
    }
};

int main(){
    return 0;
}