/************************************************************************/
/* 
˼·����̬�滮��ʵ�֣�����֪ǰ��i-1����ĸ�ܷ����ֵ�ĵ��ʺϳɺ�ֻ��Ҫ��i�����ʣ��ж���i��β�ĵ����ⲿ�ź�
��ȥ��ʣ��Ĳ��ֶ����ֵ�Ļ�����������ʾͿ������ֵ�ϳɡ�
*/
/************************************************************************/

#include <iostream>
#include <string>
#include <hash_set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int strLen=s.length();
        bool* flag = new bool[strLen];//��ʾ���ʵ�ǰn���ܷ����ֵ�ϳɣ���flag[n-1]�������Ľ��
        for(int i=0; i<strLen; i++){
            flag[i]=false;//��ÿ��flag��ʼ��Ϊfalse�������ֿ������ֵ�ϳ���ֵΪtrue
            for(int j=i;j>=0;j--){
                string subStr=s.substr(j,i-j+1);//���ϵ�ȡ��i��β�ĵ���
                unordered_set<string>::const_iterator isFind=dict.find(subStr);//�鿴��i��β�ĵ����ڲ����ֵ�����
                if(isFind!=dict.end()){//û�е�end�ͷ��������ʾ��dict����
                    if(j>0&&flag[j-1]==true){//���ڲ����������ʣ�Ҫ�ж���ʣ�ಿ���ڲ����ֵ���
                        flag[i]=true;
                        break;
                    }else if(j==0){//���������i��β��ȫ���У�ֱ��Ϊture
                        flag[i]=true;
                        break;
                    }
                    
                }
            }
        }
        bool result=flag[strLen-1];
        delete[] flag;
        return result;
    }
};
void main (void){
    unordered_set<string> dict;
    dict.insert("aaaa");
    dict.insert("aaa");
    string s="aaaaaaa";
    Solution slu;
    cout<<slu.wordBreak(s,dict)<<endl;

}