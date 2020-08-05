// https://leetcode.com/problems/valid-palindrome/
// space O(n)
// time O(n)

class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        for(char ch: s){
            if(ch > 64 && ch < 91) newS += ch;
            else if(ch > 96 && ch < 123) newS += (ch-32);
            else if(ch > 47 && ch < 58) newS += ch;
        }
        for(int i=0, j = newS.size()-1;i<j;i++,j--){
            if(newS[i]!=newS[j]){
                return false;
            }
        }
        return true;
    }
};
