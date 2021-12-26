#pragma once
#define BOOST_TEST_MODULE Test
//#define BOOST_TEST_MODULE FibonacciHeap
#include <boost/test/included/unit_test.hpp>
#include "../include/node.hpp"
#include "../include/BinomialHeap.hpp"
#include "../include/FibonacciHeap.hpp"

using namespace boost;

int n = 1;
Node* x= new Node(80);
Node* y = new Node(100);


	BOOST_AUTO_TEST_CASE(Build_Binomial_Heap)
	{
		for (int i = 0; i < n; i++) {
			BinomialHeap* binomialHeap = new BinomialHeap();
		}
	}
	BOOST_AUTO_TEST_CASE(BinomialHeap_Insert) {
		BinomialHeap* binomialHeap = new BinomialHeap();
		for (int i = 0; i < n; i++) {
			binomialHeap->BinomialHeap_Insert(new Node(n));
		}
	}

	BOOST_AUTO_TEST_CASE(BinomialHeap_Union) {
		BinomialHeap* binomialHeap1 = new BinomialHeap();
		BinomialHeap* binomialHeap2 = new BinomialHeap();
		binomialHeap1->BinomialHeap_Insert(x);
		binomialHeap2->BinomialHeap_Insert(y);
		binomialHeap1->BinomialHeap_Union(binomialHeap2);
		BOOST_ASSERT(binomialHeap1->getRoot()->getChild() == y);
		
	}

	BOOST_AUTO_TEST_CASE(BinomialHeap_extractMin) {
		BinomialHeap* binomialHeap1 = new BinomialHeap();
		binomialHeap1->BinomialHeap_Insert(x);
		binomialHeap1->BinomialHeap_Insert(y);
		BOOST_ASSERT((binomialHeap1->getRoot() == x));
		binomialHeap1->BinomialHeap_extractMin();
		BOOST_ASSERT((binomialHeap1->getRoot() == y));
		binomialHeap1->BinomialHeap_extractMin();
	}

	BOOST_AUTO_TEST_CASE(BinomialHeap_decreaseKey) {
		BinomialHeap* binomialHeap1 = new BinomialHeap();
		binomialHeap1->BinomialHeap_Insert(x);
		binomialHeap1->BinomialHeap_Insert(y);
		binomialHeap1->BinomialHeap_decreaseKey(y, 10);
		BOOST_ASSERT((binomialHeap1->getRoot()->getKey() == 10));
	}

	BOOST_AUTO_TEST_CASE(BinomialHeap_delete) {
		BinomialHeap* binomialHeap1 = new BinomialHeap();
		binomialHeap1->BinomialHeap_Insert(x);
		binomialHeap1->BinomialHeap_Insert(y);
		BOOST_ASSERT((binomialHeap1->getRoot()->getKey() == x->getKey()));
		binomialHeap1->BinomialHeap_deleteNode(x);
		BOOST_ASSERT((binomialHeap1->getRoot()->getKey() == y->getKey()));
	}

	BOOST_AUTO_TEST_CASE(Build_Fibonacci_Heap) {
		for (int i = 0; i < n; i++) {
			FibonacciHeap* fibonacciHeap = new FibonacciHeap();
		}
	}
	BOOST_AUTO_TEST_CASE(FibonacciHeap_Insert) {
		FibonacciHeap* fibonacciHeap = new FibonacciHeap();
		for (int i = 0; i < n; i++) {
			fibonacciHeap->FibonacciHeap_Insert(new Node(n));
		}
		BOOST_ASSERT(fibonacciHeap->getnumberOfNodes()==n);
	}
	BOOST_AUTO_TEST_CASE(FibonacciHeap_Union) {
		FibonacciHeap* fibonacciHeap1 = new FibonacciHeap();
		FibonacciHeap* fibonacciHeap2 = new FibonacciHeap();
		fibonacciHeap1->FibonacciHeap_Insert(x);
		fibonacciHeap2->FibonacciHeap_Insert(y);
		fibonacciHeap1->FibonacciHeap_Union(fibonacciHeap2);
		BOOST_ASSERT(fibonacciHeap1->getMin()->getLeft() == y);
	}
	BOOST_AUTO_TEST_CASE(FibonacciHeap_extractMin) {
		FibonacciHeap* fibonacciHeap1 = new FibonacciHeap();
		fibonacciHeap1->FibonacciHeap_Insert(x);
		fibonacciHeap1->FibonacciHeap_Insert(y);
		BOOST_ASSERT((fibonacciHeap1->getMin() == x));
		fibonacciHeap1->FibonacciHeap_extractMin();
		BOOST_ASSERT((fibonacciHeap1->getMin() == y));
		fibonacciHeap1->FibonacciHeap_extractMin();
	}

	BOOST_AUTO_TEST_CASE(FibonacciHeap_decreaseKey) {
		FibonacciHeap* fibonacciHeap1 = new FibonacciHeap();
		fibonacciHeap1->FibonacciHeap_Insert(x);
		fibonacciHeap1->FibonacciHeap_Insert(y);
		fibonacciHeap1->FibonacciHeap_decreaseKey(y, 10);
		BOOST_ASSERT((fibonacciHeap1->getMin()->getKey() == 10));
	}

	BOOST_AUTO_TEST_CASE(FibonacciHeap_delete) {
		FibonacciHeap* fibonacciHeap1 = new FibonacciHeap();
		fibonacciHeap1->FibonacciHeap_Insert(x);
		fibonacciHeap1->FibonacciHeap_Insert(y);
		BOOST_ASSERT((fibonacciHeap1->getMin()->getKey() == x->getKey()));
		fibonacciHeap1->FibonacciHeap_delete(x);
		BOOST_ASSERT((fibonacciHeap1->getMin()->getKey() == y->getKey()));
	}