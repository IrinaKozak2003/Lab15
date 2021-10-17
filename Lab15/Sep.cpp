#include "stdafx.h"
namespace Seporator {
	
	unsigned char** Seporator(In::IN in) {
		int i = 0;
		bool count = 0;
		cout << '\n';
		int row = 0;
		int rows = 500;
		int calls = 256;
		int call = 0;
		unsigned char** arr = new unsigned char* [rows];
		arr[row] = new unsigned char[calls];
			for (int i = 0; i < strlen((const char*)in.text); i++) {
				char temp;
				temp = in.text[i];
				unsigned char x = temp;
			
				if (in.code[x] != in.S) {
				arr[row][call++] = (char)in.text[i];
				}
				else {
					if (in.text[i] == ' ' && count == 0) {
						arr[row][call] = '\0';
						arr[++row] = new  unsigned char[calls];
						call = 0;
						continue;
					}
					else if (in.code[in.text[i - 1]] != in.S && (in.code[x] == in.S) && count == 0) {
						arr[row][call] = '\0';
						arr[++row] = new  unsigned char[calls];
						call = 0;
					}
					
					if (in.text[i] == (unsigned unsigned char)*"'") {
						count = not(count);
					}
					else if (count == 1 && in.text[i] == '|') {
						count = not(count);
					}
					if (count == 0) {
						arr[row][call++] = in.text[i];
						arr[row][call] = '\0';
						arr[++row] = new unsigned char[calls];
						call = 0;
					}
					else if (count == 1) {
						arr[row][call++] = in.text[i];
					}
				}

				
			}
			arr[row] = nullptr;
		/*for (int i = 0; i < row; i++) {
				cout<<i<<"." << arr[i] << "\t";
			cout << endl;
		}*/
		return arr;
	}
}