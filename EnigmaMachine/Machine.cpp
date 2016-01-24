#include "Machine.h"

Machine::Machine(const PlugBoard &board, Rotor::RotorType type1, Rotor::RotorType type2, Rotor::RotorType type3, Rotor::RotorType reflector)
: rotor1_(type1),
rotor2_(type2),
rotor3_(type3),
reflector_(reflector){
	board_ = board;
	std::cout << "Initialized a machine!" << std::endl;
}

std::string Machine::Encrypt(std::string message){
	int char_count = 0;
	int char_count2 = 0;
	std::string encrypted;
	//Iterate through the message one char at a time
	//rotor1_.Rotate(Rotor::UP);
	for each(char c in message){
		//Go through plugging board and each rotor
		char step1 = board_.Encrypt(c);
		char step2 = rotor1_.Encrypt(step1, Rotor::LEFT);
		char step3 = rotor2_.Encrypt(step2, Rotor::LEFT);
		char step4 = rotor3_.Encrypt(step3, Rotor::LEFT);

		char step5 = reflector_.Encrypt(step4, Rotor::LEFT);

		//Go back through each rotor in reverse order
		char step6 = rotor3_.Encrypt(step5, Rotor::RIGHT);
		char step7 = rotor2_.Encrypt(step6, Rotor::RIGHT);
		char step8 = rotor1_.Encrypt(step7, Rotor::RIGHT);
		char step9 = board_.Encrypt(step8);
		encrypted += step9;

		//Do required rotations of rotors
		rotor1_.Rotate(Rotor::UP);
		char_count++;
		if (char_count == 26){
			rotor2_.Rotate(Rotor::UP);
			char_count = 0;
			char_count2++;
		}
		if (char_count2 == 26){
			rotor3_.Rotate(Rotor::UP);
			char_count2 = 0;
		}
	}
	return encrypted;
}

std::string Machine::Decrypt(std::string message){
	int char_count = 0;
	int char_count2 = 0;
	std::string decrypted;
	//Reinitialize rotors
	rotor1_.ResetRotation();
	rotor2_.ResetRotation();
	rotor3_.ResetRotation();
	return Encrypt(message);
}
