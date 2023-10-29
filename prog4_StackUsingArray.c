#include <stdio.h>
#define N 10

int top = -1;
int stack[N];

void push()
{
    int x;
    printf("Enter data : ");
    scanf("%d", &x);
    if (top == -1)
    {
        top = 0;
        stack[top] = x;
    }
    else if (top < N)
    {
        stack[++top] = x;
    }
    else
    {
        printf("Stack Overflow!");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack empty!!");
    }
    printf("Element at the top - %d ", stack[top]);
}

void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void main()
{
    int choice;
    do
    {
        printf("Enter 1.Push 2.Pop 3.Peek 4.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid input!!");
        }
    } while (choice != 0);
}