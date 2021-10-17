#include "stdafx.h"
using namespace std;
namespace In {
	IN getin(wchar_t infile[]) {
		IN in{ 0, 0, 0 , new unsigned char[IN_MAX_LEN_TEXT], IN_CODE_TABLE };
		int col = 0;
		bool count = 0;
		ifstream fin(infile);
		if (!fin.is_open()) throw ERROR_THROW(110)
			while (in.size < IN_MAX_LEN_TEXT)
			{
				char temp;

				fin.get(temp);
				unsigned char x = temp;

				if (fin.eof())
				{
					in.text[in.size] = '\0';
					in.lines++;
					break;
				}
				if (in.code[x] == in.T) {
					in.text[in.size] = x;
					in.size++;
					col++;
				}
				else if (in.code[x] == in.I) {
					in.ignor++;
				}
				else if (in.code[x] == in.S) {
				
					 if ((in.code[in.text[in.size - 1]] == in.S) && (x == ' ') && count ==0)
					{
						continue;
					}
					 else 
						if (in.text[in.size - 1] == ' ' && count == 0) {
							in.size = in.size - 1;
						}
						in.text[in.size] = x;
						in.size++;
						col++;
						if (in.text[in.size-1] == (unsigned char)*"'") {
							count = not(count);
						}
					
				}
				
				else if (in.code[x] == in.F) { throw ERROR_THROW_IN(111, in.lines, col); }
				else {
					in.text[in.size] = in.code[x];
					in.size++;
					in.ignor++;
				}
				if (temp == IN_CODE_ENDL) {
					in.lines++;
					col = 0;
				}
			}
		return in;
	}
}
