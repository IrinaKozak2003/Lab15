#pragma once
#include"IT.h"
#include"LT.h"
#define EXP1 4
#define EXP2 27
#define EXP3 28
#define DOG '@'


namespace PN {
	struct buff {
		int idxTI;
		unsigned char lexema;
	};
	bool PolishNotation(
		int		lextable_pos,
		LT::LexTable& lextable,
		IT::IdTable& idtable

	);
	void testPN(
		LT::LexTable& lextable,
		IT::IdTable& idtable);
	void WriteLT(LT::LexTable& lextable);
}