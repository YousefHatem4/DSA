#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode(int val) : val(val) {}
};

struct BinaryTree
{
    TreeNode *root{};
    BinaryTree(int root_value)
        : root(new TreeNode(root_value)) {}

    void add(vector<int> values, vector<char> direction)
    {
        assert(values.size() == direction.size());

        TreeNode *current = this->root;
        for (int i = 0; i < (int)values.size(); ++i)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new TreeNode(values[i]);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new TreeNode(values[i]);
                current = current->right;
            }
        }
    }
};
bool isLeaf(TreeNode *node)
{
    return node && !node->left && !node->right;
}
class Solution
{
public:
    bool PathSum(TreeNode *root, int targetSum)
    {
        // check if there root or not
        if (!root)
            return false;
        // check if the root has moved to the leaf or not
        // && check if the target sum has found the value
        if (isLeaf(root) && targetSum == root->val)
            return true;
        // we moved from up to down and while we moved down we subtract the target with the root in both sides
        return PathSum(root->left, targetSum - root->val) ||
               PathSum(root->right, targetSum - root->val);
    }
};

int main()
{
    BinaryTree tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'});
    tree.add({3, 6, 10}, {'R', 'R', 'L'});

    cout << Solution().PathSum(tree.root, 17) << "\n";
    cout << Solution().PathSum(tree.root, 170) << "\n";
    cout << Solution().PathSum(tree.root, 0) << "\n";
}
