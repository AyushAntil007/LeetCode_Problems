class Solution {
public:
bool canEat(vector<int>&piles,int h,int k){
    int hoursNeed=0;
    int n=piles.size();

    for(int i=0;i<n;i++){
        hoursNeed+=ceil((double)piles[i] / k);   //count hours of each k set bananas
        if(hoursNeed>h)return false;
    }
    return hoursNeed<=h;
    
}
    int binarySearch(vector<int>&piles,int h,int low,int high){   
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(canEat(piles,h,mid)){   // if speed is enough to eat all bananas within h
                high=mid-1;             //reduce it as we need slow speed
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return binarySearch(piles,h,1,maxi);   // speed is bw 1 ....max(piles)
    }
};