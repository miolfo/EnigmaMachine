#pragma once

#include <iostream>
#include <vector>
class PlugBoard{
public:
	//Structure for keeping track of which letter is paired with which
	struct PluggedPair{
		char letter1;
		char letter2;
		bool PluggedPair::operator==(const PluggedPair &other);
	};
	PlugBoard();
	//Add a new pairing to the board
	void AddPair(PluggedPair pair);
	void AddPair(char letter1, char letter2);
	//Remove pairing with letter1 
	void RemovePairing(char letter1);
	//Reset all pairings
	void Reset();
	//Return all current pairs
	std::vector<PluggedPair> GetPairs();
	//Encrypt the message using current pairings
	char Encrypt(char character);
private:
	//List of all current pairs
	std::vector<PluggedPair> plugged_pairs_;
};