/***
˼·��
��һ�δ�ǰ����ɨ�裬�����ֺ����rate��ǰ�����candy��Ŀ��1
�ڶ��δӺ���ǰɨ�裬������ǰ���rate�Ⱥ���Ĵ���ȡmax����ǰ�洢ǰ���ǹ���Ŀ�������ǹ���Ŀ+1��
������Ŀ����ͬ��rateδ��˵�����������ｫ��ͬ����С�ڿ�
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