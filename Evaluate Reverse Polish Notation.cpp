/************************************************************************/
/* 
˼·��
1�� �½�һ������num���洢����
2�� ��vecto����ѭ����������string�������ַ�������ת�����֣�atoi��������num��β�����������ǲ���������ȡ��num���������
      ���֣��������������в�������������Ľ�������num��ĩβ
3�� num�����һ�������������յĽ��
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int evalRPN(vector<string> &tokens) {
    vector<int> num;
    int i;
    for(i=0;i<tokens.size();i++){//��vector����ѭ��
        string tmpstr=tokens[i];
        if(tmpstr==(string)("+")||tmpstr==(string)("-")||tmpstr==(string)("*")||tmpstr==(string)("/"))
        {//�ж��ǲ��ǲ�������ע��Ҫǿ������ת��
            //ȡnum��ĩβ������������ɾ��
            int b=num.back();
            num.pop_back();
            int a=num.back();
            num.pop_back();
            int c=0;
            switch(*tmpstr.c_str()){
            case '+':
                c=a+b;
                break;
            case '-':
                c=a-b;
                break;
            case '*':
                c=a*b;
                break;
            case '/':
                c=a/b;
                break;
            default:
                break;
            }
            num.push_back(c);
        }else{//���������֣�ֱ�ӷ���num�����
            int tmpnum;
            tmpnum = atoi(tmpstr.c_str());
            num.push_back(tmpnum);
        }
    }
    return num.back();
}
void main(void)
{
    vector<string> a;
    a.push_back((string)("3"));
    a.push_back((string)("-4"));
    a.push_back((string)("+"));
    int result=evalRPN(a);
    cout<<result<<endl;
}