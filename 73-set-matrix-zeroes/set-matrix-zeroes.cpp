class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix[0].size();
        int m=matrix.size();

        //approacxh-1......loops

        // for ( int i=0;i<m; i++){
        //     for( int j=0; j<n; j++){
        //         if(matrix[i][j]==0){
                    
        //             for(int k=0; k<n; k++){
        //                 if(matrix[i][k]!=0){
        //                     matrix[i][k]=-1;
        //                 }
                       
        //             }
        //             for ( int k=0; k<m; k++){
        //                 if(matrix[k][j]!=0){
        //                     matrix[k][j]=-1;
        //                 }
                        
        //             }
        //         }
        //     }
        // }
        //  for ( int i=0;i<m; i++){
        //     for( int j=0; j<n; j++){
        //         if(matrix[i][j]==-1){
                    
        //             matrix[i][j]=0;
        //         }
        //     }
        // }


        //Approach-2.....mark index i , j

        // vector<int>sRow(m);
        // vector<int>sCol(n);
        // for ( int i=0;i<m; i++){
        //     for( int j=0; j<n; j++){
        //         if(matrix[i][j]==0){
                    
        //             sRow[i]=1;
        //             sCol[j]=1;
        //         }
        //     }
        // }

        //  for ( int i=0;i<m; i++){
        //     for( int j=0; j<n; j++){
        //         if(sRow[i]|| sCol[j]){
                    
        //             matrix[i][j]=0;
        //         }
        //     }
        // }

    // Approach-3......store index i,j



    set<int>sRow;
        set<int>sCol;
        for ( int i=0;i<m; i++){
            for( int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    
                    sRow.insert(i);
                    sCol.insert(j);
                }
            }
        }

        for(auto it: sRow){
            for(int k=0; k<n; k++){
                
                    matrix[it][k]=0;
                
                       
            }
        }
        
        for(auto it : sCol){
            for ( int k=0; k<m; k++){
                
                    matrix[k][it]=0;
                
                
            }
        }




        
                    
         


        
    }
};