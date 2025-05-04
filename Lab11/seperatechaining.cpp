//Program to implement Hash ADT using seperate chaining
#include <cstdio>
#include <cstdlib>
#define TABLESIZE 10
class sepchaining{
    private:
    struct node{
        int data;
        struct node* next;
    };
    struct node* arr[TABLESIZE];
    public:
    sepchaining(){
        for(int i=0;i<TABLESIZE;i++){
            arr[i] = nullptr;
        }
    }
    int insert(int);
    int delete1(int);
    int search(int);
    void display();
};
int main(){
    sepchaining s1;
    int choice;
    int value;
    int result;
    while(1){
        printf("Enter 1 for insert\nEnter 2 for delete\nEnter 3 for search\n");
        printf("Enter 4 for display\nEnter 5 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            result = s1.insert(value);
            if(result == 1){
                printf("Insertion successfull\n");
            }
            else{
                printf("Cannot insert\nTable is full\n");
            }
            break;
            case 2:
            printf("Enter the value to delete:");
            scanf("%d",&value);
            result = s1.delete1(value);
            if(result == -1){
                printf("Cannot delete elements\n");
            }
            else{
                printf("The element is found at the index %d\n",result);
            }
            break;
            case 3:
            printf("Enter the value to search:");
            scanf("%d",&value);
            result = s1.search(value);
            if(result == -1){
                printf("The element is not found\n");
            }
            else{
                printf("The element is found at the index %d",result);
            }
            break;
            case 4:
            s1.display();
            break;
            case 5:
            return 0;
            default:
            printf("Enter valid choice\n");
        }
        printf("\n");
        printf("\n");
    }
    return 0;
}
//Function to insert
int sepchaining::insert(int key){
    int index = key%TABLESIZE;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = arr[index];
    arr[index] = newnode;
    return 1;
}
//Function to delete
int sepchaining::delete1(int key){
    int index = key%TABLESIZE;
    struct node* curr = arr[index];
    struct node* prev = nullptr;
    while( curr!= nullptr){
        if(curr->data==key){
            if (prev == nullptr) {
                arr[index] = curr->next;
                return 1;
            }
            struct node* deletenode = curr; 
            prev->next = curr->next;
            free(deletenode);
            return 1;
        }
        prev = curr;
        curr=curr->next;
    }
    return -1;
}
//Function to search
int sepchaining::search(int key){
    int index = key%TABLESIZE;
    struct node* curr = arr[index];
    while(curr != nullptr){
        if(curr->data == key){
            return index;
        }
        curr = curr->next;
    }
    return -1;
}
//Function to display
void sepchaining::display(){
    struct node* curr;
    for(int i =0;i<TABLESIZE;i++){
        curr = arr[i];
        while(curr!=nullptr){
            printf("%d   ",curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}