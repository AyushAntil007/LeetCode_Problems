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
bool solve(TreeNode*lTree,TreeNode* rTree){
    if(rTree==NULL||lTree==NULL)return rTree==lTree;

    bool leftCheck=solve(lTree->left,rTree->right);
    bool rightCheck=solve(lTree->right,rTree->left);

    bool val=lTree->val==rTree->val;

    return leftCheck&&rightCheck&&val;
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;

        return solve(root->left,root->right);

        
    }
};