#include "stdafx.h"


using namespace std;

namespace Log {
	LOG getlog(wchar_t logfile[]) {
		LOG log; ofstream stream;
		stream.open(logfile);
		if (!stream.is_open()) throw ERROR_THROW(112)
		else {
			wcscpy_s(log.logfile, logfile);
			log.stream = new ofstream;
			log.stream->open(logfile);
		}
		return log;
	}
	void WriteLine(LOG log, const char* c, ...)
	{
		const char** ptr = &c;
		int i = 0;
		while (ptr[i] != "")
			*log.stream << ptr[i++];
		*log.stream << endl;
	}
	void WriteLine(LOG log, const wchar_t* c, ...)
	{
		const wchar_t** ptr = &c;
		char temp[100];
		int i = 0;
		while (ptr[i] != L"")
		{
			wcstombs(temp, ptr[i++], sizeof(temp));
			*log.stream << temp;
		}
		*log.stream << endl;
	}
	void WriteLog(LOG log)
	{
		tm* tm;
		time_t timet;
		time(&timet);
		tm = localtime(&timet);
		char temp[100];
		strftime(temp, sizeof(temp), "\n------------��������------------\n ----%d.%m.%y %T----\n ", tm);
		*log.stream << temp;
	}
	void WriteIn(LOG log, In::IN in)
	{
		*log.stream << "\n---- �������� ������ ----\n" << in.text
			<< "\n\n����� ��������: " << in.size
			<< "\n\n����� �����: " << in.lines
			<< "\n\n���������: " << in.ignor << endl;

	}
	void WriteParm(LOG log, Parm::PARM parm)
	{
		char in_text[PARM_MAX_SIZE];
		char out_text[PARM_MAX_SIZE];
		char log_text[PARM_MAX_SIZE];
		wcstombs(in_text, parm.in, PARM_MAX_SIZE);
		wcstombs(out_text, parm.out, PARM_MAX_SIZE);
		wcstombs(log_text, parm.log, PARM_MAX_SIZE);
		*log.stream << "\n ---- ��������� ---- \n\n-in: " << in_text
			<< "\n-out: " << out_text
			<< "\n-log: " << log_text << endl;
	}
	void WriteError(LOG log, Error::ERROR error)
	{
		if (log.stream)
		{
			*log.stream << "\n������ " << error.id
				<< ": " << error.massage
				<< "\n������ " << error.inext.line
				<< " ������� " << error.inext.col << endl;
			Close(log);
			cout << "\n������ " << error.id
				<< ": " << error.massage
				<< "\n������ " << error.inext.line
				<< " ������� " << error.inext.col << endl;
		}
		else
		{
			cout << "\n������ " << error.id
				<< ": " << error.massage
				<< "\n������ " << error.inext.line
				<< " ������� " << error.inext.col << endl;
		}
	}
	void Close(LOG log)
	{
		log.stream->close();
		delete log.stream;
	}
}
