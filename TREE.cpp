//!--------------------------------(Video 12 Binary tree )-------------------------------------
// #include <iostream>
// using namespace std;
// struct Node
// {
//     int data{};
//     Node *left{};
//     Node *right{};
//     Node(int data) : data(data) {}
// };
// //?--------------- { L P R } --------------------
// void print_inorder(Node *cur)
// {
//     if (!cur)
//         return;
//     print_inorder(cur->left);
//     cout << cur->data << "\n";
//     print_inorder(cur->right);
// }
// //?------------- { P L R } -----------------------
// void print_preorder(Node *cur)
// {
//     if (!cur)
//         return;
//     cout << cur->data << "\n";
//     print_inorder(cur->left);
//     print_inorder(cur->right);
// }
// //?------------- { L R P } -----------------------
// void print_postorder(Node *cur)
// {
//     if (!cur)
//         return;
//     print_inorder(cur->left);
//     print_inorder(cur->right);
//     cout << cur->data << "\n";
// }
// int main()
// {
//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);

//     cout << "Inorder traversal:\n";
//     print_inorder(root);
//     cout << "\n";

//     cout << "Preorder traversal:\n";
//     print_preorder(root);
//     cout << "\n";

//     cout << "Postorder traversal:\n";
//     print_postorder(root);

//     // Clean up memory
//     delete root->left->left;
//     delete root->left->right;
//     delete root->right->left;
//     delete root->right->right;
//     delete root->left;
//     delete root->right;
//     delete root;

//     return 0;
// }
//!--------------------------------(Video 13 Binary tree )-------------------------------------
#include <iostream>
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
};
