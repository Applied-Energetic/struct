#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int LEN = 10;
// 自定义循环队列类，来实现题目要求的某一类通话列表的保存
// 在程序中调用定义举例如下：
// circular_queue Q;
// 如果要定义数组，比如这道题需要定义一个长度为3的循环队列数组，则参考如下定义：
// circular_queue Q[3];
class circular_queue {
public:
    // 自定义的类用到了STL中的deque，也就是双端队列
    // 双端队列，顾名思义，可以从队列的头或者尾插入或者删除元素
    deque<string> q;
    // 构造函数，将队列清空
    // 构造函数会在声明一个类变量的时候自动调用
    circular_queue() {
        q.clear();
    }
    // 在队尾插入元素，如果队列长度超过限制(LEN=10)则将队首元素弹出
    // 调用方法举例如下：
    // Q.add("hello world");
    void add(string str) {
        // 在队尾插入元素
        q.push_back(str);
        // 判断队列长度是否超过限制
        if (q.size() > LEN) {
            // 如果长度超过限制，则弹出队首元素
            q.pop_front();
        }
    }
    // 返回队首元素的值，如果队列是空的，就按照题面要求返回一个字符串"0"
    string get_tail() {
        // 判断队列是否为空
        if (q.size() > 0) {
            // 返回队首元素
            return q.front();
        } else {
            // 返回一个默认的字符串"0"
            return "0";
        }
    }
    // 弹出队尾元素，如果队列空则不进行操作
    void pop_tail() {
        // 判断队列是否为空
        if (q.size() > 0) {
            // 弹出队尾元素
            q.pop_front();
        }
    }
};
int main() {
    int _type;
    string str;
    circular_queue q[3];
    // 读到文件结束，每行一个整数和一个字符串
//    while (cin >> _type >> str) {
//        // 这里实现循环队列的插入操作。
//        // _type的范围为0，1，2，刚好对应到q数组的三个下标
//        // 插入元素要调用循环队列的add(str)方法
//        // 比如对于循环队列q，插入元素的代码为   q.add(str);
//        // 聪明的你，快在下面一行把答案写出来吧
//
//        q[_type].add(str);
//    }
    
    for (int i = 0; i < 10; i++) {
    	cin >> _type >> str;
        q[_type].add(str);
    }
    for (int i = 0; i < 10; ++i) {
        // 输出三个循环队列的队尾元素，要调用循环队列的get_tail()方法
        // 比如对于循环队列q，获取队尾元素值的代码为   q.get_tail();

        cout << q[0].get_tail()<< " " << q[1].get_tail() << " " << q[2].get_tail() << endl;

        // 接下来依次将三个循环队列的队尾元素分别删除
        // 对于循环队列q，删除循环队列的队尾元素的代码为   q.pop_tail();

        q[0].pop_tail();
        q[1].pop_tail();
        q[2].pop_tail();
    }
    return 0;
}
