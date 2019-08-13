//
// Created by yanpan on 2019/7/14.
//
#if 0
#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        int res = -1;
        auto it = hash.find(key);
        if(it == hash.end())
            return res;
        else
        {
            res = it -> second -> second;
            _list.erase(it -> second);
            _list.push_front(make_pair(key, res));
            hash[key] = _list.begin();
        }

        return res;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if(it != hash.end())
            _list.erase(it -> second);
        _list.push_front(make_pair(key, value));
        hash[key] = _list.begin();
        if(hash.size() > cap)
        {
            int k = _list.rbegin() -> first;

            hash.erase(k);
            _list.pop_back();
        }
    }
private:
    int cap;
    list<pair<int, int>> _list;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main()
{
    LRUCache lru(2);
    lru.put(1,10);
    lru.put(2,2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    lru.get(2);
    lru.put(4, 4);
    cout << lru.get(1) << endl;       // 返回 -1 (未找到)
    cout << lru.get(3) << endl;       // 返回  3
    cout << lru.get(4) << endl;       // 返回  4
}
#endif