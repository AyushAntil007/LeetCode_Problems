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
int maxDepth(TreeNode* root, int &dia){
    if(root==NULL)return 0;

        int lh=maxDepth(root->left,dia);
        int rh=maxDepth(root->right,dia);

        dia=max(dia,rh+lh);
        

        return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {

        int dia=0;
        maxDepth(root,dia);
        return dia;
        
    }
};