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
   q.buf = malloc(sizeof(char) * len);
   q.len = len;
   q.ActualLen = 0;
   q.callList = 0;

   return q;
}


void Enqueue(MyQuaue* q, char res[])
{   
    if ( q->ActualLen > q->len)
    {
        q->buf = realloc(q->buf, sizeof(char) * q->len * 2);
        q->len = q->len * 2;
    }
    strcpy(q->buf + q->ActualLen,res);
    
    q->ActualLen += strlen(res) + 1;
    q->callList++;
}

void freeQueue(MyQuaue* q){
    if (q->buf){
        free(q->buf);   
    }

}
        
int main()
{
    MyQuaue q = createQue(20);
    char* res = "hallo";
    Enqueue(&q, res);
    freeQueue(&q);

    return 0;
}
