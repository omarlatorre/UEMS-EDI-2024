/*
 * AppListaDEnc.cpp
 * Programa mostra para usar a Lista Duplamente Encadeada
 * Autor Omar latorre Vilca
*/

#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "ListaDEnc.h"

using namespace std;

using ED::ListaDEnc;

int main(int argc, char ** argv){
  ListaDEnc<int> lista;
  
  lista.insere(34);
  lista.insere(14);
  lista.insere(2);
  lista.insere(34);
  lista.insere(99);
  lista.insere(23);
  lista.insere(34);
  lista.insere(17);
  lista.insere(17);
  lista.insere(17);
  
  lista.imprime();
  
    lista.remove_pos(2);
    cout << "Apos remover a posição 2 \n";
    lista.imprime();
    cout << "Apos remover a posição 4 \n";
    lista.remove_pos(4);
    lista.imprime();
    cout << "o segundo elemento = " << lista.elemento(2) << endl;
  return(0);
}/* main */