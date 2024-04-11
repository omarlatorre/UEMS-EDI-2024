#include <iostream>
#include <string>
#include "ListaSeq.h"

using ED::ListaSeq;
using namespace std;
using std::string;

int main(int argc, char** argv) {
	string str;
	ListaSeq<string> lista(10);
	while (true) 
	{
		cin >> str;
		if (str == "fim") break;
		lista.insere(str);
	}
	lista.imprime();
	lista.remove_pos(1);
	cout << "depois de remover o elto na pos = 1 " << endl;
	lista.imprime();
	cout << "o elemento na posição pos = 0" << endl;
	cout << lista.elemento(0) << endl;
}
