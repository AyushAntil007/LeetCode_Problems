class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int elt1=INT_MIN,elt2=INT_MIN;

        vector<int>ans;

        int n=nums.size();

        for(int i=0;i<n;i++){

            if(cnt1==0&& elt2!=nums[i]){
                elt1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0&& elt1!=nums[i]){
                elt2=nums[i];
                cnt2=1;
            }
            else if(nums[i]==elt1)cnt1++;
            else if(nums[i]==elt2)cnt2++;

            else cnt1--,cnt2--;

        }
        // Reset counts to verify actual frequency
       cnt1 = cnt2 = 0;
for (int num : nums) {
    if (num == elt1) cnt1++;
    else if (num == elt2) cnt2++;
}

        if(cnt1>n/3)ans.push_back(elt1);
        if(cnt2>n/3)ans.push_back(elt2);

        return ans;
    }
};