#include<iostream>
#include "AVLTree.h"
#include<vector>
using namespace std;

AVLTree::TreeNode::TreeNode(){
    key = 0;
    value = "";
    left = NULL;
    right = NULL;
    leftHeight = 0;
    rightHeight = 0;
    parent = NULL;

}

AVLTree::TreeNode::TreeNode(int newKey, string newValue){
    key = newKey;
    value = newValue;
    left = NULL;
    right = NULL;
    leftHeight = 0;
    rightHeight = 0;
    height = 0;
    parent = NULL;
    
}


AVLTree::AVLTree(){
    root = NULL;
    previous = NULL;
    numNodes = 0;
}

bool AVLTree::insert(int key, string value){
   
    return insert(key, value, root);
 
}

bool AVLTree::insert(int key, string value, TreeNode*& current){

    if (current == NULL){
            current = new TreeNode(key, value);
            numNodes++;
            nodeCount = 0;
            current->parent = previous; 
            balanceCalculator(current);
            return true;
    }
    else if (key < current->key){
       previous = current;
      return insert(key, value, current->left);
    }
    else if (key > current->key){
      previous = current;
      return insert(key, value, current->right);
    }
    else{
        return false;
    }
}

void AVLTree :: balanceCalculator(TreeNode* current){
   
   if(current!=NULL){
      treeBalance(current);
   
      balanceCalculator(current->parent);
      
   }
   
}

int AVLTree::getSize(){
    return numNodes;
}
ostream& operator<<( ostream& os, AVLTree& s )
{   
    s.print(os);
    return os;

}
void AVLTree:: print(ostream&){
    int space = 0;
    int count = 50;
    incorderTraversalprint(root);
}

void AVLTree :: incorderTraversalprint(TreeNode*& node){
     if (node !=  NULL) {
    incorderTraversalprint(node->left);
    cout<<node->key<<", "<<node->value<<endl;
    incorderTraversalprint(node->right);
  }
}

bool AVLTree::find(int key, string& value){
    return search(key, root,value);
}

bool AVLTree::search(int key,TreeNode*& node,string& value){
    if(node == NULL)
        return false;

    if(node->key == key){
        value = node->value;
        return true;
    }
    else if (key < node->key){
        return search(key, node->left,value);
    }
    else if(key> node->key){
        return search(key, node->right,value); 
    }
    else
        return false;
}

//balanceing
void AVLTree :: treeBalance(TreeNode*& node){
   UpdateNodeHeight(node);      
   if (node->leftHeight-node->rightHeight == -2) {
      if ((node->right->leftHeight - node->right->rightHeight) == 1) {
         // Double rotation case.
         doublerotateRight(node);
      }
      rotateLeft(node);
   }
   else if (node->leftHeight-node->rightHeight == 2) {
      if ((node->left->leftHeight - node->left->rightHeight) == -1) {
         // Double rotation case.
            doublerotateLeft(node);
      }
      return rotateRight(node);
   }       
}

// height calucation
void AVLTree :: UpdateNodeHeight(TreeNode*& node) {
  // node->leftHeight = -1;
   if (node->left != NULL)
      node ->leftHeight = node->left->height+1;
   //node->rightHeight = -1;
   if (node->right != NULL)
      node->rightHeight = node->right->height+1;
   if(node->left == NULL && node->right == NULL)
      node->height = 0;
   else
      node->height = max(node->leftHeight,node->rightHeight) ;

}



int AVLTree::GetNodeBalance(TreeNode*& node) {
   node->leftHeight = -1;
   if (node->left != NULL)
      node->leftHeight = node->left->height;
   node->rightHeight = -1;
   if (node->right != NULL)
      node->rightHeight = node->right->height;
   return node->leftHeight - node->rightHeight;
}

