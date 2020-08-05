// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// space O(256) i.e. constant
// time O(length(s))

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.length();
        int i,start=0,end=0,ans=0,freq[256];
        for(i=0;i<256;i++)
            freq[i] = 0;
        while(end<n)
        {
            if(freq[s[end]]==0)
            {
                freq[s[end]]++;
                end++;
                ans = max(ans,end-start);
            }
            else
            {
                freq[s[start]]--;
                start++;
            }
            
        }
        return ans;
    }
};
