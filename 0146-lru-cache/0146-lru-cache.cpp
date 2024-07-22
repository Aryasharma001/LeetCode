class LRUCache {
public:
    LRUCache(int capacity): capacity(capacity) {
        
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        } else {
            // Move the accessed key to the front of the list
            usage.splice(usage.begin(), usage, it->second.second);
            return it->second.first;
        }
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Key already exists, update the value and move to the front
            it->second.first = value;
            usage.splice(usage.begin(), usage, it->second.second);
        } else {
            if (cache.size() == capacity) {
                // Remove the least recently used element
                int lru_key = usage.back();
                usage.pop_back();
                cache.erase(lru_key);
            }
            // Insert the new key-value pair
            usage.push_front(key);
            cache[key] = {value, usage.begin()};
        }
    }
    
private:
    int capacity;
    list<int> usage; // Doubly-linked list to maintain usage order
    unordered_map<int, pair<int, list<int>::iterator>> cache; // Hash map to store key-value pairs and list iterators
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */