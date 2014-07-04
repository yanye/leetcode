/************************************************************************/
/* 
˼·��
���ȶ��б�ֳ�ǰ�����룬Ȼ��Ժ���һ����о͵����ã����ǰ������ϲ�����
*/
/************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <fstream>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public:
	//��ȡ�м�ڵ㺯���������м�ڵ㣬�������ֻ�������ڵ�0��1���򷵻�0����ڵ�
    ListNode* getMid(ListNode *head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            if(fast==NULL){
                break;
            }
            slow=slow->next;
        }
        return slow;
    }
	//����͵����ã�ע���±��ָ��
    ListNode* reverseList(ListNode *head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* pre=NULL;
        ListNode* curr=head;
        ListNode* after=head->next;
        while(curr!=NULL){
            after=curr->next;
            curr->next=pre;
            pre=curr;
            curr=after;
        }
        return pre;
        
    }
	//�ϲ���������
    void mergeList(ListNode* list1, ListNode* list2){
        if(list1==NULL) return ;
        if(list2==NULL) return ;
        ListNode* result=list1;
        ListNode* pos1=list1;
        ListNode* pos2=list2;
        while(pos2!=NULL && pos1!=NULL){//һ��Ҫע��resultҪ����ǰ����
            pos1=result->next;//�ȱ���list1����һ���ڵ�
            result->next=pos2;//��list1ָ��list2�Ľڵ�
            pos2=pos2->next;//list2�ڵ�������
            result=result->next;//һ��Ҫ�ǵø���result����Ϊresult��next�Ѿ�ָ������pos2��resultҪ�ߵ�pos2��λ��
            result->next=pos1;//�ٰ�resultָ��ȥ��list1
            result=result->next;//ע��Ҫ����result��
        }
        return;
    }
	//���ź���
    void reorderList(ListNode *head) {
        if(head==NULL || head->next==NULL) return ;
        ListNode* midNode=getMid(head);//��ȡ�м�ڵ�
		//��list�ֳ�����
        ListNode* list2=NULL;
        if(midNode->next){
            list2=midNode->next;
            midNode->next=NULL;
        }
        ListNode* list2Rev=reverseList(list2);//�Ժ�벿������
        mergeList(head,list2Rev);//�ϲ���������
        
    }
};
void insertBack(ListNode** head, ListNode** tail,  ListNode* n) //��β������
{	
    if (n)
    {
        if (*head == NULL)
        {
            *head = n ;
            *tail = n ;
        }
        else
        {
            (*tail)->next = n ;
            *tail = n ;
        }
    }
}

int main(int argc, char** argv)
{

    ifstream in("data.txt") ;
    ListNode* head = NULL ;
    ListNode* tail = NULL ;
    int val ;

    Solution s ;
    while(in >> val)
    {
        ListNode*tmp = new ListNode(val) ;
        insertBack(&head, &tail, tmp) ;
    }
    s.mergeList(head) ;
    while(head)
    {
        cout << head->val << " " ;
        head = head->next ;
    }
    cout << endl ;
    return 0 ;
}