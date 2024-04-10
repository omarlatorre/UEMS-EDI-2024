/*
 * A classe Lista Duplamente Encadeada 
 * nome do arquivo ListaDEnc.h
 * O Autor Omar Latorre Vilca
 * Versão 1
 */

#ifndef _ListaDEnc_H
#define _ListaDEnc_H
#include <iostream>
#include <stdexcept>

using std::logic_error;
using namespace std;

namespace ED {
    template <typename Tipo>
    class ListaDEnc {
	public:
	  ListaDEnc();
// 	  ~ListaDEnc();
	
	// Métodos principais
	void insere(const Tipo &el) throw (logic_error);
	void insere_pos(const Tipo &el, int pos) throw (logic_error);
	void remove(const Tipo &el) throw (logic_error);
	void remove_pos(int pos) throw (logic_error);
	Tipo elemento(int pos) throw (logic_error);
	int pesquisa(const Tipo &el); 
	
	// Métodos auxiliares
	void volta_cursor();
	int tem_proximo();
	Tipo proximo() throw (logic_error);
	void imprime();
	
	private:
	  struct Celula {
	    Tipo el;
	    Celula *ant, *prox;
	  };
	  
	  Celula *ini, *pc;
	  unsigned int nelem;
    };
    
    // Construtor
    template <typename Tipo>
    ListaDEnc<Tipo>::ListaDEnc() {
      ini = new Celula;
      ini->ant = ini->prox = pc = ini;
      nelem = 0;
    } /* ListaDEnc */
    
    // Métodos principais
    template <typename Tipo>
    void ListaDEnc<Tipo> :: insere(const Tipo &el) throw (logic_error){
      Celula *nova = new Celula;
      if (nova == NULL)
	    throw logic_error("Memoria insuficiente \n");
      
      nova->el = el;
      nova->prox = ini;
      nova->ant = ini->ant;
      
      ini->ant->prox = nova;
      ini->ant = nova;
      nelem++;
    }/* insere */
    
    template <typename Tipo>
    void ListaDEnc<Tipo> :: insere_pos(const Tipo &el, int pos) throw (logic_error){
      if((pos < 0) || (pos >= nelem))
        throw logic_error("posição fora dos limites \n");
      Celula *aux, *nova;
      aux = ini->prox;
      for (int i=0; i < pos; i++)
	       aux=aux->prox;
      
      nova = new Celula;
      if (nova == NULL)
	    throw logic_error("Memoria insuficiente \n");
      nova->el = el;
      nova->prox = aux;
      nova->ant = aux->ant;
      
      aux->ant->prox = nova;
      aux->ant = nova;
      nelem++;
    }/* insere_pos */
    
    template <typename Tipo>
    void ListaDEnc<Tipo> :: remove_pos(int pos) throw (logic_error)
    {
        if(ini->prox == ini)
        throw logic_error("Lista vazia \n");
      // verificar se a posição inserida encontra-se no limites da lista
      if(pos <= nelem || pos >= 0)
      {
      	Celula *aux;
      	aux = ini->prox;
      	for (int i=1; i<pos; i++)
      	  aux=aux->prox;
	
      	aux->ant->prox = aux->prox;
      	aux->prox->ant = aux->ant;
      	delete aux;
      	nelem--;
      }
      else throw logic_error("posição fora dos limites \n");
    }/* remove_pos */
    
    template <typename Tipo>
    Tipo ListaDEnc<Tipo> :: elemento(int pos)throw (logic_error)
    {
      // verificar se a posição inserida encontra-se no limites da lista
      if(pos <= nelem || pos >= 0)
      {
      	Celula *aux;
      	aux = ini->prox;
      	for (int i=1; i<pos; i++)
      	  aux=aux->prox;
      	return(aux->el);
      }
      else throw logic_error("posição fora dos limites \n");
    }/* elemento */
    
    template <typename Tipo>
    int ListaDEnc<Tipo> :: pesquisa(const Tipo &el)
    {
      Celula *aux;
      aux = ini->prox;
      int pos = 1;
      while ((aux!=ini)&&(aux->el != el)) 
      {
      	aux = aux->prox;
      	pos++;
      }
      if (aux == ini) return(-1);
      return(pos);
    }/* pesquisa */
    
    /* Metodos auxiliares */
    template <typename Tipo>
    void ListaDEnc<Tipo> :: volta_cursor()
    {
      pc = ini;
    }/* volta_cursor */
    
    template <typename Tipo>
    int ListaDEnc<Tipo> :: tem_proximo()
    {
      return(pc->prox != ini);
    }/* tem_proximo */
    
    template <typename Tipo>
    Tipo ListaDEnc<Tipo> :: proximo() throw (logic_error)
    {
      if (pc->prox == ini) throw logic_error("Não há próximo \n");
      pc = pc->prox;
      return(pc->el);
    }/* proximo */
    
    template <typename Tipo>
    void ListaDEnc<Tipo> :: imprime()
    {
      while (pc->prox != ini){
	       cout << proximo() <<" ";
      }
      cout << endl;
      volta_cursor();
    }/* imprime */
    
} /* namespace ED */
#endif
 