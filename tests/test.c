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
#define TEST_EQ_INT(exp,act){\
    if (exp != act){\
        printf("[FAIL] %s:%d: expected %d, got %d\n",  __FILE__, __LINE__, (exp), (act));\
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
void test_isEmptyQue()
{
    MyQueue q = createQue(50);

    Enqueue(&q, "hello");

    int n1 = isEmptyQue(&q);
    TEST_EQ_INT(0,n1);

    char res[10];
    Dequeue(&q, res);

    int n2 = isEmptyQue(&q);
    TEST_EQ_INT(1,n2);
}

void test_sizeQueue()
{
    MyQueue q = createQue(50);

    Enqueue(&q, "hello");
    Enqueue(&q, "hello");
    int n1 = sizeQueue(&q);
    TEST_EQ_INT(2,n1);

    char res[10];
    Dequeue(&q, res);
    Dequeue(&q, res);
    int n2 = sizeQueue(&q);
    TEST_EQ_INT(0,n2);
}


int main()
{
    test_Enqueue_Dequeue();
    test_Peekqueue();
    test_isEmptyQue();
    test_sizeQueue();
    return 1;
}