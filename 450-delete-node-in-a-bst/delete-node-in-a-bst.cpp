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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return root;

        if(root->val==key){  // if key is present 
            if(root->left==NULL&& root->right==NULL) return NULL;   //case -1  key is leaf node
               
            else if(root->left==NULL){    // key is having single child
                return root->right;
            }
            else if(root->right==NULL){ 
                return root->left;
            }
            else{     //key is having two child
                
                TreeNode* temp=root->left;
                while(temp->right){
                    temp=temp->right;
                }
                root->val=temp->val;
                root->left = deleteNode(root->left, temp->val); 
                return root;
            }
        }
        else if(key>root->val){       
            root->right=deleteNode(root->right,key);
        }
        else {
            root->left=deleteNode(root->left,key);
        }
        return root;
    }
};