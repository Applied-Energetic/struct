#include <studio.h>

typedef struct{
	datatype data;
	int next;
}snode;
#define MAXSIZE 1023
snode spool [MAXSIZE];
int unused;

void spInit (snode spol[],int *unused){
	int j;
	spool[0].next=0;
	for(j=1;)
}
