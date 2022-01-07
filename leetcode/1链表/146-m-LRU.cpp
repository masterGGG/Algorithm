/*
设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指定最大容量。当缓存被填满时，它应该删除最近最少使用的项目。

它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
*/

//双向链表+哈希表
template <typename Key,typename Val>
class LruCache {
    struct Node{
        Key key;
        Val val;
        Node(Key key,Val val):key(key),val(val);
    }
private:
    std::list<Node>                                             _list;
    std::int64_t                                                _cap;
    std::unordered_map<Key,typename::std::list<Node>::iterator> _cache_map;
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
};
