#include "node.h"



// Quick Sort code from Sort Module
int partition(vector<node>& array, int low, int high) {
    // pivot is the first element, 2 precision floating point comparison
    float pivot = array[low].acc;
    // up ptr finds elements that are greater than the pivot
    // down ptr finds elements that are less than the pivot
    int up = low, down = high;

    while (up < down) {
        // for up ptr is less than the last index (bounding purpose) AND up ptr is <= than pivot, move UP until otherwise
        while (up < high && array[up].acc <= pivot) { // Move up pointer
            up++;
        }
        // for down ptr that is greater than the first/low index AND is >= to the pivot, move DOWN until otherwise
        while (down > low && array[down].acc >= pivot) { // Move down pointer
            down--;
        }
        if (up < down) {
            swap(array[up], array[down]);
        }
    }
    swap(array[low], array[down]);
    return down;
}

void quickSort(vector<node>& array, int low, int high){
    // bound checking, low = array beginning, high = array ending
    if (low < high){
        // first pivot after 1st partition
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

// Shell sort from Module 8 Discussion Slides
void shellSort(vector<node>& array){
    int n = array.size();
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n ; i++){
            node temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap){
                array[j] = array[j - gap];
            }
        }
        array[j] = temp;
    }
    return 0;
}

