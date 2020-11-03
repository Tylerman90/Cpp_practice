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
	int start = 0;
	int stop = sizeof(Alphabet) - 1;
	while(start < stop){
		if (start > stop){
			start = 0;
			stop = sizeof(Alphabet) - 1;
		} else if (start == stop){
			char user_input;
			cout << "Is the letter '" << Alphabet[start] << "'?" << endl;
			cin >> user_input;
			if ((user_input == 'y') && (Alphabet[2])){
				cout << "stupid freaking machine"<< endl;
			} else if (user_input == 'y'){
				user_word += Alphabet[start];
				cout << "lame" << endl;
				start = 0;
				stop = sizeof(Alphabet) - 1;

			} else{
				start = 0;
				stop = sizeof(Alphabet) - 1;
			}
		} else{
			double x = ((stop-start)/2);
			int middle = start + floor(x);
			if (middle == start){
				char user_input;
				cout << "Is the letter '" << Alphabet[start] << "'?" << endl;
				cin >> user_input;
				if (user_input == 'y'){
					user_word += Alphabet[start];
					start = 0;
					stop = sizeof(Alphabet) - 1;
				} else{
					start = middle + 1;
				}
			} else{
				char user_input;
				cout << "Is the letter between '" << Alphabet[start] << "' and '" << Alphabet[middle] << "'?" << endl;
				cin >> user_input;
				if (user_input == 'y'){
					stop = middle;
				} else{
					start = middle + 1;
				}	
			}
		}
	}
	cout << "You typed:\n" << user_word << endl;
return 0;
}