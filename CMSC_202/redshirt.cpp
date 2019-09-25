/**********************************************
** File:     redshirt.cpp
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the member function
**   implementations for the redshirt class.
**********************************************/

#include <iostream>
#include <sstream>
using namespace std ;

#include "redshirt.h"

// RedShirt()
// the default constructor for the RedShirt class
RedShirt::RedShirt() {
   // empty constructor body
}

// biteMe()
// the RedShirt dies when bitten
void RedShirt::biteMe(Character *ptr) {
    m_isDead = true;
    delete ptr;
}

// hitMe()
// nothing happens when a redshirt is hit
void RedShirt::hitMe() {
  return;
}

// cureMe()
// they die too quick to be cured
void RedShirt::cureMe() {
  return;
}

// morph()
// cannot morph because they die
Character *RedShirt::morph() {
   return NULL ;
}

// identify()
// prints the type and number of the object
string RedShirt::identify() {
   ostringstream oss ;
   oss << "RedShirt #" << getId() ;
   return oss.str() ;
}

// encounter()
// RedShirts hit characters they encounter
void RedShirt::encounter(Character *ptr) {

  cout << identify() << " hits " << ptr->identify() << endl;
  ptr->hitMe();
}

// migrates()
// redshirts do not migrates, so it always returns false
bool RedShirt::migrates() {
  return false;
}

// isDead()
// returns m_isDead
bool RedShirt::isDead() {
  return m_isDead;
}
