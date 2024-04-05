#include <iostream>
#include "FilaEnc.h"

// using ED::FilaEnc;
using namespace std;

int main(int argc, char** argv) 
{
	FilaEnc<int> f;
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