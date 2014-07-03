/************************************************************************/
/* 
˼·�����ù鲢����ķ������鲢������������ȶ�����ֳ������֣�Ȼ�������ֱַ���������ź����������кϲ�
ע��ĵ㣺�߼�һ��Ҫ����������ֻ��ֺ����׳��������޵ݹ飬��������������ʱ��ȡ��ڵ��nextֵʱ��һ��Ҫ�ж����Ƿ����
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
    // ���ź��������ֳ����룬�����м���Ǹ��ڵ㣬ע�⣬����������ڵ㣬�±�Ϊ0��1�Ļ���һ��Ҫ�����±�Ϊ0�Ľڵ㣡
    //������Ϊ������sortlist��ʱ�򣬻�ѵõ����м��Ǹ��ڵ����ǰ��һ�����֣����м�ڵ��Ժ�Ĳ��֣��������ܽ�ڵ㣩���ں���Ĳ���
    //���������ֻ�������ڵ㣬0��1��������ص�Middle��1����0��1��Ϊǰ�沿�֣�����������ѭ����
    ListNode *getMid(ListNode *head){
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast&&fast->next){//��ΪҪ�õ�fast->next->next����һ��Ҫ�ж�fast->next�Ƿ����
            fast=fast->next->next;
            if (fast==NULL)
            {//��֤���ص�������ȡ���Ľڵ�
                return slow;
            }else{
                slow=slow->next;
            }
            
        }
        return slow;

    }
    //�ϲ������ź��������
    ListNode* Mergelist(ListNode *a, ListNode *b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* tempbegin=new ListNode(-1);
        ListNode* recbegin=tempbegin;
        while(a&&b){//����С�����������ӵ�tempbegin�������У����������ָ�뽻��˳�����׳���
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
    //�������������������
    ListNode *sortList(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return head;
        } 
        ListNode *middle=getMid(head);
        ListNode *middle_start=NULL;
        if(middle){//��ΪҪ�õ�middle->next������һ��Ҫ�ж�middle�Ƿ���ڣ�
            middle_start=middle->next;
            middle->next=NULL;
        }
        return Mergelist(sortList(head),sortList(middle_start));
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
    head = s.sortList(head) ;
    while(head)
    {
        cout << head->val << " " ;
        head = head->next ;
    }
    cout << endl ;
    return 0 ;
}