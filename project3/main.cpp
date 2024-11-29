#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>
#include <chrono>
#include "node.h"
using namespace std;




int main() {
    //set<string> l; //checking all languages

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

/*
    //output for testing
    cout << "First: " << first << endl;
    cout << "Timestamp: " << timestamp << endl;
    cout << "ID: " << id << endl;
    cout << "Category: " << category << endl;
    cout << "learning Lang: " << learning_lang << endl;
    cout << "native Lang: " << native_lang << endl;
    cout << "Hash: " << hash << endl;
    cout << "Lemma: " << lemma << endl;
    cout << "Lemma not used: " << nolemma << endl;
    cout << "seen: " << seen << endl;
    cout << "correct: " << correct << endl;
    cout << "Last1: " << last1 << endl;
    cout << "Last2: " << last2 << endl;
    cout << "---" << endl;
*/
        //l.insert(native_lang); //checking all native languages
        //l.insert(learning_lang);
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
     //testing english vector
     cout << "sorting" << en.size() << endl;
    quickSort(en, 0, en.size() - 1);
    cout << "sorting done" << endl;
    for(int i = 0; i < en.size(); i++){
        cout << fixed << setprecision(2) << "Word: " << en[i].word << "   " << "Language: " << en[i].language << "  " << "accuracy: " << en[i].acc << endl;

    }




    //sort algorithm




    //print results










/*
    bool run = true;
    bool quicksort = true;
    string response;


    cout << "Welcome to the Duolingo Data Sorter" << endl << "----------------------------------" << endl;
    while(run == true) {
        cout << endl << "What would you like to do?" << endl;
        cout << "1. View Words based on Native Languages" << endl << "2. Change Sort" << endl << "3. View languages" << endl << "4. Exit" <<endl;
        if(quicksort){
            cout << "(current sort: quick sort)" << endl;
        }
        else {
            cout << "(current sort: shell sort)" << endl;
        }
        cin >> response;

        if(response == "1"){
            cout << "What language would you like to view? (insert number)" << endl;
            cout << "1. English" << endl << "2. Spanish" << endl << "3. Italian" << endl << "4. Portuguese" << endl;
            cin >> response;
            if(response == "1"){
                if(quicksort){
                    cout << "quick sort english" << endl;
                }
                else {
                    cout << "shell sort english" << endl;
                }
                cout << "Would you like to reveal ascending or descending? ('a' or 'd')" << endl;
                cin >> response;
                if(response == "a"){
                    //print from index[0] to n
                }
                else if(response == "d"){
                    //print from index[size] to (size-n)
                }
            }
            else if(response == "2"){
                if(quicksort){
                    cout << "quick sort spanish" << endl;
                }
                else{
                    cout << "shell sort spanish" << endl;
                }
                cout << "Would you like to reveal ascending or descending? ('a' or 'd')" << endl;
                cin >> response;
                if(response == "a"){
                    //print from index[0] to n
                }
                else if(response == "d"){
                    //print from index[size] to (size-n)
                }
            }
            else if(response == "3"){
                if(quicksort){
                    cout << "quick sort italian" << endl;
                }
                else{
                    cout << "shell sort itlaian" << endl;
                }
                cout << "Would you like to reveal ascending or descending? ('a' or 'd')" << endl;
                cin >> response;
                if(response == "a"){
                    //print from index[0] to n
                }
                else if(response == "d"){
                    //print from index[size] to (size-n)
                }
            }
            else if(response == "4"){
                if(quicksort){
                    cout << "quick sort portuguese" << endl;
                }
                else{
                    cout << "shell sort portuguese" << endl;
                }
                cout << "Would you like to reveal ascending or descending? ('a' or 'd')" << endl;
                cin >> response;
                if(response == "a"){
                    //print from index[0] to n
                }
                else if(response == "d"){
                    //print from index[size] to (size-n)
                }
            }
        }
        else if(response == "2"){
            quicksort = !quicksort;
        }
        else if(response == "3"){
            cout << "en: English"<< endl << "sp: Spanish"<< endl << "it: Italian"<< endl << "pt: Portuguese"<< endl << "de: German" << endl << "fr: French" << endl << "(German and French are only learning languages)" << endl;
        }
        else if(response == "4"){
            cout << "Goodbye !";
            run = false;
        }
    }
*/

    return 0;
}