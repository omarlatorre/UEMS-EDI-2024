// Implementacao em C++ da
// tentativa quadratica 
// com enderecamento aberto
#include <bits/stdc++.h>
using namespace std;

// Funcao para imprimir o vetor arr 
void printArray(int arr[], int n)
{
	// Percorrendo e imprimindo o vetor arr 
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

// Funcao que implementa a 
// tentativa quadratica 
void hashing(int table[], int tsize, int arr[], int N)
{
	// Percorrendo o vetor arr
	for (int i = 0; i < N; i++) {
		// Computing the hash value
		int hv = arr[i] % tsize;

		// Insirindo na tabela num slot vazio sem collisao
		if (table[hv] == -1){
		    cout << "Base i = " << hv << " chave = " << arr[i] << endl;
			table[hv] = arr[i];
		}
		else {
			// Tem-se uma collisao
			// iterando ao longo do vetor
			// com os possiveis valores quadraticos 
			for (int j = 1; j < tsize; j++) {
				// Calculando o valor hash
				int t = (hv + j * j) % tsize;
				if (table[t] == -1) {
					// Saindo do laço depois de
					// inserir um valor 
					// na tabela 
					table[t] = arr[i];
					cout << " k = "<< j << " i = " << t << " chave = " << arr[i] << endl;
					break;
				}
			}
		}
	}
	printArray(table, N);
}

// Aplicacao do codigo
int main()
{
	int arr[] = { 50, 700, 76, 85, 92, 73, 101 };
	int N = 7;

	// Tamanho da tabela Hash
	int L = 7;
	int hash_table[7];

	// Inicializando a tabela Hash
	for (int i = 0; i < L; i++) {
		hash_table[i] = -1;
	}

	// Chamando a funcao Hash
	hashing(hash_table, L, arr, N);
	return 0;
}

