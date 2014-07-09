/*******************************************************/
/*
思路: 用32位的数组，保存每个bit位上出现的1的次数，然后模上相同的次数，即可得到那个不同的数
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
                int tmpbit=(A[j]>>i)&1;//获取不同bit位上的数
                bits[i] += tmpbit;
            }
            result+=(bits[i]%times)<<i;//模除相同的次数，得到那个不同的数
        }
        return result;

    }
};
void main(void){
    int A[4]={2,2,3,2};
    Solution s;
    cout<<s.singleNumber(A,4)<<endl;
}