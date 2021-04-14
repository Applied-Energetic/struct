#include"iostream"
#include"vector"
using namespace std;

int main()
{
	int n,m;//n个元素，m行操作
	int a,b;
	vector<int> aa[10000];
	cin>>n>>m;
	for(int i=0;i<n;i++)//赋初值
		aa[i].push_back(i+1);
	for(int i=0;i<m;i++)
	{//下标从0开始，a、b使用时要-1
		cin>>a>>b;
		if(a==b)continue;//不动
		for(int j=0;j<aa[b-1].size();j++)
			aa[a-1].push_back(aa[b-1][j]);
		aa[b-1].clear();//清空所有元素，包括其开辟地址，使用的话要继续pushback
		vector<int>().swap(aa[b-1]);//清空内存
		//aa[b-1].swap(vector<int>());//这句通不过
	}
	for(int i=0;i<n;i++)
	{//输出
		if(aa[i].size()==0)
		{
			cout<<endl;
			continue;
		}
		for(int j=0;j<aa[i].size();j++)
		{
			printf("%d",aa[i][j]);
			if(j!=aa[i].size()-1)//控制格式
				printf(" ");
		}
		cout<<endl;
	}
	return 0;
}

