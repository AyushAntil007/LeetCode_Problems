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

void solve(TreeNode* root,int level,vector<int>&ans){
    if(root==NULL)return;
    
    if(level==ans.size()){
        ans.push_back(root->val);
    }
    

    solve(root->right,level+1,ans);

    
    solve(root->left,level+1,ans);
    
}
    vector<int> rightSideView(TreeNode* root) {



        // vector<int>ans;
        // if(root==NULL)return ans;

        // map<int,int>mpp;    //  store{level,level ka last node}


        // queue<pair<TreeNode*,int>>q;

        // q.push({root,0});

        // while(!q.empty()){
            
        //    pair<TreeNode*,int>p=q.front();
        //     q.pop();

        //     TreeNode* node=p.first;

        //     int level=p.second;



        //     // if(mpp.find(line)==mpp.end()){
        //         mpp[level]=node->val;
        //     // }

        //     if(node->left)q.push({node->left,level+1});
        //     if(node->right)q.push({node->right,level+1});



        // }

        // for(auto x:mpp){
            
        //     ans.push_back(x.second);
        // }
        // return ans; 




        // Approach -2 right boundary traversal


        vector<int>ans;
        if(root==NULL)return ans;
        solve(root,0,ans);
        return ans;
    }
};