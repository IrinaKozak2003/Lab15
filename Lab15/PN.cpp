#include "stdafx.h"

namespace PN {
	bool PolishNotation(
		int		lextable_pos,
		LT::LexTable& lextable,
		IT::IdTable& idtable

	) {
		buff rez[255];
		buff stek[255];
		char* dog;
		bool flag = 0;
		int stek_pos = 0;
		int rez_pos=0;
		int funkID;
		bool find_fanc = 0;
		unsigned char par = '1';
		for (int i = 0; i < lextable.size; i++) {
			if (flag == 0 && lextable.table[i].sn == lextable_pos) {
				flag = 1;
				i += 2;
			}
			if (lextable.table[i].sn == lextable_pos) {
				if ((lextable.table[i].lexema == LEX_PLUS) || lextable.table[i].lexema == LEX_LEFTTHESIS) {
					if (!find_fanc) {
					stek[stek_pos].lexema = lextable.table[i].lexema;
					stek[stek_pos++].idxTI = lextable.table[i].idxTI;
					continue;
					}
					
				}
				else if (lextable.table[i].lexema== LEX_COMMA) {
					par++;
				}
				else if (lextable.table[i].lexema == LEX_RIGHTTHESIS) {
					if (find_fanc) {
						find_fanc = 0;
						rez[rez_pos].lexema = DOG;
						rez[rez_pos++].idxTI = funkID;
						rez[rez_pos].lexema = par;
						rez[rez_pos++].idxTI = NULL;
					}
					else {
						while (stek[--stek_pos].lexema != LEX_LEFTTHESIS)
						{
							rez[rez_pos++] = stek[stek_pos];
							stek[stek_pos].lexema = NULL;
							stek[stek_pos].idxTI = NULL;
						}
						stek[stek_pos].lexema = NULL;
						stek[stek_pos].idxTI = NULL;
						continue;
					}
				}
				else if(lextable.table[i].lexema == LEX_SEMICOLON)
				{
					while (--stek_pos !=-1)
					{
						rez[rez_pos++] = stek[stek_pos];
						stek[stek_pos].lexema = NULL;
						stek[stek_pos].idxTI = NULL;
					}
					continue;
				}
				else if (lextable.table[i].lexema == LEX_ID) {
					if (idtable.table[lextable.table[i].idxTI].idtype == 2) {
						find_fanc = 1;
						funkID = lextable.table[i].idxTI;
					}
					else  {
					rez[rez_pos].lexema = lextable.table[i].lexema;
					rez[rez_pos++].idxTI = lextable.table[i].idxTI;
				}
				}
				
			}
			
			
		}
		bool flag1 = 0;
		int j = 0;
		for (int i = 0; i < lextable.size; i++) {
			
			if (flag1 == 0 && lextable.table[i].sn == lextable_pos) {
				flag1 = 1;
				i += 2;
			}
			if (lextable.table[i].sn == lextable_pos) {
				if (rez[j].lexema) {
					lextable.table[i].lexema = rez[j].lexema;
					lextable.table[i].idxTI = rez[j++].idxTI;
				}
				else {
					lextable.table[i].lexema = NULL;
					lextable.table[i].idxTI = NULL;
				}
			}

		}
		for (int i = 0; i < rez_pos; i++) {
			 cout <<'\n' << rez[i].lexema << " " << rez[i].idxTI;

		}
		if (!stek && rez)
			return 1;
		else
			return 0;
	}
	void testPN(
		LT::LexTable& lextable,
		IT::IdTable& idtable) {
		cout << "Польская запись построена" << endl;

		if (PolishNotation(EXP1, lextable, idtable))
			cout << EXP1 << ": польская запись построена" << endl;
		else cout << EXP1 << ": польская запись  не построена" << endl;
		if (PolishNotation(EXP2, lextable, idtable))
			cout << EXP2 << ": польская запись построена" << endl;
		else cout << EXP2 << ": польская запись  не построена" << endl;
		if (PolishNotation(EXP3, lextable, idtable))
			cout << EXP3 << ": польская запись построена" << endl;
		else cout << EXP3 << ": польская запись  не построена" << endl;
	}
	void WriteLT(LT::LexTable& lextable) {
		cout << "maxsize		size		 lexema			sn			idxTI" << endl;
		for (int i = 0; i < lextable.size; i++) {
			cout<<i <<" "<< lextable.maxsize << "		" << lextable.size << "		" << lextable.table[i].lexema << "		" << lextable.table[i].sn << "		" << lextable.table[i].idxTI << endl;
		}
		
	}
}

