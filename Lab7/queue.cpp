#include <cstdio>
#include <cstdlib>

//class to implement queue suing array
class queue {
private:
    struct node {
        int data;
        struct node *next;
    } *front, *rear;

public:
    queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int);
    int dequeue();
    void peek();
};

//class to implement queue suing array
int main() {
    queue q1;
    int opt;

    while (1) {
        printf("\nEnter your choice:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1: {
                int num;
                printf("Enter the number you want to insert: ");
                scanf("%d", &num);
                q1.enqueue(num);
                break;
            }
            case 2: {
                int num1 = q1.dequeue();
                if (num1 == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("The deleted element is %d\n", num1);
                }
                break;
            }
            case 3:
                q1.peek();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
}

//Function to insert an element into queue
void queue::enqueue(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newnode->data = data;
    newnode->next = nullptr;
    
    if (rear == nullptr) {  // If queue is empty
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

//Function to delete an element from queue
int queue::dequeue() {
    if (front == nullptr) {
        return -1;  // Queue is empty
    }

    struct node *temp = front;
    int del_data = front->data;
    front = front->next;

    if (front == nullptr) {  // If the queue is now empty, update rear
        rear = nullptr;
    }

    free(temp);
    return del_data;
}

//Function to print the front element of queue
void queue::peek() {
    if (front == nullptr) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}
