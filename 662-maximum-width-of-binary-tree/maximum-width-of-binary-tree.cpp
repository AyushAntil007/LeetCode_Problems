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
        queue<pair<TreeNode*,int>>p;
        int ans=INT_MIN;
        
        p.push({root,0});
        
        while(!p.empty()){
            int s=p.size();
            long long pIdx= p.front().second;
            int first,last;
            for(int i=0;i<s;i++){
                TreeNode*temp=p.front().first;
                long long curIdx=p.front().second-pIdx;  //to prevent overflow condition
                p.pop();
                if(i==0)first=curIdx;
                if(i==s-1)last=curIdx;
                if(temp->left)p.push({temp->left,2*curIdx+1});
                if(temp->right)p.push({temp->right,2*curIdx+2});
                
                
            }
            ans=max(last-first+1,ans);

            
        }
    return ans;
    
    }
};