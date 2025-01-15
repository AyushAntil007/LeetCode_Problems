class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;  // ans mei no of set bits is required answer
        
        int count=0;
        while(ans>0){
            if(ans%2==1)count++;   //just do divide by 2 and record the 1's
            ans=ans/2;
        }
         return count;
    }
};