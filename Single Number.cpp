class Solution {
public:
    int singleNumber(int A[], int n) {
        if(A==NULL || n<=0 ) return NULL;
        int single=A[0];
        for(int i=1;i<n;i++){//�������ķ�ʽ�����ҳ���ͬ���Ǹ���
            single=single^A[i];
        }
        return single;
    }
};