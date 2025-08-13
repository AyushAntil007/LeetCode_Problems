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

bool solve(TreeNode*root, long long maxi, long long mini){
    if(root==NULL)return true;

    if(root->val >= maxi || root->val<=mini){
        return false;
    
    }
    bool left=solve(root->left, root->val,mini);
    bool right=solve(root->right,maxi,root->val);

        return left&&right;
}
    bool isValidBST(TreeNode* root) {

       long long int mini = -1000000000000, maxi = 1000000000000;

        return solve(root,maxi,mini);

        
    }
};