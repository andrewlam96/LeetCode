class MyHashSet {
    set<int> mySet;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        mySet.insert(key);
    }
    
    void remove(int key) {
        auto itr = mySet.find(key); //first need to find position of key we want to remove
        if(itr != mySet.end()) mySet.erase(itr); //remove if found
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return mySet.count(key); //since keys are unique, we can just check the count
        //other way is to find key and check if it is in set
        //auto itr = mySet.find(key);
        //return itr != mySet.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */