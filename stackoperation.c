#include<stdio.h>
#include<stdlib.h>

struct stack{

int size;
int top;
int *arr;
};

int isEmpty(struct stack* ptr){
if(ptr->top==-1)
{
return 1;
}
else{
return 0;
}
}
int isFull(struct stack* ptr){
if(ptr->top==ptr->size-1)
{
return 1;
}
return 0;
}

void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main (){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
sp->size=10;
sp->top=-1;
sp->arr=(int*)malloc(sp->size *sizeof(int));

printf("the stack has been created successfully\n");
printf("Before pushing, Full: %d\n", isEmpty(sp));
printf("Before pushing, Empty: %d\n", isFull(sp));
push(sp,45);
push(sp,56);
push(sp,56);
push(sp,67);
printf("After pushing, Full: %d\n", isEmpty(sp));
printf("After pushing, Empty: %d\n", isFull(sp));
printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
printf("Popped %d from the stack\n", pop(sp)); //
return 0;
}

