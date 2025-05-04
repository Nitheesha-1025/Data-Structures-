#include <stdio.h>
#include <stdlib.h>

class list {
private:
    struct node {
        int time;
        struct node* next;
    };

    node* head;

public:
    list() { head = nullptr; }

    int insert(int);
    int execute(int);
    void display();
};

int list::insert(int burst_time) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->time = burst_time;
    newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
        head->next = head;
        return 1;
    }

    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
    return 1;
}

int list::execute(int const_time) {
    if (head == nullptr) {
        printf("There are no processes available\n");
        return 0;
    }

    node* temp = head;
    int remaining_time = temp->time - const_time;

    printf("Executing process with burst time %d for %d ms\n", temp->time, const_time);

    if (remaining_time <= 0) {
        printf("The process is completed\n");

        if (temp->next == temp) { // Only one node
            free(temp);
            head = nullptr;
        } else {
            node* last = head;
            while (last->next != temp) {
                last = last->next;
            }

            head = temp->next;
            last->next = head;
            free(temp);
        }
    } else {
        printf("Process not completed, remaining time: %d ms\n", remaining_time);

        node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        head = temp->next;
        last->next = head;

        temp->time = remaining_time;
        last->next = temp;
        temp->next = head;
    }

    return 1;
}

void list::display() {
    if (head == NULL) {
        printf("No processes in the queue.\n");
        return;
    }

    node* temp = head;
    printf("Processes in queue: ");
    do {
        printf("%d ms   ", temp->time);
        temp = temp->next;
    } while (temp != head);
    printf("(back to start)\n");
}



