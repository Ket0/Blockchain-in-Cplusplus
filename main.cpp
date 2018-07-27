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

using namespace std;

std::string getTime(){
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    printf ("Current local time and date: %s", asctime(timeinfo));
    return asctime(timeinfo);
};

const std::string genHash(const Block& blockToHash){

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

Block erzeugeBlock(std::string myData, const std::vector<Block>& myContainer){
    // Prüfe Kettenlaenge
    if (!myContainer.empty()){
        const int anzahlBloecke = myContainer.size();
        std::cout << "Laenge der Blockchain = ", anzahlBloecke << "\nErzeuge naechsten Block.\n";
        //int preIdx0 = myContainer.back().Getm_idx();
        //std::cout << "preIdx0 :" << preIdx0;

        // Erzeuge Block X (Bx)
        Block Bx;

        int preIdx = myContainer.size();
        //std::cout << "Container size : " << preIdx << "\n";
        int newIdx = preIdx+1;
        //std::cout << "Neuer Index lautet: " << newIdx << "\n";

        std::string preHash = "";
        //preHash = myContainer[preIdx].Getm_preHash();

        //std::string newTime =

        //std::string
        return Bx;
    };
    else {
        std::cout << "Blockchain enthaelt keine Bloecke. Laenge = ", myContainer.size() << "\nErzeuge ersten Block.\n";

        // GenesisBlock (Block Null = B0)
        Block B0;
        // Attribute setzen
        B0.Setm_idx(0);
        B0.Setm_preHash("0");
        B0.Setm_timestamp("01012018");
        B0.Setm_data("myData");

        // Hashen
        std::string B0_hash = genHash(B0);

        // In Datenstruktur einfügen
        myContainer.push_back(B0);
        std::cout << "Laenge der Blockchain = ", myContainer.size() << "\n";

        // Zurückgeben
        return B0;
    };
};

Block erzeugeGenesisBlock(std::string myData, const std::vector<Block>& myContainer){

    // GenesisBlock
    Block B0;
    B0.Setm_idx(0);
    B0.Setm_preHash("0");
    B0.Setm_timestamp("01012018");

    // Hashen
    std::string B0_hash = genHash(B0);

    // In Datenstruktur einfügen
    myContainer.push_back(B0);

    // Zurückgeben
    return B0;
};

// Hilfsfunktionen
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
    // b1
    //meinGenesisBlock = erzeugeGenesisblock();

    // Block einfügen
    myBlockchain.push_back(b1);

    // Ausgeben
    std::cout << "\nAnzahl Elemente in BC: " << myBlockchain.size() << "\n";

    /*
    for (auto x : myBlockchain){
        std::cout << "Block Payload: " << x.Getm_data() << "\n";
    };
    */

    SBlock t1 = erzeugeBlock("meineDaten", myBlockchain);
    myBlockchain.push_back(t1);
    std::cout << "\nAnzahl Elemente in BC: " << myBlockchain.size() << "\n";

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
