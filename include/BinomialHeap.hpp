/**
* @file BinomialHeap.hpp
* @section Description
* This contains a class BinomialHeap which has all the necessary operations to create and modify a binomial heap
* @note
* Please Note that all pseudoCode (except for pseudocode of Binomial-Merge()) in this document is take from
* 'Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein.
* Introduction to Algorithms, 3rd Ed., MIT Press, 2009'.
* @author
* Mohamad Arabi
*/
#include "node.hpp"
//#include <utility>
class BinomialHeap {
private:
	/// <summary>
	/// Pointer to the Root of the heap
	/// </summary>
	Node* root;
	/// <summary>
	/// Pointer to the Minimum Node in the heap; this is not necessary to define as we can use findMin
	/// </summary>
	Node* min;
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// Binomial_Link function is used to link binomial trees of the same degree together;
	/// it does so by setting the node with greatest key as a child to the other node.
	/// This operation has O(1) runtime complexity
	/// </summary>
	/// <param name="1st Node"> The node with greatest Key</param>
	/// <param name="2nd Node"> The node with least Key</param>
	/// <b>Pseudocode </b>
	/// @code
	/// BINOMIAL-LINK(y, z)
	///  1  p[y] ← z
	///  2  sibling[y] ← child[z]
	///  3  child[z] ← y
	///  4  degree[z] ← degree[z] + 1
	/// @endcode
	void Binomial_Link(Node*,Node*);
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// Binomial_Merge is used to merge the root lists of two binomial heaps h1 and h2;
	/// However it does it without linking the trees together, and it orderes the root list in ascending order,
	/// depending on the degree of each node.
	/// This operation is executed in O(lg n) time
	/// </summary>
	/// <param name="1st Heap">the first Binomial Heap</param>
	/// <param name="2nd Heap">the second Binomial Heap</param>
	/// <returns>Heap with root list that is the result of merging the root lists of two Binomial Heaps H1 and H2</returns>
	/// <b>Pseudocode </b>
	/// @code
	/// BINOMIAL-Merge(H, H`)
	///  1	a = head[H1]
	///	 2	b = head[H2]
	///	 3	head[H1] = Min - Degree(a, b)
	///	 4	if head[H1] = NIL
	///	 5		return
	///	 6	if head[H1] = b
	///	 7		then b = a
	///	 8	a = head[H1]
	///	 9	while b <> NIL
	///	10		do if sibling[a] = NIL
	///	11			then sibling[a] = b
	///	12				return
	///	13		else if degree[sibling[a]] < degree[b]
	///	14				then a = sibling[a]
	///	15		else c = sibling[b]
	///	16				sibling[b] = sibling[a]
	/// 17				sibling[a] = b
	///	18				a = sibling[a]
	///	19				b = c 
	/// @endcode
	Node* Binomial_Merge(BinomialHeap*, BinomialHeap*);

public:
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// Default Constructor, used to create a new empty Binomial Heap H.
	/// This operation takes O(1) time
	/// </summary>
	BinomialHeap();
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// The BinomialHeap_Insert is used to insert a node n into a binomial heap H 
	/// This operation has O(lg n) cost
	/// </summary>
	/// <param name="n"> Node to be inserted </param>
	/// <b>Pseudocode </b>
    /// @code
	/// BINOMIAL-HEAP-INSERT(H, x)
	///  1  H′← MAKE-BINOMIAL-HEAP()	//create a new Binomial Heap
	///  2  p[x] ← NIL					//p[x] is the parent of x
	///  3  child[x] ← NIL				//child[x] is the child of x
	///  4  sibling[x] ← NIL
	///  5  degree[x] ← 0
	///  6  head[H′] ← x
	///  7  H← BINOMIAL-HEAP-UNION(H, H′) 
    /// @endcode
	void BinomialHeap_Insert(Node*);
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// BinomialHeap_Union is used to meld binomial heaps together and keeping the binomial heap priorities
	/// It does so by creting a new heap that is the result of using Binomial_Merge(h1,h2);
	/// after that it starts linking the trees depending on degree and keys to keep the min-heap property.
	/// The result is H= H1 U H2.
	/// This operation has O(lg n) cost
	/// </summary>
	/// <param name="Heap"> A binomial Heap to meld with the current heap</param>
	/// <b>Pseudocode </b>
	/// @code
	/// BINOMIAL-HEAP-UNION(H1, H2)
	///  1  H ← MAKE-BINOMIAL-HEAP()
	///  2  head[H] ← BINOMIAL-HEAP-MERGE(H1, H2)		@see Binomial_Merge(BinomialHeap*, BinomialHeap*)
	///  3  free the objects H1 and H2 but not the lists they point to 
	///  4  if head[H] = NIL
	///  5     then return H 
	///  6  prev-x ← NIL 
	///  7  x ← head[H]
	///  8  next-x ← sibling[x]
	///  9  while next-x ≠ NIL
	/// 10      do if (degree[x] ≠ degree[next-x]) or (sibling[next-x] ≠ NIL and degree[sibling[next-x]] = degree[x])
	/// 11            then prev-x ← x 
	/// 12                 x ← next-x 
	/// 13            else if key[x] ≤ key[next-x]
	/// 14                    then sibling[x] ← sibling[next-x]          
	/// 15                         BINOMIAL-LINK(next-x, x)    @see Binomial_Link(Node*,Node*);          
	/// 16                    else if prev-x = NIL                        
	/// 17                            then head[H] ←next-x▹ Case 4
	/// 18                            else sibling[prev-x] ← next-x
	/// 19                         BINOMIAL-LINK(x, next-x)               
	/// 20                         x ← next-x
	/// 21         next-x ← sibling[x]
	/// 22  return H
	/// @endcode
	void BinomialHeap_Union(BinomialHeap*);
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// BinomialHeap_extractMin is used to return the node n with the minimum key k; it deletes it from the heap H.
	/// It reverses the children of the extracted node and puts them inside a new heap H`
	/// We then call BinomialHeap_Union to meld H and H` together.
	/// This operation takes O(lg n) time
	/// </summary>
	/// <returns>
	/// The Node n with the minimum Key k
	/// </returns>
		/// <b>Pseudocode </b>
	/// @code
	/// BINOMIAL-HEAP-EXTRACT-MIN(H)
	///  1  find the root x with the minimum key in the root list of H, and remove x from the root list of H @see BinomialHeap_findMin()
	///  2  H′ ← MAKE-BINOMIAL-HEAP()
	///  3  reverse the order of the linked list of x's children, and set head[H′] to point to the head of the resulting list
	///  4  H ← BINOMIAL-HEAP-UNION(H, H′)
	///  5  return x
	/// @endcode
	Node* BinomialHeap_extractMin();
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// BinomialHeap_decreaseKey is used to decrese a key k of a node n;
	/// It checks if the new key k` is less than the actual key k of node n
	/// then it 'sifts' it down; i.e it swaps the node n with its child if it has a child that has key k less than that of node n
	/// This operation has O(lg n) cost
	/// </summary>
	/// <param name="n">the Node n, whose key we want to decrese</param>
	/// <param name="k"> new key that we want to assign to node n</param>
	/// <b>Pseudocode </b>
	/// @code
	/// BINOMIAL-HEAP-DECREASE-KEY(H, x, k)
	///   1 if k > key[x]
	///   2    then error "new key is greater than current key"
	///   3 key[x] ← k
	///   4 y ← x
	///   5 z ← p[y]
	///   6 while z≠ NIL and key[y] < key[z]
	///   7     do exchange key[y] ↔ key[z]
	///   8        ▸ If y and z have satellite fields, exchange them, too.
	///   9        y ← z
	///  10        z ← p[y]
	/// @endcode
	void BinomialHeap_decreaseKey(Node*, int);
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// BinomialHeap_deleteNode deletes a node n from heap H;
	/// It does so by simply calling BinomialHeap_decreaseKey and make it the node with the minimum key,
	/// and then it calls BinomialHeap_extractMin to take it out
	/// This Operation takes O(lg n) time
	/// </summary>
	/// <param name="n">Node to be deleted</param>
	/// <b>Pseudocode </b>
	/// @code
	/// BINOMIAL-HEAP-DELETE(H, x)
	///  1  BINOMIAL-HEAP-DECREASE-KEY(H, x, -∞)
	///  2  BINOMIAL-HEAP-EXTRACT-MIN(H)
	/// @endcode
	void BinomialHeap_deleteNode(Node*);
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// BinomialHeap_findMin() is used to find the node n with the minimum key k;
	/// This Operation takes O(lg n) time
	/// </summary>
	/// <returns>The Node n with the minimum Key k</returns>
	/// <b>Pseudocode </b>
	/// @code
	/// BINOMIAL-HEAP-MINIMUM(H)
	///  1  y ← NIL
	///  2  x ← head[H]
	///  3  min ← ∞
	///  4  while x ≠ NIL
	///  5     do if key[x] < min
	///  6           then min ← key[x]
	///  7                y ← x 
	///  8         x ← sibling[x]
	///  9  return y
	/// @endcode
	Node* BinomialHeap_findMin();
	/// <summary>
	/// <b>Description</b>
	/// <br/>
	/// getter for the root of the heap
	/// </summary>
	/// <returns>Root r of Heap H </returns>
	Node* getRoot();

};

