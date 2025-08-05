class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int>nse(n,n);
        stack<int>st1;

        for(int i=n-1; i>=0; i--){
            while(!st1.empty()  && heights[i]<=heights[st1.top()])st1.pop();
           
            if(st1.empty()) nse[i]=n;
            else  nse[i]=st1.top();
            st1.push(i);

            
    }
    while(!st1.empty())st1.pop();
    
    vector<int>pse(n,-1);
        for(int i=0; i<n; i++){
            while(!st1.empty()  && heights[i]<=heights[st1.top()])st1.pop();
           
            if(st1.empty())pse[i]=-1;
            else  pse[i]=st1.top();
            st1.push(i);

            
    }

     int area=0;
    for(int i=0; i<n; i++){
        area=max(area,(nse[i] - pse[i] -1 )*heights[i]);

    }

    return area;




    }
};