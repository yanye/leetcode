/************************************************************************/
/* 
思路：采用归并排序的方法，归并排序的是想是先对链表分成两部分，然后两部分分别排序，最后将排好序的数组进行合并
注意的点：逻辑一定要清楚，两部分划分很容易出错导致无限递归，另外对链表操作的时候，取其节点的next值时，一定要判断其是否存在
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
    // 将排好序的数组分成两半，返回中间的那个节点，注意，如果有两个节点，下标为0和1的话，一定要返回下标为0的节点！
    //这是因为在最后的sortlist的时候，会把得到的中间那个节点归于前面一个部分，而中间节点以后的部分（不包含总结节点）归于后面的部分
    //举例；如果只有两个节点，0和1，如果返回的Middle是1，则0和1分为前面部分，这样就无限循环了
    ListNode *getMid(ListNode *head){
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast&&fast->next){//因为要用到fast->next->next，故一定要判断fast->next是否存在
            fast=fast->next->next;
            if (fast==NULL)
            {//保证返回的是向下取整的节点
                return slow;
            }else{
                slow=slow->next;
            }
            
        }
        return slow;

    }
    //合并两个排好序的链表
    ListNode* Mergelist(ListNode *a, ListNode *b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* tempbegin=new ListNode(-1);
        ListNode* recbegin=tempbegin;
        while(a&&b){//将较小的数不断链接到tempbegin的链表中，这里链表的指针交换顺序容易出错
            if(a->val<=b->val){
                tempbegin->next=a;
                tempbegin=a;
                a=a->next;
            }else{
                tempbegin->next=b;
                tempbegin=b;
                b=b->next;
            }
        }
        if(a)
            tempbegin->next=a;
        if(b)
            tempbegin->next=b;
        ListNode* begin=recbegin;
        begin=begin->next;
        delete recbegin;
        return begin;
    }
    //对链表进行排序主函数
    ListNode *sortList(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return head;
        } 
        ListNode *middle=getMid(head);
        ListNode *middle_start=NULL;
        if(middle){//因为要用到middle->next，所以一定要判断middle是否存在！
            middle_start=middle->next;
            middle->next=NULL;
        }
        return Mergelist(sortList(head),sortList(middle_start));
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
    head = s.sortList(head) ;
    while(head)
    {
        cout << head->val << " " ;
        head = head->next ;
    }
    cout << endl ;
    return 0 ;
}