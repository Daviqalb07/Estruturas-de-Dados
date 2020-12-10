#include <iostream>
#include "../Busca.h"
using namespace std;

int buscaBinaria(int *v, int left, int right, int valor){
    
    while(left <= right){
        int mid = (left + right) / 2;

        if(v[mid] == valor) return mid;

        else if(v[mid] < valor){
            left = mid + 1;
        }
        else if(v[mid] > valor){
            right = mid - 1;
        }
    }

    return NULO;
}
