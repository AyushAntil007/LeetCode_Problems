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
class BSTIterator {
    vector<int>arr;
    int idx;
public:
    void inord(TreeNode* root, vector<int>&arr){
        if(root==NULL)return;

        inord(root->left,arr);
        arr.push_back(root->val);
        inord(root->right,arr);
    }
    BSTIterator(TreeNode* root) {
        idx=0;

        inord(root,arr);
    }
    
    int next() {
        
        return arr[idx++];
        
    }
    
    bool hasNext() {

        if(idx<arr.size())return true;
        return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */