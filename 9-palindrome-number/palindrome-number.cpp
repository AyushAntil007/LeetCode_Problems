class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0;
        int n = x;

        if (n < 0)
            return false; // From left to right, it reads -121. From right to
                          // left, it becomes 121-. Therefore it is not a
                          // palindrome.

        while (n != 0) { // to handle both -ve and +ve
            if (rev > (INT_MAX / 10) || rev < (INT_MIN / 10))
                return false; //  rev > (INT_MAX / 10) ensures the
                              // multiplication won’t overflow.
            int d = n % 10;
            rev = rev * 10 + d;
            n = n / 10;
        }

        return rev == x;
    }
};