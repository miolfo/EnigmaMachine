#pragma once

#include <iostream>

#include "Rotor.h"
#include "PlugBoard.h"

class Machine{
public:
	Machine(const PlugBoard &board, Rotor::RotorType type1, Rotor::RotorType type2, Rotor::RotorType type3, Rotor::RotorType reflector);
	std::string Encrypt(std::string message);
	std::string Decrypt(std::string message);
private:
	PlugBoard board_;
	Rotor rotor1_;
	Rotor rotor2_;
	Rotor rotor3_;
	Rotor reflector_;
};