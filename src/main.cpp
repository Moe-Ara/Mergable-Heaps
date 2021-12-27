#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "../include/BinomialHeap.hpp"
#include "../include/FibonacciHeap.hpp"
#define N 1000000
constexpr auto factor = 10 ^ 9;
void BinomialInsertionTest(BinomialHeap *Heap)
{
    int x = 0;
    auto start = std::chrono::system_clock::now();
    while (x < N)
    {
        Heap->BinomialHeap_Insert(new Node(x));
        x++;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "BinomialHeap_Insert: " << elapsed_seconds.count() << " s\n";
}
void BinomialMergeTest(BinomialHeap *h1)
{
    int x = 0;
    auto start = std::chrono::system_clock::now();
    while (x < N)
    {
        BinomialHeap* h2 = new BinomialHeap(new Node(x));
        h1->BinomialHeap_Union(h2);
        x++;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "BinomialHeap_Union: " << elapsed_seconds.count() << " s\n";
}
void BinomialextractMinTest(BinomialHeap *h1)
{
    int x = 0;
    while (x <= N)
    {
        h1->BinomialHeap_Insert(new Node(x));
        x++;
    }
    x = 0;
    auto start = std::chrono::system_clock::now();
    while (x < N)
    {
        h1->BinomialHeap_extractMin();
        x++;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Binomial_extractMin: " << elapsed_seconds.count() << " s\n";
}
// double FindMinTest(BinomialHeap *h1)
// {
// 	auto start = std::chrono::system_clock::now();
// 	h1->BinomialHeap_findMin();
// 	auto end = std::chrono::system_clock::now();
// 	std::chrono::duration<double> elapsed_seconds = end - start;
// 	return elapsed_seconds.count();
// }
void BinomialDeleteTest(BinomialHeap *h1)
{
    int x = 0;
    while (x <= N)
    {
        h1->BinomialHeap_Insert(new Node(x));
        x++;
    }
    x = 0;
    auto start = std::chrono::system_clock::now();
    while (x < N)
    {
        h1->BinomialHeap_deleteNode(h1->getRoot());
        x++;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Binomial_deleteNode: " << elapsed_seconds.count() << " s\n";
}
void BinomialdecreaseKey(BinomialHeap *h1)
{
    int x = 0;
    while (x <= N)
    {
        h1->BinomialHeap_Insert(new Node(x));
        x++;
    }
    x = 0;
    auto start = std::chrono::system_clock::now();
    while (x < N)
    {
        h1->BinomialHeap_decreaseKey(h1->getRoot(), h1->getRoot()->getKey()-1);
        x++;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "BinomialHeap_decreaseKey: " << elapsed_seconds.count() << " s\n";
}
//Fibonacci Heap Tests
void FibonacciInsertionTest(FibonacciHeap *Heap)
{
    int x = 0;
    auto start = std::chrono::system_clock::now();
    while (x < N)
    {
        Heap->FibonacciHeap_Insert(new Node(x));
        x++;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "FibonacciHeap_Insert: " << elapsed_seconds.count() << " s\n";
}
void FibonacciHeapMergeTest(FibonacciHeap *h1)
{
    int x = 0;
    FibonacciHeap* temp=new FibonacciHeap();
    auto start = std::chrono::system_clock::now();
    while (x < N)
    {
        FibonacciHeap* h2 = new FibonacciHeap(new Node(x));
        temp= h1->FibonacciHeap_Union(h2);
        x++;
    }
    auto end = std::chrono::system_clock::now();
    delete temp;
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "FibonacciHeap_Union: " << elapsed_seconds.count() << " s\n";
}
void FibonacciHeapextractMinTest(FibonacciHeap *h1)
{
    int x = 0;
    while (x <= N)
    {
        h1->FibonacciHeap_Insert(new Node(x));
        x++;
    }
    x = 0;
    auto start = std::chrono::system_clock::now();
    while (x < N)
    {
        h1->FibonacciHeap_extractMin();
        x++;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "FibonacciHeap_extractMin: " << elapsed_seconds.count() << " s\n";
}
void FibonacciHeapDeleteTest(FibonacciHeap *H1)
{
    int x = 0;
    while (x <= N)
    {
        H1->FibonacciHeap_Insert(new Node(x));
        x++;
    }
    x = 0;
    auto start = std::chrono::system_clock::now();
    while (x < N-1)
    {
        H1->FibonacciHeap_delete(H1->getMin());
        x++;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "FibonacciHeap_deleteNode: " << elapsed_seconds.count() << " s\n";
}
void FibonacciHeapdecreaseKey(FibonacciHeap *h1)
{
    int x = 0;
    while (x <= N)
    {
        h1->FibonacciHeap_Insert(new Node(x));
        x++;
    }
    x = 0;
    auto start = std::chrono::system_clock::now();
    while (x < N)
    {
        h1->FibonacciHeap_decreaseKey(h1->getMin(), h1->getMin()->getKey()-1);
        x++;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "FibonacciHeap_decreaseKey: " << elapsed_seconds.count() << " s\n";
}

int main()
{
    std::cout << std::endl;
    std::cout << "Each Operation is executed "<<N<<" times"<<std::endl;   
    std::cout << std::endl;
    std::cout << "=========Binomial Heap========"<<std::endl;
    //Binomial Heap tests
    std::cout << std::endl;
    BinomialHeap *H1 = new BinomialHeap();
    BinomialInsertionTest(H1);
    std::cout << std::endl;
    H1 = new BinomialHeap();
    BinomialMergeTest(H1);
    std::cout << std::endl;
    H1 = new BinomialHeap();
    BinomialextractMinTest(H1);
    std::cout << std::endl;
    H1 = new BinomialHeap();
    BinomialdecreaseKey(H1);
    std::cout << std::endl;
    H1 = new BinomialHeap();
    BinomialDeleteTest(H1);
    std::cout << std::endl;
    std::cout << "=========Fibonacci Heap========"<<std::endl;
    //Fibonacci Heap tests
    std::cout << std::endl;
    FibonacciHeap *FH1 = new FibonacciHeap();
    FibonacciInsertionTest(FH1);
    std::cout << std::endl;
    FH1 = new FibonacciHeap();
    FibonacciHeapdecreaseKey(FH1);
    std::cout << std::endl;
    FH1 = new FibonacciHeap();
    FibonacciHeapDeleteTest(FH1);
    std::cout << std::endl;
    FH1 = new FibonacciHeap();
    FibonacciHeapMergeTest(FH1);
    std::cout << std::endl;
    FH1 = new FibonacciHeap();
    FibonacciHeapextractMinTest(FH1);
    std::cout << std::endl;
    std::cout << "Finished"<<std::endl;
    //pause 
    system("pause.exe");
    return 0;
}
