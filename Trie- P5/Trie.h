#include <iostream>
#include<vector>
using namespace std;
# define alphabets 26
class Trie {
private:
    class TrieNode {
    public:
        bool isLastWord;
        int completeCount=0;
        vector<string> words;
        TrieNode* childNode[alphabets];
        char letter;
        
        TrieNode(char,string);
        TrieNode(TrieNode*, string value);
    };

    bool insert(TrieNode*&, string);
    TrieNode* root = NULL;
    
    
public:
    int numberOfWords = 0;
    int numberofNodes = 0;
    bool insert(string);
    bool checkinsert( TrieNode*, string );
    int count();
    int getSize();
    bool find(string);
    int completeCount(string);
    vector<string>complete(string);
    vector<string>prefixWords(TrieNode*, string);
};