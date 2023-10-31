/* In a post office, alone postal worker serves a single queue of customers. Every customer receives a token # 
(serial number) as soon as he/she enters the queue. After service, the token is returned to the post worker 
and the customer leaves the queue. At any point of time, the worker may want to know how many customers are yet 
to be served. Implement the system using an appropriate queue data structure, simulating a random arrival and 
departure of customers after service completion */

#include<stdio.h>
#include<stdlib.h>
#define N 6

int j=1;
int i=1;
int queues[N];
int front=-1;
int rear = -1;
int token[N]={101,102,103,104,105,106};

void enqueue(){
    if(rear == N-1){
        printf("Queue full!\n");
    }
    else if(front==-1 && rear ==-1){
        front = rear = 0;
        queues[front]=i;
        printf("Customer %d entered the queue. His/Her token is: %d\n",i,token[0]);
    }
    else{
        queues[++rear]=i;
        printf("Customer %d entered the queue. His/Her token is: %d\n",i,token[i-1]);
    }
    i++;
    printf("\n");
}

int dequeue(){

    if(front==-1 && rear ==-1){
        printf("Queue Empty :( \n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
    printf("Customer %d has been served. Token %d is returned back.\n",j,token[j-1]);
    j++;
}

void knowRemainingCustomer(){
    if (front==-1 && rear ==-1) {
        printf("Ther's no one in the queue.");
    } else if (front <= rear) {
        printf("Remaining customer in the queue is %d\n",rear - front + 1);
    } else {
        printf("Remaining customer in the queue is %d\n", N - front + rear + 1);
    }
}

void main(){
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();

    printf("\n");
    knowRemainingCustomer();

    printf("\n");
    dequeue();
    printf("\n");
    dequeue();
    printf("\n");
    knowRemainingCustomer();
    printf("\n");
}