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
  bool isPalindrome(ListNode *head) {
    vector<int> v;
    ListNode *tmp = head;
    while (tmp != nullptr) {
      v.push_back(tmp->val);
      tmp = tmp->next;
    }
    int i = v.size() - 1;
    while (head != nullptr) {
      if (head->val != v[i--]) {
        return false;
      }
      head = head->next;
    }
    return true;
  }
};
