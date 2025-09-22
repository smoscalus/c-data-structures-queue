#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct {
    char* buf;
    int len;
    int ActualLen;
    int callList;
} MyQueue;

MyQueue createQue(int len){
   MyQueue q;
   q.buf = malloc(len);
   q.len = len;
   q.ActualLen = 0;
   q.callList = 0;

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
    q->callList++;
}

void Dequeue(MyQueue* q, char res[])
{   
    if (q->callList <= 0)
        return;


    int i = 0;
    while(q->buf[i] != '\0'){
        res[i] = q->buf[i];
        i++;
    }
    res[i] = '\0';
    i++;

    memmove(q->buf,q->buf + i,q->ActualLen - i);
    q->callList--;
}

char* Peekqueue(MyQueue* q)
{
    if (q->callList <= 0){
        printf("Overflow \n");
        return NULL;
    }
    return q->buf;
}

int isEmptyQue(MyQueue* q)
{
   return (q->callList > 0);
}

int sizeQueue(MyQueue* q)
{
  return q->callList;
}

void freeQueue(MyQueue* q){
    if (q->buf){
        free(q->buf);   
    }

}
        
int main()
{
    MyQueue q = createQue(3);
    char res[60];
    Enqueue(&q, "hallo");
    Enqueue(&q, "world");
    printf("%d \n",isEmptyQue(&q));

    printf("%d \n",sizeQueue(&q));
    
    printf("%s \n",Peekqueue(&q));
    Dequeue(&q, res);

    printf("%s \n",Peekqueue(&q));
    Dequeue(&q, res);

    printf("%d \n",sizeQueue(&q));

    freeQueue(&q);

    return 0;
}
