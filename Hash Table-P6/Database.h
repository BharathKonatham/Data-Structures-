#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "hashfunction.h"
#include "Record.h"
//#include "Slot.h"

class Database{
    private:

        Hash object;
        vector<Record> recordStore;

    public:

        Record foundRecord;
        int index;
        int collisions;
        int indexofVector = 0; 

        bool insert(const Record& newRecord, int& collisions);
        void callRandomArray();
        int insertToVector(const Record& newRecord);
        bool remove(int);
        void updateDataBase(int,int);
        bool find(int uid, Record& foundRecord);
        float alpha();
        void printHashTable();
        void printDatabase();
};