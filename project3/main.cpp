#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include "node.h"
using namespace std;




int main() {

    vector<node> en; //english
    vector<node> sp; //spanish
    vector<node> it; //italian
    vector<node> pt; //portuguese
    vector<node> ge; //german
    vector<node> fr; //french


    string filename = "data.csv";
    ifstream file(filename.c_str());

    //variables to hold different parts
    string first;     //first value
    string timestamp; //timestamp
    string id;        //ID number
    string category;  //category
    string learning_lang; //learning language
    string native_lang; //native language
    string hash;
    string lemma;     //word
    string nolemma;   //excess in data
    string seen;      //amount seen
    string correct;   //amount correct
    string last1;
    string last2;

    string line;
    //variables method from projects 1 breakdown video
    while (getline(file, line)) {
        //reset variables for each line
        first = timestamp = id = category = "";
        learning_lang = native_lang = hash = lemma = nolemma = "";
        seen = correct = last1 = last2 = "";
        istringstream ss(line);

        //section each part of the line
        getline(ss, first, ',');
        getline(ss, timestamp, ',');
        getline(ss, id, ',');
        getline(ss, category, ',');
        getline(ss, learning_lang, ',');
        getline(ss, native_lang, ',');
        getline(ss, hash, ',');
        getline(ss, lemma, '<');
        getline(ss, nolemma, ',');
        getline(ss, seen, ',');
        getline(ss, correct, ',');
        getline(ss, last1, ',');
        getline(ss, last2, ',');

        // Insert language to each vector
        if(native_lang == "en" && lemma != ""){
            en.push_back(node(lemma, learning_lang, stoi(seen), stoi(correct)));
        }
        else if(native_lang == "es" && lemma != ""){
            sp.push_back(node(lemma, learning_lang, stoi(seen), stoi(correct)));
        }
        else if(native_lang == "it" && lemma != ""){
            it.push_back(node(lemma, learning_lang, stoi(seen), stoi(correct)));
        }
        else if(native_lang == "pt" && lemma != ""){
            pt.push_back(node(lemma, learning_lang, stoi(seen), stoi(correct)));
        }
        //german and french have only learning language not native language
    }

    file.close();

    bool run = true;
    bool quicksort = true;
    string response;

    cout << "Welcome to the Duolingo Data Sorter" << endl << "----------------------------------" << endl;
    while(run == true) {
        cout << endl << "What would you like to do?" << endl;
        cout << "1. View Words based on Native Languages" << endl << "2. Change Sort" << endl << "3. View languages" << endl << "4. Compare Sorts" << endl << "5. Exit" << endl;
        if(quicksort){
            cout << "(current sort: quick sort)" << endl;
        }
        else {
            cout << "(current sort: shell sort)" << endl;
        }
        cin >> response;

        // 1. View Words based on Native Languages
        if(response == "1"){
            cout << "What language would you like to view? (insert number)" << endl;
            cout << "1. English" << endl << "2. Spanish" << endl << "3. Italian" << endl << "4. Portuguese" << endl;
            cin >> response;

            // ENGLISH
            if(response == "1"){
                if(quicksort){
                    cout << "Quick Sort English" << endl;
                    // timer to calculate how long the algo takes to run. Credit: https://www.geeksforgeeks.org/chrono-in-c/
                    auto start = chrono::high_resolution_clock::now();
                    quickSort(en, 0, en.size() - 1);
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> duration = end - start;
                    cout << "Time to Quick Sort English is: " << fixed << setprecision(5) << duration.count() << " second" << endl;

                    Summary(en);
                }
                else {
                    cout << "Shell Sort English" << endl;
                    auto start = chrono::high_resolution_clock::now();
                    shellSort(en);
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> duration = end - start;
                    cout << "Time to Shell Sort English is: " << fixed << setprecision(5) << duration.count() << " second" << endl;

                    Summary(en);

                }
                cout << "Would you like to reveal ascending or descending? ('a' or 'd')" << endl;
                cin >> response;
                if(response == "a"){
                    //print from index[0] to n
                    table(en, 8, true);
                }
                else if(response == "d"){
                    //print from index[size] to (size-n)
                    table(en, 8, false);

                }
            }
                // SPANISH
            else if(response == "2"){
                if(quicksort){
                    cout << "Quick Sort Spanish" << endl;
                    auto start = chrono::high_resolution_clock::now();
                    quickSort(sp, 0, sp.size() - 1);
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> duration = end - start;
                    cout << "Time to Quick Sort Spanish is: " << fixed << setprecision(5) << duration.count() << " second" << endl;

                    Summary(sp);

                }
                else{
                    cout << "Shell Sort Spanish" << endl;
                    auto start = chrono::high_resolution_clock::now();
                    shellSort(sp);
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> duration = end - start;
                    cout << "Time to Shell Sort Spanish is: " << fixed << setprecision(5) << duration.count() << " second" << endl;

                    Summary(sp);
                }
                cout << "Would you like to reveal ascending or descending? ('a' or 'd')" << endl;
                cin >> response;
                if(response == "a"){
                    //print from index[0] to n
                    table(sp, 8, true);

                }
                else if(response == "d"){
                    //print from index[size] to (size-n)
                    table(en, 8, false);

                }
            }
            // ITALIAN
            else if(response == "3"){
                if(quicksort){
                    cout << "Quick Sort Italian" << endl;
                    auto start = chrono::high_resolution_clock::now();
                    quickSort(it, 0, it.size() - 1);
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> duration = end - start;
                    cout << "Time to Quick Sort Italian is: " << fixed << setprecision(5) << duration.count() << " second" << endl;

                    Summary(it);

                }
                else{
                    cout << "Shell Sort Italian" << endl;
                    auto start = chrono::high_resolution_clock::now();
                    shellSort(it);
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> duration = end - start;
                    cout << "Time to Shell Sort Italian is: " << fixed << setprecision(5) << duration.count() << " second" << endl;

                    Summary(it);
                }
                cout << "Would you like to reveal ascending or descending? ('a' or 'd')" << endl;
                cin >> response;
                if(response == "a"){
                    //print from index[0] to n
                    table(it, 8, true);

                }
                else if(response == "d"){
                    //print from index[size] to (size-n)
                    table(it, 8, false);
                }
            }
            // PORTUGUESE
            else if(response == "4"){
                if(quicksort){
                    cout << "Quick Sort Portuguese" << endl;
                    auto start = chrono::high_resolution_clock::now();
                    quickSort(pt, 0, pt.size() - 1);
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> duration = end - start;
                    cout << "Time to Quick Sort Portuguese is: " << fixed << setprecision(5) << duration.count() << " second" << endl;
                    Summary(pt);

                }
                else{
                    cout << "Shell Sort Portuguese" << endl;
                    auto start = chrono::high_resolution_clock::now();
                    shellSort(pt);
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> duration = end - start;
                    cout << "Time to Shell Sort Portuguese is: " << fixed << setprecision(5) << duration.count() << " second" << endl;

                    Summary(pt);
                }
                cout << "Would you like to reveal ascending or descending? ('a' or 'd')" << endl;
                cin >> response;
                if(response == "a"){
                    //print from index[0] to n
                    table(pt, 8, true);

                }
                else if(response == "d"){
                    //print from index[size] to (size-n)
                    table(pt, 8, false);

                }
            }
        }
            // 2. Change Sort
        else if(response == "2"){
            quicksort = !quicksort;
        }
            // 3. View languages
        else if(response == "3"){
            cout << "en: English"<< endl << "sp: Spanish"<< endl << "it: Italian"<< endl << "pt: Portuguese"<< endl << "de: German" << endl << "fr: French" << endl << "(German and French are only learning languages)" << endl;
        }

            // Compare Algo
        else if (response == "4"){
            vector<vector<node>> DuolingoData;
            DuolingoData.push_back(en);
            DuolingoData.push_back(sp);
            DuolingoData.push_back(it);
            DuolingoData.push_back(pt);

            cout << "Comparing Quick Sort and Shell Sort" << endl;
            compareAlgo(DuolingoData);
        }
        // Exit
        else if(response == "5"){
            cout << "Goodbye !";
            run = false;
        }
    }

    return 0;
}