/**********************************************
** File:     buffy.cpp
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the member function
**   implementations for the buffy class.
**********************************************/

#include <iostream>
#include <sstream>
using namespace std ;

#include "buffy.h"

// Buffy()
// the default constructor for the buffy class
Buffy::Buffy() {
  //empty constructor body
}

// biteMe()
// Buffy-type characters cannot be bit, so it just prints one line
void Buffy::biteMe(Character *ptr) {
   
   cout << "Missed me!\n";
   delete ptr;
}

// hitMe()
// Buffy-type characters cannot be hit, so it just prints one line
void Buffy::hitMe() {
   
   cout << "Missed me!\n" ;
}

// cureMe()
// Buffy-type characters do not need to be cured, so it just prints one line
void Buffy::cureMe() {
  
   cout << "No need, Doc!\n" ;
}

// morph()
// always returns NULL because buffy-type characters cannot morph
Character *Buffy::morph() {

   return NULL ;
}

// identify()
// prints the identity of the object
string Buffy::identify() {
   ostringstream oss ;
   oss << "Buffy #" << getId() ;
   return oss.str() ;
}

// encounter()
// when a buffy object interacts with another object, that object is hit
void Buffy::encounter(Character *ptr) {
  cout << identify() << " hits " << ptr->identify() << endl;
  ptr->hitMe();
}

// migrates()
// Buffy-type characters migrate so it returns true
bool Buffy::migrates() {
  return true;
}

// isDead
// is always false
bool Buffy::isDead() {
  return false;
}
