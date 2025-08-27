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

        if(root==NULL)return {};
        vector<int>ans;
        stack<TreeNode*>st;

        TreeNode* cur=root;  //ek cur lenge jo sabhi left mai jjayga

        while(!st.empty()|| cur!=NULL){
            while(cur){      // traversal all left node
                st.push(cur);
                cur=cur->left;
            }

            TreeNode* node=st.top();
            st.pop();      // store teh ans

            ans.push_back(node->val);

            cur=node->right;     //left over shift to right

        }

        return ans;
    }
};