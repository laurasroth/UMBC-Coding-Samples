/*****************************************
** File:    myDriver.cpp
** Project: CMSC 341 Project 5, Fall 2016
** Author:  Laura Roth
** Date:    12/6/16
** Section: 03
** E-mail:  rolaur1@umbc.edu 
**
**   This file contains the driver I wrote that
**   tests all of the working parts of the program.
**
***********************************************/

// this code was taken from the given driver

#include <iostream>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "words.h"
#include "Pinball.h"

using namespace std ;

int main() {

  Pinball test(29);

  int i = 0;

  const char* names[16] = {"SnowWhite", "LaPucelle", "SisterNana", "Weiss",
			  "Ripple", "TopSpeed", "Cranberry", "SwimSwim",
			  "Tama", "Nemurin", "Ruler", "CalamityMary",
			   "Magicaloid44", "Yunael", "Minael", "HardgoreAlice"};

  cout << "Let's meet our Players!" << endl;

  while (i < 16) {
  test.insert(names[i]);
  cout << names[i] << endl;
  i++;
  }

  cout << "where is Nemurin?" << endl;

  cout << test.at(0) << endl;

  cout << "Wait, that's not her..." << endl;

  test.remove(names[9]);

  cout << "Where is Nemurin?" << endl;

  if (test.find(names[i]) == -1) {
    cout << "She's gone..." << endl;
  }

  test.printStats();

  return 0;
}
