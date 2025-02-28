class Solution {
public:
bool possible(vector<int>&bloomDay,int day,int m,int k){
    int cnt=0;
    int noBouquet=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            cnt++;
        }
        else{
            noBouquet+=cnt/k;
            cnt=0;
        }

    }
    noBouquet+=cnt/k;
    return noBouquet>=m;
}

int binarySearch(vector<int>&bloomDay,int m,int k,int low,int high){
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(bloomDay,mid,m,k)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n=bloomDay.size();
        long long val=1LL*m*k;
        if(val>n)return -1;   // required flowers greater than given n flowers

        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){          //find min and max range
            if(bloomDay[i]<=mini)mini=bloomDay[i];
            if(bloomDay[i]>maxi)maxi=bloomDay[i];
        }

        //brute force........seeing at each day
       
        // for(int i=mini;i<=maxi;i++){
        //     if(possible(bloomDay,i,m,k)){
        //         return i;
        //     }
        // }
        // return -1;


        //optimal  solution......binary search

        return binarySearch(bloomDay,m,k,mini,maxi);
       
    }
};