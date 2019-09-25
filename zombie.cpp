/**********************************************
** File:     zombie.cpp
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the member function
**   implementations for the zombie class.
**********************************************/

#include <iostream>
#include <sstream>
using namespace std ;

#include "zombie.h"
#include "human.h"

// Zombie()
// the default constructor for the zombie class
Zombie::Zombie() {
  m_numHits = 0; 
  m_cured = false;
}

// biteMe()
// zombies cannot be bitten, so nothing happens
void Zombie::biteMe(Character *ptr) {
   delete ptr;
}

// hitMe()
// increments the zombie's hit counter; if it is 3 or higher, the zombie dies
void Zombie::hitMe() {
  m_numHits++;

  // if a zombie is hit three times, it is removed from play
  if (m_numHits >= 3) {
    m_isDead = true;
  }
}

// cureMe()
// if the zombie is not already dead, the morph function is called
void Zombie::cureMe() {
  m_cured = true;
}

// morph()
// returns a pointer to a new human object
Character *Zombie::morph() {
  if (m_cured == true) {
  return new Human;
  }

  else {
    return NULL;
  }
}

// identify()
// prints the type of the object and it's assigned number
string Zombie::identify() {
   ostringstream oss ;
   oss << "Zombie #" << getId() ;
   return oss.str() ;
}

// encounter()
// the zombie bites the character it is interacting with, calling it's biteMe()
void Zombie::encounter(Character *ptr) {

   cout << identify() << " bites " << ptr->identify() << endl;
   ptr->biteMe(new Zombie());
}

// migrates()
// zombies migrate, so it always returns true
bool Zombie::migrates() {
  return true;
}

// isDead()
// returns m_isDead
bool Zombie::isDead() {
  return m_isDead;
}
