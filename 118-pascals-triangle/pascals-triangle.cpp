class Solution {
public:
   int ncr(int n,int r){
    int res=1;
    for(int i=0;i<r;i++){   //ncr calculate    n(n-1)(n-2)....(n-r+1)(n-r)!
        res*=(n-i);                        //  /r! *( n-r)!
        res/=(i+1);
    }
    return res;
   }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int n=numRows;
        for(int row=1;row<=n;row++){
            vector<int>level;
            for(int col=1;col<=row;col++){
                int elt=ncr(row-1,col-1);
                level.push_back(elt);
            }
            ans.push_back(level);
        }
        return ans;
    }
};