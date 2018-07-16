

#include <iostream>
#include <vector>

#include "Block.h"

using namespace std;

Block erzeugeGenesisBlock(){
    // erzeuge
};

int main(){

    cout << "Blockchain in C++" << endl;

    // Leeren Container anlegen
    std::cout << "Erstelle Blockchain."
    std::vector<Block> myBlockchain;

    //
    std::cout << "Erstelle Genesisblock."
    meinGenesisBlock = erzeugeGenesisblock();
    
    // Ausgeben
    for (auto x : myBlockchain){
        std::cout << "Block Payload: " << x.Getm_data() << "\n";
    }
    
    return 0;
}
