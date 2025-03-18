class Solution {
public:
bool checkNice(int left,int right,vector<int>&nums){
    for(int i=left;i<=right;i++){
        for(int j=i+1;j<=right;j++){
            if((nums[i]&nums[j])!=0)return false;
        }
    }
    return true;
}
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int len=1;
        int left=0;

        for(int right=0;right<n;right++){
            // if(right-left+1==1)len=max(len,1);
            if(checkNice(left,right,nums))len=max(len,right-left+1);
            else left++;
              
        }
        return len;
    }
};