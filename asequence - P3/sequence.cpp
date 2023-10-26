#include "Sequence.h"

Sequence:: Sequence(){
    head = NULL;
    
}
Sequence::Sequence( size_type sz )
{   
    if(sz == 0){
        head = NULL;
        tail = NULL;
        numElts = 0;
    }
    if(sz > 0){
        head = new SequenceNode();
        tail = head;   
        for(int i = 0 ; i < sz-1 ; i++)
        {
            SequenceNode* newNode = new SequenceNode();
            newNode-> prev = tail;
            newNode-> next = NULL;
            tail-> next = newNode;
            tail = newNode;
        }
    }
    
}

Sequence::Sequence( const Sequence& s )
{if(s.head == NULL){
      head = NULL;
  }  
  else{
      SequenceNode *current = s.head;
      SequenceNode *nextNode;
      while(current!=NULL){
            if(head==NULL){
            head = new SequenceNode(current->elt);
            }
            else{
            SequenceNode *nextNode = head;
                while(nextNode->next!=NULL){
                    nextNode = nextNode->next;
                }  
            nextNode->next = new SequenceNode(current->elt);
            }
        current = current->next;
      }
  }
}


Sequence::~Sequence()
{
    if(head != NULL){
        SequenceNode* current = head;
        SequenceNode* nextNode;
        while(current != NULL){
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
}

Sequence& Sequence::operator=( const Sequence& s )
{
    if(head != NULL){
        SequenceNode* current = head;
        SequenceNode* nextNode;
        while(current != NULL){
            nextNode = current-> next;
            delete current;
            current = nextNode;
        }
    }

    if(s.head == NULL){
        head = NULL;
    }
    else{
        SequenceNode* current = s.head; 

        SequenceNode* copyCurrent;

        while (current != NULL){ 

            if(head == NULL){ 

                head = new SequenceNode(current-> elt); 

            } 
            else{ 

                SequenceNode* copyCurrent = head; 

                while (copyCurrent->next != NULL){ 

                    copyCurrent = copyCurrent->next; 

                } 

                copyCurrent->next = new SequenceNode(current->elt); 
            }

            current = current->next; 

        } 

    }
    return *this;

}

Sequence::value_type& Sequence::operator[]( size_type position ){

    SequenceNode* current = head;

    for(int i = 0 ; i < position ; i++){
        current = current-> next;
    }

    return (current->elt);
}


void Sequence::push_back( const value_type& value ){

    SequenceNode* newNode = new SequenceNode( value );

    if(size() == 0){
        head = newNode;
        tail = head;
    }
    else{
        tail-> next = newNode;
        newNode-> prev = tail;
        newNode-> next = nullptr;
        tail = newNode;
    }
}

void Sequence::pop_back(){

    SequenceNode* current;
    if(size()==1){
        current = head;
        head->next = NULL;
        head->prev = NULL;
        head = NULL;
        tail= NULL;
        delete current;
    }
    else if(size()<1){

        throw exception();

    }
    else{
        SequenceNode* current;
        current = tail; 
        tail = current-> prev ; 
        tail-> next = NULL;
        delete current;
    }
}

void Sequence::insert( size_type position, value_type value )
{   
    SequenceNode* current = head;
    SequenceNode* newNode = new SequenceNode( value );
    if(position > size()){

        throw exception();

    }
    else{

        for(int i = 0; i <= position ; i++){
            if(position == 0){
                newNode-> prev = NULL;
                newNode-> next = current;
                current-> prev = newNode;
                head = newNode;
            }
            else if( i == (position-1) ){
                newNode-> prev = current;
                newNode-> next = current->next;
                current-> next-> prev = newNode;
                current-> next = newNode;
            }
        current = current->next;
        }
    }
}

const Sequence::value_type& Sequence::front() const
{
    if(head != NULL){

        return head-> elt;
    }
    else{
        throw exception();
    }
}

const Sequence::value_type& Sequence::back() const
{
    if(tail != NULL){

        return tail->elt;
    }
    else{

        throw exception();
    }
}

bool Sequence::empty() const{

    if(size() == 0) {
        return 1;
    }
    else if(size() > 0){
        return 0;
    }
    else{
         throw exception();
    }
}

Sequence::size_type Sequence::size() const
{
    SequenceNode* current = head;

    int count = 0;
    if(head == NULL){
        return count;
    }
    else{
        while(current != NULL){
            count++;
            current = current->next;
        }   
    }
    return count;
}

void Sequence::clear()
{
    SequenceNode* current;
    for(int i = size() ; i > 0 ; i--){

        if(size() == 1){

            current = head;
            head-> next = NULL;
            head-> prev = NULL;
            head = NULL;
            tail = NULL;
            delete current;

        }
        else if(size() < 1){

            throw exception();
        }
        else{
            SequenceNode* current;
            current = tail; 
            tail=current->prev ; 
            tail->next=NULL;
            delete current;
        }
    }
}

void Sequence::erase( size_type position, size_type count ){
    
    int sizer = size();
    SequenceNode* current = head;
    SequenceNode* nextNode;

    if(position > 0 && count >= sizer){

        throw exception();
    }
    for(int i = 0; i < sizer ; i++){
        int headPosition = 0;
        if (i == position){
            for(int j = 0 ; j < count ; j++){
                if(position == headPosition){
                    nextNode = current-> next;
                    head = current-> next;
                    current-> next-> prev = NULL;
                    delete current;
                    if(j == count){
                        break;
                    }
                    current = nextNode;
                    i++;
                }
                else if(i == size()){
                    nextNode = NULL;
                    tail = current-> prev;
                    tail-> next = NULL;
                    delete current;

                    if(j == count){
                        break;
                    }
                    i++;
                }
                else{
                    nextNode = current-> next;
                    current-> prev-> next = current-> next;
                    current-> next-> prev = current-> prev;
                    delete current;
                    if(j == count){
                         break;
                    }
                    current = nextNode;
                    i++;
                } 
            }
        }  
        current = current->next;
    }
}

ostream& operator<<( ostream& os, Sequence& s )
{
    s.print(os);
    return os;

}
void Sequence:: print(ostream&){

    SequenceNode* current = head;

    while(current != NULL){
        cout<<current-> elt<<","<<" ";
        current = current-> next;
    }
}


