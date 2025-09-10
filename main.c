#include "stdio.h"
#include "stdlib.h"


typedef struct {
    char* buf;
    int len;

    
} MyQuaue;

MyQuaue createQue(int len){
   MyQuaue q;
   q.buf = malloc(sizeof(char) * len);
   q.len = len;

   return q;
}


int free(MyQuaue* q){
    if (q->buf){
        free(q->buf);
        return 0;    
    }
    return 1;
}
        


int main(){

}
