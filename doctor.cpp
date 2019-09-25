/**********************************************
** File:     doctor.cpp
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the member function
**   implementations for the doctor class.
**********************************************/

#include <iostream>
#include <sstream>
using namespace std ;

#include "doctor.h"
#include "zombie.h"
#include "vampire.h"

// Doctor()
// the default constructor for the doctor class
Doctor::Doctor() {
  m_numTurns = 0;
  m_bitBy = NULL;
}

// biteMe()
// starts its death timer and stores what bit it
void Doctor::biteMe(Character *ptr) {
  m_numTurns = 1;
  m_bitBy = ptr;
}

// hitMe()
// doctors cannot be hit, so nothing happens
void Doctor::hitMe() {
  return;
}

// cureMe()
// resets the doctor's numTurns
void Doctor::cureMe() {
  m_numTurns = 0;
  m_bitBy = NULL;
}

// morph()
// when the doctor's numTurns = 3, it is morphed into a zombie / vampire
Character *Doctor::morph() {
  
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
string Doctor::identify() {
   ostringstream oss ;
   oss << "Doctor #" << getId() ;
   return oss.str() ;
}

// encounter()
// the doctor does cures the character it interacts with
void Doctor::encounter(Character *ptr) {
  cout << identify() << " cures " << ptr->identify() << endl;
  ptr->cureMe();
}

// migrates()
// humans migrate, so it always returns true
bool Doctor::migrates() {
  return true;
}

// isDead()
// returns m_isDead
bool Doctor::isDead() {
  return m_isDead;
}
