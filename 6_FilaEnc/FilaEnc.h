#ifndef _FilaEnc_H
#define _FilaEnc_H

#include <stdexcept>
using std::logic_error; 

template <typename Tipo>
class FilaEnc {
	public:
	FilaEnc();
	~FilaEnc();
	// Métodos principais
	void insere(const Tipo &elem) throw (logic_error);
	Tipo retira()
	throw (logic_error);
	// Métodos auxiliares
	bool vazia();
	int tamanho();

	private:
	struct Celula 
	{
		Tipo el;
		Celula *prox;
	};

	Celula *ini, *fim;
	unsigned int nelem;
};

// Construtor
template <typename Tipo>
FilaEnc<Tipo>::FilaEnc() 
{
	fim = new Celula;
	fim->prox = NULL;
	ini = fim;
	nelem = 0;
}

// Destrutor
template <typename Tipo>
FilaEnc<Tipo>::~FilaEnc() {
	Celula *aux;
	while (ini) {
		aux = ini;
		ini = ini->prox;
		delete(aux);
	}
}

// Insere
template <typename Tipo>
void FilaEnc<Tipo>::insere(const Tipo &el) throw (logic_error) 
{
	fim->prox = new Celula;
	if (!fim->prox)
	throw logic_error("Falta memoria");
	fim = fim->prox;
	fim->el = el;
	fim->prox = NULL;
	nelem++;
}

// Retira
template <typename Tipo>
Tipo FilaEnc<Tipo>::retira() throw (logic_error) 
{
	if (nelem == 0)
	throw logic_error("Fila vazia");
	Celula *aux = ini;
	ini = ini->prox;
	delete aux;
	nelem--;
	return(ini->el);
}

// Métodos auxiliares
template <typename Tipo>
bool FilaEnc<Tipo>::vazia() 
{
	return(nelem == 0);
}

template <typename Tipo>
int FilaEnc<Tipo>::tamanho() 
{
	return(nelem);
}

#endif