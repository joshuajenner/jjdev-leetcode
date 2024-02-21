//Given two integers left and right that represent the range[left, right], 
//return the bitwise AND of all numbers in this range, inclusive.

class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        //s = shift;
        int s = 0;
        while (l < r) {
            l >>= 1;  //l left
            r >>= 1;  //r right
            s++;
        }
        return l << s;
    }
};