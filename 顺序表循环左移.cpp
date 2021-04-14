#include<stdio.h>
#define N 110
int a[N];
int main(){
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	} 
	while(k--){
		int tmp=a[0];
		for(i=0;i<n-1;i++){
			a[i]=a[i+1];
		}
		a[n-1]=tmp;
	}
	for(i=0;i<n;i++){
		if(i==n-1){
			printf("%d\n",a[i]);
		}
		else{
			printf("%d",a[i]);
		}
	}
	return 0;
}
