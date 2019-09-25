/*****************************************
** File:    Pinball.cpp
** Project: CMSC 341 Project 5, Fall 2016
** Author:  Laura Roth
** Date:    12/6/16
** Section: 03
** E-mail:  rolaur1@umbc.edu 
**
**   This file contains the implementations for the 
**   Pinball hash class. The file was provided
**   and modified.
**
***********************************************/

#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdexcept>

using namespace std;

#include "Pinball.h"

// Pinball()
// default constructor
Pinball::Pinball(int n) {
    
  int i = 0;             // iterator
  
  // makes a new, dynamically allocated array
  H = new char*[n];
  
  // clears every part of the array and sets it equal to null
  while (i < n) {
    H[i] = NULL;
    i++;
  }
    
  m_size = 0;
  m_capacity = n;
  m_degree = 9;
  m_ejectLimit = 8;
  m_numEject = 0;
  m_primSlots = 0;
  m_maxHits = 1;
  m_totalEject = 0;
  m_maxEject = 0;

}

// ~Pinball()
// destructor
Pinball::~Pinball() {
    
  int i = 0;                // iterator
    
  while (i < m_capacity) {
    free(H[i]);
    i++;
  }
    
  delete[] H;
}

// insert(const char* str)
// inserts a given string
void Pinball::insert(const char* str) {

  unsigned int index = 0;             // saves the index
  unsigned int i = 0;                 // iterator
  unsigned int auxIndex = 0;          // saves the index of the auxillary slot
  unsigned int randSeed = rand();     // saves a random number
  char* ejectedStr;                   // saves the string to be ejected
  unsigned int toEject = 0;           // saves the index of the object to be ejected


  // checks that the string is not empty
  if (str == NULL) {
    return;
  }
 
  // if the ejection limit is reached, throw an exception
  if(m_numEject == m_ejectLimit) {
    throw PinballHashFull("Ejection limit was reached");
  }

  // if it's full, throw an exception
  else if (m_size == m_capacity) {
    throw PinballHashFull("Hash Table is full.");
  }

  // calculate the index
  index = hashCode(str) % m_capacity;

  // if the slot is empty
  if (H[index] == NULL) {
    H[index] = strdup(str);
    m_size++;
    m_numEject = 0;
    m_primSlots++;
    return;
  }
  
  // if the string is aldready present at that index, do nothing
  if (strcmp(H[index], str) == 0) {
    return;
  }
  // if it is full, check aux slots
  srand(index);
  
  // check each slot
  while (i < 9) {
    auxIndex = rand() % m_capacity;
    
    // if the slot is empty, insert it
    if (H[auxIndex] == NULL) {
      H[auxIndex] = strdup(str);
      m_size++;
      m_numEject = 0;
      return;
    }

    // if the string is already inserted, do nothing
    if (strcmp(H[auxIndex], str) == 0) {
      return;
    }
    i++;
  }
  
  // all aux slots full, bump one
  srand(randSeed);
  toEject = rand() % 8;
  
  i = 0;
  
  srand(index);
  
  while (i < toEject) {
    auxIndex = rand() % m_capacity;
    i++;
  }
  
  // replace and eject the string and then reinsert it
  ejectedStr = strdup(H[auxIndex]);
  H[auxIndex] = strdup(str);
  m_numEject++;
  m_size++;
  m_maxHits = m_degree + 1;
  m_totalEject++;
  if (m_numEject > m_maxEject) {
    m_maxEject = m_numEject;
  }
  insert(ejectedStr);
    
}

// find(const char* str)
// looks for the string in the hash table
int Pinball::find(const char* str) {
    
  unsigned int index = 0;                   // saves the index
  unsigned int savedIndex = 0;              // saves index of aux slots
  unsigned int i = 0;                       // iterator
  
  // if it's empty, it's not in the hash table
  if (m_size == 0) {
    return -1;
  }
  
  // hash for the index
  index = hashCode(str) % m_capacity;
  
  // if it is found at the primary slot, return the index
  if (H[index] != NULL && strcmp(str, H[index]) == 0) {
    
    return index;
  }
  
  // check the aux slots
  else {
    srand(index);
    
    while (i < 9) {
      
      savedIndex = rand() % m_capacity;
      
      if (H[savedIndex] != NULL && strcmp(str, H[savedIndex]) == 0) {
	
	return savedIndex;
      }
      i++;
    }
    // otherwise, it's not in the table
    return -1;
  }
}

// at(int index)
// returns a pointer to the object
const char* Pinball::at(int index) {

  // checks if it is a valid index
  if (index < 0 || index > m_capacity) {
        
    throw out_of_range("Out of range");
    
  }
  
  // returns the index
  else {
    return H[index];
  }
}

// remove(const char* str)
// removes the given string if it is in the hash
char* Pinball::remove(const char* str) {

  int toRemove = find(str);         // saves the index of what will be removed
    
  char* removedString = NULL;       // saves the removed string
    
  if (toRemove == -1) {
    return removedString;
  }

  else {
    removedString = strdup(H[toRemove]);
    free(H[toRemove]);
    return removedString;
  }
}

// printStats()
// prints a few stats about the heap
void Pinball::printStats() {
  m_avg = static_cast<float>(m_size) / static_cast<float>(m_primSlots);

  cout << "Hash Statistics Report:" << endl;
  cout << "Randomness Level: A little bit random" << endl;
  cout << "Capacity = " << m_capacity << endl;
  cout << "Size = " << m_size << endl;
  cout << "Degree = " << m_degree << endl;
  cout << "Ejection Limit = " << m_ejectLimit << endl;
  cout << "Number of Primary Slots = " << m_primSlots << endl;
  cout << "Average Hits to Primary Slots = "<< m_avg << endl;
  cout << "Maximum Hits to Primary Slots = "<< m_maxHits << endl;
  cout << "Total Number of Ejections = " << m_totalEject << endl;
  cout << "Maximum Number of Ejections in a Single Insertion = "<< m_maxEject << endl;
    
}
