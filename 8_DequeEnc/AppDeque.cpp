#include <iostream>
#include "DequeEnc.h"

// using ED::DequeEnc;
using namespace std;

int main() 
{
	DequeEnc<int> d;
	try {
		for (int i=0; i<15; i++){
			d.empilha(i);
		}
		for (int i=9; i>=0; i--){
		    d.inject(i);
		}
		for (int i=0; i<10; i++){
			cout << d.desempilha() << endl;	
		}
		for (int i=0; i<15; i++){
		    cout << d.eject() << endl;
		}
		
		/*d.empilha(12);
		d.empilha(25);
		d.empilha(69);
		d.inject(14);
		d.inject(11);
		cout << d.eject() << endl;
		cout << d.eject() << endl;
		cout << d.eject() << endl;
		cout << d.eject() << endl;
		cout << d.desempilha() << endl;
		*/
	}
	catch (logic_error err){
		cout << err.what();
	}
	return 0;
}