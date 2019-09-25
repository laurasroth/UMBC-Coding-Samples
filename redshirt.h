/**********************************************
** File:     redshirt.h
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the class definition for
**   the derived redshirt class. 
**********************************************/

#ifndef _REDSHIRT_H_
#define _REDSHIRT_H_

#include "character.h"

class RedShirt : public Character {

public:

  RedShirt();
  void encounter(Character *ptr);
  void biteMe(Character *ptr);
  void hitMe();
  void cureMe();
  Character *morph();
  string identify();
  bool migrates();
  bool isDead();

private:
  bool m_isDead;

};

#endif
