#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1

typedef struct Stack{
    int *elements;
    int max_size, top_index;
}Stack;

void init(Stack *s, int length) {
    s->elements = (int *)malloc(sizeof(int) * length);
    s->max_size = length;
    s->top_index = -1;
}

int push(Stack *s, int element) {
    if (s->top_index + 1 >= s->max_size) {
        return ERROR;
    }
    s->top_index++;
    s->elements[s->top_index] = element;
    return OK;
}

int pop(Stack *s) {
   if (s->top_index < 0) {
       return ERROR;
   }
    s->top_index--;
    return OK;
}

int top(Stack *s) {
    return s->elements[s->top_index];
}

int empty(Stack *s) {
    return s->top_index < 0;
}

void clear(Stack *s) {
    free(s->elements);
    free(s);
}


int main() {
    int n,m;
    scanf("%d", &n);
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    init(stack,n);
    int flag = 0;  //�ж�i�Ƿ��һ
    
    /*�жϷ����������
    1.����������mΪnʱ��i����Ϊn+1������forѭ����������滹��δ��������֣�����������жϡ�Ϊ�˱�������������������i����nʱ��i--��
    2.��1�Ļ����ϣ�������滹��������ǡ��Ϊջ��Ԫ�أ�pop��֮��ջΪ�գ���Ϊ��ʱi=n,���Բ�������forѭ����������Զ��ͣ����һ����Ϊ�˱��������������һ��if�жϣ����ջ�գ�i++������ѭ����
    3.��1�Ļ����ϣ�������滹�������Ҳ���ջ��Ԫ�أ��������ջ��ͬ2һ������ʱi=n,��������ѭ���������ڴ˴���ͣ��Ϊ�˱��������������һ��if�жϣ������ջ��Ԫ�أ�i++������ѭ����ע�⣬�˶δ�����Ҫ���ڿ�ͷ�������ǽ�β��������Ϊ������滹��δ��������֣�ջ��Ԫ�ز���������Ԫ�أ�i++�Ľ����������ѭ��������1�����⡣
    */
    
    for (int i = 1; i <= n;) {
        scanf("%d", &m);
         if (flag && top(stack) != m) { 
            i++;
        }
        while (top(stack) < m) {
            push(stack, i); 
            i++;
        }
        if (flag == 0 && i == n + 1) {
            i--;
            flag = 1;
        }
        if (!empty(stack) && top(stack) == m) {
            pop(stack);
        } 
        if (flag && empty(stack)) {
            i++;
        }
    }
    
    if (!empty(stack)) printf("NO\n");
    else printf("YES\n");
    clear(stack);
    return 0;
}
