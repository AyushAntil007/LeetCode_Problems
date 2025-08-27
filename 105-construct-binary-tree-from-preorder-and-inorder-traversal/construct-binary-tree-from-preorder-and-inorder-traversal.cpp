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
    int findElt(vector<int>&inorder,int elt){
        for(int i=0; i<inorder.size();i++){
            if(inorder[i]==elt)return i;
        }
        return -1;
    }
    TreeNode* solve(TreeNode* root,vector<int>&preorder, vector<int>&inorder, int &idx, int left, int right){
        if(left>right || idx==preorder.size())return NULL;
        
        if(root==NULL)root= new TreeNode(preorder[idx]);
        int i=findElt(inorder,preorder[idx++]);

        root->left=solve(root->left,preorder,inorder,idx,left,i-1);
        root->right=solve(root->right,preorder,inorder,idx,i+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=NULL;

        int idx=0;
        int n=preorder.size();

        root=solve(root,preorder,inorder,idx,0,n-1);
        return root;
    }
};