/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int val) {
        if (root->left == NULL || root->right == NULL) {
            if (val > root->val)
                root->right = new TreeNode(val);
            else
                root->left = new TreeNode(val);
            return;
        }

        if (val > root->val) {
            solve(root->right, val);
        } else {
            solve(root->left, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        //.........my approach.........
        // if (root == NULL)
        //     return root = new TreeNode(val);
        // solve(root, val);
        // return root;

        //..........better code..........

        if (root ==NULL) { // Base case: if root is NULL, create and return a new node
            return new TreeNode(val);
        }

        if (val > root->val) { // Traverse the tree to find the correct position
                               // for insertion
            root->right = insertIntoBST(root->right, val);
        } 
        else {
            root->left = insertIntoBST(root->left, val);
        }

        return root;
    }
};