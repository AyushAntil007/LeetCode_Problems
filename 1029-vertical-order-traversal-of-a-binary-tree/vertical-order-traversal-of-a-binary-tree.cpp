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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>>ans;
        if(root==NULL)return ans;

        map<int,map<int,multiset<int>>>mpp;


        queue<pair<TreeNode*,pair<int,int>>>q;

        q.push({root,{0,0}});

        while(!q.empty()){
            
            auto nodeMap=q.front();
            q.pop();

            int x=nodeMap.second.first;
            int y=nodeMap.second.second;

            TreeNode* node=nodeMap.first;

            mpp[x][y].insert(node->val);

            if(node->left)q.push({node->left,{x-1,y+1}});
            if(node->right)q.push({node->right,{x+1,y+1}});



        }

        for(auto x:mpp){
            vector<int>vertical;
            for(auto y: x.second){
                vertical.insert(vertical.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(vertical);
        }
        return ans; 
    }
};