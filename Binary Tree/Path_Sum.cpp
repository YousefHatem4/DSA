#include <iostream>   
#include <vector>    
#include <cassert>    
#include <algorithm>  
using namespace std; 

struct TreeNode
{
    // Initialize the value, left child, and right child of the node
    int nodeValue{};           // The value stored in the node
    TreeNode *leftChild{};     // Pointer to the left child node
    TreeNode *rightChild{};    // Pointer to the right child node

    // Constructor to initialize the node with a value
    TreeNode(int value) : nodeValue(value) {}
};

// Define a structure for the binary tree
struct BinaryTree
{
    // Initialize the root node of the tree
    TreeNode *rootNode{};  // Pointer to the root node

    // Constructor to initialize the tree with a root value
    BinaryTree(int rootValue) : rootNode(new TreeNode(rootValue)) {}

    // Function to manually insert nodes into the binary tree
    void addNodes(vector<int> nodeValues, vector<char> directions)
    {
        // Ensure the values and directions vectors are the same size
        assert(nodeValues.size() == directions.size());

        TreeNode *currentNode = this->rootNode;  // Start at the root node

        // Iterate through the path and create necessary TreeNodes
        for (int i = 0; i < (int)nodeValues.size(); ++i)
        {
            if (directions[i] == 'L')  // If the direction is 'L' (left)
            {
                if (!currentNode->leftChild)
                    currentNode->leftChild = new TreeNode(nodeValues[i]);
                currentNode = currentNode->leftChild;
            }
            else  // If the direction is 'R' (right)
            {
                if (!currentNode->rightChild)
                    currentNode->rightChild = new TreeNode(nodeValues[i]);
                currentNode = currentNode->rightChild;
            }
        }
    }
};

// Function to check if a node is a leaf node
bool isLeafNode(TreeNode *node)
{
    return node && !node->leftChild && !node->rightChild;  // A node is a leaf if it exists and has no children
}

// Define a class to solve the problem of finding a path sum
class Solution
{
public:
    // Function to check if there is a path with a given sum
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)  // If the root is null, return false
            return false;

        // If the current node is a leaf and its value equals the target sum, return true
        if (isLeafNode(root) && targetSum == root->nodeValue)
            return true;

        // Recursively check the left and right subtrees with the updated target sum
        return hasPathSum(root->leftChild, targetSum - root->nodeValue) ||
               hasPathSum(root->rightChild, targetSum - root->nodeValue);
    }
};

int main()
{
    BinaryTree tree(1);  // Create a binary tree with root value 1

    // Add nodes to the binary tree
    tree.addNodes({2, 4, 7}, {'L', 'L', 'L'});
    tree.addNodes({2, 4, 8}, {'L', 'L', 'R'});
    tree.addNodes({2, 5, 9}, {'L', 'R', 'R'});
    tree.addNodes({3, 6, 10}, {'R', 'R', 'L'});

    // Print the result of checking for path sums
    cout << Solution().hasPathSum(tree.rootNode, 17) << "\n";  // Check for path sum of 17
    cout << Solution().hasPathSum(tree.rootNode, 170) << "\n"; // Check for path sum of 170
    cout << Solution().hasPathSum(tree.rootNode, 0) << "\n";   // Check for path sum of 0

    return 0;  // Return 0 to indicate successful execution
}
