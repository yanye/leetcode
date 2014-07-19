/***
思路：
第一次从前往后扫描，若发现后面的rate比前面大，则将candy数目加1
第二次从后往前扫描，若发现前面的rate比后面的大，则取max（当前存储前面糖果数目，后面糖果数目+1）
由于题目对相同的rate未作说明，所以这里将相同当做小于看
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int candy(vector<int> &ratings) {
		int length=ratings.size();
		if(length==0) return 0;
		vector<int> eachCandyNum;
		eachCandyNum.push_back(1);
		for(int i=1;i<length;i++){
			eachCandyNum.push_back(1);
			if(ratings[i]>ratings[i-1]){
				eachCandyNum[i]=eachCandyNum[i-1]+1;
			}
		}
		int sum=eachCandyNum[length-1];
		for(int i=length-1;i>0;i--){
			if(ratings[i-1]>ratings[i]){
				int tmp=eachCandyNum[i]+1;
				eachCandyNum[i-1]=tmp>eachCandyNum[i-1]?tmp:eachCandyNum[i-1];
			}
			sum+=eachCandyNum[i-1];
		}
		eachCandyNum.clear();
		return sum;
	}
};
void main (void){
	Solution s;
	vector<int> rate;
	rate.push_back(1);
	rate.push_back(2);
	rate.push_back(2);
	cout<<s.candy(rate)<<endl;
}