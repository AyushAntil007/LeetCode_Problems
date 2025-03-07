class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime(right+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i<=sqrt(right);i++){
            if(prime[i]==1){
                for(int j=i*i;j<=right;j+=i){
                    prime[j]=0;
                }
            }
        }
        vector<int>nums;
        for(int i=left;i<=right;i++){
            if(prime[i]==1){
                nums.push_back(i);
            }
        }
        
        int n=nums.size();
        int diff=INT_MAX;
        int a=-1,b=-1;
        for(int i=1;i<n;i++){
           if(nums[i]-nums[i-1]<diff){
              diff=nums[i]-nums[i-1];
              a=nums[i-1];
              b=nums[i];
           }
        }
        return {a,b};
    }
};