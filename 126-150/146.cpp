class LRUCache {
public: // by @afernandez90 @linz36
  int size;
  std::list<int> lru;
  std::unordered_map<int, list<int>::iterator> mp; // key->iterator
  std::unordered_map<int, int> kv;                 // key->value
  LRUCache(int capacity) : size(capacity) {}
  int get(int key) {
    if (kv.count(key) == 0)
      return -1;
    update_lru(key);
    return kv[key];
  }

  void put(int key, int value) {
    if (kv.size() == size && kv.count(key) == 0)
      evict();
    update_lru(key);
    kv[key] = value;
  }
  void update_lru(int key) {
    if (kv.count(key))
      lru.erase(mp[key]);
    lru.push_front(key);
    mp[key] = lru.begin();
  }
  void evict() {
    mp.erase(lru.back());
    kv.erase(lru.back());
    lru.pop_back();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
