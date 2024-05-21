#include<iostream>
using namespace std;

template <typename Tipo>
class AVL{
    public:
        class Celula{
            public:
                Tipo el;
                unsigned char h; // Altura da subárvore
                char b; // Balanceamento da subárvore
                Celula * esq;
                Celula * dir;
                Celula(Tipo k){
                    h = 1;
                    el = k;
                    esq = NULL;
                    dir = NULL;
                }
        };
        Celula * T = NULL;
        int nelem;
        void insert(Tipo x){
            insertUtil(T, x);
        }
        void remove(Tipo x){
            removeUtil(T, x);
        } 
        Celula * search(Tipo x){
            return searchUtil(T,x);
        }
        void inorder(){
            inorderUtil(T);
            cout<<endl;
        }
    private:
        void atualiza(Celula *&x) {
            // Determina a altura da subárvore esquerda
            unsigned char hesq = x->esq? x->esq->h : 0;
            // Determina a altura da subárvore direita
            unsigned char hdir = x->dir? x->dir->h : 0;
            // Atualiza o fator da balanceamento
            x->b = hesq - hdir;
            // Atualiza a altura da subárvore
            x->h = 1 + (hesq > hdir? hesq : hdir);
        }

        void rotateRight(Celula *&x) {
            Celula *aux = x; // aux vai apontar para a antiga raiz
            x = x->esq; // A nova raiz passa a ser o filho a esquerda de X
            aux->esq = x->dir; // Fi. esq da antiga raiz passa a ser beta
            x->dir = aux; // Fi. dir da nova raiz passa a ser a antiga raiz
            atualiza(aux); // Atualiza a antiga raiz
            atualiza(x); // Atualiza a nova raiz
        }

        void rotateLeft(Celula *&x) {
            Celula *aux = x; // aux vai apontar para a antiga raiz
            x = x->dir; // A nova raiz passa a ser o filho a direita de X
            aux->dir = x->esq; // Fi. dir da antiga raiz passa a ser 
            x->esq = aux; // Fi. esq da nova raiz passa a ser a antiga raiz
            atualiza(aux); // Atualiza a antiga raiz
            atualiza(x); // Atualiza a nova raiz
        }

        void balanceia(Celula *&x) {
            if (x->b == 2) {
                if (x->esq->b == -1) 
                    rotateLeft(x->esq);
                rotateRight(x);
            }
            else if (x->b == -2) {
                if (x->dir->b == 1) 
                    rotateRight(x->dir);
                rotateLeft(x);
            }
        }

        void inorderUtil(Celula * head){
            if(head==NULL) return ;
            inorderUtil(head->esq);
            cout<<head->el<<" ";
            inorderUtil(head->dir);
        }

        void insertUtil(Celula* &x, Tipo &el) {
            if (!x) {
                x = new Celula(el);
                nelem++;
            }
            else {
                if (x->el >= el) 
                    insertUtil(x->esq, el);
                else 
                    insertUtil(x->dir, el);
                atualiza(x);
                balanceia(x);
            }
        }

        void removeUtil(Celula* &p, const Tipo &el) throw (logic_error) {
            if (!p) 
                throw logic_error("Elemento não encontrado\n");
            if (p->el > el){
                removeUtil(p->esq, el);
                atualiza(p);
                balanceia(p);
            }
            else if (p->el < el) {
                removeUtil(p->dir, el);
                atualiza(p);
                balanceia(p);
            }
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
        
        // Remoção do maior elemento da subárvore retornando o valor do
        //elemento removido
        Tipo rem_maior(Celula* &p) {
            if (!p->dir) {
                Tipo el = p->el;
                Celula *x = p;
                p = p->esq;
                delete x;
                return el;
            }
            else 
                return rem_maior(p->dir);
        }
       
        Celula * searchUtil(Celula * head, Tipo x){
            if(head == NULL) return NULL;
            Tipo k = head->el;
            if(k == x) return head;
            if(k > x) return searchUtil(head->esq, x);
            if(k < x) return searchUtil(head->dir, x);
        }
};

int main(){
    AVL<int> t;
    t.insert(17);
    t.insert(24);
    t.insert(35);
    t.insert(46);
    t.insert(57);
    t.insert(68);
    t.insert(79);
    t.inorder();
    t.remove(57);
    t.remove(68);
    t.remove(79);
    t.inorder();
}
