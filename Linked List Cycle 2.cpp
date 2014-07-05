/************************************************************************/
/* 
˼·��
���ж��Ƿ��л�������ָ�룬һ��ÿ��һ����һ��ÿ������������ָ�����������л��������޻�
�л����������㣬�޻�����NULL��
�л��Ļ���һ��ָ��������㿪ʼ��һ����ͷ��㿪ʼ��ÿ�ζ��ƶ�һ���������ٴ������ĵص���ǻ�����ʼ��
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
//����Ƿ��л����л��򷵻������㣬���򷵻ؿ�
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
	//�õ�������㺯��
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