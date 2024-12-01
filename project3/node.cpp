#include "node.h"



// Quick Sort code from Sort Module, modified to double while loops for bound checking and readability
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

// use const so we do not modify the array after sorting

void Summary(const std::vector<node>& array){
    float totalAcc = 0.00;
    for(auto &word : array){
        totalAcc += word.acc;
    }
    float meanAcc = totalAcc / array.size();
    cout << "Total learning words: " << array.size() << endl;
    cout << " Average Accuracy: " << fixed << setprecision(2) << meanAcc << endl;
}

// no change to array
void table(const std::vector<node>& array, int numberToDisplay, bool ascending){
    // Headers
    cout << endl;
    if (ascending){
        cout << numberToDisplay << " HARDEST" << " LEARNING WORDS" << endl;
    }
    else{
        cout << numberToDisplay << " EASIEST" << " LEARNING WORDS" << endl;
    }

    cout.imbue(locale(""));
    cout << left <<  setw(20) << "Word" << setw(10) << "Language" << setw(10) << "Accuracy" << endl;
    cout << string(35, '-') << endl;

    // ascending / decending ranges
    int begin = ascending ? 0 : array.size() - 1;
    int end = ascending ? numberToDisplay : array.size() - numberToDisplay - 1;
    int increment = ascending ? 1 : -1;


    for (int i = begin; i != end; i += increment){
        // Word -  Learning Language - accuracy
        cout << left
             << setw(20) << array[i].word
             << setw(10) << array[i].language
             << fixed << setprecision(2) << array[i].acc << endl;
    }

}
