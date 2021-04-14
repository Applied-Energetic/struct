#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int LEN = 10;
// �Զ���ѭ�������࣬��ʵ����ĿҪ���ĳһ��ͨ���б�ı���
// �ڳ����е��ö���������£�
// circular_queue Q;
// ���Ҫ�������飬�����������Ҫ����һ������Ϊ3��ѭ���������飬��ο����¶��壺
// circular_queue Q[3];
class circular_queue {
public:
    // �Զ�������õ���STL�е�deque��Ҳ����˫�˶���
    // ˫�˶��У�����˼�壬���ԴӶ��е�ͷ����β�������ɾ��Ԫ��
    deque<string> q;
    // ���캯�������������
    // ���캯����������һ���������ʱ���Զ�����
    circular_queue() {
        q.clear();
    }
    // �ڶ�β����Ԫ�أ�������г��ȳ�������(LEN=10)�򽫶���Ԫ�ص���
    // ���÷����������£�
    // Q.add("hello world");
    void add(string str) {
        // �ڶ�β����Ԫ��
        q.push_back(str);
        // �ж϶��г����Ƿ񳬹�����
        if (q.size() > LEN) {
            // ������ȳ������ƣ��򵯳�����Ԫ��
            q.pop_front();
        }
    }
    // ���ض���Ԫ�ص�ֵ����������ǿյģ��Ͱ�������Ҫ�󷵻�һ���ַ���"0"
    string get_tail() {
        // �ж϶����Ƿ�Ϊ��
        if (q.size() > 0) {
            // ���ض���Ԫ��
            return q.front();
        } else {
            // ����һ��Ĭ�ϵ��ַ���"0"
            return "0";
        }
    }
    // ������βԪ�أ�������п��򲻽��в���
    void pop_tail() {
        // �ж϶����Ƿ�Ϊ��
        if (q.size() > 0) {
            // ������βԪ��
            q.pop_front();
        }
    }
};
int main() {
    int _type;
    string str;
    circular_queue q[3];
    // �����ļ�������ÿ��һ��������һ���ַ���
//    while (cin >> _type >> str) {
//        // ����ʵ��ѭ�����еĲ��������
//        // _type�ķ�ΧΪ0��1��2���պö�Ӧ��q����������±�
//        // ����Ԫ��Ҫ����ѭ�����е�add(str)����
//        // �������ѭ������q������Ԫ�صĴ���Ϊ   q.add(str);
//        // �������㣬��������һ�аѴ�д������
//
//        q[_type].add(str);
//    }
    
    for (int i = 0; i < 10; i++) {
    	cin >> _type >> str;
        q[_type].add(str);
    }
    for (int i = 0; i < 10; ++i) {
        // �������ѭ�����еĶ�βԪ�أ�Ҫ����ѭ�����е�get_tail()����
        // �������ѭ������q����ȡ��βԪ��ֵ�Ĵ���Ϊ   q.get_tail();

        cout << q[0].get_tail()<< " " << q[1].get_tail() << " " << q[2].get_tail() << endl;

        // ���������ν�����ѭ�����еĶ�βԪ�طֱ�ɾ��
        // ����ѭ������q��ɾ��ѭ�����еĶ�βԪ�صĴ���Ϊ   q.pop_tail();

        q[0].pop_tail();
        q[1].pop_tail();
        q[2].pop_tail();
    }
    return 0;
}
