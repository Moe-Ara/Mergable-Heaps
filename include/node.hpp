/**
* @file Node.hpp
* @section Description
* This contains a class 'Node' which has all the necessary operations to create and modify a Node
* These nodes have keys of type integere.
* @author
* Mohamad Arabi
* 
*/

#pragma once
class Node
{
public:
    /// <summary>
    /// Default Constructor
    /// </summary>
    Node();
    /// <summary>
    /// Constructor Used to create a node for the Binomial Heap
    /// </summary>
    /// <param name="c"> Child of the node</param>
    /// <param name="s"> Sibling of the node</param>
    /// <param name="k"> Key of the node</param>
    /// <param name="d"> Degree</param>
    /// <param name="p"> Node's Parent</param>
    Node(Node *c, Node *s, int k, int d, Node* p=nullptr);
    /// <summary>
    /// Constructor to create a node with key k
    /// </summary>
    /// <param name="k">Key</param>
    Node(int k);

    Node(Node *child, Node *left,Node *right, int value, int degree, bool marked=false, Node* parent=nullptr);

/// <summary>
/// Setter for parent
/// </summary>
/// <param name="n">Node to be set as parent of the current node</param>
void setParent(Node* n);
/// <summary>
/// Getter for Parent
/// </summary>
/// <returns>A pointer to the parent node of the current node</returns>
Node* getParent();
/// <summary>
/// Setter for the child of the node
/// </summary>
/// <param name="n"> node n to be set as child to the current node</param>
void setChild(Node* n);
/// <summary>
/// Getter for the child of the node
/// </summary>
/// <returns>A pointer to the child of the current node</returns>
Node* getChild();
/// <summary>
/// Setter for the Sibling
/// </summary>
/// <param name="n">Node n to be set as the sibling of the current node</param>
void setSibling(Node* n);
/// <summary>
/// Getter for the Sibling
/// </summary>
/// <returns>A pointer to the sibling of the current node</returns>
Node* getSibling();
/// <summary>
/// Setter to set the key of the node
/// </summary>
/// <param name="k">Key to be set for the current node</param>
void setKey(int k);
/// <summary>
/// Getter for the key attribute
/// </summary>
/// <returns>the key of the node</returns>
int getKey();
/// <summary>
/// Setter for the degree
/// </summary>
/// <param name="d">degree to be set</param>
void setDegree(int d);
/// <summary>
/// Getter for the degree of the node
/// </summary>
/// <returns>the degree of the node</returns>
int getDegree();
/// <summary>
/// gets the mark of a node (for Fibonacci Heaps)
/// </summary>
/// <returns></returns>
bool getMarked();
/// <summary>
/// returns the node to the right of node x (for Fibonacci Heaps)
/// </summary>
/// <returns></returns>
Node* getRight();
/// <summary>
/// returns the node to the left of node x (for Fibonacci Heaps)
/// </summary>
/// <returns></returns>
Node* getLeft();
/// <summary>
/// Sets the right of node x to a new node n
/// </summary>
/// <param name="n"> Node set as the right node of node x </param>
void setRight(Node*);
/// <summary>
/// Sets the left of node x to a new node n
/// </summary>
/// <param name="n"> Node set as the left node of node x </param>
void setLeft(Node*);
/// <summary>
/// Sets mark of node x
/// </summary>
/// <param name="mark"> a boolean value to either set or reset the mark of a node</param>
void setMarked(bool);


 /// <summary>
 /// Overloading Operator '<' to be able to compare the keys of two nodes without using getters.
 /// It returns true if key of node x is less than key of node a, else it returns false
 /// </summary>
 /// <param name="a"> Node a, whose key is to be compared with the key of node x </param>
 /// <returns></returns>
 bool operator<(const Node& a);
 /// <summary>
/// Overloading Operator '>' to be able to compare the keys of two nodes without using getters
/// It returns true if key of node x is greater than key of node a, else it returns false
/// </summary>
/// <param name="a"> Node a, whose key is to be compared with the key of node x </param>
/// <returns></returns>
 bool operator>(const Node& a);
private:
    /// <summary>
    /// The parent of the node
    /// </summary>
    Node *parent;
    /// <summary>
    /// The child of the node
    /// </summary>
    Node *child;
    /// <summary>
    /// The sibling of the node
    /// </summary>
    Node *sibling;
    /// <summary>
    /// The key of the node
    /// </summary>
    int key;
    /// <summary>
    /// The degree of the node
    /// </summary>
    int degree;
    /// <summary>
    /// Node right to node x
    /// </summary>
    Node* right;
    /// <summary>
    /// Node left to node x
    /// </summary>
    Node* left;
    /// <summary>
    /// Mark of node x
    /// </summary>
    bool marked;
};