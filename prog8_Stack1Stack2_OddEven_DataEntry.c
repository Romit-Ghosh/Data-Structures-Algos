/*Two stacks STACK1 and STACK2 is to be implemented using single array. STACK1
and STACK2 are arranged alternately starting from index 0 (zero), write a common
push () function that will insert odd elements in STACK1 and even elements in
STACK2 and common pop () function which can delete values from any of the stack*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

int tosO = -1;
int tosE = -1;
int stack[N];

void push(int x)
{
    if (tosO == N)
    {
        printf("Overflow of Odd integers!\n");
    }
    if (tosE == N - 2)
    {
        printf("Overflow of Even integers!\n");
    }
    if (x % 2 == 0 && tosE == -1)
    {
        tosE = 0;
        stack[tosE] = x;
    }
    else if (x % 2 != 0 && tosO == -1)
    {
        tosO = 1;
        stack[tosO] = x;
    }
    else if (x % 2 == 0)
    {
        tosE = tosE + 2;
        stack[tosE] = x;
    }
    else
    {
        tosO = tosO + 2;
        stack[tosO] = x;
    }
}

void pop(int indicator)
{
    if (tosO == -1 && tosE == -1)
    {
        printf("Stack Underflow");
    }
    else if (indicator == 1 && tosO != -1)
    {
        stack[tosO] = '_';
        tosO = tosO - 2;
    }
    else
    {
        stack[tosE] = '_';
        tosE = tosE - 2;
    }
}

void display()
{
    printf("Displaying the stack elements : ");
    for (int i = 0; i < N; i++)
    {
        if (stack[i] == '_')
        {
            printf("_ ");
        }
        else
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

void main()
{
    push(1);
    push(4);
    push(3);
    push(5);
    push(7);
    push(6);
    push(10);
    push(74);
    push(9);
    push(52);
    printf("\n");
    display();
    printf("\n");

    pop(1); // 1 --> to delete odd element,  0 --> to delete even element
    pop(1);
    pop(0);
    pop(1);

    display();
    printf("\n");
}

// 1 3 5 7 9
// 0 2 4 6 8