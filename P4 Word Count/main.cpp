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

#include <vector>
#include <algorithm> 

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    // Read command line arguments

    enum {
        total, unique
    } mode = total;
    for (int c; (c = getopt(argc, argv, "tu")) != -1;) {
        switch (c) {
            case 't': mode = total;
                break;
            case 'u': mode = unique;
                break;
            default: mode = total;
                break;
        }
    }
    argc -= optind;
    argv += optind;
    // End Read command line arguments


    // Define vector
    vector<string> words;
    vector<string>::iterator it;

    string word;
    int count = 0;
    int i = 0;
    while ((cin >> word)) {

        count += 1;
        // check if word already exists in the vector
        it = words.begin();

        if ((it = find(it, words.end(), word)) == words.end()) // not found
        {
            i++;
         }
        
        // Add word to vector and sort
        words.push_back(word);

        // Break out of while in testing as we dont get an EOF
        if (word == "bbb") {
            break;
        }
    }

    switch (mode) {
        case total: cout << "Total: " << count << endl;
            break;
        case unique: cout << "Unique: " << i << endl;
            break;
    }

    // sort the list
    sort(words.begin(), words.end());
#ifdef DEBUG1   
    //Print the list
    cout << "Original List" << endl;
    i = 0;
    for (it = words.begin(), i = 0; it != words.end(); it++, i++) {

        cout << "Value: " << i << " " << *it << endl;
    }
#endif
    return 0;
}

