#include <iostream>
#include "../sort.h"
using namespace std;

int main(void){
    int size;
    cout << "Digite a quantidade de elementos a serem ordenados: ";

    cin >> size;
    int vetor[size];

    cout << "Agora digite cada um dos elementos:" << endl;
    for(int i = 0 ; i < size ; i++){
        cin >> vetor[i];
    }

    mergeSort(vetor, 0, size);

    cout << "Elementos ordenados pelo Merge Sort:" << endl;
    for(int i = 0; i < size ; i++){
        cout << vetor[i] << " ";
    }
    cout << endl << endl;

    cout << "Complexidade do algoritmo: O(n . log n)" << endl;

    return 0;
}