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

int pred(TreeNode* root){
    while(root->right)root=root->right;
    return root->val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key){
            
            if(!root->left && !root->right)return NULL;
            else if(!root->right)return root->left;
            else if(!root->left)return root->right;
            else {
                int elt=pred(root->left);
                root->val=elt;
                root->left=deleteNode(root->left,elt);
                return root;
            }

        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
            
        }
        else root->right=deleteNode(root->right,key);

        return root;
    }
};