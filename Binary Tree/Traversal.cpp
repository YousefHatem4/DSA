#include <iostream>
using namespace std;

// Define a structure for a node in the binary tree
struct TreeNode
{
    // Initialize the value, left child, and right child of the node
    int nodeValue{};        // The value stored in the node
    TreeNode *leftChild{};  // Pointer to the left child node
    TreeNode *rightChild{}; // Pointer to the right child node

    // Constructor to initialize the node with a value
    TreeNode(int value) : nodeValue(value) {}
};

// Function to perform inorder traversal (Left, Parent, Right)
void inorderTraversal(TreeNode *currentNode)
{
    if (!currentNode) // If the current node is null, return
        return;

    inorderTraversal(currentNode->leftChild);  // Recursively traverse the left subtree
    cout << currentNode->nodeValue << "\n";    // Print the value of the current node
    inorderTraversal(currentNode->rightChild); // Recursively traverse the right subtree
}

// Function to perform preorder traversal (Parent, Left, Right)
void preorderTraversal(TreeNode *currentNode)
{
    if (!currentNode) // If the current node is null, return
        return;

    cout << currentNode->nodeValue << "\n";    // Print the value of the current node
    inorderTraversal(currentNode->leftChild);  // Recursively traverse the left subtree
    inorderTraversal(currentNode->rightChild); // Recursively traverse the right subtree
}

// Function to perform postorder traversal (Left, Right, Parent)
void postorderTraversal(TreeNode *currentNode)
{
    if (!currentNode) // If the current node is null, return
        return;

    inorderTraversal(currentNode->leftChild);  // Recursively traverse the left subtree
    inorderTraversal(currentNode->rightChild); // Recursively traverse the right subtree
    cout << currentNode->nodeValue << "\n";    // Print the value of the current node
}

int main()
{
    TreeNode *rootNode = new TreeNode(1);               // Create the root node with value 1
    rootNode->leftChild = new TreeNode(2);              // Create the left child node with value 2
    rootNode->rightChild = new TreeNode(3);             // Create the right child node with value 3
    rootNode->leftChild->leftChild = new TreeNode(4);   // Create the left-left grandchild node with value 4
    rootNode->leftChild->rightChild = new TreeNode(5);  // Create the left-right grandchild node with value 5
    rootNode->rightChild->leftChild = new TreeNode(6);  // Create the right-left grandchild node with value 6
    rootNode->rightChild->rightChild = new TreeNode(7); // Create the right-right grandchild node with value 7

    cout << "Inorder traversal:\n"; // Print the title for inorder traversal
    inorderTraversal(rootNode);     // Perform inorder traversal and print the node values
    cout << "\n";

    cout << "Preorder traversal:\n"; // Print the title for preorder traversal
    preorderTraversal(rootNode);     // Perform preorder traversal and print the node values
    cout << "\n";

    cout << "Postorder traversal:\n"; // Print the title for postorder traversal
    postorderTraversal(rootNode);     // Perform postorder traversal and print the node values

    // Clean up memory by deleting the nodes
    delete rootNode->leftChild->leftChild;
    delete rootNode->leftChild->rightChild;
    delete rootNode->rightChild->leftChild;
    delete rootNode->rightChild->rightChild;
    delete rootNode->leftChild;
    delete rootNode->rightChild;
    delete rootNode;

    return 0; // Return 0 to indicate successful execution
}