
#include<bits/stdc++.h>
using namespace std;
 
int hang[100005];//记录初始行交换后的新行
int lie[100005];//记录初始列对应的新列
int a[100005];
int hd[100005];//记录当前下标行对应的初始行
int ld[100005];//记录当前下标列对应的初始列
int main(){
	int n,m;
	cin>>n>>m;
 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[m*(i-1)+j];
		}
	}
    for(int i=1;i<=n;i++){
    	hang[i]=i;
    	hd[i]=i;
    
	}
	for(int i=1;i<=m;i++){
    	lie[i]=i;
    	ld[i]=i;
	}
	int k;
	cin>>k;
	while(k--){
		int f,x,y;
		cin>>f>>x>>y;
		if(f==0){
			swap(hang[hd[x]],hang[hd[y]]);
			swap(hd[x],hd[y]);
		}
		else {
		
			swap(lie[ld[x]],lie[ld[y]]);	
			swap(ld[x],ld[y]);
		}	
	}
	int d[100005];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					d[m*(hang[i]-1)+lie[j]]=a[m*(i-1)+j];
				}
 
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cout<<d[m*(i-1)+j];
					if(j<m) cout<<" ";
				}
				cout<<endl;
			}
}
