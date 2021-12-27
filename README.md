<div id="top"></div>


# Mergable Heaps
<!-- TABLE OF CONTENTS -->
  ## Table of Contents
<detail>  
<ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
      </ul>
    </li>
    <li><a href="#documentation">Documentation</a>
     <ul>
     <li><a href="#pseudocode-for-heap-operations">Pseudocode</a></li>
     </ul>
     <ul>
     <ul>
     <li><a href="#binomial-heap-operations">Binomial Heap Operations</a></li>
      </ul>
     </ul>
     <ul>
     <ul>
     <li><a href="#fibonacci-heap-operations">Fibonacci Heap Operations</a></li>
      </ul>
     </ul>
      </li>
    <li><a href="#run-project">Run project</a></li>
  </ol>
</detail>

---

<!-- ABOUT THE PROJECT -->
## About The Project

This project is an implementation of common mergable heaps, the ___Fibonacci Heap___ and the ___Binomial Heap___. In the directory ___./src/___ you can find source files that are used in the project, and in ___./include/___ you can find the header files fully commented. In ___./tests/___ you can find a Test1.cpp that includes multiple test cases in written using <a href="https://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html">___Boost.test___</a>.
<br/>
I recommend using Visual Studio to open the project files since it includes all features necassary to run, debug and test the project.

The following is a table comparing efficient mergable heaps like Binomial heaps against the unefficient but commonly used Binary Heap:

| Operation     | Binomial Heap     | Fibonacci Heap| Binary Heap
|--------------|-----------|------------|------------|
| Build-Heap    | O(1)      | O(1)        | O(1)        |
| Insert        | O(log n)  | O(1)       | O(log n)        |
| Union         | O(log n)  | O(1)        | O(n)        |
| Extract-Min   | O(log n)  | O(log n)       | O(log n)        |
| Decrease-Key  | O(log n)  | O(1)        | O(log n)        |
| Delete-Node   | O(log n)  | O(log n)       | O(log n)        |

<p align="right">(<a href="#top">back to top</a>)</p>

---

<!-- GETTING STARTED -->
## Getting Started

First clone the repository:

  ```sh
  git clone https://github.com/Moe-Ara/Mergable-Heaps.git
  ```
### Prerequisites

For running the test cases, you might want to install the <a href="https://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html">___Boost.test___</a> framework. You also need a C/C++ compiler such as<a href="https://www.mingw-w64.org/"> ___Mingw___</a> compiler.
</br>
For documentation purposes you need <a href="https://www.doxygen.nl/index.html">___Doxygen___</a>.
* <a href="https://www.boost.org/users/download/">Install Boost</a>
* <a href="https://www.mingw-w64.org/">Install MinGw compiler</a>
* <a href="https://www.doxygen.nl/download.html">Install Doxygen</a>

---
<!-- Documentation -->
## Documentation

To read the documentation, you can open the ___index.html___ in directory ___./Documentatio/html/___ in any web browser. There are some pdf files in the directory ___./Documentatio/pdf___ that have documentation for the classes used in the project. 
To generate your own documentation files, use __DoxyGen__ as follows:
```sh
  doxygen Doxyfile
```
or use ___DoxyWizard___ to generate your own Doxygen configuration file.
The documentation files include ___PseudoCode___  for each and every operation

This project contains three fully commented header files:

- BinomialHeap.hpp 
  - This contains a class BinomialHeap which has all the necessary operations to create and modify a binomial heap 
- FibonacciHeap.hpp
  - This contains a class FibonacciHeap which has all the necessary operations to create and modify a Fibonacci Heap.
- Node.hpp
  - This contains a class 'Node' which has all the necessary operations to create and modify a Node These nodes have keys of type integere. 

### Note: 
> Please note that all ___PseudoCode___ in this project ( except for pseudocode of _Binomial-Merge_ )  is taken from 'Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. Introduction to Algorithms, 3rd Ed., MIT Press, 2009'.

## Pseudocode for Heap operations 

### **Binomial Heap Operations**

- ___Binomial Insert___
```
BINOMIAL-HEAP-INSERT(H, x)
 1  H′← MAKE-BINOMIAL-HEAP()	//create a new Binomial Heap
 2  p[x] ← NIL					//p[x] is the parent of x
 3  child[x] ← NIL				//child[x] is the child of x
 4  sibling[x] ← NIL
 5  degree[x] ← 0
 6  head[H′] ← x
 7  H← BINOMIAL-HEAP-UNION(H, H′) 
```
- ___Binomial Union___
```
BINOMIAL-HEAP-UNION(H1, H2)
 1  H ← MAKE-BINOMIAL-HEAP()
 2  head[H] ← BINOMIAL-HEAP-MERGE(H1, H2)		@see Binomial_Merge(BinomialHeap*, BinomialHeap*)
 3  free the objects H1 and H2 but not the lists they point to 
 4  if head[H] = NIL
 5     then return H 
 6  prev-x ← NIL 
 7  x ← head[H]
 8  next-x ← sibling[x]
 9  while next-x ≠ NIL
10      do if (degree[x] ≠ degree[next-x]) or (sibling[next-x] ≠ NIL and degree[sibling[next-x]] = degree[x])
11            then prev-x ← x 
12                 x ← next-x 
13            else if key[x] ≤ key[next-x]
14                    then sibling[x] ← sibling[next-x]          
15                         BINOMIAL-LINK(next-x, x)    @see Binomial_Link(Node*,Node*);          
16                    else if prev-x = NIL                        
17                            then head[H] ←next-x▹ Case 4
18                            else sibling[prev-x] ← next-x
19                         BINOMIAL-LINK(x, next-x)               
20                         x ← next-x
21         next-x ← sibling[x]
22  return H
______________________________________________

BINOMIAL-LINK(y, z)
 1  p[y] ← z
 2  sibling[y] ← child[z]
 3  child[z] ← y
 4  degree[z] ← degree[z] + 1
______________________________________________

BINOMIAL-Merge(H, H`)
 1	a = head[H1]
 2	b = head[H2]
 3	head[H1] = Min - Degree(a, b)
 4	if head[H1] = NIL
 5		return
 6	if head[H1] = b
 7		then b = a
 8	a = head[H1]
 9	while b <> NIL
10		do if sibling[a] = NIL
11			then sibling[a] = b
12				return
13		else if degree[sibling[a]] < degree[b]
14				then a = sibling[a]
15		else c = sibling[b]
16				sibling[b] = sibling[a]
17				sibling[a] = b
18				a = sibling[a]
19				b = c 
```
- ___Binomial extractMin___
```
BINOMIAL-HEAP-EXTRACT-MIN(H)
 1  find the root x with the minimum key in the root list of H, and remove x from the root list of H @see BinomialHeap_findMin()
 2  H′ ← MAKE-BINOMIAL-HEAP()
 3  reverse the order of the linked list of x's children, and set head[H′] to point to the head of the resulting list
 4  H ← BINOMIAL-HEAP-UNION(H, H′)
 5  return x
```
- ___Binomial decreaseKey___
```
BINOMIAL-HEAP-DECREASE-KEY(H, x, k)
 1 if k > key[x]
 2    then error "new key is greater than current key"
 3 key[x] ← k
 4 y ← x
 5 z ← p[y]
 6 while z≠ NIL and key[y] < key[z]
 7     do exchange key[y] ↔ key[z]
 8        ▸ If y and z have satellite fields, exchange them, too.
 9        y ← z
 10        z ← p[y]
```
- ___Binomial delete___
```
BINOMIAL-HEAP-DELETE(H, x)
 1  BINOMIAL-HEAP-DECREASE-KEY(H, x, -∞)
 2  BINOMIAL-HEAP-EXTRACT-MIN(H)
```
- ___Binomial findMin___
```
BINOMIAL-HEAP-MINIMUM(H)
 1  y ← NIL
 2  x ← head[H]
 3  min ← ∞
 4  while x ≠ NIL
 5     do if key[x] < min
 6           then min ← key[x]
 7                y ← x 
 8         x ← sibling[x]
 9  return y
