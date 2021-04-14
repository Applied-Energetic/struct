#include <stdio.h>
#include <stdlib.h>

//typedef int datatype;
typedef struct node{
//    datatype data;//����������
	int data;
    struct node * next;//����ָ����ָ��ֱ�Ӻ��Ԫ��
}linknode,*link;

//�������� 
node * creatlink();
//��ӡȫ������ 
void display(node *p);
//ǰ��
void ListInsert(node *p,int i ,int e); 
//ɾ�� 
void ListDel(link H,int i );


node * GetElem(node *p,int i);
node * LocateElem(node *p,int e);

int main(){
	printf("��ʼ������\n");
	node* p= creatlink();
	display (p);
	printf("����\n");
	
	int x;
	scanf("%d",&x);
	node* temp = GetElem(p,x);
	display(temp); 
	printf("%d\n",temp->data);

	printf("��λ����\n");

	int y;
	scanf("%d",&y);	
	node* place = LocateElem(p,y);
	display(place);
	printf("%d",place->data);

	ListInsert(p,2,2);
	display(p);

	ListDel(p,2);
	display(p);

	return 0;
	
}

link creatlink(){
	int a;
	link H,p,r;
	H = (link)malloc(sizeof(linknode));
	r=H;
	scanf("%d",&a);
	H->data = NULL;
	while(a!=-1){
		p=(link)malloc(sizeof(linknode));
		p->data = a;
		r->next=p;
		r = p;
		
		scanf("%d",&a);
	}
	r->next=NULL;
	return H;
}

//GetElem��������Ų���
link GetElem(link H,int i){
	int j = -1;
	link t = H;
	if(i<0)
		return NULL;
	while(t->next&&j<i){
		t = t->next;
		j++;
	}
	if(i==j)
		return (t);
	else
		return (NULL);
	
}
 
//��ֵ���� 
link LocateElem(link H,int e){
	link t = H;
	while(t&&t->data!=e){
		t=t->next;
	} 
	return(t);
	
}
//����ǰ�� 
void ListInsert(node *H,int i ,int e){
	link p,q;
	if(i==0){
		p=H;
	}
	else{
		p = GetElem(H,i-1);
	}
	if(p!=NULL){
		q = (link)malloc(sizeof(linknode));
		q->data=e;
		q->next=p->next;
		p->next=q;
		
	}
}

void ListDel(link H,int i ){
	link p,q;
	if(i==0){
		p=H;
	}
	else{
		p = GetElem(H,i-1);
	}
	if(p&&p->next){
		q=p->next;
		p->next=q->next;
		free(q);
	}
}



//display����������ӡ���� 
void display(node *p){
    node* temp=p->next;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
    printf("%d\t",temp->data);
	while (temp->next) {
        temp=temp->next;
        printf("%d\t",temp->data); 
    }
    printf("\n");
}

