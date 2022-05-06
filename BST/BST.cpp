#include <assert.h>
#include <cstdlib>  //for rand()
#include <iostream>
#include <fstream> // for ifstream

#include "LL.h"
using namespace std;

typedef int el_t;

class BSTNode {
    friend class BST;
   private:
    BSTNode *right;
    BSTNode *left;
    el_t elem;
   public:
    BSTNode(el_t e) {
      elem = e;
      left = right = NULL;
    } 
};

class BST {
   private:
    BSTNode *root;
    void insertNode(BSTNode*&, el_t);
    void destroy(BSTNode *&ptrNode);
    void inOrderPrint(BSTNode *ptrNode);
    void preOrderPrint(BSTNode *ptrNode);
    void postOrderPrint(BSTNode *ptrNode);
    int getNumNodes(BSTNode *ptrNode);
    bool searchRec(BSTNode *ptrNode, el_t key);
    int getMaxLength(BSTNode *ptrNode);
    int getNumNodesBetween(BSTNode *ptrNode, int min, int max);
    void printNodesBetween(BSTNode *ptrNode, int min, int max);
   public:
    BST();
    ~BST();
    void insertNode(el_t);
    bool search(el_t e);
    void destroy();
    void inOrderPrint();
    void preOrderPrint();
    void postOrderPrint();
    int getNumNodes();
    bool searchRec(el_t key);
    int getMaxLength();
    int getNumNodesBetween(int min, int max);
    void printNodesBetween(int min, int max);
};

BST::BST() { 
  root = NULL;
}

BST::~BST() {
  destroy();
}

void BST::insertNode(el_t e) { 
  insertNode(root, e); 
}

void BST::insertNode(BSTNode *&p, el_t e) {
    if (p == NULL)
        p = new BSTNode(e);
    else if (e < p->elem)
        insertNode(p->left, e);
    else
        insertNode(p->right, e);
}

bool BST::search(el_t e) {
    // Don't use recursion. Use a loop.
    // You want to know how many times it loops to find e.
    // declare a counter.
    int i = 0; // declared outside of loop so we can display the counter at the end of the function 
    BSTNode *tempNode = root;
    for(i = 0; tempNode != NULL && tempNode->elem != e; i++) {
      if(e > tempNode->elem) {
        tempNode = tempNode->right;
      } else {
        tempNode = tempNode->left;
      }
    }
    cout << i << " nodes searched" << endl;
    if(tempNode == NULL) return false;
    return true;
}

/***********************
Pass by pointer ref
************************/
void BST::destroy(BSTNode *&ptrNode) {
  if(ptrNode == NULL) return;
  destroy(ptrNode->left);
  destroy(ptrNode->right);
  delete ptrNode;
  ptrNode = NULL;
}

void BST::destroy() {
  destroy(root);
}

void BST::inOrderPrint() {
  BSTNode *ptrNode = root;
  inOrderPrint(ptrNode);
  cout << endl;
}

void BST::inOrderPrint(BSTNode *ptrNode) {
  if(ptrNode == NULL) return;
    inOrderPrint(ptrNode->left);
    cout << ptrNode->elem << "-->";
    inOrderPrint(ptrNode->right);
}

void BST::preOrderPrint() {
  BSTNode *ptrNode = root;
  preOrderPrint(ptrNode);
  cout << endl;
}

void BST::preOrderPrint(BSTNode *ptrNode) {
  if(ptrNode == NULL) return;
  cout << ptrNode->elem << "-->";
  preOrderPrint(ptrNode->left);
  preOrderPrint(ptrNode->right);  
}

void BST::postOrderPrint() {
  BSTNode *ptrNode = root;
  postOrderPrint(ptrNode);
  cout << endl;
}

void BST::postOrderPrint(BSTNode *ptrNode) {
  if(ptrNode == NULL) return;
  postOrderPrint(ptrNode->left);
  postOrderPrint(ptrNode->right);
  cout << ptrNode->elem << "-->";
}

int BST::getNumNodes() {
  BSTNode *ptrNode = root;
  return getNumNodes(ptrNode);
}

int BST::getNumNodes(BSTNode *ptrNode) {
  if(ptrNode == NULL) return 0;
  return getNumNodes(ptrNode->left) + getNumNodes(ptrNode->right) + 1;
}

bool BST::searchRec(BSTNode *ptrNode, el_t key) {
  if(ptrNode == NULL) return false; // base case
  if(ptrNode->elem == key) return true; 
  bool leftFound = searchRec(ptrNode->left, key); // search left side, check if key exists
  if(leftFound) return true; // if key exists then keep returning true back to root func
  bool rightFound = searchRec(ptrNode->right, key); // if nothing found on the left check right if key exists
  if(rightFound) return true; // if key exists keep returning true back to root func
  return false; // if neither right or left found

 // return searchRec(ptrNode->left, key) + searchRec(ptrNode->right, key); // add booleans true = 1 so if key is found 0 + 1
}

bool BST::searchRec(el_t key) {
  BSTNode *ptrNode = root;
  if(searchRec(ptrNode, key)) return true;
  return false;
}

int BST::getMaxLength() {
  BSTNode *ptrNode = root;
  return getMaxLength(ptrNode);
}

int BST::getMaxLength(BSTNode *ptrNode) {
  if(ptrNode == NULL) return 0;
  // search the entire bst
  int left = getMaxLength(ptrNode->left); // first traverse the entire left side of binary tree
  int right = getMaxLength(ptrNode->right); // traverse entire right side
  if(left > right) return left + 1; // check which side is greater and return that value
  return right + 1;
}

int BST::getNumNodesBetween(int min, int max) {
  BSTNode *ptrNode = root;
  return getNumNodesBetween(ptrNode, min, max);
}

int BST::getNumNodesBetween(BSTNode *ptrNode, int min, int max) {
  if(ptrNode == NULL) return 0; // if at the end
  else if(ptrNode->elem < min || ptrNode->elem > max) // if element is not between
    return getNumNodesBetween(ptrNode->left, min, max) + getNumNodesBetween(ptrNode->right, min, max) + 0; 
  return getNumNodesBetween(ptrNode->left, min, max) + getNumNodesBetween(ptrNode->right, min, max) + 1; // number is in between
}

void BST::printNodesBetween(int min, int max) {
  BSTNode *ptrNode = root;
  printNodesBetween(ptrNode, min, max);
}

void BST::printNodesBetween(BSTNode *ptrNode, int min, int max) {
  if(ptrNode == NULL) return;
  printNodesBetween(ptrNode->left, min, max);
  if(ptrNode->elem > min && ptrNode->elem < max) {
    cout << ptrNode->elem << "-->";
  }
  printNodesBetween(ptrNode->right, min, max);
}


int main() {
  ifstream fin;
  fin.open("bst.dat");
  if(!fin.is_open()) {
    cout << "bst.dat not found" << endl;
    return 0;
  }
  BST b1;
  b1.insertNode(8);
  b1.insertNode(5);
  b1.insertNode(3);
  b1.insertNode(9);
  b1.insertNode(14);
  b1.insertNode(2);
  b1.insertNode(1);
  b1.inOrderPrint();
  b1.destroy();
  b1.insertNode(2);
  b1.postOrderPrint();
  return 0;
}
