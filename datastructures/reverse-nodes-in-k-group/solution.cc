/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverse(ListNode *a, ListNode *b) {
    ListNode *pre, *cur, *nxt;
    pre = nullptr;
    cur = a;
    nxt = a;
    // while 终止的条件改一下就行了
    while (cur != b) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    // 返回反转后的头结点
    return pre;
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }
    // 区间 [a, b) 包含 k 个待反转元素
    ListNode *left = head;
    ListNode *right = head;

    for (int i = 0; i < k; i++) {
      // 不足 k 个，不需要反转，base case
      if (right == nullptr) {
        return head;
      }
      right = right->next;
    }
    // 反转前 k 个元素
    ListNode *newHead = reverse(left, right);
    // 递归反转后续链表并连接起来
    left->next = reverseKGroup(right, k);

    return newHead;
  }
};
