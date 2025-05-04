#include <cstdio>
#include <cstdlib>

//class to implement circular queue suing array
class queue {
private:
       int count,front,rear;
       int array[5];
public:

    queue() {
         count=0;
         front=-1;
         rear=-1;
    }

    int enqueue(int);
    int dequeue();
    void peek();
};

//Main function to implement circular queue
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
                int check=q1.enqueue(num);
                if(check==-1)
                {
                    printf("The queue is full\n");
                }
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

//Function to insert an element into circular queue
int queue::enqueue(int data)
{
    
    
    
    if((rear+1)%5==front)
        return -1;
    if(count==0)
    {
            array[0]=data;
            count++;
            front=rear=0;
            return 1;
    }
    else
    {
        count++;
        rear=(rear+1)%5;
        array[rear]=data;
        return 1;
    }


        
}

//Function to delete an element from  circular queue
int queue::dequeue()
{
  
  if(count==0)
  {
    return -1;
  }
  if(count==1)
  {
    int del_elt=array[front];
    front=rear=-1;
    count=0;
    return del_elt;
  }
  else
  {
    
    int del_elt=array[front];
    front=(front+1)%5;
    count--;
    return del_elt;
  }
  
}

//Function to print the front element of circular queue
void queue::peek()
{
  if(count==0)
  {
    printf("The queue is empty\n");
  }
  else
  {
  printf("%d",array[front]);
  }
}