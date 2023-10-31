/* In a post office, alone postal worker serves a single queue of customers. Every customer receives a token # 
(serial number) as soon as he/she enters the queue. After service, the token is returned to the post worker 
and the customer leaves the queue. At any point of time, the worker may want to know how many customers are yet 
to be served. Implement the system using an appropriate queue data structure, simulating a random arrival and 
departure of customers after service completion */

#include<stdio.h>
#include<stdlib.h>
#define N 6

int queues[N];
int front=-1;
int rear = -1;

void enqueue(int x){
    if(rear == N-1){
        printf("Queue full!\n");
    }
    else if(front==-1 && rear ==-1){
        front = rear = 0;
        queues[front]=x;
    }
    else{
        queues[++rear]=x;
    }
}

void dequeue(){
    if(front==-1 && rear ==-1){
        printf("Queue Empty :( \n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }

}

void display(){
    if(front==-1 && rear ==-1){
        printf("Nothing to display\n");
    }
    else{
        printf("Displaying elements is the queue : ");
        for(int i=front;i<=rear;i++){
            printf("%d ",queues[i]);
        }
    }
}

void main(){
    enqueue(6);
    enqueue(10);
    enqueue(26);
    enqueue(15);
    enqueue(25);
    enqueue(66);
    enqueue(60);
    display();
    dequeue();
    printf("\n");
    display();
}