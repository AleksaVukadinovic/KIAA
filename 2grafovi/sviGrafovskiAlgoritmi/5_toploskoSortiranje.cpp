#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    vector<int> ulazniStepen;
    vector<int> topoloskiPoredak;

public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        ulazniStepen.resize(n, 0);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        ulazniStepen[b]++;
    }

    void topoloskiSortiraj(){
        queue<int> red;
        for(int i=0; i<brojCvorova; i++)
            if(ulazniStepen[i]==0)
                red.push(i);

        while(!red.empty()){
            int cvor = red.front();
            red.pop();
            topoloskiPoredak.push_back(cvor);

            for(int sused: listaSusedstva[cvor]){
                ulazniStepen[sused]--;
                if(ulazniStepen[sused]==0)
                    red.push(sused);
            }
        }
    }

};

int main(){


    return 0;
}