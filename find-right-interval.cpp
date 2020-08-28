// https://leetcode.com/problems/find-right-interval/
// space O(N)
// time O(NlogN)

struct Element{
    int startPoint;
    int index;
    Element(int start, int idx){
        startPoint = start;
        index = idx;
    }
};

class Solution {
    static bool fun(const Element *a, const Element *b){
        return a->startPoint < b->startPoint;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Element *>arr;
        for(int i=0;i<intervals.size();i++){
            arr.push_back(new Element(intervals[i][0], i));
        }
        sort(arr.begin(), arr.end(), fun);
        vector<int>ans(n, -1);
        for(int i=0;i<n;i++){
            int key = intervals[i][1];
            int low = 0, high = n-1;
            while(low <= high){
                int mid = (low + high) >> 1;
                if(arr[mid]->startPoint >= key){
                    ans[i] = arr[mid]->index;
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }
        return ans;
    }
};