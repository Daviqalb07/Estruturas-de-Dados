#include <iostream>
#include "../sort.h"
using namespace std;

int main(void){
    int n;

    cout << "Digite quantos elementos o vetor irá receber: ";
    cin >> n;

    int array[n];
    cout << "Agora digite os elementos:" << endl;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> array[i];
    }
    cout << endl;
    insertionSort(array, n);

    cout << "Vetor ordenado com Insertion Sort:" << endl;
    for(int i = 0 ; i < n ; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
