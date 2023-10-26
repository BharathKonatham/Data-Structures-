#include<iostream>
#include "Database.h"
using namespace std;
Database dataBaseFunction;
void insertion();
void deletion();
void searching();
int collisions; 
int main(){ 
    
    dataBaseFunction.callRandomArray();

    string action;
    
    cout<<"Would you like to (I)nsert or (D)elete a record, or (S)earch for a record, or (Q)uit?"<<endl;
    
    while(action != "Q"){
        cout<< "Enter action: ";
        cin>>action;
        
        if(action != "I" && action!= "D" && action!= "S" && action!= "Q"){
            cout<< "incorrect action"<<endl;
            continue;
        }
        char* c = const_cast<char*>(action.c_str());
        switch (c[0]){

            case 'I':
                insertion();
                break;
            case 'D':
                deletion();
                break;
            case 'S':
                searching();
                break;
            case 'Q':
                cout<< "Exiting";
                break;
            
            default:
                cout<< "invalid action"<<endl;
                break;
        }
    }


///////////////////////////// uncomment and  Use below test data for "Insert", "Remove", "Find" /////////////////////////////////


    // Record record1("bharath", "k", 23456,"graduate");
    // Record record2("rohit", "P", 256,"graduate");
    // Record record3("simra", "T", 2456,"graduate");
    // Record record4("viru", "V", 2345,"graduate");
    // Record record5("sasi", "V", 2346,"graduate");
    // Record record6("vaishnavi", "A", 6,"graduate");
    // Record record7("pinky", "K", 26,"graduate");
    // Record record8("lalit", "D", 456,"graduate");
    // Record record9("naveen", "S", 46,"graduate");
    // Record record10("vijay", "E", 56,"graduate");
    // Record record11("vishnu", "W", 356,"graduate");
    // Record record12("divya", "Q", 236,"graduate");
    // Record record13("vishal", "O", 234,"graduate");
    // Record record14("jenny", "R", 235,"graduate");
    // Record record15("riki", "R", 3456,"graduate");
    // Record record16("pyari", "R", 346,"graduate");
    // Record record17("hari", "H", 536,"graduate");
    // Record record18("ragini", "L", 23,"graduate");
    // Record record19("Raymer", "L", 2,"graduate");
    // Record record20("TK prasad", "T", 3,"graduate");
    // Record record21("Henricson", "kellog", 77,"graduate");
    // Record record22("Tobby", "Hiller", 311,"graduate");
    // Record record23("Sonia", "Trouser", 300,"graduate");
    // dataBaseFunction.insert(record1,collisions);
    // dataBaseFunction.insert(record2,collisions);
    // dataBaseFunction.insert(record3,collisions);
    // dataBaseFunction.insert(record4,collisions);
    // dataBaseFunction.insert(record5,collisions);
    // dataBaseFunction.insert(record6,collisions);
    // cout<<"Loading factor 'alpha' for the hash tabel is "<< dataBaseFunction.alpha()<<endl;
    // dataBaseFunction.insert(record7,collisions);
    // dataBaseFunction.insert(record8,collisions);
    // dataBaseFunction.insert(record9,collisions);
    // dataBaseFunction.insert(record10,collisions);
    // dataBaseFunction.insert(record11,collisions);
    // dataBaseFunction.insert(record12,collisions);
    // dataBaseFunction.insert(record13,collisions);
    // dataBaseFunction.insert(record14,collisions);
    // dataBaseFunction.insert(record15,collisions);
    // dataBaseFunction.insert(record16,collisions);
    // dataBaseFunction.insert(record17,collisions);
    // dataBaseFunction.insert(record18,collisions);
    // dataBaseFunction.insert(record19,collisions);
    // dataBaseFunction.insert(record20,collisions);
    // cout<<dataBaseFunction.insert(record21,collisions);
    // cout<<dataBaseFunction.insert(record22,collisions);


    // dataBaseFunction.remove(256);//record2 
    // dataBaseFunction.insert(record2,collisions);
    // dataBaseFunction.remove(356);//record 11
    // dataBaseFunction.remove(6); //makes key six in hash table as emptyafterremoval and removed from database
    // dataBaseFunction.find(2345, record10);



    // loading factor 
    cout<<"Loading factor 'alpha' for the hash tabel is "<< dataBaseFunction.alpha()<<endl;
    

    ////////////////////// PRINT HASH TABLE AND DATABASE /////////////////////////
    dataBaseFunction.printHashTable();
    dataBaseFunction.printDatabase();
}


 void insertion(){

    string firstName, lastName,year;
    int UID;

    cout<< "First Name : ";
    cin>>firstName;

    cout<< "First Name : ";
    cin>>lastName;

    cout<< "UID : ";
    cin>>UID;

    cout<< "Year : ";
    cin>>year;
    
    Record record(firstName,lastName,UID,year);
    
    if( dataBaseFunction.insert( record, collisions ) ){
        cout << "Record Inserted"<<endl;
    }
    else{
        cout<< "Record not Inserted"<<endl;
    }


}

void deletion(){

    int key;

    cout<< "Enter UID to Delete : ";
    cin>>key;

    if( dataBaseFunction.remove( key ) ){
        cout<<" Record Removed "<<endl;
    }
    else{
        cout<<"record not found"<<endl;
    }
}

void searching(){
    int key;

    Record getRecord;

    cout<< "Enter UID to search  : ";
    cin>>key;

    if( dataBaseFunction.find( key, getRecord ) ){
        cout<<"Record found"<<endl;
    }
    else{
        cout<<"Record not found"<<endl;
    }
}