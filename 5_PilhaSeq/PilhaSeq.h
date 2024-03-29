#ifndef _PilhaSeq_H
#define _PilhaSeq_H

#include <stdexcept>
using std::logic_error; 

namespace ED {
	template <typename Tipo>
	// using namespace std;

	class PilhaSeq 
	{
		public:
			PilhaSeq(int size);
			~PilhaSeq();
			// Métodos principais
			void empilha(const Tipo &elem) throw (logic_error);
			Tipo desempilha() throw (logic_error);
			// Métodos auxiliares
			bool cheia();
			bool vazia();
			int tamanho();
		private:
			Tipo *vetor;
			int topo, size;
	};

	// Construtor
	template <typename Tipo>
	PilhaSeq<Tipo>::PilhaSeq(int size) {
		this->size = size;
		vetor = new Tipo[size];
		topo = -1;
	}

	// Destrutor
	template <typename Tipo>
	PilhaSeq<Tipo>::~PilhaSeq() {
		delete [] vetor;
	}

	// Empilha
	template <typename Tipo>
	void PilhaSeq<Tipo>::empilha(const Tipo &el) throw (logic_error){
		if (topo == (size-1))
		throw logic_error("Pilha cheia");
		vetor[++topo] = el;
	}

	// Desempilha
	template <typename Tipo>
	Tipo PilhaSeq<Tipo>::desempilha() throw (logic_error) {
		if (topo < 0)
			throw logic_error("Pilha vazia");
		return(vetor[topo--]);
	}

	// Métodos auxiliares
	template <typename Tipo>
	bool PilhaSeq<Tipo>::cheia() {
		return(topo == (size-1));
	}

	template <typename Tipo>
	bool PilhaSeq<Tipo>::vazia() {
		return(topo <0);
	}

	template <typename Tipo>
	int PilhaSeq<Tipo>::tamanho() 
	{
		return(topo + 1);
	}
}

#endif