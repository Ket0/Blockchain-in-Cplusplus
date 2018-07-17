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
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>      /* puts, printf */
#include <time.h> /* time_t, struct tm, difftime, time, mktime */
#include <functional> /* hash */
#include "Block.h"

using namespace std;

// Funktionen
//
void genHash(Block blockToHash) {
    // Datenmember auslesen und eventuell konvertieren
    int index = blockToHash.Getm_idx();
    auto index_str = std::to_string(index);

    // Datenmember zusammenfügen


    // Hash erstellen



    char nts1[] = "Test";
    char nts2[] = "Test";
    std::string str1 (nts1);
    std::string str2 (nts2);

    std::hash<char*> ptr_hash;
    std::hash<std::string> str_hash;

    std::cout << "same hashes:\n" << std::boolalpha;
    std::cout << "nts1 and nts2: " << (ptr_hash(nts1)==ptr_hash(nts2)) << '\n';
    std::cout << "str1 and str2: " << (str_hash(str1)==str_hash(str2)) << '\n';
};

// Zeit
//
std::string getTime(){
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);
  printf ("Current local time and date: %s", asctime(timeinfo));
};


// GenesisBlock
//
Block erzeugeGenesisBlock(){
    // erzeuge
    Block myGenBlock;

    myGenBlock.Setm_idx(0);
    myGenBlock.Setm_preHash("0");
    myGenBlock.Setm_timestamp("16.07.2018");
    myGenBlock.Setm_data("Genesis Block");

    // Gib Block zurück
    return myGenBlock;
};

int main(){
    std::cout << "\n// Programmstart\n\n";
    std::cout << "Blockchain in C++\n";

    // genHash();

    //
    //myBlock.Setm_data("Hallo vom ersten Block.");
    //myBlock2.Setm_data("Hallo vom zweiten Block.");

    // Leeren Container anlegen
    std::cout << "Erstelle Blockchain.\n";
    std::vector<Block> myBlockchain;

    //
    std::cout << "Erstelle Genesisblock.\n";
    //meinGenesisBlock = erzeugeGenesisblock();

    // Block einfügen
    //myBlockchain.push_back(myBlock);
    //myBlockchain.push_back(myBlock2);

    // Ausgeben
    for (auto x : myBlockchain){
        std::cout << "Block Payload: " << x.Getm_data() << "\n";
    }

    std::cout << "\n// Programmende\n\n";
    return 0;
}
