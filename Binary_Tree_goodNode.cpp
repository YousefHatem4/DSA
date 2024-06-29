#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
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
                currentNode = currentNode->leftChild;
            }
            else // If the direction is 'R' (right)
            {
                if (!currentNode->rightChild)
                    currentNode->rightChild = new TreeNode(nodeValues[i]);
                currentNode = currentNode->rightChild;
            }
        }
    }
};

// Define a class to solve the problem of finding good nodes
class Solution
{
public:
    // Function to count good nodes recursively with a maximum value so far
    int countGoodNodes(TreeNode *root, int maxSoFar)
    {
        if (!root) // If the root is null, return 0
            return 0;

        int isGoodNode = root->nodeValue >= maxSoFar;                                          // Check if the current node is a good node
        int leftGoodNodes = countGoodNodes(root->leftChild, max(root->nodeValue, maxSoFar));   // Count good nodes in the left subtree
        int rightGoodNodes = countGoodNodes(root->rightChild, max(root->nodeValue, maxSoFar)); // Count good nodes in the right subtree

        return isGoodNode + leftGoodNodes + rightGoodNodes; // Return the total count of good nodes
    }

    // Overloaded function to start counting good nodes from the root
    int countGoodNodes(TreeNode *root)
    {
        if (!root) // If the root is null, return 0
            return 0;

        return countGoodNodes(root, root->nodeValue); // Start the count with the root's value as the maximum so far
    }
};

int main()
{
    BinaryTree bt(3); // Create a binary tree with root value 3

    // Add nodes to the binary tree
    bt.addNodes({1, 3}, {'L', 'R'});
    bt.addNodes({4, 1}, {'R', 'L'});
    bt.addNodes({5, 5}, {'R', 'R'});

    // Print the number of good nodes in the binary tree
    cout << "Number of good nodes: " << Solution().countGoodNodes(bt.rootNode) << endl;

    return 0; // Return 0 to indicate successful execution
}