void AVLTree:: rotateRight(TreeNode*& node) {
   TreeNode* problemNode = node;
   TreeNode* hookNode = node->left;
     
   if(node->parent == NULL){
      
      if(hookNode->right == NULL){
         hookNode->parent= NULL;
         root = hookNode;
         hookNode->right = problemNode;
         problemNode->parent = hookNode;
         problemNode->left = NULL;
         problemNode->leftHeight = 0;
         hookNode->rightHeight = 0;
      }else{
         hookNode->parent= NULL;
         root = hookNode;
         TreeNode* temp = hookNode->right;
         hookNode->right = problemNode;
         problemNode->parent = hookNode;
         problemNode->left = temp;
         problemNode->leftHeight = 0;
         hookNode->rightHeight = 0;
      }
      
   }
   else{
         if(hookNode->right==NULL){
            hookNode->parent = problemNode->parent;
            if(problemNode->parent->right == problemNode){
              hookNode->parent->right = hookNode; 
            }else{
                hookNode->parent->left = hookNode;
            }
            hookNode->right = problemNode;
            problemNode->parent = hookNode;
            problemNode->left = NULL;
            problemNode->leftHeight = 0;
            hookNode->rightHeight= 0;
         }
         else{
            TreeNode* temp = hookNode->right;
            hookNode->parent = problemNode->parent;
            if(problemNode->parent->right == problemNode){
               hookNode->parent->right = hookNode; 
            }else{
               hookNode->parent->left = hookNode;
            }
            hookNode->right = problemNode;
            problemNode->parent = hookNode;
            problemNode->left = temp;
            temp->parent = problemNode;
            problemNode->leftHeight = 0;
            hookNode->rightHeight = 0;
         }
      }
      UpdateNodeHeight(hookNode->right);
      UpdateNodeHeight(hookNode);
}
void AVLTree:: doublerotateLeft(TreeNode*& node){
   TreeNode* problemNode = node;
   TreeNode* hookNode = node->left;

   problemNode->left = hookNode->right;
   hookNode->right->parent = hookNode->parent;
   hookNode->parent = hookNode->right;
   hookNode->parent->left = hookNode;
   hookNode->right = NULL;
   hookNode->leftHeight = 0;
   hookNode->rightHeight = 0;
   UpdateNodeHeight(hookNode);
   UpdateNodeHeight(hookNode->parent);

}

void AVLTree:: doublerotateRight(TreeNode*& node){
   TreeNode* problemNode = node;
   TreeNode* hookNode = node->right;

   problemNode->right = hookNode->left;
   hookNode->left->parent = hookNode->parent;
   hookNode->parent = hookNode->left;
   hookNode->parent->right = hookNode;
   hookNode->left = NULL;
   hookNode->leftHeight =0;
   hookNode->rightHeight = 0;
   UpdateNodeHeight(hookNode);
   UpdateNodeHeight(hookNode->parent);
}
void AVLTree :: rotateLeft(TreeNode*& node){
   TreeNode* problemNode = node;
   TreeNode* hookNode = node->right;
   if(node->parent == NULL){
      
      if(hookNode->left == NULL){
         hookNode->parent = NULL;
         root = hookNode;
         hookNode->left = problemNode;
         problemNode->parent = hookNode;
         problemNode->right=NULL;
         problemNode->rightHeight = 0;
         hookNode->leftHeight = 0;
      }
      else{
         TreeNode* temp = hookNode->left;
         hookNode->parent = problemNode->parent;
         hookNode->left = problemNode;
         problemNode->parent = hookNode;
         problemNode->right = temp;
         temp->parent = problemNode;
         problemNode->rightHeight = 0;
         hookNode->leftHeight = 0;
      }
   }
   else{ 
      if(hookNode->left == NULL){
         hookNode->parent = problemNode->parent;
         if(problemNode->parent->left == problemNode){
            hookNode->parent->left = hookNode;
         }
         else{
            hookNode->parent->right = hookNode;
         }
         hookNode->left = problemNode;
         problemNode->parent = hookNode;
         problemNode->right=NULL;
         problemNode->rightHeight = 0;
         hookNode->leftHeight = 0;
      }
      else{
         TreeNode* temp = hookNode->left;
         hookNode->parent = problemNode->parent;
         if(problemNode->parent->left == problemNode){
            hookNode->parent->left = hookNode;
         }
         else{
            hookNode->parent->right = hookNode;
         }
         hookNode->left = problemNode;
         problemNode->parent = hookNode;
         problemNode->right = temp;
         temp->parent = problemNode;
         problemNode->rightHeight = 0;
         hookNode->leftHeight = 0;
      }
      }
      UpdateNodeHeight(hookNode->left);
      UpdateNodeHeight(hookNode);
}
 
vector<string> AVLTree::findRange(int k1, int k2){
   range.clear();
   addData(root,k1,k2);
   return range;
}
void AVLTree:: addData(TreeNode* node, int k1, int k2)  
{  
   if (node !=  NULL) {
    addData(node->left,k1,k2);
    if((node->key >= k1) && (node->key <=k2))
      range.push_back(node->value);
    addData(node->right,k1,k2);
  }
   
} 

// destructor
AVLTree::~AVLTree(){
   Destructor(root);
   // TreeNode* node = root;
   // TreeNode* parent ;
   // TreeNode* nullNode;
   // while(node!=NULL){
   //    if(node->left == NULL && node->right == NULL){
   //       parent = node->parent;
   //       delete node;
   //       //node = NULL;
   //       node = parent;
   //    }else if(node->left != NULL){
   //       node = node->left;
   //    }else if(node->right != NULL){
   //       node = node->right;
   //    }
   // }
}

void AVLTree::Destructor(TreeNode* node)
{
    if (node)
    {
        Destructor(node->left);
        Destructor(node->right);
        delete node;
    }
}


