#include <iostream>
#include <stack>
using namespace std;
int main(){
	int i=0;
	stack<int>s;
	for (i=0;i<10;i++){
		s.push(i);
		
	}
	while(!s.empty()){
		cout << s.top()<<endl;
		s.pop();
	}
	cout<<"栈内元素个数"<<s.size()<<endl;
	return 0; 
}
