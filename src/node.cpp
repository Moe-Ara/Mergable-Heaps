
#include "../include/node.hpp"
Node::Node()
{
    parent = nullptr;
    child = nullptr;
    sibling = nullptr;
    this->key = 0;
    degree = 0;
} // default constructor

// constructor
Node::Node(Node *c, Node *s, int k, int d, Node *p /*=nullptr*/)
{
    left = right = nullptr;
    parent = p;
    child = c;
    sibling = s;
    key = k;
    degree = d;
}
Node::Node(int k)
{
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    child = nullptr;
    sibling = nullptr;
    this->key = k;
    degree = 0;
}
Node::Node(Node *child, Node *left,Node *right, int value, int degree, bool marked /*=false*/, Node* parent /*=nullptr*/){
    this->child=child;
    this->left=left;
    this->right=right;
    this->key=value;
    this->degree=degree;
    this->marked=marked;
    this->parent= parent;
}
// Getters
Node *Node::getChild()
{
    return this->child;
}
Node *Node::getSibling()
{
    return this->sibling;
}
Node *Node::getParent()
{
    return this->parent;
}

int Node::getDegree()
{
    return this->degree;
}
int Node::getKey()
{
    return this->key;
}
bool Node::getMarked()
{
    return this->marked;
}
Node *Node::getLeft()
{
    return this->left;
}
Node *Node::getRight()
{
    return this->right;
}
// setters
void Node::setChild(Node *n)
{
    child = n;
}
void Node::setSibling(Node *n)
{
    sibling = n;
}
void Node::setParent(Node *n)
{
    parent = n;
}

void Node::setKey(int k)
{
    key = k;
}

void Node::setDegree(int k)
{
    degree = k;
}
void Node::setLeft(Node *n)
{
    left = n;
}
void Node::setRight(Node *n)
{
    right = n;
}
void Node::setMarked(bool m)
{
    marked = m;
}

bool Node::operator<(const Node& a){
    return key < a.key;
}
bool Node::operator>(const Node& a){
    return key > a.key;
}