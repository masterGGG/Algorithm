//层序遍历

class Solution {
public:
  void bfs(std::vector<Node* > queue) {
    std::vector<Node* > childqueue;
    for (int i = 0; i < queue.size() - 1; ++i) {
      queue[i]->next = queue[i+1];
      if (queue[i]->left) {
        childqueue.emplace_back(queue[i]->left);
      }
      if (queue[i]->right) {
        childqueue.emplace_back(queue[i]->right);
      }
    }

    if (queue[queue.size() - 1]->left) {
      childqueue.emplace_back(queue[queue.size() - 1]->left);
    }
    if (queue[queue.size() - 1]->right) {
      childqueue.emplace_back(queue[queue.size() - 1]->right);
    }

    if (childqueue.size()) {
      bfs(childqueue);
    }
  }
  Node* connect(Node* root) {
    if (root && root->left) {
      std::vector<Node* > vec;
      vec.emplace_back(root->left);
      vec.emplace_back(root->right);
      bfs(vec);
    }
    return root;
  }
};

/*
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

进阶：
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
*/
