//Function to implement Hash ADT using Quadratic Probing
#include <iostream>
using namespace std;
#define TABLE_SIZE 10
class quadraticprobing{
    private:
    int arr[TABLE_SIZE];
    public:
    quadraticprobing(){
        for(int i=0;i<TABLE_SIZE;i++){
            arr[i]=0;
        }
    }
    int insert(int);
    int delete1(int);
    int search(int);
    void display();
};
int main(){
    quadraticprobing q1;
    int value;
    int choice;
    int result;
    while(1){
        cout<<"Enter 1 for insert\nEnter 2 for delete\nEnter 3 for search\n";
        cout<<"Enter 4 for display\nEnter 5 for exit\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            result = q1.insert(value);
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
            result = q1.delete1(value);
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
            result = q1.search(value);
            if(result == -1){
                printf("The element is not found\n");
            }
            else{
                printf("The element is found at the index %d",result);
            }
            break;
            case 4:
            q1.display();
            break;
            case 5:
            return 0;
            default:
            cout<<"Enter valid choice\n";
        }
        cout>>"\n";
        cout>>"\n";
    }
    return 0;
}
//function to insert elements
int quadraticprobing::insert(int value){
    int index = value%TABLE_SIZE;
    for(int i=0;i<TABLE_SIZE;i++){
        int ins = (index+(i*i))%TABLE_SIZE;
        if(arr[ins] == -1){
            arr[ins] = value;
            return 1;
        }
    }
    return -1;
}
//Function to delete elements
int quadraticprobing::delete1(int value){
    int index = value%TABLE_SIZE;
    for(int i=0;i<TABLE_SIZE;i++){
        int ins = (index+(i*i))%TABLE_SIZE;
        if(arr[ins] == -1){
            return -1;
        }
        if(arr[ins]==value){
            arr[ins] = -1;
            return 1;
        }
    }
    return -1;
}
//Function to search for elements
int quadraticprobing::search(int value){
    int index = value%TABLE_SIZE;
    for(int i=0;i<TABLE_SIZE;i++){
        int ins = (index+(i*i))%TABLE_SIZE;
        if(arr[ins] == -1){
            return -1;
        }
        if(arr[ins]==value){
            return ins;
        }
    }
    return -1;    
}
//Function to display
void quadraticprobing(){
    for(int i=0;i<TABLE_SIZE;i++){
        printf("%d   ",arr[i]);
    }
    printf("\n");
}