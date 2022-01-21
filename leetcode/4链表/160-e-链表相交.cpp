/*
两个单链表相交的一系列问题
【题目】 在本题中，单链表可能有环，也可能无环。
给定两个 单链表的头节点 head1和head2，
这两个链表可能相交，也可能 不相交。请实现一个函数， 
如果两个链表相交，请返回相交的 第一个节点;
如果不相交，返回null 即可。 
要求:如果链表1 的长度为N，链表2的长度为M，时间复杂度请达到 O(N+M)，
额外 空间复杂度请达到O(1)。
*/

struct Node {
    Node(int v) : value(v) {
        next = nullptr;
    }
    int value;
    struct Node *next;
};

/*
思路：
1. 先判断两个链表是不是有环
2. 无环，检查最后一个节点是不是相同
3. 有环，环入口相同相交节点在环外，否则在环内
*/

struct Node *getLoopNode(struct Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast) {
        slow = slow->next;

        if (fast->next == nullptr) {
            return nullptr;
        }

        fast = fast->next->next;

        if (fast == slow) {
            break;
        }
    }

    fast = head;

    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int listLength(struct Node *head) {
    int len = 0;

    while (head) {
        len++;
        head = head->next;
    }

    return len;
}

struct Node *getNoLoopNode(struct Node *head1, struct Node *head2) {
    int len1 = listLength(head1);
    int len2 = listLength(head2);

    while (len1 < len2) {
        head2 = head2->next;
        len2--;
    }

    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }

    while (head1) {
        if (head1 == head2) {
            return head1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}

struct Node *getIntersectLoopNode(struct Node *head1, struct Node *node1, struct Node *head2, struct Node *node2) {
    struct Node *cur = node1->next;
    struct Node *res = nullptr;

    //Intersect outside loop
    if (node1 == node2) {
        node1->next = nullptr;
        res = getNoLoopNode(head1, head2);
        node1->next = cur;
        return res;
    } else {
        while (cur != node1) {
            if (cur == node2) {
                return node1;
            }

            cur = cur->next;
        }

        return nullptr;
    }
}

struct Node *getIntersectNode(struct Node *head1, struct Node *head2) {
    struct Node *node1 = getLoopNode(head1);
    struct Node *node2 = getLoopNode(head2);
    struct Node *res = nullptr;

    if (node1 == nullptr && node2 == nullptr) {
        res = getNoLoopNode(head1, head2);
    } else if (node1 != nullptr && node2 != nullptr) {
        res = getIntersectLoopNode(head1, node1, head2, node2);
    }

    return res;
}

