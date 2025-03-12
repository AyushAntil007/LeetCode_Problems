class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int lsum=0, rsum=0;
        
        int n=cardPoints.size();

        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        int maxScore=lsum;
        int r=n-1;
        int l=k-1;
        
        while(l>=0){
            lsum-=cardPoints[l--];
            rsum+=cardPoints[r--];
            maxScore=max(rsum+lsum,maxScore);
        }
        return maxScore;
    }
};