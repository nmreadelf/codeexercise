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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    int last = head->val;
    ListNode **curr = &(head->next);
    while (*curr != nullptr) {
      ListNode *entry = *curr;
      if (entry->val == last) {
        *curr = entry->next;
        delete entry;
      } else {
        last = entry->val;
        curr = &((*curr)->next);
      }
    }
    return head;
  }
};
