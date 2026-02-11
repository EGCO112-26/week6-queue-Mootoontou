#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv) {
    Queue q;
    q.headPtr = NULL;
    q.tailPtr = NULL;
    q.size = 0;

    int i, x;

    for(i = 1; i < argc; i++) {
        if(strcmp(argv[i], "x") == 0) {
            // เช็คก่อนว่ามีของในคิวไหม
            if(q.size > 0) { 
                x = dequeue_struct(&q);
                printf("dequeuing %d\n", x);
            } else {
                printf("Empty queue\n");
            }
        } 
        else {
            // ถ้าไม่ใช่ "x" ให้เปลี่ยนเป็นตัวเลขแล้ว enqueue
            enqueue_struct(&q, atoi(argv[i]));
        }
    } // ปิดลูป for แค่ตรงนี้พอ
    
    return 0;
}