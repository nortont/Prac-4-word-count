/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tim
 *
 * Created on 3 May 2018, 9:24 AM
 */
//#define DEBUG1
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <iostream>

//#include <vector>
#include <algorithm> 
#include "WordVector.h"

using namespace std;

// Define the structure

struct WordInfo {
    string text;
    int count;
};


void unique();

/*
 * 
 */
int main(int argc, char** argv) {

    // Read command line arguments

    enum {
        total, unique, items
    } mode = total;
    for (int c; (c = getopt(argc, argv, "tui")) != -1;) {
        switch (c) {
            case 't': mode = total;
                break;
            case 'u': mode = unique;
                break;
            case 'i': mode = items;
//            default: mode = total;
//                break;
        }
    }
    argc -= optind;
    argv += optind;
    // End Read command line arguments

    WordInfo uniqueWord; // structure for each unique word 

    // Define vector
    Vector<WordInfo> words;
    Vector<WordInfo>::iterator it;

    string word;
    int count = 0;
    int i = 0;
    while ((cin >> word)) {

        count += 1;
        /* 
         * check if word already exists in the vector
         * If it does, increase the count
         */

        it = words.begin();
        bool matchFound = false;
        for (it = words.begin(); it <= words.end(); ++it) { // look through all words in vector
            uniqueWord = words.get(it); // return the values from the struct in the vector

            if (uniqueWord.text == word && matchFound == false) {
                // found a match so update existing 
                uniqueWord.count += 1; // increase the count
                words.update(it, uniqueWord);
                matchFound = true;

            }

            /* 
             * Add new word to vector 
             * in alphabetical order
             */
        }
        if (matchFound == false) { // word does not exist
            it = words.begin();
            bool matchFound = false;
            Vector<WordInfo>::iterator it_end = words.end();
            // holds last as words.end increases after each add 
            Vector<WordInfo>::iterator it_pos = words.begin();
            // position of new word
            for (it = words.begin(); it < it_end; ++it) {
                // look through all words in vector
                uniqueWord = words.get(it);
                // return the values from the struct in the vector
                if (uniqueWord.text > word) {
                    //determine position in alphabetical order
                    it_pos = it; //insert word before the last larger item
                    break; //exit for loop and insert here
                } else { // insert at first position
                    it_pos = it+1; //Add to the right of last
                }
            }
            //insert the word in the correct location
            uniqueWord.text = word;
            uniqueWord.count = 1;
            words.insert(it_pos, uniqueWord);

         

        }

        // Add word to vector and sort
        ;

        // Break out of while in testing as we dont get an EOF
        if (word == "bbb") {
            break;
        }
    }

    switch (mode) {
        case total: cout << "Total: " << count << endl;

            break;

        case unique:
            for (it = words.begin(); it < words.end(); it++) {
                // uniqueWord = words.get(it);
                //cout << "Value: " << i << " " << uniqueWord.text << " " << uniqueWord.count << endl;
                i++;
            }
            cout << "Unique: " << i << endl;
            break;
        case items:
            for (it = words.begin(); it < words.end(); it++) {
                 uniqueWord = words.get(it);
                 uniqueWord = words.get(it);
                cout << uniqueWord.text << ": " << uniqueWord.count << endl;
            }
            
            break;
    }



    // sort the list
    //    sort(words.begin(), words.end());
#ifdef DEBUG1   
    //Print the list
    cout << "Original List" << endl;
    i = 0;

    for (it = words.begin(); it < words.end(); it++) {
        uniqueWord = words.get(it);
        cout << "Value: " << i << " " << uniqueWord.text << " " << uniqueWord.count << endl;
        i++;
    }
#endif
    return 0;
}

