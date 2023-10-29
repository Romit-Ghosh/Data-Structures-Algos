#include<stdio.h>
# define MAX 10

int front=-1;
int rear=-1;
char queue[MAX];

void enqueue(char element){
    if(front==-1&&rear==-1){
        front=rear=0;
        //rear=0;
        queue[front]=element;
    }

    else if(rear<MAX){
        queue[++rear]=element;
    }

    else{
        printf("Queue full");
    }

}

char dequeue(){
    if(front<=rear){
        return queue[front++];
    }
    else if(front>rear){
        front=rear=-1;
    }
}

void main(){
    char sentence[]="CSE##AI#ML###DE#PT##";
    for(int i=0;sentence[i]!='\0';i++){
        if(sentence[i]=='#'){
            char dequeued = dequeue();
            if(dequeued!='\0'){
                printf("%c",dequeued);
            }
        }

        else{
            enqueue(sentence[i]);
        }
    }
}
