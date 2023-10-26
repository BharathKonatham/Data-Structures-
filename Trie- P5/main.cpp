#include <iostream>
#include<vector>
using namespace std;
#include "Trie.h"
// #include <fstream>
// #include <iomanip>
// #include <string>
#include <stdlib.h>
using namespace std;
// Example code
int main() {

//    string nextWord;
//    // Create an input file stream and open a file
//    ifstream infile;
//    infile.open("wordlist_windows.txt");
//    // If the file couldn't be opened, infile will be false
//    if (!infile){
//       cout << "Couldn't open file" << endl;
//       return 1;
//    }
//    // Read lines from the file into nextWord
//    // until we reach the end-of-file marker
//    while(!infile.eof()){
//       getline(infile, nextWord);
//       cout << "|" << nextWord << "|" << endl;
//       string response;
//       cin >> response;
//    }
   

    Trie trieObject;
    cout<<"and first time: "<<trieObject.insert("and")<<endl;
    cout<<"ant first time: "<<trieObject.insert("ant")<<endl;
    cout<<"animal first time: "<<trieObject.insert("animal")<<endl;
    cout<<"andrew first time: "<<trieObject.insert("andrew")<<endl;
    cout<<"bharath first time: "<<trieObject.insert("bharath")<<endl;
    cout<<"simra first time: "<<trieObject.insert("simra")<<endl;
    cout<<"rohit first time: "<<trieObject.insert("rohit")<<endl;

    cout<<"and second time: "<<trieObject.insert("and")<<endl;
    cout<<"ant second time: "<<trieObject.insert("ant")<<endl;
    cout<<"animal second time: "<<trieObject.insert("animal")<<endl;
    cout<<"andrew second time: "<<trieObject.insert("andrew")<<endl;
    cout<<"bharath second time: "<<trieObject.insert("bharath")<<endl;
    cout<<"simra second time: "<<trieObject.insert("simra")<<endl;
    cout<<"rohit second time: "<<trieObject.insert("rohit")<<endl;

    cout<<"andrew third time: "<<trieObject.insert("andrew")<<endl;

    
    

    cout<<"number of nodes: "<<trieObject.getSize()<< endl;
    cout<<"number of words: "<< trieObject.count()<<endl;
    cout<<"find 'bharath': "<< trieObject.find("bharath")<<endl;
    cout<<"find 'and': "<< trieObject.find("and")<<endl;
    cout<<"find 'an': "<< trieObject.find("an")<<endl;
    cout<<"total number of words start with 'a': "<<trieObject.completeCount("a")<<endl;
    cout<<"total number of words start with 'and': "<<trieObject.completeCount("and")<<endl;
    vector<string>vec = trieObject.complete("ant");//left subtree
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << endl;
	}
}