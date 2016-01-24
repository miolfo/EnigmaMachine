#include <iostream>

#include "Machine.h"



int main(){
	//Example usage using Rotors I, IV and II with Reflector A
	PlugBoard board;
	board.AddPair('A', 'G');
	board.AddPair('C', 'D');
	board.AddPair('F', 'E');
	board.AddPair('U', 'R');
	Machine m(board, Rotor::I, Rotor::IV, Rotor::II, Rotor::REFLECTOR_A);
	std::string message = "JUUPATIJUU";
	std::string encrypted = m.Encrypt(message);
	std::cout << "Encrypted message " << message << " to " << encrypted << ", decrypted back to " << m.Decrypt(encrypted) << std::endl;
	return 0;
}