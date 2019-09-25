/*****************************************
** File:    Pinball.h
** Project: CMSC 341 Project 5, Fall 2016
** Author:  Laura Roth
** Date:    12/6/16
** Section: 03
** E-mail:  rolaur1@umbc.edu 
**
**   This file contains the declarations for the 
**   Pinball hash class. The file was provided
**   and modified.
**
***********************************************/

#ifndef _PINBALL_H_
#define _PINBALL_H_

#include <string>
#include <stdexcept>
using namespace std ;

class PinballHashFull : public std::out_of_range {

public:
   PinballHashFull(const string& what) : std::out_of_range(what) { }
} ;


class Pinball {

public:

   //---------------------------------------------------------
   // Name: Pinball()
   // PreCondition:  the desired size of the hash table
   // PostCondition: Returns an empty hash table
   //---------------------------------------------------------
   Pinball(int n=1019) ;    // default capacity is prime

   //---------------------------------------------------------
   // Name: ~Pinball()
   // PreCondition: N/A
   // PostCondition: any dynamically allocated parts are
   //                deleted
   //---------------------------------------------------------
   ~Pinball() ;

   //---------------------------------------------------------
   // Name: void insert(const char *str)
   // PreCondition: a string to insert
   // PostCondition: it is insert
   //---------------------------------------------------------
   void insert(const char *str) ;

   //---------------------------------------------------------
   // Name: int find(const char *str)
   // PreCondition: a string to find
   // PostCondition: returns index if found, -1 if not
   //---------------------------------------------------------
   int find(const char *str) ;
   
   //---------------------------------------------------------
   // Name: const char * at(int index)
   // PreCondition: an index
   // PostCondition: returns a pointer to the string, if found
   //---------------------------------------------------------
   const char * at(int index) ;

   //---------------------------------------------------------
   // Name: char * remove(const char *str)
   // PreCondition: a string
   // PostCondition:  the string is removed if it is present
   //---------------------------------------------------------
   char * remove(const char *str) ;

   //---------------------------------------------------------
   // Name: void printStats()
   // PreCondition: N/A
   // PostCondition: prints some statistics about the hash
   //---------------------------------------------------------
   void printStats() ;

   //---------------------------------------------------------
   // Name: int size()
   // PreCondition: N/A
   // PostCondition: returns the current size
   //---------------------------------------------------------
   int size() { return m_size ; }

   // add public data members and 
   // public member functions as needed


private:
 
   char ** H ;        // the actual hash table
   int m_size ;       // number of items stored in H
   int m_capacity ;   // number slots allocated in H

   int m_degree ;     // use degree assigned to you
   int m_ejectLimit ; // use ejection limit assigned to you
   
   int m_numEject;    // the number of ejections in the current insert

   int m_primSlots;   // the number of primary slots
   int m_maxHits;     // the maximum hits on a primary slot
   int m_totalEject;  // the total number of ejections
   int m_maxEject;    // the max number of ejections in a single insert
   float m_avg;       // the average hits to primary slots

   float m_pAvg;


   // Made inline definition of hashCode() so everyone uses
   // the same function.
   //
   unsigned int hashCode(const char *str) {

      unsigned int val = 0 ; 
      const unsigned int thirtyThree = 33 ;  // magic number from textbook

      int i = 0 ;
      while (str[i] != '\0') {
         val = val * thirtyThree + str[i] ;
         i++ ;
      }
      return val ; 
   }


   // add private data members and 
   // private member functions as needed

} ;


#endif
