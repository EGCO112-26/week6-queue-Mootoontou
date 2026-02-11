typedef struct {
    NodePtr headPtr, tailPtr;
    int size;
} Queue;

void enqueue_struct(Queue* q, int x) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node) {
        new_node->data = x;
        new_node->nextPtr = NULL; // โหนดใหม่ต้องชี้ไป NULL เสมอเพราะอยู่ท้ายคิว

        if (q->size == 0) {
            q->headPtr = new_node; // ถ้าคิวว่าง head ต้องชี้มาที่นี่
        } else {
            q->tailPtr->nextPtr = new_node; // ถ้ามีของอยู่แล้ว ให้ตัวท้ายเดิมชี้มาที่ตัวใหม่
        }
        
        q->tailPtr = new_node; // อัปเดต tail ให้เป็นตัวใหม่ล่าสุด
        q->size++; // เพิ่มขนาดคิว
    }
}

int dequeue_struct(Queue *q) {
    NodePtr t = q->headPtr;
    if (t) {
        int value = t->data;
        q->headPtr = t->nextPtr;
        if (q->headPtr == NULL) q->tailPtr = NULL;
        free(t);
        q->size--;
        return value;
    }
    return -1; // คืนค่าที่บอกว่าคิวว่าง
}