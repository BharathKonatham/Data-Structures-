#pragma once
#include "slot.h"

#define MAXHASH 20
#pragma once



class Hash{
   public:
      int key;
      int index;
      int collisions;
      int TotalNoOfItems=0;
      int randArray[MAXHASH];
      Slot hashTable[MAXHASH];


      unsigned int jsHash(const int key);
      void createHashTable();
      void randomArray();
      bool insert(int key, int index, int& collisions);
      bool find(int key, int& index);
      bool remove(int key);
      int returnIndexOfKey(int );
      void updateHashTable(int,int);
      float alpha();
      int totalItems();
           
};


