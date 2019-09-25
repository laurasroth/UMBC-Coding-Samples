/**********************************************
** File:     proj4.cpp
** Project:  CMSC 202 Project 4, Fall 2015
** Author:   Laura Roth
** Date:     11/23/15
** Section:  01
** Email:    rolaur1@umbc.edu
**
**   This file contains my tests for Project 4.
**   Only working functions will be tested.
**********************************************/

// I honestly did not realize we had to submit a
// test program until an hour before the project
// was due. This is what I was able to piece 
// together in that time. Thank you for your
// time! I hope you're having a nice day!

#include <iostream>
using namespace std ;

#include "character.h"
#include "ghost.h"
#include "human.h"
#include "zombie.h"
#include "doctor.h"
#include "buffy.h"
#include "redshirt.h"
#include "vampire.h"

#include "game.h"

int main() {

  bool map[] = {
       // Room     0  1 
                   0, 1,
                   1, 0 
  };

  Game G(2, map, 1234);

  G.addToRoom(0, new Ghost());

  G.addToRoom(0, new Zombie());

  G.addToRoom(0, new Human());

  G.addToRoom(0, new Doctor());

  G.addToRoom(1, new Buffy());

  G.addToRoom(1, new Vampire());

  G.addToRoom(1, new RedShirt());

  G.addToRoom(1, new RedShirt());

  G.display();

for (int i=0 ; i < 5 ; i++) {

      cout << "***********************************\n" ;
      cout << "Begin Round #" << i << ":\n" ;
      cout << "***********************************\n" ;

      G.playOneTurn() ;

      cout << "----------------------------------\n" ;
      cout << "Characters in each room:\n" ;
      cout << "----------------------------------\n" ;
      G.display() ;
      cout << "----------------------------------\n" ;
   }

   cout << "Goodbye!\n" ;


return 0;
}
