class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        //brute force

    //     for (int i = 0; i <= n; i++) {
    //     int flag = 0;
    //     for (int j = 0; j < n; j++) {
    //         if (nums[j] == i) {
    //             // i is present in the array:
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 0) return i;
    // }
    // return -1;


    //better solution
    
    // vector<int>vis(n+1,-1);
    // for (int i = 0; i <n; i++){
    //     vis[nums[i]]=1;
    // }
    // for (int i = 0; i <= n; i++) {
    //     if (vis[i]==-1) {
    //         return i;
    //     }
    // }
    // return -1;


    //optimal solution-......sum

    // int expSum = (n * (n+ 1)) / 2;
    // int actSum = 0;

    // for (int i = 0; i < n; i++) {
    //     actSum += nums[i];
    // }

    // int missingNum = expSum-actSum;
    // return missingNum;


    //optimal solution-....XOR

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++) {
        xor2 = xor2 ^ nums[i]; 
        xor1 = xor1 ^ i; 
    }
    xor1 = xor1 ^ n;   //xor from 0 to n  
    return (xor1 ^ xor2); // the missing number
    
    }
};