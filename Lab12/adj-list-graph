//Program to implement graph ADT using adjacency list
#include <cstdio>
#include <iostream>
using namespace std;
class graph{
    private:
    struct node{
        int data;
        struct node* next;
    }*list[9];
    int numvertices;
    public:
    graph(int vertices){
        if(vertices > 9) {
            cout<<"Number of vertices entered greater than maxsize\n";
            vertices = 9
        }
        numvertices = vertices;
        for (int =0;i<numvertices;i++){
            list[i] = nullptr;
        }
    }
    int edgexists(int,int);
    int insert(int,int);
    int delete1(int,int);
    int search(int,int);
    void display();
};
int main(){
    int choice;
    int src;
    int dest;
    int vertices;
    cout<<"Enter number of vertices:";
    cin>>vertices;
    graph g1(vertices);
    while(1){
        printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to display\n");
        printf("Enter 4 to display\nEnter 5 to exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the src vertex to insert:");
            scanf("%d",&src);
            printf("Enter the dest vertex to insert:");
            scanf("%d",&dest);
            g1.insert(src,dest);
            break;
            case 2:
            printf("Enter the src vertex to delete:");
            scanf("%d",&src);
            printf("Enter the dest vertex to delete:");
            scanf("%d",&dest);
            g1.delete1(src,dest);
            break;
            case 3:
            printf("Enter the src vertex to search for:");
            scanf("%d",&src);
            printf("Enter the dest vertex to search for:");
            scanf("%d",&dest);
            g1.search(src,dest);
            break;
            case 4:
            g1.display();
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
//Function to check if a edge exists
int graph:: edgexists(int src,int dest){
    struct node* temp = list[src];
    while (temp){
        if(temp->data == dest){
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}
//Function to insert elements
int graph::insert(int src,int dest){
    if(src>9 || dest<0 ||src<0 || dest>9){
        cout<<"Enter valid src and dest values\n";
        return -1;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnnode->data = src;
    newnode->next = arr[dest];
    list[dest] = newnode;
    struct node* newnode1 = (struct node*)malloc(sizeof(struct node));
    newnnode1->data = dest;
    newnode1->next = arr[src];
    list[src] = newnode1;
    return 1;
}
//Function to delete elements
int graph::delete1(int src,int dest){
    if(src>9 || dest<0 ||src<0 || dest>9){
        cout<<"Enter valid src and dest values\n";
        return -1;
    }
     if(edgexists(src,dest) == 1){
        struct node* curr = list[src];
        struct node* prev = nullptr;
        while(curr){
            if(curr->data == dest){
                if(prev == nullptr){
                    struct node* delnode = curr;
                    list[src] = curr->next;
                    free(delnode);
                }
                else{
                    struct node* delnode = curr;
                    prev->next = current->next;
                    free(delnode);
                }
            }
        }
        struct node* curr = list[dest];
        struct node* prev = nullptr;
        while(curr){
            if(curr->data == src){
                if(prev == nullptr){
                    struct node* delnode = curr;
                    list[src] = curr->next;
                    free(delnode);
                }
                else{
                    struct node* delnode = curr;
                    prev->next = current->next;
                    free(delnode);
                }
            }
        }
        cout<<"Deletion successfull\n";
        return 1;
     }  
     cout<<"Cannot perform deletion\nVertices not connected\n";
     return -1
}
//Function to search for elements
int graph::search(int src,int dest){
    if(src>9 || dest<0 ||src<0 || dest>9){
        cout<<"Enter valid src and dest values\n";
        return -1;
    }
    if(edgexists(src,dest)==1){
        cout<<src<<"and"<<dest<<"are connected\n";
        return 1;
    }   
    cout<<"No such edge exists\n";
    return -1;
}
//Function to display elements
void graph::display(){
    for(int i=0;i<numvertices;i++){
        cout<<i<<"->";
        struct node* temp = list[i];
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"\n";
    }
}
