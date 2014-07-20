/************************************************************************/
/* 
˼·��
1�����������վΪ0����ʼ����������0

2��������������վ����������

3�����������������0����������һ��վ�����������վǰ��һ����վ

�ظ�2��3����ֱ�����г�վ�����ꡣ�����������ʣ����ڵ���0�����س�����վ�����򷵻أ�1.
*/
/************************************************************************/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int length=gas.size();
        int start=0;//��ʶ��ʼ��
        int end=0;//��ʶ������
        int pos=0;//��ʶ��ǰλ��
        int gastotal=0;
        for(int i=0;i<length;i++){//��ʾѭ������N���ص�
            gastotal+=gas[pos]-cost[pos];
            if(gastotal>=0){
                end++;
                pos=end;
            }else{
                start--;
                if(start<0){
                    start=length+start;
                }
                pos=start;
            }
        }
        if(gastotal>=0){
            return start;
        }else{
            return -1;
        }
    }
};