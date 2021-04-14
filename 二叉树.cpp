#include <stdio.h>
#include <stdlib.h>

typedef struct Bnode{
	char data;
	struct Bnode *Lchild,*Rchild; 
}Btnode,*BTptr;
CreateLBtree(BTptr BT){
	char ch;
	int i=0;
	BTptr p,q;
	Clearqueue(Q);
	BT=NULL;
	ch=getchar();
	while(ch!='#'){
		p=NULL;
		if(ch!='@'){
			p=(BTptr)malloc(sizeof(BTnode));
			p->data=ch;
			p->Lchild=p->Rchild=NULL;
		}
		i++;
		Enqueue(Q,p);
		if(i==1){
			BT=p;
		}
		else{
			q=Getqtop(Q);
			if(p&&q)
			if(i%2==0) q->Lchild=p;
			else q->Rchild=p;
			if(i%2==1) Delqueue(Q,q);
		}
		ch=gechar();
		
	}
	return(BT);
} 
int main(){
	return 0;
}
