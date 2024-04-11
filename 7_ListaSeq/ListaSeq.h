#ifndef _ListaSeq_H
#define _listaSeq_H

#include <stdexcept>
#include <iostream>

using std::logic_error;
using namespace std; 

namespace ED
{
	template <typename Tipo>
	class ListaSeq {
		public:
		ListaSeq(int size);
		~ListaSeq();
		// Métodos principais
		void insere(const Tipo &el) throw (logic_error);
		void insere_pos( const Tipo &el, int pos) throw (logic_error);
		void remove(const Tipo &el) throw (logic_error);
		void remove_pos(int pos) throw (logic_error);
		Tipo elemento(int pos) throw (logic_error);
		int pesquisa(const Tipo &el);
		// Métodos auxiliares
		void volta_cursor();
		bool tem_proximo();
		Tipo proximo();
        void imprime();

		private:
		Tipo *vetor;
		int ult, pc, nelem, size;
	};

	// nova lista sequencial
	// Construtor
	template <typename Tipo>
	ListaSeq<Tipo>::ListaSeq(int size) 
	{
		this->size = size;
		vetor = new Tipo[size];
		pc = ult = -1;
		nelem = 0;	
	}

	template <typename Tipo>
	ListaSeq<Tipo>::~ListaSeq()
	{
		delete [] vetor;
	}

	// inserção no final da lista
	template <typename Tipo>
	void ListaSeq<Tipo>::insere(const Tipo &el) throw (logic_error)
	{
		// cout << "tamanho lista " << size << endl;
		if (nelem==size) 
			throw logic_error("Lista cheia");
		ult++;
		vetor[ult] = el;
		nelem ++;	
	}

	// inserção na posição pos
	template <typename Tipo>
	void ListaSeq<Tipo>::insere_pos( const Tipo &el, int pos) throw (logic_error)
	{
		if (nelem==size) 
			throw logic_error("Lista cheia");

		if ((pos<0) || (pos>ult))
			throw logic_error("Posição inválida");

		for (int i=ult; i>= pos; i--)
			vetor[i+1] = vetor[i];

		ult++;
		vetor[pos] = el;
		nelem++;
	}

	// remoção na posição pos
	template <typename Tipo>
	void ListaSeq<Tipo>::remove_pos(int pos) throw (logic_error)
	{
		if (nelem==0) 
			throw logic_error("Lista vazia");

		if ((pos<0) || (pos>ult))
			throw logic_error("Posição inválida");

		for (int i=pos; i<ult; i++)
			vetor[i] = vetor[i+1];
		ult--;
		nelem--;
	}

	template <typename Tipo>
	Tipo ListaSeq<Tipo>::elemento(int pos) throw (logic_error){
		if ((pos<0) || (pos>ult))
			throw logic_error("Posição inválida");
		return vetor[pos];
	}

	//pesquisa
	template <typename Tipo>
	int ListaSeq<Tipo>::pesquisa(const Tipo &el)
	{
        int i;
		for (i=0; i<=ult; i++)
			if (vetor[i] == el)
				break;
		if(i == ult)
		    return (-1);
		else
		    return i;
	}

	template <typename Tipo>
	void ListaSeq<Tipo>::remove(const Tipo &el) throw (logic_error)
	{
        int p;
		if (nelem==0) 
			throw logic_error("Lista vazia");

		for (p=0; p<=ult; p++)
			if (vetor[p] == el)
				break;
		if (p > ult) 
			throw logic_error("Não está na lista");

		for (int i=p; i < ult; i++)
			vetor[i] = vetor[i+1];
		ult--;
		nelem--;
	}

	template <typename Tipo>
	void ListaSeq<Tipo>::volta_cursor()
	{
		pc = -1;
	}

	template <typename Tipo>
	bool ListaSeq<Tipo>::tem_proximo()
	{
		return(pc != ult);	
	}

	template <typename Tipo>
	Tipo ListaSeq<Tipo>::proximo()
	{
		if (pc == ult) 
			throw logic_error("Não há próximo");
		pc++;
		return(vetor[pc]);
	}

    template <typename Tipo>
	void ListaSeq<Tipo>::imprime()
	{
		while(tem_proximo()){
            cout << proximo() << endl;
        }
        volta_cursor();
	}
}
#endif
