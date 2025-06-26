// BinarySearchTree_0061
// 15 Commit

#include <iostream>
using namespace std;

class node
{
public:
    int info;
    node *leftchild;
    node *rightchild;

    // Contructor for the node class
    node()
    {
        leftchild = nullptr; // Initialize left child to null
        rightchild = nullptr; // Initialize right child to null
    }
};

class BinaryTree
{
public:
    node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // Initializing ROOT to null
    }

    void insert()
    {
 