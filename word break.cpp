/************************************************************************/
/* 
思路：动态规划的实现，若已知前面i-1个字母能否用字典的单词合成后，只需要对i个单词，判断已i结尾的单词这部门和
除去他剩余的部分都在字典的话，则这个单词就可以由字典合成。
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
        bool* flag = new bool[strLen];//表示单词的前n个能否用字典合成，故flag[n-1]则是最后的结果
        for(int i=0; i<strLen; i++){
            flag[i]=false;//对每个flag初始化为false，若发现可以由字典合成则赋值为true
            for(int j=i;j>=0;j--){
                string subStr=s.substr(j,i-j+1);//不断的取以i结尾的单词
                unordered_set<string>::const_iterator isFind=dict.find(subStr);//查看以i结尾的单词在不在字典里面
                if(isFind!=dict.end()){//没有到end就发现了则表示在dict里面
                    if(j>0&&flag[j-1]==true){//对于不是整个单词，要判断其剩余部门在不在字典中
                        flag[i]=true;
                        break;
                    }else if(j==0){//针对若是以i结尾的全序列，直接为ture
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