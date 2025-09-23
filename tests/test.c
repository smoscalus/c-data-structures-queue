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

void test_Enqueue_Dequeue()
{
    MyQueue q = createQue(50);
    Enqueue(&q, "hello");
    char res[10];
    Dequeue(&q, res);
    TEST_EQ_STR("hello", res);
}
void test_Peekqueue()
{
    MyQueue q = createQue(50);
    Enqueue(&q, "hello");
    char* res = Peekqueue(&q);
    
    TEST_EQ_STR("hello", res);

}


int main()
{
    test_Enqueue_Dequeue();
    test_Peekqueue();
    return 1;
}