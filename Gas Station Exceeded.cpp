/************************************************************************/
/* 
˼·��ѭ������ÿ���ڵ㣬����Ӹýڵ�������᲻������������Ϊ�����������������򷵻�-1
*/
/************************************************************************/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int length=gas.size();
        int start=-1;
        for(int i=0;i<length;i++){//��ʾѭ������N���ص�
            int gastmp=0;
            bool finishFlag=true;
            for(int j=0;j<length;j++){//��ÿ���ص㣬���ܲ��ܻ���һȦ
                int pos=(i+j)%length;
                gastmp+=gas[pos];
                if(gastmp>=cost[pos]){
                    gastmp=gastmp-cost[pos];
                }
                else{
                    finishFlag=false;
                    break;
                }
            }
            if(finishFlag==true){
                start=i;
                break;
            }
        }
        return start;
    }
};