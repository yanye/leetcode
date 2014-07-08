/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 /******************************************
  * ˼·��
  * ���Ƚ�������һ�ݣ�ֻ����next��label�������Ľڵ�ֱ����ÿ��ԭ�ڵ�ĺ��棬��������ΪN������ͱ���˳���Ϊ2N������
  * ��ʱ�����еĽڵ㶼�ǿ��õģ���������Ҫ����random�ڵ㣻
  * ������random�ڵ���ٰѿ����Ľڵ�����������
  * ����ϸ�ڿɲμ���http://www.2cto.com/kf/201401/276086.html
  * ****************************************/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return head;
        RandomListNode *begin=head;
        //����next��label������ֻ��next�Ŀ���
        while(begin!=NULL){
            RandomListNode *newNode = new RandomListNode(begin->label);
            newNode->next=begin->next;
            begin->next=newNode;
            begin=begin->next->next;
        }
        begin=head;
        //����ramdon
        while(begin!=NULL){
            if(begin->random!=NULL){//ע��Ҫ�ж��Ƿ�Ϊ��
                begin->next->random=begin->random->next;
            }
            begin=begin->next->next;
        }
        begin=head;
        RandomListNode* copyHead=head->next;
        //�����random�ڵ�
        while(begin!=NULL){//ע��Ҫ�ж��Ƿ�Ϊ��
            RandomListNode* tmp=begin->next;
            begin->next=begin->next->next;
            if(tmp->next!=NULL){
                tmp->next=tmp->next->next;
            }
            begin=begin->next;
        }
        return copyHead;
    }
};