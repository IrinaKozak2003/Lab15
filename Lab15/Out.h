#pragma once
#include "stdafx.h"
using namespace std;
namespace Out {
	struct OUT {
		wchar_t logfile[PARM_MAX_SIZE];
		ofstream* stream;
	};
	static const OUT INTLOG = { L"", NULL };
	void WriteLine(wchar_t logfile[], OUT out, In::IN a);

}