

#include <iostream>
#include <vector>

#include "Block.h"

using namespace std;

Block erzeugeGenesisBlock(){
    // erzeuge
};

int main(){

    cout << "Blockchain in C++" << endl;

    Block myBlock;
    Block myBlock2;

    //
    myBlock.Setm_data("Hallo vom ersten Block.");
    myBlock2.Setm_data("Hallo vom zweiten Block.");

    // Leeren Container anlegen
    std::cout << "Erstelle Blockchain."
    std::vector<Block> myBlockchain;

    //
    std::cout << "Erstelle Genesisblock."
    meinGenesisBlock = erzeugeGenesisblock();

    // Block einfügen
    myBlockchain.push_back(myBlock);
    myBlockchain.push_back(myBlock2);

    // Ausgeben
    for (auto x : myBlockchain){
        std::cout << "Block Payload: " << x.Getm_data() << "\n";
    }


    return 0;
}
