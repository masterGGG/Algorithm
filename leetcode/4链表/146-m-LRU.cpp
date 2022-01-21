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
