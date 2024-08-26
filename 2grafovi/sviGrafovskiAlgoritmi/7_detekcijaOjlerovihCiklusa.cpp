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
    vector<int> ojlerovCiklus;
public:   
    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
    }

    void pronadjiOjlerovCiklus(){
        vector<int> ojlerovCiklus;
        stack<int> tekuciPut;
        tekuciPut.push(0);

        while(!tekuciPut.empty()){
            int cvor = tekuciPut.top();
            
            if(listaSusedstva[cvor].size()>0){
                int sused = listaSusedstva[cvor].back();
                listaSusedstva[cvor].pop_back();
                tekuciPut.push(sused);
            } else {
                ojlerovCiklus.push_back(cvor);
                tekuciPut.pop();
            }
        }
    }
};

int main(){
    return 0;
}