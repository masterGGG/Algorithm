/*
49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母都恰好只用一次。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

/*
思路：用hash值记录字符串，统计过的字符串加入哈希表中。
*/
class Solution {
public:
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
};