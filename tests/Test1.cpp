#define BOOST_TEST_MODULE TestUnit
//#define BOOST_TEST_MODULE FibonacciHeap
#include <boost/test/included/unit_test.hpp>
#include "../include/node.hpp"
#include "../include/BinomialHeap.hpp"
#include "../include/FibonacciHeap.hpp"
// #include <time.h>
// #include <chrono>
using namespace boost;
struct prep{
public:
	int n = 10; //number of times each test should be executed
	Node* x = new Node(80);
	Node* y = new Node(100);
	BinomialHeap* binomialHeap1;
	BinomialHeap* binomialHeap2;
	FibonacciHeap* fibonacciHeap1;
	FibonacciHeap* fibonacciHeap2;
	prep(){
		binomialHeap1 = new BinomialHeap();
		binomialHeap2 = new BinomialHeap();
		fibonacciHeap1 = new FibonacciHeap();
		fibonacciHeap2 = new FibonacciHeap();
		//fill Heaps
		{
			int i = 0;
			do {
				binomialHeap1->BinomialHeap_Insert(new Node(i));
				binomialHeap2->BinomialHeap_Insert(new Node(i));
				fibonacciHeap1->FibonacciHeap_Insert(new Node(i));
				fibonacciHeap2->FibonacciHeap_Insert(new Node(i));
				i++;
			} while (i < n);
		}
	};

};
BOOST_AUTO_TEST_SUITE(BinomialHeap_Insert)


	BOOST_AUTO_TEST_CASE(Build_Binomial_Heap)
	{
		prep p;
		for (int i = 0; i < p.n; i++) {
			BinomialHeap* binomialHeap = new BinomialHeap();
		}
	}
	BOOST_AUTO_TEST_CASE(BinomialHeap_Insert) {
		prep p;
		//insert first node incase heap is empty
		p.binomialHeap1->BinomialHeap_Insert(new Node(p.n));
		//get degree of root
		int oldDegreeOfRoot=p.binomialHeap1->getRoot()->getDegree();
		//insert n times
		for (int i = 0; i < p.n; i++) {
			p.binomialHeap1->BinomialHeap_Insert(new Node(i));
		}
		p.binomialHeap1->BinomialHeap_Insert(new Node(p.n));
		int newDegreeOfRoot = p.binomialHeap1->getRoot()->getDegree();
		BOOST_ASSERT(oldDegreeOfRoot!=newDegreeOfRoot);
	}

	BOOST_AUTO_TEST_CASE(BinomialHeap_Union) {
		prep p;
		int oldDegreeOfRoot = p.binomialHeap1->getRoot()->getDegree();
		for (int i = 0; i < p.n; i++) {
			p.binomialHeap1->BinomialHeap_Union(new BinomialHeap(new Node(i)));
		}
		int newDegreeOfRoot = p.binomialHeap1->getRoot()->getDegree();
		BOOST_ASSERT(newDegreeOfRoot != oldDegreeOfRoot);
	}

	BOOST_AUTO_TEST_CASE(BinomialHeap_extractMin) {
		prep p;
		p.binomialHeap1->BinomialHeap_Insert(p.x);
		Node* n;
		Node* t;
		for (int i = 0; i < p.n; i++) {
			n = p.binomialHeap1->getRoot();
		t= p.binomialHeap1->BinomialHeap_extractMin();
		}
		BOOST_ASSERT(t==n);
		BOOST_ASSERT((!(p.binomialHeap1->getRoot())|| (p.binomialHeap1->getRoot() != t)));
	}

	BOOST_AUTO_TEST_CASE(BinomialHeap_decreaseKey) {
		prep p;
		p.binomialHeap1->BinomialHeap_Insert(new Node(0));
		int oldKey=p.binomialHeap1->getRoot()->getKey();
		for (int i = 0; i <= p.n; i++) {
		p.binomialHeap1->BinomialHeap_decreaseKey(p.binomialHeap1->getRoot(),oldKey-i);
		}
		BOOST_ASSERT((p.binomialHeap1->getRoot()->getKey() != oldKey));
	}

	BOOST_AUTO_TEST_CASE(BinomialHeap_delete) {
		prep p;
		for (int i = 0; i < p.n; i++) {
			p.binomialHeap1->BinomialHeap_deleteNode(p.binomialHeap1->getRoot());
		}
		BOOST_ASSERT((p.binomialHeap1->getRoot()== nullptr));
	}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(Fibonacci_Heap_Test)
	BOOST_AUTO_TEST_CASE(Build_Fibonacci_Heap) {
		prep p;
		for (int i = 0; i < p.n; i++) {
			FibonacciHeap* fibonacciHeap = new FibonacciHeap();
		}
	}
	BOOST_AUTO_TEST_CASE(FibonacciHeap_Insert) {
		prep p;
		for (int i = 0; i < p.n; i++) {
		//	p.fibonacciHeap1->FibonacciHeap_Insert(new Node(i));
		}
		//BOOST_ASSERT(p.fibonacciHeap1->getnumberOfNodes()==p.n);
	}
	BOOST_AUTO_TEST_CASE(FibonacciHeap_Union) {
		prep p;
		FibonacciHeap* temp= new FibonacciHeap(new Node(0));
		FibonacciHeap* FH1 = new FibonacciHeap(new Node(1));
		FibonacciHeap* FH2 = new FibonacciHeap(new Node(2));
		/*		for (int i = 0; i < p.n; i++) {
			FH1 = new FibonacciHeap(new Node(i));
			FH2 = new FibonacciHeap(new Node((-1)* i));
			temp= FH1->FibonacciHeap_Union(FH2);
		}*/
		temp = FH1->FibonacciHeap_Union(FH2);
		//BOOST_ASSERT(newNumberOfNodes!= oldNumberOfNodes);
		BOOST_ASSERT(temp->getMin()->getLeft()!= temp->getMin());
	}
	BOOST_AUTO_TEST_CASE(FibonacciHeap_extractMin) {
		prep p;
		Node* temp = new Node();
		for (int i = 0; i < p.n-1; i++) {
			temp= p.fibonacciHeap1->FibonacciHeap_extractMin();
			
		}

		BOOST_ASSERT((p.fibonacciHeap1->getMin() != temp));
	}

	BOOST_AUTO_TEST_CASE(FibonacciHeap_decreaseKey) {
		prep p;
		Node* temp = new Node(100);
		p.fibonacciHeap2 = new FibonacciHeap(temp);
		int oldKey = p.fibonacciHeap2->getMin()->getKey();
		for (int i = 1; i <= p.n; i++) {
			p.fibonacciHeap2->FibonacciHeap_decreaseKey(p.fibonacciHeap2->getMin(),oldKey-1);
		}
		BOOST_ASSERT((p.fibonacciHeap2->getMin()->getKey() !=oldKey));
	}

	BOOST_AUTO_TEST_CASE(FibonacciHeap_delete) {
		prep p;

		for (int i = 0; i < p.n; i++) {
			p.fibonacciHeap1->FibonacciHeap_delete(p.fibonacciHeap1->getMin());
			
		}
		BOOST_ASSERT(!(p.fibonacciHeap1->getMin()));
	}
	BOOST_AUTO_TEST_SUITE_END()