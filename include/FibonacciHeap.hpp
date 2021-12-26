/**
* @file FibonacciHeap.hpp
* @section Description
* This contains a class FibonacciHeap which has all the necessary operations to create and modify a Fibonacci Heap.
* @note
* Please Note that all pseudoCode in this document is take from
* 'Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein.
* Introduction to Algorithms, 3rd Ed., MIT Press, 2009'.
* @author
* Mohamad Arabi
*/
#pragma once
#include "node.hpp"
#include <math.h>
#include <iostream>
class FibonacciHeap{
    public:
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// Constructor to create an empty Fibonacci Heap
    /// </summary>
    FibonacciHeap();
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// Constructor to create a Fibonacci Heap with one node
    /// </summary>
    /// <param name="node"> single node to insert to the newly created Fibonacci Heap</param>
    FibonacciHeap(Node*);
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// Insert Operation to insert a new node n into a Fibonacci Heap H.
    /// It has O(1) actual cost and O(1) amortized cost
    /// </summary>
    /// <param name="n"> Node to insert into the Fibonacci Heap H </param>
    /// <b>Pseudocode </b>
    /// @code
    /// FIB-HEAP-INSERT(H, x)  
    ///  1  degree[x] ← 0    //degree of node x
    ///  2  parent[x] ← NIL  //Parent of node x
    ///  3  child[x] ← NIL   //Child of node x
    ///  4  left[x] ←x       //Node left to node x
    ///  5  right[x] ←x      //Node right to node x
    ///  6  mark[x] ← FALSE  //Mark of x
    ///  7  concatenate the root list containing x with root list H 
    ///  8  if min[H] = NIL or key[x] < key[min[H]]  
    ///  9  then min[H] ←x 10  n[H] ←n[H] + 1    //n[H]= number of nodes in H
    /// @endcode
    void FibonacciHeap_Insert(Node*);
    /// <summary>
        /// <b>Description </b>
        /// <br/>
        /// Operation to Merge two Fibonacci Heap H1 and H2 into one Fibonacci Heap H.
        /// It has O(1) actual cost and O(1) amortized cost
        /// </summary>
        /// <param name="H2"> A Fibonacci Heap H2 to merge with Fibonacci Heap H1 </param>
        /// <returns> Heap H which is the result of merging H1 and H2 together </returns>
        /// <b>Pseudocode </b>
        /// @code  
        /// FIB-HEAP-UNION(H1, H2)
        ///  1  H← MAKE-FIB-HEAP()
        ///  2  min[H] ←min[H1]
        ///  3  concatenate the root list of H2 with the root list of H
        ///  4  if (min[H1] = NIL) or (min[H2] ≠ NIL and min[H2] < min[H1])
        ///  5    then min[H] ←min[H2]
        ///  6  n[H] ←n[H1] + n[H2]     //n[H]= number of nodes in the heap
        ///  7  free the objects H1 and H2
        ///  8  return H
        /// @endcode
    FibonacciHeap* FibonacciHeap_Union(FibonacciHeap*);
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// Operation used to extract the node with the highest priority (node with minimum key), the operation removes it from the Heap and returns it.
    /// It has O(D(n) + t(H)) actual cost, and O(D(n)) amortized cost which is O(lg n)
    /// </summary>
    /// <returns> Node x with the minimum key (node with highest priority) </returns>
    /// <b>Pseudocode </b>
    /// @code
    /// FIB-HEAP-EXTRACT-MIN(H)
    ///   1  z←min[H]
    ///   2  if z≠ NIL
    ///   3     then for each child x of z
    ///   4              do add x to the root list of H
    ///   5                 parent[x] ← NIL
    ///   6          remove z from the root list of H
    ///   7          if z = right[z]
    ///   8             then min[H] ← NIL
    ///   9             else min[H] ← right[z]
    ///  10                  CONSOLIDATE(H)
    ///  11          n[H] ← n[H] - 1
    ///  12  return z
    /// @endcode
    Node* FibonacciHeap_extractMin();
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// Operation used to decrease a key k of a node x.
    /// It has O(c) actual cost, and O(1) amortized cost
    /// </summary>
    /// <param name="node"> The node, whose key we want to decrease</param>
    /// <param name="k"> New key k that we want to assign to node</param>
    /// <b>Pseudocode </b>
    /// @code
    /// FIB-HEAP-DECREASE-KEY(H, x, k)
    ///  1  if k > key[x]
    ///  2     then error "new key is greater than current key"
    ///  3  key[x] ← k
    ///  4  y ← parent[x]
    ///  5  if y≠ NIL and key[x] < key[y]
    ///  6     then CUT(H, x, y)            //CUT() is included in the documentation
    ///  7          CASCADING-CUT(H, y)     //CASCADING-CUT() is included in the documentation
    ///  8  if key[x] < key[min[H]]
    ///  9      then min[H] ←x
    /// @endcode
    void FibonacciHeap_decreaseKey(Node*, int);
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// This operation is used to delete a node n from Heap.
    /// Its amortized cost is O(lg n)
    /// </summary>
    /// <param name="n"> Node n, which we want to delete from H</param>
    /// <b>Pseudocode </b>
    /// @code
    /// FIB-HEAP-DELETE(H, x)
    ///  1 FIB-HEAP-DECREASE-KEY(H, x, -∞)
    ///  2 FIB-HEAP-EXTRACT-MIN(H) 
    /// @endcode
    void FibonacciHeap_delete(Node*);
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// Getter to get the number of nodes n[H]
    /// </summary>
    /// <returns>The number of nodes n in Fibonacci Heap H</returns>
    int getnumberOfNodes();
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// Getter to get the node with the minimum key
    /// </summary>
    /// <returns> The node that has the minimum key</returns>
    Node* getMin();

