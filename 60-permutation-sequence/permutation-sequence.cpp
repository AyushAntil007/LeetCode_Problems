class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        for (int i = 1; i < n; i++) { // compute n-1 factorial
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k = k - 1; // actual position
        string ans = "";
        while (true) {
            ans = ans + to_string(numbers[k / fact]);  // add number
            numbers.erase(numbers.begin() + k / fact); // erase number
            if (numbers.size() == 0)
                break;

            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};