#include <iostream>
#include <map>
#include<vector>
using namespace std;

class AVLTree {
private:
    class TreeNode {
    public:
        int key;
        string value;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        int leftHeight;
        int rightHeight;
        int height;
        TreeNode();
        TreeNode(int key, string value);
    };

TreeNode* root;
TreeNode* previous ;
int numNodes;
bool insert(int, string, TreeNode*&);

public:
    int nodeCount =0;
    AVLTree();
    int getSize();
    ~AVLTree();
    friend ostream& operator <<( ostream& , AVLTree& );
    bool insert(int, string);
    void print(ostream&);
    bool find(int, string&);
    void incorderTraversalprint(TreeNode*&);
    bool search(int, TreeNode*&, string&);
    void balanceCalculator(TreeNode*);
    void treeBalance(TreeNode*&);
    void UpdateNodeHeight(TreeNode*&);
    int GetNodeBalance(TreeNode*& node);
    void rotateRight(TreeNode*&);
    bool setChild(TreeNode*&,string,TreeNode*&); 
    bool replaceChild(TreeNode*&,TreeNode*&,TreeNode*&);
    void rotateLeft(TreeNode*&);
    void parentUpdater(TreeNode*&);
    void doublerotateRight(TreeNode*&);
    void doublerotateLeft(TreeNode*&);
    vector<string> findRange(int, int);
    vector<string> range;
    void addData(TreeNode*, int, int ); 
    void Destructor(TreeNode*);
};