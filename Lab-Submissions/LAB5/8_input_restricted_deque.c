#include <stdio.h>
#define MAX 10

int dq[MAX];
int front=-1, rear=-1;

int isFull() {
    return (front==0 && rear==MAX-1) || (front==rear+1);
}

int isEmpty() {
    return front==-1;
}

void insertRear() {
    int x;
    if(isFull()) return;
    scanf("%d",&x);
    if(front==-1) front=rear=0;
    else if(rear==MAX-1) rear=0;
    else rear++;
    dq[rear]=x;
}

void deleteFront() {
    if(isEmpty()) return;
    if(front==rear) front=rear=-1;
    else if(front==MAX-1) front=0;
    else front++;
}

void deleteRear() {
    if(isEmpty()) return;
    if(front==rear) front=rear=-1;
    else if(rear==0) rear=MAX-1;
    else rear--;
}

int main() {
    int ch;
    while(1){
        scanf("%d",&ch);
        if(ch==1) insertRear();
        else if(ch==2) deleteFront();
        else if(ch==3) deleteRear();
        else break;
    }
    return 0;
}
