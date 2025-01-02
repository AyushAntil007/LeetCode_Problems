/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {}; //....important base case
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ans;

        while (!st.empty()) {
            TreeNode* node = st.top();
            ans.push_back(node->val);    // value store
            st.pop();
            if (node->right)            // first access right due to LIFO 
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return ans;
    }
};