#include <iostream>
#include "../Busca.h"
#include "../../Sort/sort.h"
using namespace std;

int main(void){
    int size;

    cout << "Indique a quantidade de elementos: ";
    cin >> size;

    int vetor[size];
    cout << "Elementos:" << endl;

    for(int i = 0 ; i < size ; i++){
        cin >> vetor[i];
    }

    insertionSort(vetor, size);

    int procurado;
    cout << "Elemento que deseja procurar: ";
    cin >> procurado;

    int resultado = buscaBinaria(vetor, 0, size-1, procurado);
    if(resultado == NULO){
        cout << "Nenhum elemento do vetor corresponde a esse valor!" << endl;
    }
    else{
        cout << "O elemento " << procurado << " pertence ao vetor e tem indice " << resultado << " no vetor ordenado.\n";
    }

    cout << endl << "Complexidade: O(log n)" << endl;
    return 0;
}
