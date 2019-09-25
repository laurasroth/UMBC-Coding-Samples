/**********************************************
** File:     vampire.h
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the class definition for
**   the derived vampire class. 
**********************************************/

#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "character.h"

class Vampire : public Character {

public:

  Vampire();
  void encounter(Character *ptr);
  void biteMe(Character *ptr);
  void hitMe();
  void cureMe();
  Character *morph();
  string identify();
  bool migrates();
  bool isDead();

 private:
  int m_numHits;    // the number of hits before a vampire dies
  bool m_isDead;

};

#endif
