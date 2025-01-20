class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // for (int i = 0; i < arr.size(); i++) { .......tle
        //     for (int j = 0; j < m; j++) {
        //         for (int l = 0; l < n; l++) {
        //             if (arr[i] == mat[j][l]) {
        //                 mat[j][l] = -1; // Mark the cell as visited

        //                 // Check if the entire row is complete
        //                 int cntRow = 0;
        //                 for (int k = 0; k < n; k++) {
        //                     if (mat[j][k] == -1) cntRow++;
        //                 }
        //                 if (cntRow == n) return i; // Row is complete

        //                 // Check if the entire column is complete
        //                 int cntCol = 0;
        //                 for (int k = 0; k < m; k++) {
        //                     if (mat[k][l] == -1) cntCol++;
        //                 }
        //                 if (cntCol == m) return i; // Column is complete
        //             }
        //         }
        //     }
        // }

        // return -1; // If no row or column is completely marked

        
         // Step 1: Create a map to store the position of each element in `mat`
        unordered_map<int, pair<int, int>> positionMap;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                positionMap[mat[i][j]] = {i, j};
            }
        }

        // Step 2: Create row and column count arrays
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        // Step 3: Process the elements in `arr`
        for (int i = 0; i < arr.size(); i++) {
            auto it = positionMap.find(arr[i]);
            if (it != positionMap.end()) {
                int row = it->second.first;
                int col = it->second.second;

                // Mark the element by incrementing counts
                rowCount[row]++;
                colCount[col]++;

                // Check if the row or column is complete
                if (rowCount[row] == n || colCount[col] == m) {
                    return i;
                }
            }
        }

        return -1; // If no row or column is completely marked
    }
};
