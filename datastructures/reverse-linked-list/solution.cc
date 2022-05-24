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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        std::stack<ListNode*> s;
        while (head != nullptr) {
            s.push(head);
            head = head->next;
        }
        head = s.top();
        ListNode* t = head;
        s.pop();
        
        for (int i = s.size(); i > 0; i--) {
            t->next = s.top();
            t = t->next;
            s.pop();
        }
        t->next = nullptr;
        return head;

    }
};
