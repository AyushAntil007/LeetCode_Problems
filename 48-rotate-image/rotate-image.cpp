class Solution {
public:
    void rotate(vector<vector<int>>& a) {

        // brute force
        //  int row=arr1.size();
        //  int col=arr1[0].size();
        //   vector<vector<int>> arr2(col, vector<int>(row));
        //  for(int r=row-1;r>=0;r--){
        //      for(int c=0;c<col;c++){
        //           arr2[c][row-1-r]=arr1[r][c];
        //      }
        //  }
        //  arr1=arr2;

        // optimal sol

        int m = a.size();
        int n = a[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                swap(a[i][j], a[j][i]); // taking transpose
            }
        }

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n / 2; j++) {
        //         swap(a[i][j], a[i][n - 1 - j]); // reverse each rows
        //     }
        // }

        // reversing each row of the matrix
        for (int i = 0; i < m; i++) {
            reverse(a[i].begin(), a[i].end());
        }
    }
};