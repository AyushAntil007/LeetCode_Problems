class Solution {
public:
    bool lemonadeChange(vector<int>& bill) {
        int count5 = 0;
        int count10 = 0;

        int n = 0;
        bool success = true;
        while (n < bill.size()) {
            if (bill[n] == 5) {
                count5++;
            }
           else if (bill[n] == 10) {
                if (count5) {
                    count10++;
                    count5--;
                } else
                    return false;
            }
           else {
                if (count10 && count5) {
                    count10--;
                    count5--;
                } 
                else if (count5 >= 3){
                  count5 -= 3;
                }
                else return false;
                       
                }
            
            n++;
        }
        return true;
    }
};