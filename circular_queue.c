#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q,int val){
    if(isFull(q)){
        printf("already full\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("enqued element : %d\n",val);
    }
}

int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("circularQueue is empty\n");
        return -1;
    }
    else{
        q->f = (q->f+1)%q->size;
        printf("Dequed element : %d\n",q->arr[q->f]);
        // return q->arr[q->f];
    }
}

int main(){
    struct circularQueue q;
    q.size = 4;
    q.r =q.f = 0;
    q.arr = (int *) malloc(q.size * sizeof(int));
    
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,14);
    
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    
    if(isEmpty(&q)){
        printf("circularQueue is empty");
    }
    if(isFull(&q)){
        printf("circularQueue is full");
    }
    return 0;
}