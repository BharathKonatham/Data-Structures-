#include "Sequence.h"

Sequence:: Sequence(){
    head = NULL;
    
   // next = NULL;
}
Sequence::Sequence( size_type sz )
{   
    if(sz ==0){
        head = NULL;
        tail = nullptr;
        numElts = 0;
    }
    if(sz>0){
        head = new SequenceNode();
        tail = head;   
        numElts++;
        for(int i=0;i<sz-1;i++){
            SequenceNode* newNode = new SequenceNode();
            newNode->prev = tail;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            numElts++;
            //cout<<tail->nodePostion<<endl;
        }
    }
    
}

Sequence::Sequence( const Sequence& s )
{
}

Sequence::~Sequence()
{
    if(head!=NULL){
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
}

Sequence::value_type& Sequence::operator[]( size_type position )
{
SequenceNode* current = head; 
for(int i=0;i<position;i++){
    current = current->next;
    }
    return (current->elt);
}


void Sequence::push_back( const value_type& value )
{
    SequenceNode* newNode = new SequenceNode(value);
    if(numElts==0){
        head = newNode;
        tail=head;
        numElts++;
        //cout<<numElts<<endl;
    }
    else{
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = nullptr;
    tail = newNode;
    //cout<<numElts<<endl;
    numElts++;
    }
}

void Sequence::pop_back()
{   
    //Sequence sz.size();
    if(numElts==1){
        delete head,tail;

    }
    else if(numElts<1){
        throw;
    }
    else{
        SequenceNode* current = tail; 
        tail=current->prev ; 
        tail->next=NULL;
        numElts--;
        delete current;
       // cout<<numElts<<endl;
    }
}

void Sequence::insert( size_type position, value_type value )
{   
    SequenceNode* current = head;
    SequenceNode* newNode = new SequenceNode(value);
    for(int i=0;i<=position;i++){
    //current = current->next;
    if(i==position){
    current->next = newNode;
    newNode->prev = tail;
    //tail->next = newNode;
    newNode->prev = tail;
    newNode->next = nullptr;
    tail = newNode;
    }
}
}

const Sequence::value_type& Sequence::front() const
{
}

const Sequence::value_type& Sequence::back() const
{
}

bool Sequence::empty() const
{
}

Sequence::size_type Sequence::size() 
{
    SequenceNode* current = head;
    numElts = 0;
    while(current != NULL){
        numElts++;
        current = current->next;
    }
    return numElts;
}

void Sequence::clear()
{
}

void Sequence::erase( size_type position, size_type count )
{
}


ostream& operator<<( ostream& os, Sequence& s )
{
    s.print(os);
    return os;

}
void Sequence:: print(ostream&){
    
    SequenceNode* current=head;
    while(current !=NULL){
        cout<<current->elt<<","<<" ";
        current = current->next;
    }
}