// https://leetcode.com/problems/add-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        return (num % 9 ? num % 9 : (num ? 9 : 0));
    }
};

int main()
{
    int num;
    cin >> num;
    cout << (new Solution())->addDigits(num);
}
