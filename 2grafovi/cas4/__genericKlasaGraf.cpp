#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;

public:
    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        // listaSusedstva[b].push_back(a);
    }
};

int main(){
    return 0;
}