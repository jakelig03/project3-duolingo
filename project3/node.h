#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct node {
    string word;
    string language;
    float acc;

    node(string w, string lang, float total, float correct){
        this->word = w;
        this->language = lang;
        this->acc = (correct/total);
    }
};



