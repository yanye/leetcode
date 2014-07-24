/************************************************************************/
/* 思想和1是一样的，采用dfs遍历，但是会超时                                                                     */
/************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isPalindrome (string s){
		int len=s.length();
		if(len<=0) return false;
		if(len==1) return true;
		bool flag=true;
		for(int i=0;i<=len/2;i++){
			if(s[i]!=s[len-i-1]){
				flag=false;
				break;
			}
		}
		return flag;
	}
	void dfs(int &min, int &tmp, string s){
 		if(s.length()==0) {
			if(tmp<min){
				min=tmp;
			}
			return;
		}
		for(int i=0;i<s.length();i++){
			string sub=s.substr(0,i+1);
			if(isPalindrome(sub)){
				tmp++;
				dfs(min,tmp,s.substr(i+1,s.length()-i-1));
				tmp--;
			}
		}
	}
	int minCut(string s) {
		int minnum=s.length();
		int tmp=0;
		dfs(minnum,tmp,s);
		return minnum;
	}
};
void main (void){
	Solution so;
	string s="aba";
	cout<<so.minCut(s)<<endl;

}