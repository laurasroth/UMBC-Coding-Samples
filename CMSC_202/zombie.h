/**********************************************
** File:     zombie.h
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the class definition for
**   the derived zombie class. 
**********************************************/

#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include "character.h"

class Zombie : public Character {

public:

  Zombie();
  void encounter(Character *ptr);
  void biteMe(Character *ptr);
  void hitMe();
  void cureMe();
  Character *morph();
  string identify();
  bool migrates();
  bool isDead();

private:
  int m_numHits;      // the number of hits before a zombie dies
  bool m_isDead;
  bool m_cured;     // used to mark if a zombie will be cured

};

#endif
