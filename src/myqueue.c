#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct {
    char* buf;
    int len;
    int ActualLen;
    int size;
} MyQueue;

MyQueue createQue(int len){
   MyQueue q;
   q.buf = malloc(len);
   q.len = len;
   q.ActualLen = 0;
   q.size = 0;

   return q;
}


void Enqueue(MyQueue* q, char res[])
{   
    if (q->ActualLen + strlen(res) + 1 > q->len)
    {
        q->len = q->len * 2;
        q->buf = realloc(q->buf, q->len);
    }
    strcpy(q->buf + q->ActualLen,res);

    q->ActualLen += strlen(res) + 1;
    q->size++;
}

void Dequeue(MyQueue* q, char res[])
{   
    if (q->size <= 0)
        return;


    int len = strlen(q->buf);
    strcpy(res, q->buf);


    memmove(q->buf,q->buf + len + 1,q->ActualLen - len - 1);
    q->ActualLen = len + 1;
    q->size--;
}

char* Peekqueue(MyQueue* q)
{
    if (q->size <= 0){
        printf("Overflow \n");
        return NULL;
    }
    return q->buf;
}

int isEmptyQue(MyQueue* q)
{
   return (q->size == 0);
}

int sizeQueue(MyQueue* q)
{
  return q->size;
}

void freeQueue(MyQueue* q){
    if (q->buf){
        free(q->buf);   
    }

}
        
