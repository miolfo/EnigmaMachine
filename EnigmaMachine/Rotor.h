#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <locale> 
class Rotor{
public:
	//Rotor types according to the Enigma machine specifications from 1941
	enum RotorType{
		I, II, III, IV, V, VI, VII, VIII, REFLECTOR_A, REFLECTOR_B
	};
	enum RotateType{
		UP, DOWN
	};
	enum EncryptDirection{
		LEFT, RIGHT
	};
	Rotor(RotorType type);
	void Rotate(RotateType type);
	char Encrypt(char character, EncryptDirection dir);
	void ResetRotation();
private:
	std::vector<char> inner_ring_;
	std::vector<char> outer_ring_;
	int offset;
	char upperCase(char character);
};