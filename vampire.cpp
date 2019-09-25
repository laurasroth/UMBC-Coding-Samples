/**********************************************
** File:     vampire.cpp
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the member function
**   implementations for the vampire class.
**********************************************/

#include <iostream>
#include <sstream>
using namespace std ;

#include "vampire.h"

// Vampire()
// the default constructor for the vampire class
Vampire::Vampire() {
  m_numHits = 0;
}

// biteMe()
// vampires cannot be bitten, so nothing happens
void Vampire::biteMe(Character *ptr) {
   delete ptr;
}

// hitMe()
// increments the vampire's hit counter; if it is higher than 3, it dies
void Vampire::hitMe() {
  m_numHits++;
  
  // marks the vampire as dead if it has been hit three times
  if (m_numHits >= 3) {
    m_isDead = true;
  }
}

// cureMe()
// vampires cannot be cured, so nothing happens
void Vampire::cureMe() {
  return;
}

// morph()
// vampires cannot morph, so it returns NULL
Character *Vampire::morph() {  
   return NULL ;
}

// identify()
// prints the type and number of the object
string Vampire::identify() {
   ostringstream oss ;
   oss << "Vampire #" << getId() ;
   return oss.str() ;
}

// encounter()
// the vampire bites the other character
void Vampire::encounter(Character *ptr) {
   cout << identify() << " bites " << ptr->identify() << endl;
   ptr->biteMe(new Vampire());
}

// migrates()
// vampires migrate, so it returns true
bool Vampire::migrates() {
  return true;
}

// isDead()
// returns m_isDead
bool Vampire::isDead() {
  return m_isDead;
}
