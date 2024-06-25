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

// Define a class to find the maximum depth in the binary tree
class MaxDepthFinder
{
public:
    // Function to find the maximum depth of the binary tree
    int findMaxDepth(TreeNode *root)
    {
        if (!root) // If the root is null, return 0
            return 0;

        int leftDepth = findMaxDepth(root->leftChild);   // Find the depth of the left subtree
        int rightDepth = findMaxDepth(root->rightChild); // Find the depth of the right subtree

        return max(leftDepth, rightDepth) + 1; // Return the maximum depth plus one for the current node
    }
};

int main()
{
    BinaryTree tree(1);                         // Create a binary tree with root value 1
    tree.addNodes({2, 4, 7}, {'L', 'L', 'L'});  // Add nodes with values 2, 4, and 7 to the left
    tree.addNodes({2, 4, 8}, {'L', 'L', 'R'});  // Add nodes with values 2, 4, and 8 to the left-right
    tree.addNodes({2, 5, 9}, {'L', 'R', 'R'});  // Add nodes with values 2, 5, and 9 to the left-right
    tree.addNodes({3, 6, 10}, {'R', 'R', 'L'}); // Add nodes with values 3, 6, and 10 to the right

    // Print the maximum depth of the tree
    cout << MaxDepthFinder().findMaxDepth(tree.rootNode) << "\n";

    return 0; // Return 0 to indicate successful execution
}
