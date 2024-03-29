#ifndef _PilhaEnc_H
#define _PilhaEnc_H

#include <stdexcept>
using std::logic_error; 


template <typename Tipo>

class PilhaEnc 
{
	public:
	PilhaEnc();
	~PilhaEnc();
	// Métodos principais
	void empilha(const Tipo &elem) throw (logic_error);
	Tipo desempilha() throw (logic_error);
	// Métodos auxiliares
	bool vazia();
	int tamanho();

	private:
	struct Celula 
	{
		Tipo el;
		Celula *prox;
	};

	Celula *topo;
	int nelem;
};

// Construtor
template <typename Tipo>
PilhaEnc<Tipo>::PilhaEnc() 
{
	topo = NULL;
	nelem = 0;
}

// Destrutor
template <typename Tipo>
PilhaEnc<Tipo>::~PilhaEnc() 
{
	Celula *aux;
	while (topo) 
	{
		aux = topo;
		topo = topo->prox;
		delete aux;
	}
}

// Empilha
template <typename Tipo>
void PilhaEnc<Tipo>::empilha(const Tipo &el) throw (logic_error)
{
	Celula *nova = new Celula;
	if (nova == NULL) throw logic_error("Falta memoria\n");
	nova->el = el;
	nova->prox = topo;
	topo = nova;
	nelem++;
}

// Desempilha
template <typename Tipo>
Tipo PilhaEnc<Tipo>::desempilha() throw (logic_error) 
{
	if (nelem == 0)
		throw logic_error("Pilha vazia\n");
	Tipo ret = topo->el;
	Celula *aux = topo;
	topo = topo->prox;
	delete aux;
	nelem--;
	return(ret);
}

// Métodos auxiliares
template <typename Tipo>
bool PilhaEnc<Tipo>::vazia() 
{
	return(nelem == 0);
}

template <typename Tipo>
int PilhaEnc<Tipo>::tamanho() 
{
	return(nelem);
}

#endif
