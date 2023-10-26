
#include<iostream>
#include <bits/stdc++.h>
#include "hashfunction.h"
#include "Database.h"
using namespace std;

//////////////////////// JHASH FUNCTION /////////////////////

unsigned int Hash :: jsHash(const int key)
{
   const char* kptr = (char *)&key;
   unsigned int length = sizeof(int);
   unsigned int hash = 1315423911;
   unsigned int i    = 0;

   for (i = 0; i < length; ++kptr, ++i)
   {
      hash ^= ((hash << 5) + (*kptr) + (hash >> 2));
   }

   return hash;  
}

/////////////////////// OFFSEST ARRAY //////////////////////

void Hash :: randomArray(){

    for(int i = 0 ; i < MAXHASH; i++){

        randArray[i] = i+1;
    }
    srand( time(0) );
    random_shuffle( randArray, randArray + MAXHASH );
}

/////////////////////// INSERT TO HASTABLE ////////////////

bool Hash::insert( int key, int index, int &collisions ){
   
    int position = jsHash( key ) % MAXHASH;
    int bucketsProbed = 0;
    int i = 0; 

    while ( bucketsProbed < MAXHASH ) {

        // Insert item in next empty bucket
        if(hashTable[ position ].isEmptySinceStart() || hashTable[ position ].isEmptyAfterRemoval() ){ 

            hashTable[ position ] = Slot( key, index);
            TotalNoOfItems++;
            return true;
        }

        // Increment bucket index
        position = ( position + randArray[ i ]) % MAXHASH;

        // Increment number of buckets probed
        ++bucketsProbed;
        collisions++;
        i++;
   }
    return false;
}

/////////////////////// HASH TABLE FIND //////////////////////

bool Hash :: find( int key, int& index ){

    int position = jsHash( key ) % MAXHASH;
    int bucketsProbed = 0;
    int i = 0; 

    while ( bucketsProbed < MAXHASH ) {
        
        if( hashTable[ position ].isNormal()  && ( hashTable[ position ].getKey() == key ) ){   

            index = hashTable[ position ].getIndex();
            return true;
        }

        if( hashTable[ position ].isEmptySinceStart() ){
            return false;
        }

        // Increment bucket index
        position = ( position + randArray[ i ]) % MAXHASH;

        // Increment number of buckets probed
        ++bucketsProbed;
        i++;
    }
   return false;
}

//////////////////// REMOVE FROM HASH TABLE ///////////////////////////////

bool Hash :: remove( int key ){

    int position = jsHash( key ) % MAXHASH;
    int bucketsProbed = 0;
    int i = 0; 

    while (bucketsProbed < MAXHASH ) {
        
        if( hashTable[ position ].isNormal() && ( hashTable[ position ].getKey() == key ) ){   
    
            hashTable[ position ].kill();
            TotalNoOfItems--;
            return true;
        }
        if( hashTable[ position ].isEmptySinceStart() ){
            return false;
        }

        // Increment bucket index
        position = ( position + randArray[ i ]) % MAXHASH;

        // Increment number of buckets probed
        ++bucketsProbed;
        i++;
   }

   
   return false;

}

/////////////////////////// UPDATE HASHTABLE /////////////////////////////

void Hash :: updateHashTable(int index, int key){

    int position = jsHash( key ) % MAXHASH;
    int bucketsProbed = 0;
    int i = 0; 

    while (bucketsProbed < MAXHASH) {
        
        //cout<<hashTable[position].isNormal();
        if( hashTable[ position ].isNormal() && ( hashTable[ position ].getKey() == key ) ){   
    
            hashTable[position] = Slot( key, index );
            return ;
        }

        // Increment bucket index
        position = ( position + randArray[ i ]) % MAXHASH;
        // Increment number of buckets probed
        ++bucketsProbed;
        i++;
   }
}

float Hash::alpha(){  
    return float(TotalNoOfItems)/float(MAXHASH);
}

int Hash:: totalItems(){
    return TotalNoOfItems;
}