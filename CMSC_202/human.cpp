/**********************************************
** File:     human.cpp
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the member function
**   implementations for the human class.
**********************************************/

#include <iostream>
#include <sstream>
using namespace std ;

#include "human.h"

// Human()
// the default constructor for the human class
Human::Human() {
  m_numTurns = 0;
  m_bitBy = NULL;
}

// biteMe()
// starts the turn counter and tracks what it was bit by
void Human::biteMe(Character *ptr) {
  m_bitBy = ptr;
  m_numTurns = 1;
}

// hitMe()
// humans cannot be hit, so nothing happens
void Human::hitMe() {
  return;
}

// cureMe()
// resets the human's numTurns
void Human::cureMe() {
  m_numTurns = 0;
  m_bitBy = NULL;
}

// morph()
// when the human's numTurns = 3, it is morphed into a zombie / vampire
Character *Human::morph() {

  if (m_numTurns > 0) {
  m_numTurns++;
  }

  if (m_numTurns >= 3) {
    return m_bitBy;
  }

  else {
    return NULL;
  }
}

// identify()
// prints the type of class of the object and ID number 
string Human::identify() {
   ostringstream oss ;
   oss << "Human #" << getId() ;
   return oss.str() ;
}

// encounter()
// the human does nothing
void Human::encounter(Character *ptr) {
  cout << identify() << " does nothing" << endl;
}

// migrates()
// humans migrate, so it always returns true
bool Human::migrates() {
  return true;
}

// isDead()
// returns m_isDead
bool Human::isDead() {
  return m_isDead;
}
