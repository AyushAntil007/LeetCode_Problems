class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();

        int l=0, r=n-1;

        int maxArea =0;

        while(l < r) {

            int h = min(height[l], height[r]);
            int b= r - l;

            int area = h*b;

           // cout<< area<<" ";

            maxArea = max(area, maxArea);

            if( height[l]< height[r])l++;
            else  r--;
        }

        return maxArea;
        
    }
};