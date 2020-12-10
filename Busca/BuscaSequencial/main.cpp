#include <iostream>
#include "../Busca.h"
using namespace std;

int main(void){
    int size;

    cout << "Indique quantos elemento o vetor possui: ";
    cin >> size;

    int vetor[size];
    cout << "Elementos: " << endl;
    for(int i = 0 ; i < size ; i++){
        cin >> vetor[i];
    }

    int procurado;

    cout << "Qual elemento deseja encontrar? ";
    cin >> procurado;

    int resultado = buscaSequencial(vetor, procurado, size);

    if(resultado == NULO){
        cout << "Nenhum elemento do vetor corresponde a esse valor!" << endl;
    }
    else{
        cout << "O elemento " << procurado << " pertence ao vetor e tem indice " << resultado << ".\n";
    }

    cout << endl << "Complexidade: O(n)" << endl;
    return 0;
}
