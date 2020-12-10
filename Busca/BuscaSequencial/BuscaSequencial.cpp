#include <iostream>
#include "../Busca.h"
using namespace std;

int buscaSequencial(int *v, int valor, int size){
    for(int i = 0 ; i < size ; i++){
        if(v[i] == valor){
            return i;
        }
    }

    return NULO;
}
