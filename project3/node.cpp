#include "node.h"



// Quick Sort code from Sort Module
int partition(vector<node>& array, int low, int high){
    float pivot = array[low].acc;
    int up = low, down = high;
    while (up < down){
        for(int i = up; i < high; i++){
            if(array[up].acc > pivot){
                break;
            }
            up++;
        }
        for (int j = down; j > low; j--){
            if(array[down].acc < pivot){
                break;
            }
            down--;
        }
        if(up < down){
            swap(array[up], array[down]);
        }
    }
    swap(array[low], array[down]);
    return down;
}
void quickSort(vector<node>& array, int low, int high){
    if (low < high){
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}