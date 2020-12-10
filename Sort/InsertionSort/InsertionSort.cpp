#include <iostream>
#include <vector>
#include "../sort.h"
using namespace std;

void insertionSort(int *v, int size){

    for(int i = 1 ; i < size ; i++){
        int x = v[i];
        int j = i - 1;

        while(j >= 0 && v[j] > x){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}
