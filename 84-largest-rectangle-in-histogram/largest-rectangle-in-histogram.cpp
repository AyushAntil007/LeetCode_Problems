class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n);  // Default value is n, not 2
        stack<int> st1;

        // Compute Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && heights[i] <= heights[st1.top()])
                st1.pop();
            if (!st1.empty()) nse[i] = st1.top();
            st1.push(i);
        }

        // Clear stack for PSE
        while (!st1.empty()) st1.pop();

        vector<int> pse(n, -1);

        // Compute Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st1.empty() && heights[i] <= heights[st1.top()])
                st1.pop();
            if (!st1.empty()) pse[i] = st1.top();
            st1.push(i);
        }

        // Compute max area
        int area = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            area = max(area, width * heights[i]);
        }

        return area;
    }
};
