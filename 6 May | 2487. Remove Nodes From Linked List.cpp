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
    ListNode * head2;
    ListNode * head3;
    void reverse()
    {
        // Initialize current, previous and next pointers
        ListNode* current = head2;
        ListNode *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head2 = prev;
    }
    void reverse2()
    {
        // Initialize current, previous and next pointers
        ListNode* current = head3;
        ListNode *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head3 = prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head2 = head;
        reverse();
        ListNode * temp = head2;
        ListNode * temp2 = head2 -> next;
        while(temp2 != NULL) {
            if(temp -> val > temp2 -> val) {
                temp -> next = temp2 -> next;
                temp2 = temp2 -> next;
            } else if(temp2 -> val >= temp -> val) {
                temp2 = temp2 -> next;
                temp = temp -> next;
            }
        }
        head3 = head2;
        reverse2();
        return head3;
    }
};
