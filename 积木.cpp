#include"iostream"
#include"vector"
using namespace std;

int main()
{
	int n,m;//n��Ԫ�أ�m�в���
	int a,b;
	vector<int> aa[10000];
	cin>>n>>m;
	for(int i=0;i<n;i++)//����ֵ
		aa[i].push_back(i+1);
	for(int i=0;i<m;i++)
	{//�±��0��ʼ��a��bʹ��ʱҪ-1
		cin>>a>>b;
		if(a==b)continue;//����
		for(int j=0;j<aa[b-1].size();j++)
			aa[a-1].push_back(aa[b-1][j]);
		aa[b-1].clear();//�������Ԫ�أ������俪�ٵ�ַ��ʹ�õĻ�Ҫ����pushback
		vector<int>().swap(aa[b-1]);//����ڴ�
		//aa[b-1].swap(vector<int>());//���ͨ����
	}
	for(int i=0;i<n;i++)
	{//���
		if(aa[i].size()==0)
		{
			cout<<endl;
			continue;
		}
		for(int j=0;j<aa[i].size();j++)
		{
			printf("%d",aa[i][j]);
			if(j!=aa[i].size()-1)//���Ƹ�ʽ
				printf(" ");
		}
		cout<<endl;
	}
	return 0;
}

