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
        int x;
        cout << "Masukkan nilai : ";
        cin >> x;

        // Step 1 : Allocate memory for the new node
        node *newnode = new node();

        // Step 2 : Assign value to the data field of new node
        newnode->info = x;

        // Step 3 : make the left and right child of the new node point to null
        newnode->leftchild = nullptr;
        newnode->rightchild = nullptr;

        // Step 4 : Locate the node which will be the parent of the node to be inserted
        node *parent = nullptr;
        node *currentnode = nullptr;
        search(x, parent, currentnode);

        // Step 5 : if parent is NULL (Tree is empty)
        if(parent == nullptr)
        {
            // 5a : Mark the new node as ROOT
            ROOT = newnode;

            // 5b : Exit
            return;
        }

        // step 6 : If the value in  the data field of the new node is less than that of parent
        if (x < parent->info)
        {
            // 6a: Make the left child of parent point to the new node
            parent->leftchild = newnode;

            // 6b : exit
            return;
        }
        
        // step 7 : if the value in the data field of the new node is greater than that of the parent
        else if (x > parent->info)
        {
            // 7a : Make the right child of parent point to the new node
            parent->rightchild = newnode;

            // 7b : Exit
            return;
        }
    }
void search(int element, node *&parent, node *&currentnode)
