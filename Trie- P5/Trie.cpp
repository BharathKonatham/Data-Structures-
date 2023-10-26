#include <iostream>
#include<vector>
using namespace std;
#include "Trie.h"

// default constructor
Trie:: TrieNode:: TrieNode(char character, string word){

   
    letter = character;
    isLastWord = false;
    for (int i = 0; i < alphabets; i++)
    childNode[i] = NULL;
    completeCount++;
    words.push_back(word);
}


// Parameterized constructor
Trie::TrieNode::TrieNode(TrieNode*, string value){


}


bool Trie::insert(string word){

    if(root == NULL)
        root = new TrieNode('\0', word);
    return checkinsert( root, word );

 }

bool Trie::checkinsert(TrieNode* root, string word){

     
    TrieNode* pointer = root;
    int head;
    for(int i = 0; i < word.size(); i++){

        char c = word[i];
        head = word[i]-'a';
        
        if(pointer->childNode[head] == NULL){

            return insert(root, word);

        }

        pointer = pointer->childNode[head];
    }

    if(pointer != NULL && pointer->isLastWord == true){

        return false;

    }
    return false;
}


//insert method
bool Trie::insert( TrieNode*& root, string word ){

    
    TrieNode* pointer = root;

    for(int i = 0; i < word.size(); i++){

        //char c = word[i];
        int head = word[i]-'a';
        if (pointer->childNode[head] == NULL){
            pointer->childNode[head] = new TrieNode(word[i],word);
            numberofNodes++;
            }
        else{   
            pointer->childNode[head]->completeCount++;
            pointer->childNode[head]->words.push_back(word);
        }
        pointer = pointer->childNode[head];
        //cout<< pointer->childNode[head]->completeCount;
    }

    pointer->isLastWord = true;
    numberOfWords++;

return true;
    
}

int Trie :: count(){
    return numberOfWords;
}

int Trie :: getSize(){
    return numberofNodes;
}

bool Trie::find(string word){

    TrieNode* pointer = root;
    bool isExist;
    int k = word.size();
    for(int i = 0; i < word.size(); i++){
        
        //char c = word[i];
        int head = word[i]-'a';
        if (pointer->childNode[head] == NULL){
            isExist = false;
            break;
        }
        else{
            //cout<< pointer->childNode[head]->isLastWord;
            if((i+1)==word.size() && pointer->childNode[head]->isLastWord == true){
                isExist = true;
                break;
            }
        }
        pointer = pointer->childNode[head];
    }
    return isExist;
}

int Trie::completeCount(string prefix){
    TrieNode* pointer = root;
    int head;
    for(int i = 0; i < prefix.size(); i++){
        
        //char c = word[i];
        head = prefix[i]-'a';

        if (pointer->childNode[head] == NULL){
            return 0;
        }
        pointer = pointer->childNode[head];
        
    }
    return pointer->completeCount;
       
}

vector<string> Trie :: complete(string prefix){

    return prefixWords(root, prefix);

}

vector<string>Trie::prefixWords(TrieNode* root, string prefix){

    TrieNode* pointer = root;
    int head;
    for(int i = 0; i < prefix.size(); i++){
        
        //char c = word[i];
        head = prefix[i]-'a';

        if (pointer->childNode[head] == NULL){
            return pointer->words;
        }
        pointer = pointer->childNode[head];
        
    }
    return pointer->words;
}