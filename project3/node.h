#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
    string word;
    string language;
    float acc;

    node(std::string w, std::string lang, float total, float correct){
        this->word = w;
        this->language = lang;
        this->acc = (correct / total);
    }
};

int partition(std::vector<node>& array, int low, int high);
void quickSort(std::vector<node>& array, int low, int high);
void shellSort(vector<node>& array);

void Summary(const std::vector<node>& array);
void SummaryShell(const vector<node>& array);
void table(const std::vector<node>& array, int numberToDisplay, bool ascending);
