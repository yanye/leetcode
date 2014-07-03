/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /********************/
 /*
 ˼·��
 ����������ǲ��ϵĽ��µ�Ԫ�ز�����ǰ�����ź����������
 */
 /********************/
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *begin=new ListNode(-1);//�����������ͷ�����һ��ͷ����Ϊ�Ժ���������ϵ�����head�϶�����ʱ�仯�������ټ����ͷ�����Զ�λ�ʼ�Ľڵ�
        ListNode *tmpbegin=begin;//Ϊ��ǰͷ������ʱֵ
        tmpbegin->next=head;//���½�������ָ��ǰ����ͷ��
        ListNode* nextNode=head->next;//nextNode��ʾ��һ���ڵ�
        ListNode* preNode=head;//��¼nextnode��ǰһ���ڵ�
        while(nextNode){//��һ���ڵ�ǿ�
            tmpbegin=begin;//��Զ���ʼ��ͷ�ڵ�Ѱ�Һ��ʲ����λ��
            while(tmpbegin->next != nextNode && tmpbegin->next->val < nextNode->val){//�ڵ�ǰ�ڵ���ǰ�Ľڵ���Ѱ�Һ��ʲ����λ��
                tmpbegin=tmpbegin->next;
            }
            if(tmpbegin->next==nextNode){//���ֵ�ǰ�ڵ�λ�ò��ý�����ֱ����󻬶�һ��
                preNode=nextNode;
                nextNode=nextNode->next;
            }else{//��Ҫ�����ڵ�
                ListNode* tmpswap=tmpbegin->next;//��������ڵ����һ���ڵ㱣������
                tmpbegin->next=nextNode;
                preNode->next=nextNode->next;//ע����Ҫ�����ź������������һ���ڵ�ָ��nextNode����һ���ڵ�
                nextNode->next=tmpswap;
                nextNode=preNode->next;
            }
        }//���ź���
        ListNode* recbegin=begin;
        begin=begin->next;
        delete recbegin;//ɾ���¼����ͷ��� 
        return begin;
    }
};