/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations:
get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 - capacity );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

class LRUCache {
private:
    unordered_map<int,pair<int,list<int>::iterator>> value; // will keep only existing elements
    list<int> accessed; // list to keep track of accessed elements
    int capacity; // capacity of cache
    void erase(int key) {
        auto it = value.find(key); // for map, find returns end if element to find is not in map
        assert(it != value.end()); // if the element is not present, exit
        accessed.erase(it->second.second); // remove the element from both cache and tracking list
        value.erase(it);
    }
    void push(int key, int v) {
        accessed.push_back(key);  // add the key to the end of accessed list
        value[key] = {v, prev(accessed.end())};  // add the element to queue with value and position of value inserted to list at end
    }
public:
    LRUCache(int given_capacity) {
        capacity = given_capacity;
    }
    int get(int key) {
        auto it = value.find(key);
        if(it == value.end()) { // if element if not in list
            return -1; // return -1
        }
        int old_value = it->second.first; // otherwise, store the value
        erase(key); // erase the element from cache and list 
        push(key, old_value); // and add it again, to make it most recently accessed
        return old_value; // return the value for the key
    }
    void put(int key, int v) { 
        if(value.find(key) != value.end()) { // If element is in cache
            erase(key); // erase it, adding it back later to mark at recently used in list
        }
        if((int) value.size() == capacity) { // if the capacity is reached
            assert(!accessed.empty()); // check if the tracking list is not empty
            erase(accessed.front()); // erase the least used element
        }
        push(key, v); // add the element as most recently accessed
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
