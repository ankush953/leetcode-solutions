// https://leetcode.com/problems/iterator-for-combination/
// space O(nCk)
// time O(n!)

class CombinationIterator {
private:
    vector<string>allStrings;
    int index = 0;

    void precomputeAll(string currS, string s, int k, int index) {
        if (currS.size() == k) {
            allStrings.push_back(currS);
            return;
        }
        if (index >= s.size()) return;
        for (int i=index;i<s.size();i++) {
            currS += s[i];
            precomputeAll(currS, s, k, i+1);
            currS.pop_back();
        }
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        precomputeAll("", characters, combinationLength, 0);
    }

    string next() {
        return allStrings[index++];
    }

    bool hasNext() {
        return index < allStrings.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */