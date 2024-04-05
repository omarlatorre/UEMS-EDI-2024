#ifndef _FilaSeq_H
#define _FilaSeq_H

#include <stdexcept>
using std::logic_error; 

namespace ED
{
	template <typename Tipo>
	class FilaSeq {
		public:
		FilaSeq(int size);
		~FilaSeq();

		// Métodos principais
		void insere(const Tipo &elem) throw (logic_error);
		Tipo retira()
		throw (logic_error);
		// Métodos auxiliares
		bool cheia();
		bool vazia();
		int tamanho();

		private:
		Tipo *vetor;
		int ini, fim, nelem, size;
	};

	// Construtor
	template <typename Tipo>
	FilaSeq<Tipo>::FilaSeq(int size) {
		this->size = size;
		vetor = new Tipo[size];
		fim = -1;
		ini = nelem = 0;
	}

	// Destrutor
	template <typename Tipo>
	FilaSeq<Tipo>::~FilaSeq() 
	{
		delete [] vetor;
	}

	// Insere
	template <typename Tipo>
	void FilaSeq<Tipo>::insere(const Tipo &el) throw (logic_error) 
	{
		if (nelem == size)
			throw logic_error("Fila cheia");
		fim++;
		if (fim >= size) 
			fim = 0;
		vetor[fim] = el;
		nelem++;
	}

	// Retira
	template <typename Tipo>
	Tipo FilaSeq<Tipo>::retira() throw (logic_error) 
	{
		if (nelem == 0)
		throw logic_error("Fila vazia");
		Tipo ret = vetor[ini];
		ini++;
		if (ini >= size) ini = 0;
		nelem--;
		return(ret);
	}

	// Métodos auxiliares
	template <typename Tipo>
	bool FilaSeq<Tipo>::cheia() 
	{
		return(nelem == size);
	}

	template <typename Tipo>
	bool FilaSeq<Tipo>::vazia() 
	{
		return(nelem == 0);
	}

	template <typename Tipo>
	int FilaSeq<Tipo>::tamanho() 
	{
		return(nelem);
	}
}

#endif