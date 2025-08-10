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
    int widthOfBinaryTree(TreeNode* root) {

        if(root==NULL)return 0;

        queue<pair<TreeNode*,int>>q;

        q.push({root,0});

        long long ans=0;

        while(!q.empty()){
            
            int s=q.size();
            long long minIdx=q.front().second;

          
            long long last,first;
            for(int i=0;i<s; i++){
                TreeNode* node=q.front().first;
                long long  idx=q.front().second-minIdx;
                q.pop();

                if(i==0)first=idx;
                if(i==s-1)last=idx;

                if(node->left)q.push({node->left,2*idx+1});
                if(node->right)q.push({node->right,2*idx+2});





            }
            ans=max(last-first+1,ans);
 
        }
        return ans;
        
    }
};