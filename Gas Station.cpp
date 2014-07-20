/************************************************************************/
/* 
思路：
1：假设出发车站为0，初始化车内油量0

2：车内油量＝车站油量－消耗

3：如果车内油量大于0，车开到下一车站，否则出发车站前移一个车站

重复2，3步，直到所有车站遍历完。如果车内油量剩余大于等于0，返回出发车站，否则返回－1.
*/
/************************************************************************/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int length=gas.size();
        int start=0;//标识开始点
        int end=0;//标识结束点
        int pos=0;//标识当前位置
        int gastotal=0;
        for(int i=0;i<length;i++){//表示循环遍历N个地点
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