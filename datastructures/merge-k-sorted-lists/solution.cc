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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        ListNode dummy(-1);
        ListNode* cur = &dummy;

        auto comp = []( ListNode* a, ListNode* b ) { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> q(comp);

        for (auto l : lists) {
            if (l == nullptr) {
                continue;
            }
            q.push(l);
        }

        while (!q.empty()) {
            ListNode *n = q.top();
            q.pop();
            cur->next = n;
            if (n->next != nullptr) {
                q.push(n->next);
            }
            cur = cur->next;
        }

        return dummy.next;
    }
};

