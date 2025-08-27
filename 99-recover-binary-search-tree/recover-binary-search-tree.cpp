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

void solve(TreeNode*root, TreeNode* &prev, TreeNode*&first, TreeNode*&mid, TreeNode*&last){
    if(root==NULL)return;

    solve(root->left,prev,first,mid,last);

    if(prev &&prev->val>root->val){
        if(!first){
            first=prev;
            mid=root;
        }
        else{
            last=root;
        }

    }
    prev=root;

    solve(root->right,prev,first,mid,last);
}
    void recoverTree(TreeNode* root) {
        

        //swap node are adjacent

        //swap nodes aree not adjacent

        TreeNode*prev=NULL;
        TreeNode*first=NULL;
        TreeNode*mid=NULL;
        TreeNode*last=NULL;

        solve(root, prev,first,mid,last);

        if(first&&last)swap(first->val,last->val);
        else if(first&&mid)swap(first->val,mid->val);
        
    }
};