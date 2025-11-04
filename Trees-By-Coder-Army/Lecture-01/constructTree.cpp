// Array - based Binary Tree(Interactive ADT Implementation)

#include <iostream>
#include <vector>
using namespace std;

class ArrayBinaryTree
{
private:
    vector<int> tree;
    int capacity;

public:
    ArrayBinaryTree(int cap)
    {
        capacity = cap;
        tree.resize(cap, -1);
    }

    void insertNode(int index, int data)
    {
        if (index >= capacity)
        {
            cout << "Index out of range.\n";
            return;
        }
        if (tree[index] != -1)
        {
            cout << "Node already exists at index " << index << ".\n";
            return;
        }
        tree[index] = data;
    }

    void setLeft(int parentIndex, int data)
    {
        int left = 2 * parentIndex + 1;
        if (parentIndex >= capacity || tree[parentIndex] == -1)
        {
            cout << "Invalid parent index.\n";
            return;
        }
        insertNode(left, data);
    }

    void setRight(int parentIndex, int data)
    {
        int right = 2 * parentIndex + 2;
        if (parentIndex >= capacity || tree[parentIndex] == -1)
        {
            cout << "Invalid parent index.\n";
            return;
        }
        insertNode(right, data);
    }

    void display()
    {
        cout << "\n Tree (Array Representation): ";
        for (int val : tree)
        {
            if (val == -1)
                cout << "_ ";
            else
                cout << val << " ";
        }
        cout << endl;
    }

    void inorderTraversal(int index)
    {
        if (index >= capacity || tree[index] == -1)
            return;
        inorderTraversal(2 * index + 1);
        cout << tree[index] << " ";
        inorderTraversal(2 * index + 2);
    }

    int size()
    {
        int count = 0;
        for (int val : tree)
            if (val != -1)
                count++;
        return count;
    }
};

int main()
{
    int n;
    cout << "Enter maximum capacity of tree: ";
    cin >> n;

    ArrayBinaryTree t(n);

    cout << "Enter root value: ";
    int rootVal;
    cin >> rootVal;
    t.insertNode(0, rootVal);

    char choice;
    do
    {
        cout << "\nChoose operation: \n";
        cout << "1. Add Left Child\n";
        cout << "2. Add Right Child\n";
        cout << "3. Display Tree\n";
        cout << "4. Show Inorder Traversal\n";
        cout << "5. Show Size\n";
        cout << "Enter choice: ";

        int opt;
        cin >> opt;

        if (opt == 1)
        {
            int p, v;
            cout << "Enter parent index and value: ";
            cin >> p >> v;
            t.setLeft(p, v);
        }
        else if (opt == 2)
        {
            int p, v;
            cout << "Enter parent index and value: ";
            cin >> p >> v;
            t.setRight(p, v);
        }
        else if (opt == 3)
        {
            t.display();
        }
        else if (opt == 4)
        {
            cout << "Inorder Traversal: ";
            t.inorderTraversal(0);
            cout << endl;
        }
        else if (opt == 5)
        {
            cout << "Total nodes: " << t.size() << endl;
        }

        cout << "\nContinue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Linked List - based Binary Tree(Interactive ADT Implementation)

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class LinkedBinaryTree
{
private:
    Node *root;

public:
    LinkedBinaryTree()
    {
        root = nullptr;
    }

    Node *getRoot() { return root; }

    void insertRoot(int data)
    {
        if (root != nullptr)
        {
            cout << "Root already exists.\n";
            return;
        }
        root = new Node(data);
    }

    Node *findNode(Node *node, int value)
    {
        if (!node)
            return nullptr;
        if (node->data == value)
            return node;
        Node *leftSearch = findNode(node->left, value);
        if (leftSearch)
            return leftSearch;
        return findNode(node->right, value);
    }

    void insertLeft(int parentVal, int data)
    {
        Node *parent = findNode(root, parentVal);
        if (!parent)
        {
            cout << "Parent not found.\n";
            return;
        }
        if (parent->left)
        {
            cout << "Left child already exists.\n";
            return;
        }
        parent->left = new Node(data);
    }

    void insertRight(int parentVal, int data)
    {
        Node *parent = findNode(root, parentVal);
        if (!parent)
        {
            cout << "Parent not found.\n";
            return;
        }
        if (parent->right)
        {
            cout << "Right child already exists.\n";
            return;
        }
        parent->right = new Node(data);
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    int size(Node *node)
    {
        if (!node)
            return 0;
        return 1 + size(node->left) + size(node->right);
    }
};

int main()
{
    LinkedBinaryTree tree;
    char choice;
    int val;

    cout << "Enter root value: ";
    cin >> val;
    tree.insertRoot(val);

    do
    {
        cout << "\nChoose operation: \n";
        cout << "1. Add Left Child\n";
        cout << "2. Add Right Child\n";
        cout << "3. Show Inorder Traversal\n";
        cout << "4. Show Tree Size\n";
        cout << "Enter choice: ";

        int opt;
        cin >> opt;

        if (opt == 1)
        {
            int p, v;
            cout << "Enter parent value and left child value: ";
            cin >> p >> v;
            tree.insertLeft(p, v);
        }
        else if (opt == 2)
        {
            int p, v;
            cout << "Enter parent value and right child value: ";
            cin >> p >> v;
            tree.insertRight(p, v);
        }
        else if (opt == 3)
        {
            cout << "Inorder Traversal: ";
            tree.inorder(tree.getRoot());
            cout << endl;
        }
        else if (opt == 5)
        {
            cout << "Total nodes: " << tree.size(tree.getRoot()) << endl;
        }

        cout << "\nContinue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}