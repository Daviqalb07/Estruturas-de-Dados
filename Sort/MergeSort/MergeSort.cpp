#include <iostream>
#include <math.h>
#include "../sort.h"
using namespace std;
//g++ main.cpp MergeSort.cpp -o main
void merge(int *v, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1], right[n2];

    for(int i = 0 ; i < n1 ; i++){
        left[i] = v[p+i];
    }

    for(int i = 0 ; i < n2 ; i++){
        right[i] = v[q+1+i];
    }

    int x = 0, y = 0;
    int j = p;
    while(x < n1 && y < n2){
        if(left[x] < right[y]){
            v[j] = left[x];
            x++;
        }
        else{
            v[j] = right[y];
            y++;
        }
        j++;
    }

    while(x < n1){
        v[j] = left[x];
        j++;
        x++;
    }

    while(y < n2){
        v[j] = right[y];
        j++;
        y++;
    }
}

void mergeSort(int *v, int p, int r){
    if(p < r){
        int q = (p+r) / 2;

        mergeSort(v, p, q);
        mergeSort(v, q + 1, r);
        merge(v, p, q, r);
    }
}
