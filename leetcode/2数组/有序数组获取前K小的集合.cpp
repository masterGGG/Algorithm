/*
M个升序数组中获取前K小的集合
*/

/*
思路：大顶堆
堆中每个节点为包括两个成员：所属数组，数组遍历位置
*/
class Solution {
public:
  struct Node {
    vector<int> _vec;
    int _pos;

    Node(vector<int> vec, int pos) : _vec(vec), _pos(pos) {}
  };

  vector<int> minSet(vector<vector<int>> list, int k) {
    struct Cmp {
      bool operator()(Node a, Node b) {
        return a._vec[a._pos] > b._vec[b._pos];
      }
    };

    priority_queue<Node, vector<Node>, Cmp> heap;
    vector<int> res;

    for (int i = 0; i < list.size(); ++i) {
      heap.emplace(Node(list[i], 0));
    }

    while (k-- && heap.size()) {
      auto it = heap.top();
      res.emplace_back(it._vec[it._pos]);
      heap.pop();
      if (it._pos < it._vec.size() - 1) {
        heap.emplace(Node(it._vec, it._pos+1));
      }
    }

    return res;
  }
};