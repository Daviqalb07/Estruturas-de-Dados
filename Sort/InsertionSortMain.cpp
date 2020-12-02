#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;

int main(void){
    vector<int> array;
    int n;

    cout << "Digite quantos elementos o vetor irá receber: ";
    cin >> n;

    cout << "Agora digite os elementos:" << endl;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> temp;

        array.push_back(temp);
    }
    cout << endl;
    insertionSort(array);

    cout << "Vetor ordenado com Insertion Sort:" << endl;
    for(int i = 0 ; i < array.size() ; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}