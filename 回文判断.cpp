#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    int i,j,lethen;
    char s[20];
    for(i =0;i<20;i++){
    	//cin>>s[i];
    	scanf("%c",&s[i]);
    	if(s[i]=='@'){
    		break;
		}
	} 
	    lethen=strlen(s)-1;
    {
        for(i=0,j=lethen-1;i<=j;i++,j--)
        {    
	          if(s[i]!=s[j]) {printf("false\n");break;}
        }
         if(i>=j) printf("true\n");
    }
           }
