class MyHashMap {
    map<int, int> myMap;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        //need to check if key is in map first because you cannot have multiple of the same keys
        auto itr = myMap.find(key);
        if(itr == myMap.end()) myMap.insert({key, value}); //if it's not there insert key and value
        else myMap[key] = value; //otherwise update the value for the key
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto itr = myMap.find(key);
        if(itr != myMap.end()) return itr->second; //if key is found (!= end) return value
        return -1; //otherwise return -1
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto itr = myMap.find(key);
        if(itr != myMap.end()) myMap.erase(key); //if key is found erase it
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */