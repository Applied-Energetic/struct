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
    int flag = 0;  //判断i是否减一
    
    /*判断分三种情况：
    1.当输入数字m为n时，i自增为n+1，跳出for循环，如果后面还有未输入的数字，将不会进行判断。为了避免出现这种情况，发现i大于n时，i--。
    2.在1的基础上，如果后面还有数字且恰好为栈顶元素，pop完之后栈为空，因为此时i=n,所以不会跳出for循环，程序将永远暂停在这一步。为了避免这种情况，加一个if判断，如果栈空，i++，跳出循环。
    3.在1的基础上，如果后面还有数字且不是栈顶元素，即错误的栈，同2一样，此时i=n,不会跳出循环，程序在此处暂停。为了避免这种情况，加一个if判断，如果非栈顶元素，i++，跳出循环。注意，此段代码需要加在开头而不能是结尾，这是因为如果后面还有未输入的数字，栈顶元素不等于输入元素，i++的结果就是跳出循环，陷入1的问题。
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
