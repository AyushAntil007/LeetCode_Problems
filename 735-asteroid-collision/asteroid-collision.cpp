class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size();

        vector<int> ans;
        stack<int> st;

        for(int i=0; i< n; i++){
            if(ast[i]> 0) st.push(ast[i]);

            else {
                while(!st.empty()  && st.top()>0 && abs(ast[i])>st.top() )st.pop();
                if(!st.empty() && st.top()== abs(ast[i]))st.pop();
                else if(st.empty()  || st.top()<0) st.push(ast[i]);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());


        return ans;

    }
};