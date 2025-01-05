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

    bool isPossible(TreeNode* root, long long l, long long r) {
        if (root == nullptr)
            return true;
        if (root->val < r and root->val > l)   //track the range min< root->val  <max
            return isPossible(root->left, l, root->val) &&
                   isPossible(root->right, root->val, r);
        else
            return false;
    }
    void isPossible(TreeNode* root, bool& flag) {
        if (root == nullptr)
            return;
        if (root->left != NULL && root->val <= root->left->val) {   //check root->left and root->right with root

            flag = false;
            return;
        }
        if (root->right != NULL && root->val >= root->right->val) {
            flag = false;
            return;
        }

        isPossible(root->left, flag);
        isPossible(root->right, flag);
    }

public:
    bool isValidBST(TreeNode* root) {

        //........Approach-1...........few test cases are not passed

        // bool flag = true;
        // isPossible(root, flag);
        // return flag;

        //........Approach-2.......... this is the better approach for this question

        long long int min = -1000000000000, max = 1000000000000;
        return isPossible(root, min, max);
    }
};