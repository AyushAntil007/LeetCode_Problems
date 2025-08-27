/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void inorder(TreeNode*& root, int &k, int &elt) {
        if (root == NULL) {
            return;
        }
       
        inorder(root->left, k,elt);
         k--;
       if(k==0){
        elt=root->val;
        return;
       }
        inorder(root->right, k,elt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int elt;
        inorder(root,k,elt);
        return elt;
    }
};