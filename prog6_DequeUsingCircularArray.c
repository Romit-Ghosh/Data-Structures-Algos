#include <stdio.h>
#define N 5
int deque[N];
int rear = -1;
int front = -1;

void enqueuefront(int x)
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    { // full condition
        printf("Queue is full");
        printf("\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front == 0) // while inserting from front we do front--
    {
        front = N - 1;
        deque[front] = x;
    }
    else
    {
        // front--;
        deque[--front] = x;
    }
}

void enqueuerear(int x)
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    { // full condition
        printf("Queue is full");
        printf("\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else if (rear == N - 1)
    {
        rear = 0;
        deque[rear] = x;
    }
    else
    {
        // rear++;
        deque[++rear] = x;
    }
}

void dequeuefront()
{
    if (front == -1 && rear == -1)
    {
        printf("Empty queue!!");
        printf("\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == N - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void dequeuerear()
{
    if (front == -1 && rear == -1)
    {
        printf("Empty queue!!");
        printf("\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = N - 1;
    }
    else
    {
        rear--;
    }
}

void getfront()
{
    if (front == -1 && rear == -1)
    {
        printf("Empty queue!!");
        printf("\n");
    }
    else
    {
        printf("%d ", deque[front]);
    }
}

void getrear()
{
    if (front == -1 && rear == -1)
    {
        printf("Empty queue!!");
        printf("\n");
    }
    else
    {
        printf("%d ", deque[rear]);
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Empty queue!!");
        printf("\n");
    }
    else
    {
        while (i != rear)
        {
            printf("%d ", deque[i]);
            i = (i + 1) % N;
        }
        printf("%d ", deque[rear]);
        printf("\n");
    }
}

void main()
{
    enqueuefront(6);
    enqueuefront(10);
    enqueuerear(16);
    enqueuerear(26);
    enqueuefront(15);
    enqueuefront(25);
    printf("After enqueuing from both sides, the queue is : ");
    display();
    // printf("\n");
    dequeuefront();
    dequeuerear();
    dequeuefront();
    printf("After dequeuing from both sides, the queue is : ");
    display();
    
}