/************************************************************************/
/* 
思路：
两个指针，一个每次一步，一个每次两步，若两指针相遇，则有环，否则无环
*/
/************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast!=NULL && slow==fast){
                break;
            }
        }
        if(fast!=NULL && slow==fast){
            return true;
        }else{
            return false;
        }
    }
};