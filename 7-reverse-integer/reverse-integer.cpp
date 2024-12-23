class Solution {
public:
    int reverse(int n) {
        int rev = 0;

        while (n != 0) { // to handle both -ve and +ve
            if (rev > (INT_MAX / 10) || rev < (INT_MIN / 10))
                return 0; //  rev > (INT_MAX / 10) ensures the
                          // multiplication won’t overflow.
            int d = n % 10;
            rev = rev * 10 + d;
            n = n / 10;
        }

        return rev;
    }
};