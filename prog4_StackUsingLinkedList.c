#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = 0;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        printf("Stack is empty");
        printf("\n");
    }
    else
    {
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == 0)
    {
        printf("Empty");
        printf("\n");
    }
    else
    {
        printf("%d ", top->data);
        printf("\n");
    }
}

void display()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        printf("Stack is empty");
        printf("\n");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->next;
            printf("\n");
        }
    }
}

void main()
{
    push(6);
    push(10);
    push(16);
    push(26);
    push(15);
    push(25);
    printf("Displaying data after PUSH operation\n");
    display();
    peek();
    pop();
    printf("Displaying data after POP operation\n");
    display();
    peek();
    //display();
}