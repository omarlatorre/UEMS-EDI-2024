#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <stdexcept>
using std::logic_error;

using namespace std;

template <typename Tipo>
class BST{
    public:
        class Celula{
            public:
                Tipo el;
                Celula * esq;
                Celula * dir;
                Celula(Tipo el_){
                    el = el_;
                    esq = NULL;
                    dir = NULL;
                }
        };
        Celula * T = NULL;
        int nelem;
        void insert(Tipo el){
            insertUtil(T, el);
        }
        void remove(Tipo el){
            removeUtil(T, el);
        }
        bool search(Tipo el){
            return searchUtil(T, el);
        }
        void inorder(){
            inorderUtil(T);
            cout << endl;
        }
        unsigned short altura(){
            return alturaUtil(T);
        }
        Tipo menor(){
            return menorUtil(T);
        }
        Tipo maior(){
            return maiorUtil(T);
        }
    private:
        void inorderUtil(Celula * p){
            if(p == NULL) 
                return ;
            inorderUtil(p->esq);
            cout<< p->el <<" ";
            inorderUtil(p->dir);
        }
        void insertUtil(Celula * &p, const Tipo &el){
            if(p == NULL){
                nelem++;
                p = new Celula(el);
            }
            else{
                if (p->el > el) 
                    insertUtil(p->esq, el);
                else 
                    insertUtil(p->dir, el);
            }
        }

        bool searchUtil(Celula * p, const Tipo &el){
            if (p == NULL) 
                return false; // Caso trivial para falso
            if (p->el == el) 
                return true; // Caso trivial para verdadeiro
            if (el > p->el) 
                return searchUtil(p->dir, el);
            return searchUtil(p->esq, el);
        }

        // Remoção do maior elemento da subárvore retornando o valor do
        // elemento removido
        Tipo rem_maior(Celula* &p) {
            if (p->dir == NULL) {
                Tipo el = p->el;
                Celula *x = p;
                p = p->esq;
                delete x;
                return el;
            }
            else 
                return rem_maior(p->dir);
        }

        void removeUtil(Celula* &p, const Tipo &el) throw (logic_error) {
            if (p == NULL) 
                throw logic_error("Elemento não encontrado\n");
            if (p->el > el) 
                removeUtil(p->esq, el);
            else if (p->el < el) 
                removeUtil(p->dir, el);
            else { // o elemento foi alcançado
                if (!p->esq) { 
                    Celula *x = p; 
                    p = p->dir; 
                    delete x; 
                }
                else if (!p->dir) { 
                    Celula *x = p; 
                    p = p->esq; 
                    delete x; 
                }
                else 
                    p->el = rem_maior(p->esq);
                nelem--;
            }
        }

        unsigned short alturaUtil(Celula *x) {
            if (!x) 
                return 0; // caso trivial
            // chamada recursiva para calcular a altura da subárvore esquerda
            unsigned short hesq = alturaUtil(x->esq);
            // chamada recursiva para calcular a altura da subárvore direita
            unsigned short hdir = alturaUtil(x->dir);
            // retorna a maior altura calculada + 1
            return (1 + (hesq>hdir? hesq : hdir) );
        }

        Tipo menorUtil(Celula *x){
            Celula *aux = x;
            while (aux->esq != NULL) 
                aux = aux->esq;
            return aux->el;
        }

        Tipo maiorUtil(Celula *x){
            Celula *aux = T;
            while (aux->dir != NULL) 
                aux = aux->dir;
            return aux->el;
        }
};
int main(){
    srand (time(NULL));
    int item;
    BST<int> t;
    for (int i = 0; i < 10; i++)
    {
        item = rand()%100 + 1;
        t.insert(item);
    }
    
    t.inorder();
    cout << t.search(item) << endl;
    cout << "Altura da arvore = " << t.altura() << endl;
    cout << "Maior elemento " << t.maior() << endl;
    cout << "Menor elemento " << t.menor() << endl;
    t.remove(item);
    t.inorder();

}