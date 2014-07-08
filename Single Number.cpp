class Solution {
public:
    int singleNumber(int A[], int n) {
        if(A==NULL || n<=0 ) return NULL;
        int single=A[0];
        for(int i=1;i<n;i++){//采用异或的方式即可找出不同的那个数
            single=single^A[i];
        }
        return single;
    }
};