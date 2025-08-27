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

void inord(TreeNode* root, vector<int>&elts, bool check,int &idx){
    if(root==NULL)return;

    inord(root->left,elts,check,idx);
    if(check)root->val=elts[idx++];
   else  elts.push_back(root->val);
    inord(root->right,elts,check, idx);
}
    void recoverTree(TreeNode* root) {
        vector<int>elts;
        bool check=false;
         int idx=0;


        inord(root,elts,check,idx);
        sort(elts.begin(),elts.end());
        check=true;
       
        
        inord(root,elts,check,idx);
    }
};