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
        leftchild = nullptr;  // Initialize left child to null
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
        if (parent == nullptr)
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
    {
        // This function serches the currentnode of the specified node as well as the current node of its parent
        currentnode = ROOT;
        parent = nullptr;
        while ((currentnode != nullptr) && (currentnode->info != element))
        {
            parent = currentnode;
            if (element < currentnode->info)
                currentnode = currentnode->leftchild;
            else
                currentnode = currentnode->rightchild;
        }
    }

    bool isEmpty()
    {
        // Check if the tree is empty
        return ROOT == nullptr;
    }
    void inorder(node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        inorder(ptr->leftchild);
        cout << ptr->info << " "; // parent
        inorder(ptr->rightchild);
    }

    void preorder(node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;
            
        cout << ptr->info << " "; // parent
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }

    void postoreder(node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;
            
        postoreder(ptr->leftchild);
        postoreder(ptr->rightchild);
        cout << ptr->info << " "; // parent
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postoreder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}