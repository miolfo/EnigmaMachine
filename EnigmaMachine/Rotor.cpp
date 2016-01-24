#include "Rotor.h"

Rotor::Rotor(Rotor::RotorType type): 
offset(0)
{
	//The inner ring is always alphabetical
	std::string inner = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::copy(inner.begin(), inner.end(), std::back_inserter(inner_ring_));
	std::string outer;
	switch (type){
	case I:
		outer = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	case II:
		outer = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	case III:
		outer = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	case IV:
		outer = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	case V:
		outer = "VZBRGITYUPSDNHLXAWMJQOFECK";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	case VI:
		outer = "JPGVOUMFYQBENHZRDKASXLICTW";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	case VII:
		outer = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	case VIII:
		outer = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	case REFLECTOR_A:
		outer = "EJMZALYXVBWFCRQUONTSPIKHGD";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	case REFLECTOR_B:
		outer = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
		std::copy(outer.begin(), outer.end(), std::back_inserter(outer_ring_));
		break;
	}
}

void Rotor::Rotate(RotateType type){
	if (type == UP){
		offset++;
		if (offset == 26) offset = 0;
	}
	else{
		offset--;
		if (offset < 0) offset = inner_ring_.size()-1;
	}
}

char Rotor::Encrypt(char character, EncryptDirection dir){
	char upper_c = upperCase(character);
	char encrypted;
	//Get the index in the first ring
	int index = -1;
	if (dir == LEFT){
		for (size_t i = 0; i < inner_ring_.size(); i++){
			if (inner_ring_.at(i) == upper_c) index = i;
		}
	}
	else{
		for (size_t i = 0; i < outer_ring_.size(); i++){
			if (outer_ring_.at(i) == upper_c) index = i;
		}
	}
	if (dir == LEFT){
		if (index + offset > 25){
			index = (index + offset) - 26;
		}
		else{
			index += offset;
		}
		encrypted = outer_ring_.at(index);
	}
	else{
		if (index - offset < 0){
			index = (index - offset) + 26;
		}
		else{
			index -= offset;
		}
		encrypted = inner_ring_.at(index);
	}
	//std::cout << "Encrypted " << upper_c << " to " << encrypted << " with offset " << offset << std::endl;
	return encrypted;
}

char Rotor::upperCase(char character){
	char upper;
	std::locale loc;
	upper = std::toupper(character, loc);
	return upper;
}

void Rotor::ResetRotation(){
	offset = 0;
}
