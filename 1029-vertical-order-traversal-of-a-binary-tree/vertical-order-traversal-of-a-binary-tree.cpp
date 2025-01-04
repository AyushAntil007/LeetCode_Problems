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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        queue<pair<TreeNode*, pair<int, int>>> todo;
        map<int, map<int, multiset<int>>> nodes; //{x,{y,node}}

        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front(); // automatically deduct the type
            todo.pop();

            TreeNode* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(temp->val);

            if (temp->left) {

                todo.push({temp->left, {x - 1, y + 1}}); // row-1, col+1
            }
            if (temp->right) {

                todo.push({temp->right, {x + 1, y + 1}}); // row+1,col+1
            }
        }

        vector<vector<int>> ans;
        for (auto p : nodes) { // traverse vertical ie x
            vector<int> col;
            for (auto q : p.second) { // traverse the levels ie y
                // Insert node values
                // into the column vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Add the column vector
            // to the final result
            ans.push_back(col);
        }
        return ans;
    }
};