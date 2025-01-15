class Solution {
public:
    bool isPowerOfTwo(int n) {

        //method 1
        // bool check = true;

        // while (n > 1) {
        //     if (n % 2 != 0) {//check oddd
        //         return false;
        //     }
        //     n = n >> 1;  //shift one bit right
        // }
        // return true;

        //method 2
        return (n > 0) && ((n & (n - 1)) == 0);

    }
};