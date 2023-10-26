#include<iostream>
#include "Database.h"
using namespace std;


///////////////////// INSERT METHOD ////////////////////////////////

bool Database :: insert( const Record& newRecord, int& collisions ){
    collisions = 0;
    int key = newRecord.getUID();

    if( object.find( key, index ) || object.totalItems() == MAXHASH ){
        return false;
    }
    index = insertToVector( newRecord );
     
    bool isInserted = object.insert(  key, index, collisions );
    cout<<"collisions for inserting "<< key <<" = "<< collisions<< endl;
    return isInserted;
}

//////////////////// DELETE METHOD //////////////////////////////////

bool Database :: remove( int key ){

    int recordPosition ;

    if(object.find( key, index )){

        object.remove( key );
        updateDataBase( index, key );
        return true;
    }
    return false;   
}

//////////////////// OFFSET VALUE ARRAY ////////////////////////////

void Database :: callRandomArray(){
    object.randomArray();
}

/////////////////// INSERT VALUE TO DATABASE ///////////////////////

int Database :: insertToVector( const Record& newRecord ){
    
    recordStore.push_back( newRecord );
    return indexofVector++;
}

////////////////// UPDATE DATA BASE AFTER DELETE //////////////////

void Database :: updateDataBase( int position, int key ){

    recordStore[ position ] = recordStore[ recordStore.size() - 1 ];
    recordStore.pop_back();
    indexofVector--;
    object.updateHashTable(position,recordStore[position].getUID());
}

///////////////// FIND METHOD ////////////////////////////////////

bool Database :: find(int uid, Record& foundRecord){

    if(object.find( uid, index )){

        foundRecord = recordStore[ index ];
        return true;
    }
    return false;
}

////////////////// ALPHA FOR THE HASH TABLE //////////////////////

float Database :: alpha(){
    return object.alpha();
}

///////////////// PRINTING HASH TABLE ////////////////////////////

void Database :: printHashTable(){

   for(int i = 0 ; i < MAXHASH; i++){
       
       if( object.hashTable[ i ].isNormal() ){
            cout<< "HashTable Slot "<< i << ": ";
            operator<<( cout, object.hashTable[ i ] )<<endl;
        }
    } 
}

//////////////// PRINTING DATABASE //////////////////////////////

void Database :: printDatabase(){
    for(int i = 0 ; i < MAXHASH; i++){
        if( object.hashTable[ i ].isNormal() ){
            cout<< "HashTable Slot "<< i << ": ";

            operator<<( cout, recordStore[ object.hashTable[ i ].getIndex() ] )<<endl;
        }
        
    }
}