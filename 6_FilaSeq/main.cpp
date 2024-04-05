#include <iostream>
#include "FilaSeq.h"

using ED::FilaSeq;
using namespace std;

int main(int argc, char** argv) 
{
	FilaSeq<int> f(30);
	try {
		for (int i=0; i<20; i++)
			f.insere(i);
		for (int i=0; i<20; i++)
			cout << f.retira() << endl;
	}
	catch (logic_error err){
		cout << err.what();
	}
}