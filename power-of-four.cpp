// https://leetcode.com/problems/power-of-four/
// space O(1)
// time O(log num base 4)

class Solution {
public:
    bool isPowerOfFour(int num) {
        int pow = 0;
        while(1LL<<pow < num)
            pow++;
        return ((num > 0 ) && !(pow&1) && !(num%(1LL<<pow)));
    }
};
