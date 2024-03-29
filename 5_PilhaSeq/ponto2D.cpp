#include <iostream>
#include "PilhaSeq.h"

using ED::PilhaSeq;
using namespace std;

// Exemplo de uma pilha de pontos (x,y)
struct Ponto2D {
	int x, y;
};	

int main(int argc, char** argv) 
{
	PilhaSeq<Ponto2D> p(50);
	Ponto2D pt;
	for (int i=0; i<5; i++)
		for (int j=0; j<5; j++) 
		{
			pt.x = i;
			pt.y = j;
			p.empilha(pt);
		}

	for (int i=0; i<25; i++) 
	{
		pt = p.desempilha();
		cout << pt.x << "," << pt.y << endl;
	}
}