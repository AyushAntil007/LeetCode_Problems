class Solution {
public:
    // void solve(int num, int k, int n, vector<vector<int>>&ans, int sum, vector<int>&layer){
    //     if (sum > n || layer.size() > k || num > 9) return; // prune invalid cases
        
        
    //         if(sum==n && layer.size()==k){
    //             ans.push_back(layer);
    //             return;
    //         }
        

    //     layer.push_back(num);
    //     solve(num+1,k,n,ans,sum+num,layer);
    //     layer.pop_back();
    //     solve(num+1,k,n,ans,sum,layer);
    // }


    void solve(int k,int target,  int num, vector<vector<int>>&ans, vector<int>&layer){
        if(k==0&& target==0){
            ans.push_back(layer);
            return;
        }


        for( int i=num; i<=9; i++){
            if(i>target|| k<=0)break;

            layer.push_back(i);
            solve(k-1,target-i,i+1,ans,layer);
            layer.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>layer;
        //solve(1,k,n,ans,0,layer);

        solve(k,n,1,ans,layer);

        return ans;
    }
};