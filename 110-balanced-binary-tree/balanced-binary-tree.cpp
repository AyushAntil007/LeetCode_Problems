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

int maxDepth(TreeNode* root, bool &check){
    if(root==NULL)return 0;

        int lh=maxDepth(root->left,check);
        int rh=maxDepth(root->right,check);

        int diff= abs(lh-rh);
        if(diff>1)check=false;
        

        return 1+max(lh,rh);
}
    bool isBalanced(TreeNode* root) {
        bool check=true;
        int depth=maxDepth(root,check);

        return check;
    }
};