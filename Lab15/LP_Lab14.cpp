#include "stdafx.h"


using namespace std;
int wmain(int argc, wchar_t* argv[]) {
	setlocale(LC_ALL, "rus");

	int colp = 0;
	Log::LOG  log = Log::INTLOG;
	Out::OUT  out = Out::INTLOG;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Текст:", "без ошибок", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		//WriteLine(parm.out,out, in);
		char String[100]{};
		for (int i = 0, j = 0; j < strlen((const char*)in.text); j++)
		{
			cout << in.text[j];

		}

		Seporator::Seporator(in);
		LA::LEX lex = LA::lexAnaliz(log, in);
		LT::showTable(lex.lextable, parm);
		Log::Close(log);
		//PN::WriteLT(lex.lextable);
		PN::testPN(lex.lextable, lex.idtable);
		PN::WriteLT(lex.lextable);
	}


	catch (Error::ERROR e) {
		Log::WriteError(log, e);
	}

	system("pause");
	return 0;
};