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

class Solution
{
public:
    int goodNodes(TreeNode *root, int maxsofar)
    {
        if (!root)
            return 0;
        int addme = root->val >= maxsofar;
        int l = goodNodes(root->left, max(root->val, maxsofar));
        int r = goodNodes(root->right, max(root->val, maxsofar));
        return addme + l + r;
    }

    int goodNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return goodNodes(root, root->val);
    }
};

int main()
{
    BinaryTree bt(3);

    // Add nodes to the binary tree
    bt.add({1, 3}, {'L', 'R'});
    bt.add({4, 1}, {'R', 'L'});
    bt.add({5, 5}, {'R', 'R'});
    cout << "Number of good nodes: " << Solution().goodNodes(bt.root) << endl;

    return 0;
}
