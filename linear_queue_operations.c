#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("already full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("queue is empty\n");
    }
    else{
        q->f++;
        return q->arr[q->f];
    }
}

int main(){
    struct queue q;
    q.size = 4;
    q.r =q.f = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));
    
    printf("enqued element : %d\n",enqueue(&q,12));
    printf("enqued element : %d\n",enqueue(&q,13));
    printf("enqued element : %d\n",enqueue(&q,14));
    printf("enqued element : %d\n",enqueue(&q,16));
    
    printf("dequed element : %d\n",dequeue(&q));
    printf("dequed element : %d\n",dequeue(&q));
    printf("dequed element : %d\n",dequeue(&q));
    printf("dequed element : %d\n",dequeue(&q));
    
    enqueue(&q,16);
    if(isEmpty(&q)){
        printf("queue is empty\n");
    }
    if(isFull(&q)){
        printf("queue is full");
    }
    return 0;
}