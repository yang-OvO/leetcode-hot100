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
    ListNode* reverseList1(ListNode* head)
    {
        if (!head) {
            return nullptr;
        }
        if (head->next) {
            ListNode* reversed = reverseList1(head->next);
            head->next->next = head;
            head->next = nullptr;
            return reversed;
        }
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        return reverseList1(head);
    }
};