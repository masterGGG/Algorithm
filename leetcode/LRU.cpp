/*
设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指定最大容量。当缓存被填满时，它应该删除最近最少使用的项目。

它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

示例:

LRUCache cache = new LRUCache( 2 缓存容量);

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
*/

struct Node {
    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }

    int key;
    int value;
    struct Node * prev;
    struct Node * next;
};

class LRUCache {
public:

    unordered_map<int, struct Node *> _map;
    struct Node *head;
    int _capacity;

    LRUCache(int capacity) {
        _capacity = capacity;
        head = new struct Node(-1, -1);
        head->prev = head;
        head->next = head;
    }

    void move2tail(struct Node *node) {
        if (node->next == head) {
            return;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;

        head->prev->next = node;
        node->prev = head->prev;
        node->next = head;
        head->prev = node;
    }

    void removehead(struct Node *node) {
        if (node) {
            auto mapit = _map.find(head->next->key);
            _map.erase(mapit);
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }

        return ;
    }

    int get(int key) {
        if (_map.empty()) {
            return -1;
        }

        auto it = _map.find(key);

        if (it == _map.end()) {
            return -1;
        }

        struct Node *node = _map[key];
        move2tail(node);

        return node->value;
    }
    
    void put(int key, int value) {
        auto it = _map.find(key);

        if (it == _map.end() && _map.size() == _capacity) {
            removehead(head->next);
        } else if (it != _map.end()) {
            struct Node *node = _map[key];
            node->value = value;
            move2tail(node);

            return ;
        }
        
        struct Node *node = new struct Node(key, value);
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
        node->next = head;
        _map.emplace(key, node);

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




//Impl by curlwang
#include <unordered_map>
#include <vector>
#include <list>

template <typename Key,typename Val>
class LruCache {
    struct Node{
        Key key;
        Val val;
        Node(Key key,Val val):key(key),val(val);
    }
public:
    LruCache(int cap):_cap(1<<cap){}
    
    ~LruCache(){}

    void Put(Key key,Val val){
        auto it = _cache_map.find(key);
        if (it == _cache_map.end()){
            Node node=Node(key,val);
            _list.push_front(node);
            std::pair<Key,typename::std::list<Node>::iterator> pair(key,_list.begin());
            _cache_map.insert(pair);
            if (_cache_map.size() > _cap){
                _cache_map.erase(_list.back().key);
                _list.pop_back();
            }
        }else{
            it->second->value = val;
            _list.splice(_list.begin(),_list,it->second);
        }
    }

    Val Get(Key key){
        auto it = _cache_map.find(key);
        if(it == _cache_map.end()){
            return static_cast<Val>(-1);
        }
        _list.splice(_list.begin(),_list,it->second);
        return it->second->value;
    }

#ifdef DEBUG
    void show() {
        cout << "Lrulist: ";

        for (auto i : _list) {
            cout << "(" << i.key << " " << i.value << ") -> ";
        }

        cout << endl;
    }
#endif
private:
    std::list<Node>                                             _list;
    std::int64_t                                                _cap;
    std::unordered_map<Key,typename::std::list<Node>::iterator> _cache_map;
};

#ifdef DEBUG
int main() {
    LruCache<int, int> lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    lru.show();
    cout << "lru.get(1):" << lru.get(1) << endl;       // 返回  1
    lru.show();
    lru.put(3, 3);    // 该操作会使得密钥 2 作废
    lru.show();
    lru.get(2);       // 返回 -1 (未找到)
    cout << "lru.get(2):" << lru.get(2) << endl; 
    lru.put(4, 4);    // 该操作会使得密钥 1 作废
    lru.show();
    cout << "lru.get(1):" << lru.get(1) << endl;       // 返回 -1 (未找到)
    cout << "lru.get(3):" << lru.get(3) << endl;        // 返回  3
    lru.show();
    cout << "lru.get(4):" << lru.get(4) << endl;        // 返回  4
    lru.show();

    return 0;
}
#endif