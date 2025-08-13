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


int findRoot(int elt, vector<int>&inorder){
    for(int i=0; i<inorder.size();i++){
        if(inorder[i]==elt)return i;
    }
    return -1;
}
TreeNode* solve (TreeNode* root,int &pidx, vector<int>&inorder, vector<int>&postorder, int left, int right){
    if(left>right)return NULL;

    if(root==NULL)root= new TreeNode(postorder[pidx]);
   
    int id=findRoot(postorder[pidx--],inorder);
    
    root->right=solve(root->right,pidx,inorder,postorder,id+1,right);
    root->left=solve(root->left, pidx,inorder, postorder,left,id-1 );
    

    return root;


}



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pidx=inorder.size()-1;
        
        TreeNode* root=NULL;
       root= solve(root,pidx,inorder, postorder, 0, pidx);
       return root;
    }
};