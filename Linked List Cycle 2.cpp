/************************************************************************/
/* 
思路：
先判断是否有环：两个指针，一个每次一步，一个每次两步，若两指针相遇，则有环，否则无环
有环返回相遇点，无环返回NULL；
有环的话，一个指针从相遇点开始，一个从头结点开始，每次都移动一步，两者再次相遇的地点就是环的起始点
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
//检测是否有环，有环则返回相遇点，否则返回空
    ListNode *hasCycle(ListNode *head){
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast!=NULL && fast==slow){
                break;
            }
        }
        if(fast!=NULL && fast==slow){
            return fast;
        }else{
            return NULL;
        }
    }
	//得到环的起点函数
    ListNode *detectCycle(ListNode *head) {
        ListNode *meetPoint=hasCycle(head);
        if(meetPoint==NULL){
            return NULL;
        }
        ListNode* begin=head;
        while(1){
            if(begin!=meetPoint){
                begin=begin->next;
                meetPoint=meetPoint->next;
            }
            else{
                break;
            }
        }
        return meetPoint;
        
    }
};