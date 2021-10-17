#include "stdafx.h"

using namespace std;

namespace Out {

	void WriteLine(wchar_t logfile[], OUT out1, In::IN a) {
		OUT out; ofstream stream;
		stream.open(logfile);
		if (!stream.is_open()) throw ERROR_THROW(112)
		else {
			wcscpy_s(out1.logfile, logfile);
			out1.stream = new ofstream;
			out1.stream->open(logfile);
		}
		{
			*out1.stream << "\n---- Исходные данные ----\n" << a.text;
		}
	}
}