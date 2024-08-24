#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    vector<bool> posecen;
    vector<int> odlazniRedosled;
    vector<int> komponenta;

    vector<vector<int>> transponujGraf(){
        vector<vector<int>> transponovaniGraf(brojCvorova);
        for(int cvor=0;cvor<brojCvorova;cvor++)
            for(int sused: listaSusedstva[cvor])
                transponovaniGraf[sused].push_back(cvor);
        return transponovaniGraf;
    }

    void odrediOdlazniRedosled(int cvor){
        posecen[cvor]=true;
        for(int sused: listaSusedstva[cvor])
            if(!posecen[sused])
                odrediOdlazniRedosled(sused);
        odlazniRedosled.push_back(cvor);
    }

    void odrediKomponentu(int cvor, int brojac){
        komponenta[cvor]=brojac;
        for(int sused: listaSusedstva[cvor])
            if(komponenta[sused]==-1)
                odrediKomponentu(sused, brojac);
    }

public:

    vector<int> kosaraju(){
            posecen.resize(brojCvorova, false);
            for(int cvor = 0; cvor< brojCvorova; cvor++)
                if(!posecen[cvor])
                    odrediOdlazniRedosled(cvor);
            
            vector<vector<int>> transponovaniGraf = transponujGraf();
            int brojac = 0;

            for(int i=brojCvorova-1;i>=0;i--){
                int cvor = odlazniRedosled[i];
                if(komponenta[cvor]==-1)
                    odrediKomponentu(cvor, brojac++);
            }
        return komponenta;
        }   
};

int main(){
    return 0;
}