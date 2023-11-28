//============================================================================
// Name        : Aufgabenblock_2.cpp
// Author      : Asidovic
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "Fahren.h"
#include "Parken.h"
#include "Verhalten.h"

using namespace std;


void vAufgabe6() {
    Weg autobahn("Autobahn", 500); // 500 km uzunluğunda bir yol

    // Araçları oluştur
    auto bmw = std::make_unique<Fahrzeug>("BMW", 100);
    auto audi = std::make_unique<Fahrzeug>("Audi", 120);

    // Araçları yola ekle
    autobahn.vAnnahme(std::move(bmw), 1); // BMW, 1 saat sonra yola çıkacak
    autobahn.vAnnahme(std::move(audi)); // Audi hemen yola çıkacak

    const double zeittakt = 0.25; // 15 dakika (0.25 saat)
    const double gesamtZeit = 2; // Toplam 2 saat için simülasyon

    for (double dGlobaleZeit = 0; dGlobaleZeit < gesamtZeit; dGlobaleZeit += zeittakt) {
        // Yolu simüle et
        autobahn.vSimulieren();

        // Araçların güncel durumlarını yazdır
        autobahn.vAusgeben(std::cout);

        std::cout << "Globale Zeit: " << dGlobaleZeit << " Stunden\n";
    }
}

void vAufgabe7(){
    std::vector<std::unique_ptr<Fahrzeug>> vFahrzeuge;
    int anzahlFahrzeuge;
    std::string name;
    double maxGeschwindigkeit, startzeit;
    Weg autobahn("Autobahn", 500); // 500 km uzunluğunda
    Weg landstrasse("Landstrasse", 300); // 300 km uzunluğunda

    std::cout << "Anzahl der Fahrzeuge: ";
    std::cin >> anzahlFahrzeuge;
    for (int i = 0; i < anzahlFahrzeuge; ++i) {
        std::cout << "Fahrzeug #" << i+1 << " Name: ";
        std::cin >> name;
        std::cout << "Maximalgeschwindigkeit: ";
        std::cin >> maxGeschwindigkeit;
        std::cout << "Startzeit (in Stunden, 0 für sofort): ";
        std::cin >> startzeit;

        if (startzeit == 0) {
            vFahrzeuge.push_back(std::make_unique<Fahrzeug>(name, maxGeschwindigkeit));
            vFahrzeuge.back()->vNeueStrecke(autobahn);
        } else {
            vFahrzeuge.push_back(std::make_unique<Fahrzeug>(name, maxGeschwindigkeit));
            vFahrzeuge.back()->vNeueStrecke(landstrasse, startzeit);
        }
    }

    const double zeittakt = 0.25; // 15 Minuten
    const double gesamtZeit = 10; // 10 Stunden für die Simulation


    while (dGlobaleZeit < gesamtZeit) {
        dGlobaleZeit += zeittakt;

        for (auto& fahrzeug : vFahrzeuge) {
            fahrzeug->vSimulieren();

        }

        std::cout << "Globale Zeit: " << dGlobaleZeit << " Stunden\n";
    }
}


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//vAufgabe2();
	//vAufgabe4();
	//vAufgabe5();
	vAufgabe6();
	//vAufgabe7();

	return 0;
}

