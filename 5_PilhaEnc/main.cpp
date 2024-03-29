#include <iostream>
#include "PilhaEnc.h"

using namespace std;

int main(int argc, char** argv) {
	PilhaEnc<int> p;
	for (int i=0; i<20; i++)
		p.empilha(i);
	for (int i=0; i<20; i++)
		cout << p.desempilha() << endl;
}