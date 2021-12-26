#include "../include/BinomialHeap.hpp"
#include <iostream>

//Default Constructor
BinomialHeap::BinomialHeap() {
	 root = nullptr;
	 min = nullptr;
}
//getter for the root
Node* BinomialHeap::getRoot() {
	return this-> root;
}
//This Functoin
void BinomialHeap::Binomial_Link(Node* n1, Node* n2) {
	//check if degrees are not equal
	if (n1->getDegree() != n2->getDegree() || n1->getKey() < n2->getKey()) return;
		//make the second node the parent of the first node
		n1->setParent(n2);
		//Leftmost child of the second node is now the sibling of the first node
		n1->setSibling(n2->getChild());
		//make the first node the child of the second node 
		n2->setChild(n1);
		//increment degree of the second node (the new root)
		n2->setDegree(n2->getDegree() + 1);

}

Node* BinomialHeap::Binomial_Merge(BinomialHeap* h1, BinomialHeap* h2) {

	Node* result = new Node();
	Node* end = result;

	Node* h1_root = h1->root;
	Node* h2_root = h2->root;
	if (h1_root == nullptr) return h2_root;
	if (h2_root == nullptr) return h1_root;

	while (h1_root!=nullptr || h2_root!=nullptr) {
		if (h1_root == nullptr) {
			end->setSibling(h2_root);
			end = end->getSibling();
			h2_root = h2_root->getSibling();
		}
		else if (h2_root == nullptr) {
			end->setSibling(h1_root);
			end = end->getSibling();
			h1_root = h1_root->getSibling();
		}
		else{
			if (h1_root->getDegree() < h2_root->getDegree()) {
				end->setSibling(h1_root);
				end = end->getSibling();
				h1_root = h1_root->getSibling();
			}else{
				end->setSibling(h2_root);
				end = end->getSibling();
				h2_root = h2_root->getSibling();
			}
		}

	}
	return (result->getSibling());
}

Node* BinomialHeap::BinomialHeap_findMin() {
	Node* head = this->root;
	if (head->getSibling() == nullptr)
	{
		return head;
	}
	Node* temp = head;
	Node* minNode = temp;
	int min = temp->getKey();
	while (temp->getSibling() != nullptr)
	{
		temp = temp->getSibling();
		if (min > temp->getKey()) {
			min = temp->getKey();
			minNode = temp;
		}
	}
	return minNode;
}

void BinomialHeap::BinomialHeap_Insert(Node* node) {

	//Create a new Binomial heap temp
	BinomialHeap* temp=new BinomialHeap();
	//Set its root to the inserted node
	temp->root = node;
	BinomialHeap_Union(temp);

	}

void BinomialHeap::BinomialHeap_Union(BinomialHeap* h2) {
	BinomialHeap* temp = new BinomialHeap();
	temp->root = Binomial_Merge(this, h2);

	if (temp->root==nullptr){
		this->root = nullptr;
		this->min = nullptr;
		return;
	}
	Node* prev_x = nullptr;
	Node* x = temp->root;
	Node* next_x = x->getSibling();

	while (next_x != nullptr) {
		if (x->getDegree() != next_x->getDegree() || (next_x->getSibling() != nullptr && next_x->getSibling()->getDegree()==x->getDegree())) {
			prev_x = x;
			x = next_x;
		}
		else if (x->getKey() <= next_x->getKey()) {
			x->setSibling(next_x->getSibling());
			Binomial_Link(next_x, x);
		}
		else  {
			if (prev_x == nullptr) temp->root = next_x;
			else prev_x->setSibling(next_x);
			
			Binomial_Link(x, next_x);
			x = next_x;
		}
		next_x = x->getSibling();
	}
	//This will make our current heap the newly merged heap; h1 = h1 U h2
	this->root = temp->root;
	this->min = temp->root;
	Node* tmp = this->root;

	//Searching for min, in the new union heap, and setting it to that node
	while (tmp != nullptr)
	{
		if (tmp->getKey() < this->min->getKey()) this->min = tmp;
		tmp = tmp->getSibling();
	}
	//this->min = temp->BinomialHeap_findMin();

}

void BinomialHeap::BinomialHeap_decreaseKey(Node* node, int key) {
	//if (node->getKey() <= key) return;
	node->setKey( key) ;
	Node* y = node;
	Node* z = y->getParent();
	while (z != nullptr && y->getKey() < z->getKey()) {
	int t = y->getKey();
	y->setKey(z->getKey());
	z->setKey(t);
	y = z;
	z = y->getParent();
	}
	//this->min = BinomialHeap_findMin();
	if (y->getKey() < this->min->getKey())this->min= y;
}

void BinomialHeap::BinomialHeap_deleteNode(Node* n) {
	BinomialHeap_decreaseKey(n, min->getKey()-1);
	BinomialHeap_extractMin();
}

Node* BinomialHeap::BinomialHeap_extractMin(){	
	//this-> min= this->BinomialHeap_findMin();
	Node* minNode = this->min;
	//delete minNOde from the list of root
	Node* prev = nullptr;
	Node* x = this->root;
	//get the sibling of min
	while (x != minNode) {
		prev = x;
		x = x->getSibling();
	}
	 
	if (prev == nullptr) this->root = x->getSibling();
	else prev->setSibling(x->getSibling());
	//reverse the list of min's children
	Node* revChd = nullptr;
	Node* tmp = minNode->getChild();

	while (tmp != nullptr) {
		Node* next = tmp->getSibling();
		tmp->setSibling(revChd);
		revChd = tmp;
		tmp = next;
	}
	//merge heaps together
	BinomialHeap* tempHeap = new BinomialHeap();
	tempHeap->root = revChd;
	this->BinomialHeap_Union(tempHeap);
	//deleting temp heap
	//tempHeap->~BinomialHeap();
	//returning min
	return minNode;

}


