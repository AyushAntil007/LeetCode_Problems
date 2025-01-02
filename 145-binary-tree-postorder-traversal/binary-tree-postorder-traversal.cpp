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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};

        //.........using 2 stacks..............

        // stack<TreeNode*> st1;
        // stack<int> st2;

        // st1.push(root);

        // while (!st1.empty()) {
        //     TreeNode* node =
        //         st1.top(); // direct root k sath bi solve kar sakte hai  ,
        //                    // without creating new node each tym
        //     st1.pop();
        //     st2.push(node->val);

        //     if (node->left)
        //         st1.push(node->left);
        //     if (node->right)
        //         st1.push(node->right);
        // }

        // vector<int> ans;
        // while (!st2.empty()) {
        //     ans.push_back(st2.top());
        //     st2.pop();
        // }
        // return ans;

        //.........using 1 stack............

        stack<TreeNode*> st;

        vector<int> ans;
        TreeNode* cur = root;

        while (!st.empty() || cur != nullptr) {
            // Traverse left subtree
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* temp = st.top()->right;
                if (temp == nullptr) {
                    // No right child, process the node
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    // Check if the current node is the right child of the next
                    // node
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    // Traverse the right subtree
                    cur = temp;
                }
            }
        }

        return ans;
    }
};