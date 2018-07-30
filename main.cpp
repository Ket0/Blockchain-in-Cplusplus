// Einfache Blockchain in C++11
//
// Version: 0.2
//
// Autor : Stefan Eickholz
// Datum:   28.07.2018
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
#include <stdio.h>
#include <time.h>
#include <functional>

#include "Block.h"
using namespace std;

// Vorangestellte Definition
struct Fehler;
struct Pruefung;

void printBlock(const Block& myBlock);
void printKette(const std::vector<Block>& vec);
void checkString(const std::string& s);

const std::string getTime(){
    // Systemdatum
   time_t now = time(0);
   // Konversion in String
   char* dt = ctime(&now);
   // R�ckgabewert
   return dt;
};

void checkString(const std::string& s){
    if(!s.empty()){
        // Wert gut!
        // Mach gar nichts.
    }
    else{
        std::cout << "Error.\n String empty!\nHit ENTER to stop execution.\n";
        std::cin.get();
        abort();
    };
};

std::string genHash(Block& b){
    // Datenmember auslesen und eventuell konvertieren
    int index = b.Getm_idx();
    std::string s1 = std::to_string(index);

    // Pruefe erst, ob diese Strings vorhanden sind
    const std::string s2 = b.Getm_preHash();
    checkString(s2);

    const std::string s3 = b.Getm_timestamp();
    checkString(s3);

    const std::string s4 = b.Getm_data();
    checkString(s4);

    // Datenmember zusammenf�gen
    std::string myNewString = s1 + s2 + s3 + s4;

    // Hash erstellen
    std::hash<std::string> hashMe;

    // in String umwandeln
    std::string hashMe_str = std::to_string(hashMe(myNewString));

    // Attribut speichern
    b.Setm_blockhash(hashMe_str);

    // Hash String zurueckgeben
    return hashMe_str;
};


Block erzeugeBlock(const std::string myData, std::vector<Block>& myContainer){
    //std::cout << "Versuche neuen Block zu erstellen..." << "\n";
    // Pr�fe Kettenlaenge
    if (!myContainer.empty()){

        // Erzeuge einen weiteren Block Bx
        Block Bx;

        int preIdx = myContainer.back().Getm_idx();
        int newIdx = preIdx+1;
        Bx.Setm_idx(newIdx);

        // Teste of string leer oder nicht
        const std::string test = myContainer.back().Getm_blockhash();
        if(!test.empty()){
            auto preHash = myContainer.back().Getm_blockhash();
            Bx.Setm_preHash(preHash);
        }
        else{
            // Hash des Vorg�ngers darf nie leer sein!
            std::cout << "Error. Hit ENTER to stop execution.\n";
            std::cin.get();
            abort();
        }

        // Zeit
        std::string myTime = getTime();
        Bx.Setm_timestamp(myTime);

        // Daten
        Bx.Setm_data(myData);

        // Neuen Hash erstellen
        std::string myHash = genHash(Bx);
        Bx.Setm_blockhash(myHash);

        // Pruefe Block

        // Fuege Block in die Kette ein
        myContainer.push_back(Bx);

        //std::cout << "...Block erstellt." << "\n";
        return Bx;
    }
    else {
        //std::cout << "\nErzeuge ersten Block...\n";

        // GenesisBlock (Block Null = B0)
        Block B0;
        // Attribute setzen
        B0.Setm_idx(0);
        B0.Setm_preHash("0");
        B0.Setm_timestamp("01012018");
        B0.Setm_data("The Times 03/Jan/2009 Chancellor on brink of second bailout for banks.");

        // Hashen
        std::string B0_hash = genHash(B0);

        // In Datenstruktur einf�gen
        std::cout << "Fuege ersten Block in Blockchain ein." << "\n";
        myContainer.push_back(B0);

        // Cout Attribute
        //printBlock(B0);

        //std::cout << "...erster Block erstellt.\n\n";

        // Zur�ckgeben
        return B0;
    };

};

// Hilfsfunktionen
void printBlock(const Block& myBlock){
    std::cout << "\nDie Attribute von Block " << myBlock.Getm_idx() << " lauten: \n";
    std::cout << " Blockindex: " << myBlock.Getm_idx() << "\n";
    std::cout << " Hash Vorgaenger: " << myBlock.Getm_preHash() << "\n";
    std::cout << " Zeitmarke: " << myBlock.Getm_timestamp() << "\n";
    std::cout << " Blockdaten: " << myBlock.Getm_data() << "\n";
    std::cout << " Blockhash: " << myBlock.Getm_blockhash() << "\n";
};

void printKette(const std::vector<Block>& v){
    std::cout << "\nDie Blockchain enthaelt folgende Bloecke: \n";
    for (auto x : v){
        std::cout << "\nBlock Index: " << x.Getm_idx() << ", \nPayload: " << x.Getm_data() << "\n";
    };
};

struct Fehler{
    inline std::string f1(){std:: cout << "<<< Fehlercode 001 >>>" << "\n";};
    inline std::string f2(){std:: cout << "<<< Fehlercode 002 >>>" << "\n";};
    inline std::string f3(){std:: cout << "<<< Fehlercode 003 >>>" << "\n";};
    inline std::string f4(){std:: cout << "<<< Fehlercode 004 >>>" << "\n";};
};

struct Pruefung{
    static Fehler fehlermeldung;
    bool status = 0;
    Fehler pruefeBlock(const Block& bb){

        // Pruefe erst Typdefinition,
        // Pruefe dann Instanziierung

        // 1 Pruefe Index
        // 10 Ist ein Wert gesetzt?
        auto idx = bb.Getm_idx();

        // 11 Ist es ein Integer?
        auto x = bb.Getm_idx();
        cin >> x;
        if (cin.fail()) {
            std::cout << fehlermeldung.f2();
            return fehlermeldung;
            };

        // 12 Ist ein gueltiger Wert gesetzt?
        // mach was

        // Pruefe Hash
        auto h1 = bb.Getm_preHash();
        // pruefe

        // Pruefe Zeitstempel
        auto zs = bb.Getm_timestamp();
        // pruefe

        // Pruefe Daten
        auto dn = bb.Getm_data();
        // pruefe

        // Pruefe Blockhash
        auto bh = bb.Getm_blockhash();
        // pruefe
        };
};

// #################################### Main
// ####################################
int main(){
    std::cout << "C++ Version: " << __cplusplus << "\n";
    std::cout << "\n// Programmstart\n\n";
    std::cout << "Blockchain in C++\n";

    std::cout << "\nErstelle Blockchain.\n";
    std::vector<Block> myBlockchain;

    //std::cout << "Erstelle Genesisblock.\n";
    auto b0 = erzeugeBlock("myData", myBlockchain);

    // Ausgeben
    //std::cout << "\nAnzahl Elemente in BC: " << myBlockchain.size() << "\n";

    /*
    printKette(myBlockchain);
    */

    // Hauptschleife
    // Erzeuge weitere Bloecke
    int i = 0; //zaehlvariable
    const int maxBlocks = 100000*100;
    std::cout << "\nErzeuge " << maxBlocks << " weitere Bloecke...\n";
    while (true) {
        // Erzeuge i Bl�cke
        if (i<maxBlocks){
            Block bx = erzeugeBlock("myData", myBlockchain);
            i += 1;
        }
        else{
            break;
        }//#endIf
    }; //#endWhile
    std::cout << maxBlocks << " neue Bloecke erzeugt.\n";

    //printKette(myBlockchain);

    // Ende
    std::cout << "\n// Programmende\n\n";
    std::cout << "\nPress ENTER to exit" << std::cin.get();
    return 0;
};
