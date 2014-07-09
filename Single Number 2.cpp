/*******************************************************/
/*
˼·: ��32λ�����飬����ÿ��bitλ�ϳ��ֵ�1�Ĵ�����Ȼ��ģ����ͬ�Ĵ��������ɵõ��Ǹ���ͬ����
*/
/*******************************************************/


#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n<=0 || A == NULL) return NULL;
        if(n==1) return A[0];
        int bits[32]={0};
        int times=3;
        int result=0;
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                int tmpbit=(A[j]>>i)&1;//��ȡ��ͬbitλ�ϵ���
                bits[i] += tmpbit;
            }
            result+=(bits[i]%times)<<i;//ģ����ͬ�Ĵ������õ��Ǹ���ͬ����
        }
        return result;

    }
};
void main(void){
    int A[4]={2,2,3,2};
    Solution s;
    cout<<s.singleNumber(A,4)<<endl;
}