// https://leetcode.com/problems/design-hashset/
// space O(1000000)
// time O(numberofOps)

class MyHashSet {
    private:
    int hash[1000001];
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        memset(hash,0,sizeof hash);
    }
    
    void add(int key) {
        hash[key] = 1;
    }
    
    void remove(int key) {
        hash[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */