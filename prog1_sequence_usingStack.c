#include<stdio.h>
#define Max 10

char stack[Max];
int top =-1;

void push(char element){
    if(top<Max-1){
        stack[++top]=element;
    }
    else{
        printf("Overflow");
    }
}

char pop(){
    if(top>=0){
        return stack[top--];
    }
    else{
        return printf("overflow");
    }
}

void main(){
    char sentence[]="CSE##AI#ML###DE#PT##";
    for(int i=0;sentence[i]!='\0';i++){
        if(sentence[i]=='#'){
            char deleted = pop();
            if(deleted!='\0'){
                printf("%c",deleted);
            }
        }
        else{
            push(sentence[i]);
        }

    }
}