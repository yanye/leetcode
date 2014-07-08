/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 /******************************************
  * 思路：
  * 首先将链表拷贝一份（只拷贝next和label）拷贝的节点分别接在每个原节点的后面，这样长度为N的链表就变成了长度为2N的链表
  * 这时，所有的节点都是可用的，接下来就要复制random节点；
  * 复制完random节点后，再把拷贝的节点分离出来即可
  * 具体细节可参见：http://www.2cto.com/kf/201401/276086.html
  * ****************************************/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return head;
        RandomListNode *begin=head;
        //复制next和label，仅仅只将next的拷贝
        while(begin!=NULL){
            RandomListNode *newNode = new RandomListNode(begin->label);
            newNode->next=begin->next;
            begin->next=newNode;
            begin=begin->next->next;
        }
        begin=head;
        //复制ramdon
        while(begin!=NULL){
            if(begin->random!=NULL){//注意要判断是否为空
                begin->next->random=begin->random->next;
            }
            begin=begin->next->next;
        }
        begin=head;
        RandomListNode* copyHead=head->next;
        //分离出random节点
        while(begin!=NULL){//注意要判断是否为空
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