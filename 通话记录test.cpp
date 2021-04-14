#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
const int LEN=10;
using namespace std; 
class stacktest{
	public:
		stack<string>q;
		stacktest(){
		}
		void add(string str){
			q.push(str);
			if(q.size()>LEN){
			q.pop();
			}
		}
		string get(){
			if(q.size()>0){
				return q.top();
			}
			else {
				return "0";
			}
		}
		void pop(){
			if(q.size()>0){
				q.pop();
			}
		}
};

int main(){
	int _type;
	string str;
	stacktest q[3];
	for(int i =0;i<10;i++){
		cin>>_type>>str;
		q[_type].add(str);
	}
	for(int i=0;i<10;++i){
		cout<<q[0].get()<<" "<<q[1].get()<<" "<<q[2].get()<<" "<<endl;
		q[0].pop();
		q[1].pop();
		q[2].pop();
		
	}
	return 0;
}