    private:
    /// <summary>
    /// number of nodes in Heap H, n[H]
    /// </summary>
    int numberOfNodes;
    /// <summary>
    /// pointer to the root in Heap H
    /// </summary>
    Node* root;
    /// <summary>
    /// pointer the Node with the minimum key value
    /// </summary>
    Node *min;
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// This operation is used to link nodes together, it does so by removing a node y from the root list of heap H,
    /// and making it a child of a node x
    /// </summary>
    /// <param name="y">The node y, which will be removed from the root list and assigned as a child to node x</param>
    /// <param name="x"> Node x, which will be the parent of y </param>
    /// <b>Pseudocode </b>
    /// @code
    /// FIB-HEAP-LINK(H, y, x)
    ///  1  remove y from the root list of H
    ///  2  make y a child of x, incrementing degree[x]
    ///  3  mark[y] ← FALSE 
    /// @endcode
    void FibonacciHeap_Link(Node*, Node*);
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// This operation is used by extractMin(). It is used to link roots that has equal degrees
    /// until each root in the rool List of H, has a unique degree. 
    /// </summary>
    /// <b>Pseudocode </b>
    /// @code
    /// CONSOLIDATE(H)
    ///   1 for i ← 0 to D(n[H])     //D(n[H]) Maximum degree of any node in Heap H
    ///   2      do A[i] ← NIL       //A[] buffer we want to use to link the trees together
    ///   3 for each node w in the root list of H
    ///   4      do x ← w
    ///   5         d ← degree[x]
    ///   6         while A[d] ≠ NIL
    ///   7             do y ← A[d]      ▹ Another node with the same degree as x.
    ///   8                if key[x] > key[y]
    ///   9                   then exchange x ↔ y
    ///  10                FIB-HEAP-LINK(H, y, x)
    ///  11                A[d] ← NIL
    ///  12                d←d + 1
    ///  13         A[d] ←x
    ///  14 min[H] ← NIL
    ///  15 for i← 0 to D(n[H])
    ///  16      do if A[i] ≠ NIL
    ///  17            then add A[i] to the root list of H
    ///  18                 if min[H] = NIL or key[A[i]] < key[min[H]]
    ///  19                    then min[H] ←A[i]
    /// @endcode
    void consolidate();
    /// <summary>
    /// <b>Description </b>
    /// <br/>
    /// This operation is used by decreaseKey(). it is used to cut the link between node x and its parent y
    /// making x a new root in the root list
    /// </summary>
    /// <param name="x">Node x, which we want to cut from its parent y</param>
    /// <param name="y">Node y, parent of x</param>
    /// <b>Pseudocode </b>
    /// @code
    /// CUT(H, x, y)
    ///  1 remove x from the child list of y, decrementing degree[y]
    ///  2 add x to the root list of H
    ///  3 parent[x] ← NIL 4 mark[x] ← FALSE
    /// @endcode
    void cut(Node*, Node*);
    /// <summary>
    /// <b>Description</b>
	/// <br/>
    /// This operation is used by decreaseKey(). It cuts y from its parent and makes it a new root, however the parent of y is the new y.
    /// It calls itself recursivly, to cut all children of node n and make them new roots.
    /// It recurses until y is a root or it finds an unmarked node
    /// </summary>
    /// <param name="y">Node y, which we want to cut from its parent parent[y]</param>
    /// <b>Pseudocode </b>
    /// @code
    /// CASCADING-CUT(H, y)
    ///  1 z ← p[y]
    ///  2 if z ≠ NIL 
    ///  3    then if mark[y] = FALSE
    ///  4            then mark[y] ← TRUE
    ///  5            else CUT(H, y, z)
    ///  6                 CASCADING-CUT(H, z)
    /// @endcode
    void cascadingCut( Node*);

};