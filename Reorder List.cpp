/************************************************************************/
/* 
思路：
首先对列表分成前后两半，然后对后面一半进行就地逆置，最后将前后两半合并即可
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
	//获取中间节点函数，返回中间节点，例如如果只有两个节点0和1，则返回0这个节点
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
	//链表就地逆置，注意下标的指向
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
	//合并两个链表
    void mergeList(ListNode* list1, ListNode* list2){
        if(list1==NULL) return ;
        if(list2==NULL) return ;
        ListNode* result=list1;
        ListNode* pos1=list1;
        ListNode* pos2=list2;
        while(pos2!=NULL && pos1!=NULL){//一定要注意result要不断前进！
            pos1=result->next;//先保存list1后面一个节点
            result->next=pos2;//将list1指向list2的节点
            pos2=pos2->next;//list2节点往后走
            result=result->next;//一定要记得更新result，因为result的next已经指定成了pos2，result要走到pos2的位置
            result->next=pos1;//再把result指回去到list1
            result=result->next;//注意要更新result！
        }
        return;
    }
	//重排函数
    void reorderList(ListNode *head) {
        if(head==NULL || head->next==NULL) return ;
        ListNode* midNode=getMid(head);//获取中间节点
		//将list分成两半
        ListNode* list2=NULL;
        if(midNode->next){
            list2=midNode->next;
            midNode->next=NULL;
        }
        ListNode* list2Rev=reverseList(list2);//对后半部分逆置
        mergeList(head,list2Rev);//合并两个链表
        
    }
};
void insertBack(ListNode** head, ListNode** tail,  ListNode* n) //从尾部插入
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