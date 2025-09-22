#ifndef MYQUEUE_H
#define MYQUEUE_H

typedef struct {
    char* buf;
    int len;
    int ActualLen;
    int size;
} MyQueue;

//create queue
MyQueue createQue(int len);

//add elem
void Enqueue(MyQueue* q, char res[]);

//give elem
void Dequeue(MyQueue* q, char res[]);

// check last elem
char* Peekqueue(MyQueue* q);

// check if the queue is empty
int isEmptyQue(MyQueue* q);

// check size queue
int sizeQueue(MyQueue* q);

//free member
void freeQueue(MyQueue* q);

#endif 