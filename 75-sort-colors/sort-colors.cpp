class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;

       while(mid<=high){
            if(nums[mid]==0){      // 0 
                swap(nums[mid],nums[low]);  
                mid++;
                low++;
            }
            else if(nums[mid]==2){    // 2.......hum pichse kuch la re hai ..maybe vo zero ajaye isliye id ko nahi increse karenge
                swap(nums[high],nums[mid]);
                high--;
               
            }
            else{      // 1
                mid++;
            }
            
        }
    }
};