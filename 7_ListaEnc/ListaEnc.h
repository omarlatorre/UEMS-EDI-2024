#ifndef _ListaEnc_H
#define _listaEnc_H

#include <stdexcept>
#include <iostream>

using std::logic_error;
using namespace std; 

template <typename Tipo>
class ListaEnc 
{
	public:
	ListaEnc();
	~ListaEnc();
	// Métodos principais
	void insere(const Tipo &el) throw (logic_error);
	void insere_pos(const Tipo &el, int pos) throw (logic_error);	
	void remove(const Tipo &el) throw (logic_error);
	void remove_pos(int pos) throw (logic_error);
	Tipo elemento(int pos) throw (logic_error);
	int pesquisa(const Tipo &el);
	
	// Métodos auxiliares
	Tipo proximo() throw (logic_error);
	void volta_cursor();
	void imprime();
	
	private:
	struct Celula {
		Tipo el;
		Celula *prox;
	};
	Celula *ini, *pc;
	unsigned int nelem;
};

// criação da lista
template <typename Tipo>
ListaEnc<Tipo>::ListaEnc()
{
	ini = new Celula;
	pc = ini;
	ini->prox = NULL;
	nelem = 0;
}

template <typename Tipo>
ListaEnc<Tipo>::~ListaEnc()
{
    Celula *aux = ini;
    while(aux->prox){
        delete aux;
    }
}

// adicionando um elemento na posição pos
template <typename Tipo>
void ListaEnc<Tipo>::insere_pos(const Tipo &el, int pos) throw (logic_error)
{
    if((pos < 0) || (pos >= nelem))
        throw logic_error("posição fora dos limites \n");
	Celula *aux, *nova;
	aux = ini;
	for (int i=0; i<pos; i++)
		aux = aux->prox;
	nova = new Celula;
	if (nova == NULL)
	    throw logic_error("Memoria insuficiente \n");
	nova->el = el;
	nova->prox = aux->prox;
	aux->prox = nova;
	nelem++;
}

template <typename Tipo>
void ListaEnc<Tipo>::remove_pos(int pos) throw (logic_error)
{
    if((pos < 0) || (pos >= nelem))
        throw logic_error("posição fora dos limites \n");
    if(ini->prox == NULL)
        throw logic_error("Lista vazia \n");
	Celula *aux, *aux2;
	aux = ini;
	aux2 = ini->prox;
	for (int i=0; i<pos; i++){
		aux = aux->prox;
		aux2 = aux2->prox;
	}
	aux->prox = aux2->prox;
	delete aux2;
	nelem--;
}

template <typename Tipo>
void ListaEnc<Tipo>::insere(const Tipo &el) throw (logic_error)
{
	Celula *nova = new Celula, *aux;
    aux = ini;
	if (nova == NULL)
	    throw logic_error("Memoria insuficiente \n");
    while(aux->prox != NULL)
        aux = aux->prox;
	nova->el = el;
	nova->prox = NULL;
	aux->prox = nova;
	nelem++;
}

template <typename Tipo>
void ListaEnc<Tipo>::remove(const Tipo &el) throw (logic_error)
{
    if(ini->prox == NULL)
        throw logic_error("Lista vazia \n");
	Celula *aux, *aux2;
	aux = ini;
	aux2 = ini->prox;
	while((aux != NULL) && (aux->el != el)){
	    aux = aux->prox;
	    aux2 = aux2->prox;
	}
	if(aux == NULL) throw logic_error("elemento não achado \n");
	aux->prox = aux2->prox;
	delete aux2;
	nelem--;
}

template <typename Tipo>
int ListaEnc<Tipo>::pesquisa(const Tipo &el)
{
	Celula *aux = ini->prox;
	int pos = 0;
	while ((aux != NULL)&&(aux->el != el)) 
	{
		aux = aux->prox;
		pos++;
	}
	if (aux == NULL) 
		return(-1);
	return(pos);
}

template <typename Tipo>
Tipo ListaEnc<Tipo> :: proximo() throw (logic_error)
{
  if (pc->prox == NULL) throw logic_error("Não há próximo \n");
  pc = pc->prox;
  return(pc->el);
}/* proximo */

template <typename Tipo>
void ListaEnc<Tipo> :: volta_cursor()
{
  pc = ini;
}/* volta_cursor */

template <typename Tipo>
void ListaEnc<Tipo>::imprime()
{
	while (pc->prox != NULL)
	{
		cout << proximo() << endl;
    }
	cout << endl;
	volta_cursor();
}

#endif