class Solution {
public:
    bool check(vector<int>& arr) {
        int k;
        int n=arr.size();
        

        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1])continue;
            else{
                k=i;
                if(arr[n-1]>arr[0])return false;
                break;
            }
        }
        for(int i=k+1;i<n;i++){
             if(arr[i]>=arr[i-1])continue;
             else{
               return false;
            }
        }
        return true;
    }
};