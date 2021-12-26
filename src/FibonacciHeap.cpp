#include "../include/FibonacciHeap.hpp"
FibonacciHeap::FibonacciHeap()
{
    root = nullptr;
    min = nullptr;
    numberOfNodes = 0;
}
FibonacciHeap::FibonacciHeap(Node *n)
{
    root = n;
    min = n;
    numberOfNodes = 1;
}
void FibonacciHeap::FibonacciHeap_Insert(Node *node)
{
    // increment number of nodes
    numberOfNodes++;
    // first we make the node it self a circular linked list
    node->setRight(node);
    node->setLeft(node);
    // clear its mark
    node->setMarked(false);
    node->setParent(nullptr);
    node->setChild(nullptr);
    node->setDegree(0);
    // we check if the initial heap is empty
    if (!min)
    {
        min = node;
        return;
    }
    // we concatinate the two lists together
    min->getLeft()->setRight(node);
    node->setLeft(min->getLeft());
    min->setLeft(node);
    node->setRight(min);
    // update min[H]
    if (node->getKey() < min->getKey())
    {
        min = node;
    }
}
FibonacciHeap *FibonacciHeap::FibonacciHeap_Union(FibonacciHeap *H)
{
    // create empty heap
    FibonacciHeap *temp = new FibonacciHeap();
    temp->min = this->min;
    // number of node in the newly created heap is the sum of number of nodes in both heaps
    temp->numberOfNodes = this->numberOfNodes + H->numberOfNodes;
    // check if we have merged two empty heaps
    if (temp->numberOfNodes == 0 || !(temp->min && H->min))
    {
        return nullptr;
    }
    // concatinate
    temp->min->getRight()->setLeft(H->min->getLeft());
    H->min->getLeft()->setRight(temp->min->getRight());
    temp->min->setRight(H->min);
    H->min->setLeft(temp->min);
    // update min
    if (this->min==nullptr || (H->min &&( H->min->getKey() < this->min->getKey())))
    {
        temp->min = H->min;
    }
    // return the result heap
    return temp;
}

Node *FibonacciHeap::FibonacciHeap_extractMin()
{
    Node *result = min;
    Node *chd, *nxt;
    Node **childList;
    if (result)
    {
        chd = result->getChild();
        if (chd)
        {
            childList = new Node *[result->getDegree()];
            nxt = chd;
            for (int i = 0; i < result->getDegree(); i++)
            {
                childList[i] = nxt;
                nxt = nxt->getRight();
            }
            for (int i = 0; i < result->getDegree(); i++)
            {
                chd = childList[i];

                min->getLeft()->setRight(chd);
                chd->setLeft(min->getLeft());
                min->setLeft(chd);
                chd->setRight(min);

                chd->setParent(nullptr);
            }
            delete[] childList;
        }
        result->getLeft()->setRight(result->getRight());
        result->getRight()->setLeft(result->getLeft());

        if (result == result->getRight())
        {
            min = nullptr;
        }
        else
        {
            min = result->getRight();
            consolidate();
        }
        numberOfNodes--;
    }
    return result;
}

void FibonacciHeap::FibonacciHeap_decreaseKey(Node *node, int k)
{
    if (node->getKey() < k)
    {
        return;
    }

    Node *y;

    node->setKey(k);

    y = node->getParent();

    if (y != nullptr && (node->getKey() < y->getKey()))
    {
        cut(node, y);
        cascadingCut(y);
    }

    if (node->getKey() < min->getKey())
    {
        min = node;
    }
}

void FibonacciHeap::FibonacciHeap_delete(Node *n)
{
    FibonacciHeap_decreaseKey(n, min->getKey() - 1);
    FibonacciHeap_extractMin();
}

void FibonacciHeap::cut(Node *x, Node *y)
{
    if (x->getRight() == x)
    {
        y->setChild(nullptr);
    }
    else
    {
        x->getRight()->setLeft(x->getLeft());
        x->getLeft()->setRight(x->getRight());
        if (y->getChild() == x)
        {
            y->setChild(x->getRight());
        }
    }
    y->setDegree(y->getDegree() - 1);

    min->getRight()->setLeft(x);
    x->setRight(min->getRight());
    min->setRight(x);
    x->setLeft(min);

    x->setParent(nullptr);
    x->setMarked(false);
}

void FibonacciHeap::cascadingCut(Node *y)
{
    Node *z;

    z = y->getParent();

    if (z)
    {
        if (!(y->getMarked()))
        {
            y->setMarked(true);
        }
        else
        {
            cut(y, z);
            cascadingCut(z);
        }
    }
}

void FibonacciHeap::consolidate()
{
    Node **A, **rootlist;
    Node *w, *next, *x, *y, *temp;

    int d, rootSize;
    // determining the maximum degree according to the following golden rule Φ=(1+√5)/2
    int max_degree = static_cast<int>(floor(log(static_cast<double>(numberOfNodes)) / log(static_cast<double>(1 + sqrt(static_cast<double>(5))) / 2)));

    // initializing the buffer A
    A = new Node *[max_degree + 2];

    std::fill_n(A, max_degree + 2, nullptr);
    w = min;
    rootSize = 0;
    next = w;
    do
    {
        rootSize++;
        next = next->getRight();
    } while (next != w);
    rootlist = new Node *[rootSize];
    for (int i = 0; i < rootSize; i++)
    {
        rootlist[i] = next;
        next = next->getRight();
    }
    for (int i = 0; i < rootSize; i++)
    {
        w = rootlist[i];

        x = w;
        d = x->getDegree();

        while (A[d] != nullptr)
        {
            y = A[d];

            if (y->getKey() < x->getKey())
            {
                temp = x;
                x = y;
                y = temp;
            }
            FibonacciHeap_Link(y, x);
            A[d] = nullptr;
            d++;
        }
        A[d] = x;
    }
    delete[] rootlist;

    min = nullptr;
    for (int i = 0; i < max_degree + 2; i++)
    {
        if (A[i] != nullptr)
        {
            if (min == nullptr)
            {
                //!
                min = A[i];
                A[i]->setLeft(A[i]);
                A[i]->setRight(A[i]);
            }
            else
            {
                min->getLeft()->setRight(A[i]);
                A[i]->setLeft(min->getLeft());
                min->setLeft(A[i]);
                A[i]->setRight(min);

                if (A[i]->getKey() < min->getKey())
                {
                    min = A[i];
                }
            }
        }
    }
    delete[] A;
}

void FibonacciHeap::FibonacciHeap_Link(Node *x, Node *y)
{
    y->getLeft()->setRight(y->getRight());
    y->getRight()->setLeft(y->getLeft());

    if (x->getChild())
    {
        x->getChild()->getLeft()->setRight(y);
        y->setLeft(x->getChild()->getLeft());
        x->getChild()->setLeft(y);
        y->setRight(x->getChild());
    }
    else
    {
        x->setChild(y);
        y->setRight(y);
        y->setLeft(y);
    }
    y->setParent(x);
    x->setDegree(x->getDegree() + 1);
    y->setMarked(false);
}

int FibonacciHeap::getnumberOfNodes() {
    return numberOfNodes;
}
Node* FibonacciHeap::getMin() {
    return min;
}