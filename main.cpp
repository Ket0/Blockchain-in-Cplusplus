// Einfache Blockchain in C++11
//
// Version: 0.1
//
// Autor : Stefan Eickholz
// Datum:   19.07.2018
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
#include "SBlock.h"
#include "GenesisBlock.h"


using namespace std;

// Funktionen
//
std::string genHash(SBlock blockToHash) {

    // Datenmember auslesen und eventuell konvertieren
    int index = blockToHash.Getm_idx();
    auto index_str = std::to_string(index);

    std::string preHash_str = blockToHash.Getm_preHash();
    std::string timestamp_str = blockToHash.Getm_timestamp();
    std::string data_str = blockToHash.Getm_data();

    // Datenmember zusammenfügen
    std::string myString_str = index_str + preHash_str + timestamp_str + data_str;
    std::cout << "\nGibt verketteten String aus: " << myString_str << "\n";

    // Hash erstellen
    std::hash<std::string> hashMe;
    std::cout << "Hash: " << hashMe(myString_str);

    // in String umwandeln
    std::string hashMe_str = std::to_string(hashMe(myString_str));
    std::cout << "\nHash: " << hashMe_str;

    return hashMe_str;
};

// Zeit
//
std::string getTime(){
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    printf ("Current local time and date: %s", asctime(timeinfo));
    return asctime(timeinfo);
};

/*
// GenesisBlock
//
GenesisBlock erzeugeGenesisBlock(){
    // erzeuge
    GenesisBlock myGenBlock;

    myGenBlock.Setm_idx(0);
    myGenBlock.Setm_preHash("0");
    myGenBlock.Setm_timestamp("01.01.2018");
    myGenBlock.Setm_data("The Times 03/Jan/2009 Chancellor on brink of second bailout for banks.");

    // Gib Block zurück
    return myGenBlock;
};
*/

// Diese Funktion erzeugt die neuen Blöcke
//
SBlock erzeugeBlock(std::string myData, const std::vector<Block>& myContainer){

    if (myContainer.empty()) {
        std::cout << "\nKeine Elemente in der Blockchain.\n";
    }
    else {
        //int preIdx0 = myContainer.back().Getm_idx();
        //std::cout << "preIdx0 :" << preIdx0;

        int preIdx = myContainer.size();
        std::cout << "Container size : " << preIdx << "\n";
        int newIdx = preIdx+1;
        std::cout << "Neuer Index lautet: " << newIdx << "\n";

        std::string preHash = "";
        //preHash = myContainer[preIdx].Getm_preHash();

        //std::string newTime =

        //std::string

    }

    SBlock meinNeuerBlock;
    return meinNeuerBlock;
};

// Hilfsfunktionen
void printGenesisBlock(const GenesisBlock& myBlock){
    std::cout << "\nDie Attribute von Block " << myBlock.Getm_idx() << " lauten: \n";
    std::cout << " Blockindex: " << myBlock.Getm_idx() << "\n";
    std::cout << " Hash Vorgaenger: " << myBlock.Getm_preHash() << "\n";
    std::cout << " Zeitmarke: " << myBlock.Getm_timestamp() << "\n";
    std::cout << " Blockdaten: " << myBlock.Getm_data() << "\n";
};

void printBlock(const SBlock& myBlock){
    std::cout << "\nDie Attribute von Block " << myBlock.Getm_idx() << " lauten: \n";
    std::cout << " Blockindex: " << myBlock.Getm_idx() << "\n";
    std::cout << " Hash Vorgaenger: " << myBlock.Getm_preHash() << "\n";
    std::cout << " Zeitmarke: " << myBlock.Getm_timestamp() << "\n";
    std::cout << " Blockdaten: " << myBlock.Getm_data() << "\n";
};


// #################################### Main
// ####################################
int main(){
    std::cout << "C++ Version: " << __cplusplus << "\n";
    std::cout << "\n// Programmstart\n\n";
    std::cout << "Blockchain in C++\n";

    std::cout << "\nErstelle Blockchain.\n";
    std::vector<Block> myBlockchain;

    std::cout << "Erstelle Genesisblock.\n";
    GenesisBlock GenesisBlock;
    printGenesisBlock(GenesisBlock);

    //meinGenesisBlock = erzeugeGenesisblock();

    // Block einfügen
    myBlockchain.push_back(GenesisBlock);
    //myBlockchain.push_back(myBlock2);
    SBlock myBlock2;
    myBlock2.Setm_idx(1);

    myBlockchain.push_back(myBlock2);

    // Ausgeben
    std::cout << "\nAnzahl Elemente in BC: " << myBlockchain.size() << "\n";

    std::cout << "\nmyBlock0 Index: " << GenesisBlock.Getm_idx();
    std::cout << "\nmyBlock0 Index: " << myBlockchain.front().Getm_idx();
    std::cout << "\nmyBlock0 Index: " << myBlockchain.at(0).Getm_idx();

    std::cout << "\nmyBlock1 Index: " << myBlockchain.at(1).Getm_idx();
    std::cout << "\nmyBlock1 Index: " << myBlock2.Getm_idx() << "\n";

    /*
    for (auto x : myBlockchain){
        std::cout << "Block Payload: " << x.Getm_data() << "\n";
    };
    */

    SBlock einTestBlock = erzeugeBlock("meineDaten", myBlockchain);

    /*
    Block myTestBlock;
    myTestBlock.Setm_idx(1);
    myTestBlock.Setm_preHash("myPreHash");
    myTestBlock.Setm_timestamp("19.07.2018");
    myTestBlock.Setm_data("Block Block\n");
    genHash(myTestBlock);
    */

    std::cout << "\nPress ENTER to exit" << std::cin.get();
    std::cout << "\n// Programmende\n\n";
    return 0;
};
