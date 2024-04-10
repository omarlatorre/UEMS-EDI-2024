#include <iostream>
#include <string.h>
#include "ListaEnc.h"

using namespace std;
using std::string;

int main(int argc, char** argv) {
	string str;
	ListaEnc<string> lista;
	while (true) 
	{
		cin >> str;
		if (str == "fim") break;
		lista.insere(str);
	}
	cout << "Imprimindo a lista " << endl;
	lista.imprime();
    lista.remove_pos(1);
    cout << "Apos a remoção do elto na pos = 1" << endl;
    cout << "Imprimindo a lista " << endl;
    lista.imprime();
    
    cout << "Apos a inserção do elto na pos = 1" << endl;
    lista.insere_pos("Estrutura", 1);
    cout << "Imprimindo a lista " << endl;
    lista.imprime();
}
