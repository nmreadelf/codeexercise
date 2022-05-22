#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // delete Nth node, need find N + 1 th node

        ListNode dummy(-1, head);

        ListNode* preNth = findNth(&dummy, n);
        ListNode* old = preNth->next;
        preNth->next = preNth->next->next;
        delete old;
        return dummy.next;
    }
    ListNode* findNth(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};


int main() {
	ListNode *head = new ListNode(0);
	ListNode *cur = head;
	for (int i = 1; i < 6; i++) {
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	cur = head->next;
	while (cur != nullptr) {
		std::cout << cur->val << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
	Solution s;
	ListNode* nl = s.removeNthFromEnd(head->next, 2);
	cur = nl;
	while (cur != nullptr) {
		std::cout << cur->val << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
	{
		ListNode *n = new ListNode(1);
		ListNode* nl = s.removeNthFromEnd(n, 1);
		
		while (cur != nullptr) {
			std::cout << cur->val << " ";
			cur = cur->next;
		}
	}
	return 0;
}
