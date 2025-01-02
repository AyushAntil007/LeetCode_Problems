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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)return{};
        vector<int>ans;

        stack<TreeNode*>st;
        
        TreeNode* node=root;
        while(true){
           if(node!=NULL){
            st.push(node);
            node=node->left;    // Keep left until NULL
           }
           else{
            if(st.empty())break;
            
            node=st.top();      
            ans.push_back(node->val);  //if left NULL store value
            st.pop();

            node=node->right;  //One tym right move
           }
        }
        return ans;
        
    }
};