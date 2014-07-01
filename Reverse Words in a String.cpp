#include <iostream>
#include <string>
using namespace std;
//void reduceMultipleSpace(string &s)
//{
//    int i=0;
//    int j=0;
//    if (s.length()<=0)
//        return;
//    while (i<s.length())
//    {
//        if ()
//        {
//        }
//    }
//}
void reverseWholeStr(string &s, int begin , int end){
    int i;
    if (begin<0||end<=0||begin>=end)
        return;
    for(i=0;i<=(end-begin)/2;i++){
        char tmp=s[begin+i];
        s[begin+i]=s[end-i];
        s[end-i]=tmp;
    }
    return;
}
void reverseWords(string &s) {
    if(s.length()<=0)
        return;
    int i=0;
    int j=0;
    while (s[j]==' ')
    {
        s.erase(j,1);
    }
    reverseWholeStr(s,0,s.length()-1);
    while (s[j]==' ')
    {
        s.erase(j,1);
    }
    while(j<s.length()){
        if(s[j]!=' '){
            j++;
        }else{
            if(j>i+1){
                reverseWholeStr(s,i,j-1);
                j++;
                i=j;
            }else{
                if (j+1<s.length()&&s[j+1]!=' ')
                {
                    j++;
                    i=j;
                }else{
                    s.erase(j,1);
                    j=j-1;
                    i=j;
                }
            }
        }
    }
    if(j>i+1){
        reverseWholeStr(s,i,j-1);
        j++;
        i=j;
    }
    return;
}
void main (void)
{
    string s="   hi   ,      ";
    reverseWords(s);
    cout <<s<<endl;
}