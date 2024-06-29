#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Define a structure for a tree node
struct TreeNode
{
    // Initialize the value, left child, and right child of the node
    int nodeValue{};        // The value stored in the node
    TreeNode *leftChild{};  // Pointer to the left child node
    TreeNode *rightChild{}; // Pointer to the right child node

    // Constructor to initialize the node with a value
    TreeNode(int value) : nodeValue(value) {}
};

// Define a structure for the binary tree
struct BinaryTree
{
    // Initialize the root node of the tree
    TreeNode *rootNode{}; // Pointer to the root node

    // Constructor to initialize the tree with a root value
    BinaryTree(int rootValue) : rootNode(new TreeNode(rootValue)) {}

    // Function to manually insert nodes into the binary tree
    void addNodes(vector<int> nodeValues, vector<char> directions)
    {
        // Ensure the values and directions vectors are the same size
        assert(nodeValues.size() == directions.size());

        TreeNode *currentNode = this->rootNode; // Start at the root node

        // Iterate through the path and create necessary TreeNodes
        for (int i = 0; i < (int)nodeValues.size(); ++i)
        {
            if (directions[i] == 'L') // If the direction is 'L' (left)
            {
                if (!currentNode->leftChild)
                    currentNode->leftChild = new TreeNode(nodeValues[i]);
                else
                    assert(currentNode->leftChild->nodeValue == nodeValues[i]);
                currentNode = currentNode->leftChild;
            }
            else // If the direction is 'R' (right)
            {
                if (!currentNode->rightChild)
                    currentNode->rightChild = new TreeNode(nodeValues[i]);
                else
                    assert(currentNode->rightChild->nodeValue == nodeValues[i]);
                currentNode = currentNode->rightChild;
            }
        }
    }
};

// Define a class to find the maximum element in the binary tree
class MaxElementFinder
{
public:
    // Function to find the maximum value in the binary tree
    int findMaxValue(TreeNode *root)
    {
        if (!root) // If the root is null, return 0
            return 0;

        int maxVal = root->nodeValue; // Initialize the maximum value with the root node's value

        if (root->leftChild) // If the left child exists, find the maximum value in the left subtree
            maxVal = max(maxVal, findMaxValue(root->leftChild));

        if (root->rightChild) // If the right child exists, find the maximum value in the right subtree
            maxVal = max(maxVal, findMaxValue(root->rightChild));

        return maxVal; // Return the maximum value
    }
};

// Main function
int main()
{
    BinaryTree tree(1);                                             // Create a binary tree with root value 1
    cout << MaxElementFinder().findMaxValue(tree.rootNode) << "\n"; // Find and print the maximum value in the tree

    tree.addNodes({2, 3, 4}, {'L', 'L', 'L'});                      // Add nodes with values 2, 3, and 4 to the left
    cout << MaxElementFinder().findMaxValue(tree.rootNode) << "\n"; // Find and print the maximum value in the tree

    tree.addNodes({5, 7, 10}, {'R', 'R', 'R'});                     // Add nodes with values 5, 7, and 10 to the right
    cout << MaxElementFinder().findMaxValue(tree.rootNode) << "\n"; // Find and print the maximum value in the tree
}