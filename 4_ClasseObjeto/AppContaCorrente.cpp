#include <iostream>
using namespace std;

class ContaCorrente {
    
private: // atributos da classe
    int numero;
    double saldo;
    
public:    
    ContaCorrente(int numero, double saldo = 0) {
        cout << "Construindo Conta " << numero << endl;
        this->numero = numero;
        this->saldo = saldo;
    }
    
    ~ContaCorrente() {
        cout << "Destruindo Conta " << numero << endl;
    }
    
    bool retirada(double valor) {
        if (saldo - valor >= 0) {
            saldo -= valor;
            return true;
        }
        return false;
    }
    
    void deposito(double valor) {
        this->saldo += valor;
    }
    
    bool transferencia(ContaCorrente &outra, double valor) {
        bool ok = this->retirada(valor);
        if (ok) {
            outra.deposito(valor);
        }
        return ok;
    }
    
    void imprime() {
        cout << "Numero: " << numero << ", saldo: " << saldo << endl;
    }
};

int main()
{
    ContaCorrente c1(1000, 1200.50);
    ContaCorrente c2(2000);
    
    cout << endl << "Antes da Transferência" << endl << endl;
    
    c1.imprime();
    c2.imprime();
    
    c1.transferencia(c2, 500);
    
    cout << endl << "Depois da Transferência" << endl << endl;
    
    c1.imprime();
    c2.imprime();
    
    cout << endl;
    
    return 0;
}