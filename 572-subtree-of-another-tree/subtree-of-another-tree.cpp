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

bool check(TreeNode* root, TreeNode* subRoot){
    if(!root&&!subRoot)return true;

    if(!root|| !subRoot)return false;

    bool left=check(root->left,subRoot->left);
    bool right=check(root->right, subRoot->right);
    bool val=root->val==subRoot->val;

    return left&&right&&val;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==NULL)return false;

        if(root->val==subRoot->val){
            bool valid=check(root,subRoot);
            if(valid)return true;
        }

        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);

        return left||right;
    }
};