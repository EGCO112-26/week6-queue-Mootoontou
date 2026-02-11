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
                // ⚠️ แก้ตรงนี้: ตัดตัว 'u' ออก ให้เหมือนต้นฉบับ
                printf("dequeing %d\n", x); 
            } else {
                // เช็คว่าระบบต้องการ Empty queue เฉยๆ หรือมีอะไรต่อท้าย
                // ปกติใช้แบบนี้ครับ
                printf("Empty queue\n");
            }
        } 
        else {
            enqueue_struct(&q, atoi(argv[i]));
        }
    }
    return 0;
}