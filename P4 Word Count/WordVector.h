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
        // create a reference to the array in use
        items= new T[capacity]; 
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
 
        checkSize(); // see if there is enough room in the array
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

    T& get(iterator position) {
        return *position;
    }

    void checkSize() {
        /*
         * When trying to insert a new item into the array, make sure the array
         * is large enough.
         * When the space runs out, allocate a new block that's twice as large, 
         * copy all of the old values into the new space, then delete the 
         * old block.
         */

        // Check size of array and increase if required by copying to a new array
        if (used >= capacity-1) {

            // if size exceeds the limit of the array double it 

            capacity = capacity * 2;
//          items= new T[capacity]; 
             T* itemsTemp = new T[capacity];
            
                        //copy to a new array of double the size
            int i;
            for(i=0;i<=used;++i){
                itemsTemp[i]=items[i];
            }
            
            // dispose of old array
            delete[] items;
            
            // point to new array
                         items = itemsTemp;
                         // copy back
//             for(i=0;i<=used;++i){
//                items[i]=itemsTemp[i];
//            }
            
        }
    }

private:

    int used; // the actual number of used elements
    int capacity = 1000; //max number of elements before increasing
    T* items;
 //   T items[3]; //Original array
 //  T* itemsTemp; //Temp array to grow


};
#endif /* WORDVECTOR_H */

