/*
思路：二分思想
满二叉树的节点数是2的树高加1次幂减1
*/

int getMostLevel(struct Node *root) {
    if (root == nullptr) {
        return 0;
    }

    int level = 1;

    while (root->left) {
        level++;
        root = root->left;
    }

    return level;
}

int getMostLeftLevel(struct Node *root) {
    int level = 0;

    if (root->left) {
        struct Node *node = root->left;
        level = 1;

        while (node->right) {
            level++;
            node = node->right;
        }
    }

    return level;
}

int getNode(struct Node *root) {
  if (root == nullptr) {
      return 0;
  }

  int level = getMostLevel(root);

  if (level == 1) {
      return 1;
  }

  int leftLevel = getMostLeftLevel(root);
  int count = 1;

  if (level == (leftLevel+1)) {
      count += int(pow(2.0, level - 1)) - 1;
      count += getNode(root->right);
  } else {
      count += int(pow(2.0, level - 2)) - 1;
      count += getNode(root->left);
  }

  return count;
}