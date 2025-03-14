class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        // if(k>n)return 0;
        // sort(candies.begin(),candies.end());
        // long long i=0;
        // while(i+k-1<n-1){
        //     i++;
        // }
        
        // return candies[i];

        // binary Search
        long long left=1,right = *max_element(candies.begin(), candies.end());
        long long result=0;
        while(left<=right){
            long long mid=(left+right)/2;

            long long countChild=0;
            for(int pile : candies){
                countChild+=pile/mid;
            }
            if(countChild>=k){
                left=mid+1;
                result=mid;
            }
            else{
                right=mid-1;
            }
        }

         return result;

    }
};