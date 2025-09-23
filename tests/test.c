#include "stdio.h"
#include "../include/myqueue.h"
#include "string.h"

#define TEST_EQ_STR(exp,act){\
    if (strcmp(exp, act) != 0){\
        printf("[FAIL] %s:%d: expected %s, got %s\n",  __FILE__, __LINE__, (exp), (act));\
    }\
    else { \
        printf("[PASS] %s:%d\n", __FILE__, __LINE__); \
    } \
    }

int test_Enqueue_Dequeue()
{
    MyQueue q = createQue(50);
    Enqueue(&q, "hello");
    char res[10];
    Dequeue(&q, res);
    TEST_EQ_STR("hello", res);
    return 1;
}


int main()
{
    int res = test_Enqueue_Dequeue();
    printf("%d", res);
    return 1;
}