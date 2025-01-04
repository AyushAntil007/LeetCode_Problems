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
    
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {      //if root is null or the node is having null child
            return NULL;
        }
        if (root->val == val) {  //value found  return that node
            return root;
        }
        if (root->val < val) {
            return searchBST(root->right, val);   //search right
        } else {
            return searchBST(root->left, val);    //search left
        }
    }
};