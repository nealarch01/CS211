#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstdlib> // rand()
class BSTNode {
friend class BST;
private:
	int data;
    BSTNode *left;
    BSTNode *right;
public:
	BSTNode(int n); // default constructor
};

BSTNode::BSTNode(int n) {
	data = n;
	left = right = nullptr;
}

class BST {
private:
	BSTNode *root;
	void destroy(BSTNode *&node);
	void insertNode(BSTNode *&node, int n);
	void printInOrder(BSTNode *node) const;
	void printPreOrder(BSTNode *node) const;
	void printPostOrder(BSTNode *node) const;
	bool findRecursive(BSTNode *node, int key) const;
	int getNumNodes(BSTNode *node) const;
	int getMaxLength(BSTNode *node) const;
	int findOccurences(BSTNode *node, int key) const;
public:
	BST();
	BST(const BST &b); // copy constructor
	~BST();
	void destroy(); // delete all elements of the tree	
	void insertNode(int n);
	void printInOrder() const; // left -> root -> right	
	void printPreOrder() const; // root -> left -> right
	void printPostOrder() const; // left -> right -> root
	bool findRecursive(int key) const; // return the number of times an element is inside a tree
	int findOccurences(int key) const;
	int getNumNodes() const;
	bool findIterative(int key) const; 
	int getMaxLength() const;
};

BST::BST() {
	root = nullptr;
}

BST::~BST() {
	destroy();
}

BST::BST(const BST &b) {
	
}

void BST::destroy() {
	destroy(root); // pass the root node
}

void BST::destroy(BSTNode *&node) {
	if(node == nullptr) return;
	destroy(node->left);
	destroy(node->right);
	delete node;
	node->left = nullptr;
	node->right = nullptr;
}

void BST::insertNode(int n) {
	insertNode(root, n);	
}

void BST::insertNode(BSTNode *&node, int n) {
	if(node == nullptr) {
		node = new BSTNode(n);
	} else if(n > node->data) {
		insertNode(node->right, n);
	} else if(n < node->data) {
		insertNode(node->left, n);
	} else {  // if dupliate do not add to bst
		return;
	}
}

void BST::printInOrder(BSTNode *node) const {
	if(node == nullptr) return;
	printInOrder(node->left);
	std::cout << node->data << " -> ";
	printInOrder(node->right);
}

void BST::printInOrder() const{
	printInOrder(root);
	std::cout << std::endl;
}

void BST::printPreOrder(BSTNode *node) const{
	if(node == nullptr) return;
	std::cout << node->data << " -> ";
	printPreOrder(node->left);
	printPreOrder(node->right);
}

void BST::printPreOrder() const{
	printPreOrder(root);	
	std::cout << std::endl;
}

void BST::printPostOrder(BSTNode *node) const{
	if(node == nullptr) return;
	printPostOrder(node->left);
	printPostOrder(node->right);
	std::cout << node->data << std::endl;
}

void BST::printPostOrder() const{
	printPreOrder(root);
	std::cout << std::endl;
}

bool BST::findRecursive(BSTNode *node, int key) const {
	if(node == nullptr) return false;
	if(node->data == key) return true;
	if(findRecursive(node->left, key)) return true;
	if(findRecursive(node->right, key)) return true;
	return false;
}

bool BST::findRecursive(int key) const {
	return findRecursive(root, key);
}

bool BST::findIterative(int key) const {
	BSTNode *tempPtr = root;
	while(tempPtr != nullptr) {
		if(tempPtr->data == key) return true;
		else if(tempPtr->data > key) {
			tempPtr = tempPtr->left;
		} else { // if tempPtr->data < key
			tempPtr = tempPtr->right;
		}
	}
	return false;
}

int BST::getNumNodes(BSTNode *node) const {
	if(node == nullptr) return 0;
	return getNumNodes(node->left) + getNumNodes(node->right) + 1;
}

int BST::getNumNodes() const {
	return getNumNodes(root);
}

int BST::getMaxLength(BSTNode *node) const {
	if(node == nullptr) return 0;
	int leftDepth = getMaxLength(node->left);
	int rightDepth = getMaxLength(node->right);
	if(rightDepth > leftDepth) return leftDepth + 1;
	else return rightDepth + 1;	
}

int BST::getMaxLength() const {
	return getMaxLength(root);
}

#endif
