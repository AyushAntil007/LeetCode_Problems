class Solution {
public:
void findXOR(int i,int n,int xor_cur,vector<int>&nums,vector<int>&ans){
    if(i==n){
        ans.push_back(xor_cur);
        return;
    }
    findXOR(i+1,n,xor_cur^nums[i],nums,ans);
    findXOR(i+1,n,xor_cur,nums,ans);
}
    int subsetXORSum(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();

        findXOR(0,n,0,nums,ans);

        int xor_total=0;
        for(int it: ans){
            xor_total+=it;
        }
        return xor_total;
    }
};