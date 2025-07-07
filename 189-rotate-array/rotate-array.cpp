class Solution {
public:

void reverse(vector<int>&nums,int start,int end){
    while(start<=end){
        swap(nums[start],nums[end]);
        start++;
        end--;
    }
}
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1||k==0)return;

        //Approach-1.....Shifting 

        // for(int i=0;i<k;i++){
        //     int temp=nums[n-1];
        //     for(int j=n-1;j>0;j--){
        //         nums[j]=nums[j-1];
        //     }
        //     nums[0]=temp;
        // }

        //Approach-2.....Storing

        // vector<int>temp(k+1);

        // for(int i=n-k;i<n;i++){
        //     temp[i-(n-k)]=nums[i];
        // }
        // for(int i=n-k-1;i>=0;i--){
        //     nums[i+k]=nums[i];
        // }
        // for(int i=0;i<k;i++){
        //     nums[i]=temp[i];
        // }


        //Approach-3.....3 times reverse
        
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);




        
    }
};