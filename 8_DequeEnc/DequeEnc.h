#ifndef _DequeEnc_H
#define _DequeEnc_H

#include <stdexcept>
using std::logic_error; 

template <typename Tipo>
class DequeEnc {
	public:
	DequeEnc();
	~DequeEnc();
	// Métodos principais
	// Insere o elemento A no in´ıcio da deque
	void empilha(const Tipo &elem) throw (logic_error);
	//Remove o elemento que est´a no in´ıcio da deque.
	Tipo desempilha() throw (logic_error);
	
	// Insere o elemento A no final da deque
	void inject(const Tipo &elem) throw (logic_error);
	//Remove o elemento que est´a no final da deque.
	Tipo eject() throw (logic_error);
	
	// Métodos auxiliares
	bool vazio();
	int tamanho();

	private:
	struct Celula 
	{
		Tipo el;
		Celula *prox;
		Celula *ant;
	};

	Celula *ini, *fim;
	unsigned int nelem;
};

// Construtor
template <typename Tipo>
DequeEnc<Tipo>::DequeEnc() 
{
	ini = fim = NULL;
	nelem = 0;
}

// Destrutor
template <typename Tipo>
DequeEnc<Tipo>::~DequeEnc() {
	Celula *aux;
	while (ini) {
		aux = ini;
		ini = ini->prox;
		delete(aux);
	}
}

// Insere o elemento el no in´ıcio da deque
template <typename Tipo>
void DequeEnc<Tipo>::empilha(const Tipo &el) throw (logic_error) 
{
	Celula *nova = new Celula;
	if (nova == NULL)
	    throw logic_error("Falta memoria");
	nova->el = el;
	if (vazio()) {
        ini = fim = nova;
    } else {
        nova->prox = ini;
        ini->ant = nova;
        ini = nova;
    }
	nelem++;
}

//Remove o elemento que est´a no in´ıcio da deque.
template <typename Tipo>
Tipo DequeEnc<Tipo>::desempilha() throw (logic_error) 
{
	if (vazio())
		throw logic_error("Deque vazio");
	Celula *aux = ini;
	Tipo elem = ini->el;
	ini = ini->prox;
	if (ini == NULL) {
        fim = NULL;
    } else {
        ini->ant = NULL;
    }
	delete aux;
	nelem--;
	return(elem);
}

// Insere o elemento A no final da deque
template <typename Tipo>
void DequeEnc<Tipo>::inject(const Tipo &el) throw (logic_error) 
{
	Celula *nova = new Celula;
	if (nova == NULL)
	    throw logic_error("Falta memoria");
	nova->el = el;
	if (vazio()) {
        ini = fim = nova;
    } else {
        nova->ant = fim;
        fim->prox = nova;
        fim = nova;
    }
	nelem++;
}

//Remove o elemento que est´a no final da deque.
template <typename Tipo>
Tipo DequeEnc<Tipo>::eject() throw (logic_error) 
{
	if (vazio())
	    throw logic_error("Deque vazio");
	Celula *aux = fim;
	Tipo elem = fim->el;
	fim = fim->ant;
	if (fim == NULL) {
        ini = NULL;
    } else {
        fim->prox = NULL;
    }
	delete aux;
	nelem--;
	return(elem);
}

// Métodos auxiliares
template <typename Tipo>
bool DequeEnc<Tipo>::vazio() 
{
	return(nelem == 0);
}

template <typename Tipo>
int DequeEnc<Tipo>::tamanho() 
{
	return(nelem);
}

#endif