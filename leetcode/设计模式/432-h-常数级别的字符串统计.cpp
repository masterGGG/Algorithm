/*
请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
实现 AllOne 类：
AllOne() 初始化数据结构的对象。
inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。*/

class AllOne {
public:
    std::unordered_map<std::string, int> keys;
    std::map<int, std::list<std::string>> counts;
    AllOne() {

    }
    
    void inc(string key) {

    }
    
    void dec(string key) {

    }
    
    string getMaxKey() {

    }
    
    string getMinKey() {

    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */