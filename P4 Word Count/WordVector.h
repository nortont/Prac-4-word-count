/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WordVector.h
 * Author: Tim
 *
 * Created on 7 May 2018, 8:49 AM
 */

#ifndef WORDVECTOR_H
#define WORDVECTOR_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip> 
#include <stdio.h>
#include <string.h>

using namespace std;

template <class T>
class Vector {
public:
    typedef T* iterator;

    Vector() {
        used = 0;
    }
    //     ~Vector() { delete[]items;}

    iterator begin() {
        //address of first array member
        return items;
    }

    iterator end() {
        return items + used;
    }//last array member used

    int size() {
        return used;
    }

    iterator insert(iterator position, const T& item) {

        iterator i = items + used; //the memory of the last item
        iterator temp;

        for (i; i > position; i--) { //work from end of list moving each item
            if (i > position) {
                temp = i - 1; // copy the location before i
                *i = *temp; // shift all other items right
            }
        }

        *position = item; // add the new item

        used++;
    }

    iterator update(iterator position, const T& item) {
        // update (replace and existing entry)
        *position = item; // add the new item

    }
    
    T& get(iterator position){
     return *position ;  
    }
    

//    friend ostream& operator<<(ostream& out, Vector& d);
//    {
//        for (Vector::iterator i = d.begin(); i != d.end(); i++) {
//            out << *i << " ";
//        }
//        return out;
//    }

private:
    T items[1000];
    int used;


};
#endif /* WORDVECTOR_H */

