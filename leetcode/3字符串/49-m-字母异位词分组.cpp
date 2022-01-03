/*
49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母都恰好只用一次。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:
输入: strs = [""]
输出: [[""]]
示例 3:
输入: strs = ["a"]
输出: [["a"]]
 
提示：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
*/
class Solution {
public:
#if 1
  int hash(string str) {
    int h = 0;

    for (auto c : str) {
      h |= 1 << (c - 'a');
    }

    return h;
  }
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<int, int> map_;
    std::vector<std::vector<std::string> > vec_;

    for (auto it : strs) {
      int hash_ = hash(it);

      if (map_.find(hash_) == map_.end()) {
        map_[hash_] = vec_.size();
        vec_.emplace_back(std::vector<std::string>());
      }

      vec_[map_[hash_]].emplace_back(it);
    }

    return vec_;
  }
#else
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<std::string, int> map_;
    std::vector<std::vector<std::string> > vec_;

    for (auto str : strs) {
      std::string sort_(str);
      std::sort(sort_.begin(), sort_.end());

      if (map_.find(sort_) == map_.end()) {
        map_[sort_] = vec_.size();
        vec_.emplace_back(std::vector<std::string>());
      }

      vec_[map_[sort_]].emplace_back(str);
    }

    return vec_;
  }
#endif
};