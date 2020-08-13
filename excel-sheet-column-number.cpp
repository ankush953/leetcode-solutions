// https://leetcode.com/problems/excel-sheet-column-number/
// space O(1)
// time O(s.length())

class Solution {
public:
    int titleToNumber(string s) {
        int power = 0;
        int ans = 0;
        for (int i = s.length()-1;i>-1;i--) {
            ans += pow(26, power)*(s[i]-64);
            power++;
        }
        return ans;
    }
};