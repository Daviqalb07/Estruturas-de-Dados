#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;

void insertionSort(vector<int> &array){
    const int size = array.size();

    for(int i = 1 ; i < size ; i++){
        int x = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > x){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = x;
    }
}
