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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head ;
        ListNode* odd = head ;
        ListNode* even = head->next ;
        ListNode* evenhead = even ;
        if (odd == nullptr || even == nullptr) return head ;
        ListNode* temp = head->next->next ;
        if (temp == nullptr) {
            return head ;
        }
        bool flag = true;
        while(temp != nullptr){
            if (flag){
                odd->next = temp ;
                odd = odd->next ;
            } else {
                even->next = temp ;
                even = even->next ;
            }
            flag = !flag ;
            temp = temp->next ;
        }
        odd->next = evenhead ;
        even->next = nullptr ;
        return head ;
    }
};