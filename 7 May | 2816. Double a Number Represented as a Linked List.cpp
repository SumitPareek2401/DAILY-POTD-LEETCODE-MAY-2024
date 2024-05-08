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
    ListNode * head1;
    ListNode * head2;
    void reverse()
    {
        // Initialize current, previous and next pointers
        ListNode* current = head1;
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
        head1 = prev;
        head2 = head1;
    }

    
    
    ListNode* doubleIt(ListNode* head) {
        head1 = head;
        reverse();
        ListNode * dummy = new ListNode();
        ListNode * temp = dummy;
        int carry = 0;
        // return head1;
        while(head1 || head2 || carry) {
            int s = 0;
            if(head1 != NULL) {
                s += head1 -> val;
                head1 = head1 -> next;
            }

            if(head2 != NULL) {
                s += head2 -> val;
                head2 = head2 -> next;
            }
            s += carry;
            carry = s/10;
            ListNode * newnode = new ListNode(s % 10);
            temp -> next = newnode;
            temp = temp-> next;
        }
        ListNode* current = dummy -> next;
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
        dummy -> next = prev;
        return dummy->next;
    }
};
