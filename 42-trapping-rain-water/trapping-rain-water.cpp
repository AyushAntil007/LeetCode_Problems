class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int>preSum(n,0);
        vector<int>postSum(n,0);

        preSum[0]=height[0];
        for(int i=1;i<n;i++){

            preSum[i]=max(preSum[i-1],height[i]);

        }    
        postSum[n-1]=height[n-1];

        for(int i= n-2; i>=0; i--){
            postSum[i]=max(postSum[i+1],height[i]);
        }  

        int count=0;
        for( int i=0; i<n; i++){
            count+=min(preSum[i], postSum[i])-height[i];
        }

        return count;
    }
};