```
</br>

### **Fibonacci Heap Operations**

- ___Fibonacci Insert___
```
     FIB-HEAP-INSERT(H, x)  
      1  degree[x] ← 0    //degree of node x
      2  parent[x] ← NIL  //Parent of node x
      3  child[x] ← NIL   //Child of node x
      4  left[x] ←x       //Node left to node x
      5  right[x] ←x      //Node right to node x
      6  mark[x] ← FALSE  //Mark of x
      7  concatenate the root list containing x with root list H 
      8  if min[H] = NIL or key[x] < key[min[H]]  
      9  then min[H] ←x 10  n[H] ←n[H] + 1    //n[H]= number of nodes in H
```
- ___Fibonacci Union___
```  
    FIB-HEAP-UNION(H1, H2)
     1  H← MAKE-FIB-HEAP()
     2  min[H] ←min[H1]
     3  concatenate the root list of H2 with the root list of H
     4  if (min[H1] = NIL) or (min[H2] ≠ NIL and min[H2] < min[H1])
     5    then min[H] ←min[H2]
     6  n[H] ←n[H1] + n[H2]     //n[H]= number of nodes in the heap
     7  free the objects H1 and H2
     8  return H
```
- ___Fibonacci extractMin___
```  
 FIB-HEAP-EXTRACT-MIN(H)
  1  z←min[H]
  2  if z≠ NIL
  3     then for each child x of z
  4              do add x to the root list of H
  5                 parent[x] ← NIL
  6          remove z from the root list of H
  7          if z = right[z]
  8             then min[H] ← NIL
  9             else min[H] ← right[z]
 10                  CONSOLIDATE(H)
 11          n[H] ← n[H] - 1
 12  return z
______________________________________________

CONSOLIDATE(H)
  1 for i ← 0 to D(n[H])     //D(n[H]) Maximum degree of any node in Heap H
  2      do A[i] ← NIL       //A[] buffer we want to use to link the trees together
  3 for each node w in the root list of H
  4      do x ← w
  5         d ← degree[x]
  6         while A[d] ≠ NIL
  7             do y ← A[d]      ▹ Another node with the same degree as x.
  8                if key[x] > key[y]
  9                   then exchange x ↔ y
 10                FIB-HEAP-LINK(H, y, x)
 11                A[d] ← NIL
 12                d←d + 1
 13         A[d] ←x
 14 min[H] ← NIL
 15 for i← 0 to D(n[H])
 16      do if A[i] ≠ NIL
 17            then add A[i] to the root list of H
 18                 if min[H] = NIL or key[A[i]] < key[min[H]]
 19                    then min[H] ←A[i]
```
- ___Fibonacci decreaseKey___
```  
FIB-HEAP-DECREASE-KEY(H, x, k)
 1  if k > key[x]
 2     then error "new key is greater than current key"
 3  key[x] ← k
 4  y ← parent[x]
 5  if y≠ NIL and key[x] < key[y]
 6     then CUT(H, x, y)            //CUT() is included in the documentation
 7          CASCADING-CUT(H, y)     //CASCADING-CUT() is included in the documentation
 8  if key[x] < key[min[H]]
 9      then min[H] ←x
______________________________________________

CUT(H, x, y)
 1 remove x from the child list of y, decrementing degree[y]
 2 add x to the root list of H
 3 parent[x] ← NIL 4 mark[x] ← FALSE
______________________________________________

CASCADING-CUT(H, y)
 1 z ← p[y]
 2 if z ≠ NIL 
 3    then if mark[y] = FALSE
 4            then mark[y] ← TRUE
 5            else CUT(H, y, z)
 6                 CASCADING-CUT(H, z)
```
- ___Fibonacci delete___
```  
FIB-HEAP-DELETE(H, x)
 1 FIB-HEAP-DECREASE-KEY(H, x, -∞)
 2 FIB-HEAP-EXTRACT-MIN(H) 
```
<p align="right">(<a href="#top">back to top</a>)</p>

---
<!-- Run Project -->
## Run Project
To run the project, use the Makefile:
```sh
  make
```
  And then run ___output.exe___
```sh
  ./output.exe
```
### 1. Result of running ___output.exe___ (Each operation is run 1000 000 times):

<img src=".\ScreenShots\output.jpg" height=50% width=50%>

### 2. Result of running ___Test1.cpp___ in visual studio (Each operation is run 10 000 times):

<img src=".\ScreenShots\testCases.jpg" height=50% width=50%>

<p align="right">(<a href="#top">back to top</a>)</p>