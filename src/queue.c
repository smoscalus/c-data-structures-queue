#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct {
    char* buf;
    int len;
    int ActualLen;
    int callList;
} MyQuaue;

MyQuaue createQue(int len){
   MyQuaue q;
   q.buf = malloc(len);
   q.len = len;
   q.ActualLen = 0;
   q.callList = 0;

   return q;
}


void Enqueue(MyQuaue* q, char res[])
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

void Dequeue(MyQuaue* q, char res[])
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


void freeQueue(MyQuaue* q){
    if (q->buf){
        free(q->buf);   
    }

}
        
int main()
{
    MyQuaue q = createQue(3);
    char res[60];
    Enqueue(&q, "hallo");
    Enqueue(&q, "world");
    Dequeue(&q, res);

    
    freeQueue(&q);

    return 0;
}
