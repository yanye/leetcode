/************************************************************************/
/* 
思路：
1） 新建一个数组num，存储数字
2） 对vecto进行循环，若发现string是数字字符，则将其转化数字（atoi），存入num的尾部；若发现是操作符，则取出num的最后两个
      数字，用运算符对其进行操作。将操作后的结果存放在num的末尾
3） num中最后一个数字则是最终的结果
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
    for(i=0;i<tokens.size();i++){//对vector进行循环
        string tmpstr=tokens[i];
        if(tmpstr==(string)("+")||tmpstr==(string)("-")||tmpstr==(string)("*")||tmpstr==(string)("/"))
        {//判断是不是操作符，注意要强制类型转化
            //取num中末尾两个数并将其删除
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
        }else{//发现是数字，直接放在num的最后
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