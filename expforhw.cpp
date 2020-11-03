#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main (){

	char Alphabet[29] = {' ', '!', '.', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
	'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
	'x', 'y', 'z'};

	string user_word = "";
	int i = 0;
	int j = sizeof(Alphabet) - 1;
	while(true){
		if (i > j){
			i = 432;
			break;
		} else if (i == j){
			char user_input;
			cout << "Is the letter '" << Alphabet[i] << "'?" << endl;
			cin >> user_input;
			if ((user_input == 'y') && (Alphabet[i] != '!')){
				user_word += Alphabet[i];
				i = 0;
				j = sizeof(Alphabet) - 1;
			} else if ((user_input == 'y') && (Alphabet[i] == '!')){
				cout << "I will break  '" << endl;
				i = 432;
				break;
			} else{
				i = 0;
				j=sizeof(Alphabet) - 1;
			}
		} else{
			double x = ((j-i)/2);
			int middle = i + floor(x);
			if (i = 432){
				break;
			} else if (middle == i){
				char user_input;
				cout << "Is the letter '" << Alphabet[i] << "'?" << endl;
				cin >> user_input;
				if ((user_input == 'y') && (Alphabet[i] != '!')){
					user_word += Alphabet[i];
					i = 0;
					j = sizeof(Alphabet) - 1;
				} else if ((Alphabet[i] == '!') && (user_input == 'y')){
					cout << "I will break  '" << endl;
					i = 432;
					break;
				} else{
					i = middle + 1;
				}
			} else{
				char user_input;
				cout << "Is the letter between '" << Alphabet[i] << "' and '" << Alphabet[middle] << "'?" << endl;
				cin >> user_input;
				if (user_input == 'y'){
					j = middle;
				} else{
					i = middle + 1;
				}	
			}
		}
	}
	cout << "You typed:\n" << user_word << endl;
return 0;
}