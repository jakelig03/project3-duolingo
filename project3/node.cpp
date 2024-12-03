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

// Shell sort from Module 8 Discussion Slides
void shellSort(vector<node>& array){
    int n = array.size();
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n ; i++){
            node temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap].acc > temp.acc; j -= gap){
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

// use const so we do not modify the array after sorting

void Summary(const vector<node>& array){
    float totalAcc = 0.00;
    for(auto &word : array){
        totalAcc += word.acc;
    }
    float meanAcc = totalAcc / array.size();

    // shellSort(array);

    float medianAcc;
    if (array.size() % 2 != 0){
        medianAcc = array[array.size() / 2].acc;
    }
    else {
        // in the case of where there is an even amount and has tp avg between two values
        medianAcc = (array[(array.size() / 2) - 1].acc + array[array.size() / 2].acc) / 2.0;
    }

    // learned
    float stdDevAcc;
    float variance = 0.0;
    for (const auto& word : array) {
        variance += (word.acc - meanAcc) * (word.acc - meanAcc);
    }
    variance /= array.size();
    stdDevAcc = sqrt(variance); // learned from https://www.w3schools.com/cpp/cpp_ref_math.asp

    cout << " Total learning words: " << array.size() << endl;
    cout << " Mean Accuracy: " << fixed << setprecision(2) << meanAcc << endl;
    cout << " Median Accuracy: " << fixed << setprecision(2) << medianAcc << endl;
    cout << " Standard Deviation Accuracy: " << fixed << setprecision(2) << stdDevAcc << endl << endl;
}

void table(const std::vector<node>& array, int numberToDisplay, bool ascending) {
    int totalEntries = array.size();
    int currentPage = 0;
    int totalPages = (totalEntries + numberToDisplay - 1) / numberToDisplay; // Total pages (ceil)
    string response;

    while (true) {

        int startIndex = currentPage * numberToDisplay; // CURRNET page of table
        int endIndex = std::min(startIndex + numberToDisplay, totalEntries); // end page


        // Header
        cout << endl;
        if (ascending) {
            cout << numberToDisplay << " HARDEST LEARNING WORDS (Page " << currentPage + 1 << " of " << totalPages << ")" << endl;
        } else {
            cout << numberToDisplay << " EASIEST LEARNING WORDS (Page " << currentPage + 1 << " of " << totalPages << ")" << endl;
        }
        cout << left << setw(10) << "Index" << setw(20) << "Word" << setw(10) << "Language" << setw(10) << "Accuracy" << endl;
        cout << string(50, '-') << endl; // -----

        // display page
        for (int i = startIndex; i < endIndex; ++i) {
            cout << left  // align left
                 << setw(10) << i + 1 // index
                 << setw(20) << array[i].word // learning WORD
                 << setw(10) << array[i].language // learning language
                 << fixed << setprecision(2) << array[i].acc << endl; // accuracy score
        }

        // After displaying sorted list, provide optinos for user to traverse through the pages using inputs, 1, 2 and 3. 
        cout << "1. Previous Page" << endl
             << "2. Next Page" << endl
             << "3. Exit" << endl;
        cout << "Input: ";
        cin >> response;

        // Handle user response
        if (response == "1") { // Previous Page
            if (currentPage > 0) {
                --currentPage;
            } else {
                cout << "You are already on the first page.\n";
            }
        } else if (response == "2") { // NextNpage
            if (currentPage < totalPages - 1) {
                ++currentPage;
            } else {
                cout << "You are already on the last page.\n";
            }
        } else if (response == "3") { // Exit
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

