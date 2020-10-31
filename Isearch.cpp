#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <string>
using namespace std;

int main (){

	char Alphabet[29] = {' ', '!', '.', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
	'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
	'x', 'y', 'z'};

	string user_word = "";
	int i = 0;

	while(i <= 29){
		char user_input;
		cout << "Are you thinking of the following character? '" << Alphabet[i] << "' (y/n)\n" << endl;
		cin >> user_input;
		if ((user_input == 'y') && (Alphabet[i] != '!')){
			user_word += Alphabet[i];
			i = 0;
		} else if (user_input == 'n'){
			i += 1;
		} else{
			break;
		}
	}
	cout << "You typed:\n" << user_word << endl;
return 0;
}