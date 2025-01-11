class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = m - 1, bottom = n - 1, top = 0;

        while (top <= bottom && left <= right) {   //cxheck boundary condition
            for (int i = left; i <= right; i++) {   // row1
                ans.push_back(matrix[top][i]);
            }
            top++;

            for (int j = top; j <= bottom; j++) {  //last col
                ans.push_back(matrix[j][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {  //  last row
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {  // first col
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};