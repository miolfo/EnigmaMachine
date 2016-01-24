#include "PlugBoard.h"

bool PlugBoard::PluggedPair::operator==(const PluggedPair &other){
	if (letter1 == other.letter1 && letter2 == other.letter2) return true;
	else return false;
}

PlugBoard::PlugBoard(){
	std::cout << "Created a new empty plugboard!" << std::endl;
}

void PlugBoard::AddPair(PluggedPair pair){
	for each(PluggedPair p in plugged_pairs_){
		if (pair.letter1 == p.letter1){
			std::cout << "Letter " << pair.letter1 << " already paired with letter " << p.letter2 << "!" << std::endl;
			return;
		}
	}
	plugged_pairs_.push_back(pair);
}

void PlugBoard::AddPair(char letter1, char letter2){
	PluggedPair p;
	p.letter1 = letter1;
	p.letter2 = letter2;
	plugged_pairs_.push_back(p);
	PluggedPair p2;
	p2.letter1 = letter2;
	p2.letter2 = letter1;
	plugged_pairs_.push_back(p2);
}

void PlugBoard::RemovePairing(char letter1){
	for (size_t i = 0; i < plugged_pairs_.size(); i++){
		if (plugged_pairs_.at(i).letter1 == letter1){
			plugged_pairs_.erase(plugged_pairs_.begin() + i);
			std::cout << "Removed pairing" << std::endl;
			return;
		}
	}
	std::cout << "Pairing for removal not found!" << std::endl;
}

void PlugBoard::Reset(){
	plugged_pairs_.clear();
}

std::vector<PlugBoard::PluggedPair> PlugBoard::GetPairs(){
	return plugged_pairs_;
}

char PlugBoard::Encrypt(char character){
	char encrypted_string;
	bool pairing_found = false;
	for each(PluggedPair p in plugged_pairs_){
		if (character == p.letter1){
			encrypted_string = p.letter2;
			pairing_found = true;
		}
	}
	if (!pairing_found){
		encrypted_string = character;
	}
	return encrypted_string;
}