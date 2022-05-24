#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    std::stack<ListNode *> s;
    while (head != nullptr) {
      s.push(head);
      head = head->next;
    }
    head = s.top();
    ListNode *t = head;
    s.pop();

    for (int i = s.size(); i > 0; i--) {
      t->next = s.top();
      t = t->next;
      s.pop();
    }
    t->next = nullptr;
    return head;
  }

  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode dummyNode(-1, head);

    ListNode *pre = &dummyNode;
    // go to left - 1 node, pre node position
    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }

    // from pre node walk (right - left + 1) steps, come to right node
    ListNode *rightNode = pre;
    for (int i = 0; i < right - left + 1; i++) {
      rightNode = rightNode->next;
    }

    // prepare cut sub linklist, first get left node, and right node next
    ListNode *leftNode = pre->next;
    ListNode *cur = rightNode->next;

    // cut linklist
    pre->next = nullptr;
    rightNode->next = nullptr;

    reverseList(leftNode);

    // connect linked
    pre->next = rightNode;
    leftNode->next = cur;
    return dummyNode.next;
  }
};
