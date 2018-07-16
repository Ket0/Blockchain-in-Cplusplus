// 
// 
// // Einfache Blockchain in C++11 \\
//
// Version: 0.1
//
// Autor : Stefan Eickholz
// Datum:   16.07.2018
// Ort:     Potsdam
// Sprache: C++
// Version: 11
//
// In den folgend gezeigten Programmanweisungen wird meine Python Blockchain
// in C++ umgesetzt.
// 
// 

// Includes
#include <iostream>
#include <vector>
#include "Block.h"
using namespace std;

// Funktionen
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
