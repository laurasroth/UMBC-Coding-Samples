/**********************************************
** File:     human.h
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the class definition for
**   the derived human class. 
**********************************************/

#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "character.h"
#include "zombie.h"
#include "vampire.h"

class Human : public Character {

public:

  Human();
  void encounter(Character *ptr);
  void biteMe(Character *ptr);
  void hitMe();
  void cureMe();
  Character *morph();
  string identify();
  bool migrates();
  bool isDead();

private:
  int m_numTurns;       // number of turns before the human transforms
  bool m_isDead;
  Character *m_bitBy;   // what the human should morph to after being bit

};

#endif
