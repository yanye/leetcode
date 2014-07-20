/************************************************************************/
/* 
思路：循环遍历每个节点，假设从该节点出发，会不会有油箱油量为负数的情况，如果有则返回-1
*/
/************************************************************************/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int length=gas.size();
        int start=-1;
        for(int i=0;i<length;i++){//表示循环遍历N个地点
            int gastmp=0;
            bool finishFlag=true;
            for(int j=0;j<length;j++){//对每个地点，看能不能环绕一圈
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