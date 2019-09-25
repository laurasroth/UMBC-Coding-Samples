/**********************************************
** File:     buffy.h
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the class definition for
**   the derived buffy class. 
**********************************************/

#ifndef _BUFFY_H_
#define _BUFFY_H_

#include "character.h"

class Buffy : public Character {

public:

  Buffy();
  void encounter(Character *ptr);
  void biteMe(Character *ptr);
  void hitMe();
  void cureMe();
  Character *morph();
  bool migrates();
  string identify();
  bool isDead();

protected:
  bool m_isDead;

};

#endif
