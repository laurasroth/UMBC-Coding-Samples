/**********************************************
** File:     doctor.h
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains the class definition for
**   the derived doctor class. 
**********************************************/

#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include "character.h"
#include "vampire.h"
#include "zombie.h"

class Doctor : public Character {

public:

  Doctor();
  void encounter(Character *ptr);
  void biteMe(Character *ptr);
  void biteMe(Zombie *ptr);
  void biteMe(Vampire *ptr);
  void hitMe();
  void cureMe();
  Character *morph();
  string identify();
  bool migrates();
  bool isDead();

private:
  int m_numTurns;        // number of turns before the doctor transforms
  bool m_isDead;
  Character *m_bitBy;    // what the doctor will transform into

};

#endif
