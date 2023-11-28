/*
 * Losfahren.cpp
 *
 *  Created on: 28 Kas 2023
 *      Author: kekillialiresid
 */

#include "Losfahren.h"



Losfahren::Losfahren(Fahrzeug& _fzg, Weg& _weg) : Fahrausnahme(_fzg, _weg) {}

void Losfahren::vBearbeiten() {

	 std::cout << "Losfahren Ausnahme: Fahrzeug " << fzg.getName()
	                  << " auf Weg " << weg.getName() << std::endl;

}
