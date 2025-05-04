#include<cstdio>
#include<cstdlib>

class list
{
    private:
    struct node
    {
        int data;
        struct node *next;
    }*head;

    public:
    list()
    {
        head=NULL;
    }
    void insert_beg(int);
    void insert_end(int);
    void insert_pos(int,int);
    int del_beg();
    int del_end();
    int del_pos(int);
    int search(int);
    void display();

};
//Main function to implement menu drive 
int main()
{
    list l1;
    int choice;
    while(1)
    {
        printf("\nChoose an operation:");
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n"
               "4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n"
               "7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                int val;
                printf("enter the value of element you want to insert:");
                scanf("%d",&val);
                l1.insert_beg(val);
                break;
            }
            case 2:
            {
                int val;
                printf("enter the value of element you want to insert:");
                scanf("%d",&val);
                l1.insert_end(val);
                break;
            }
            case 3:
            {
                int pos;
                printf("enter the position of element where you want to insert:");
                scanf("%d",&pos);
                int val;
                printf("enter the value of element you want to insert:");
                scanf("%d",&val);
                l1.insert_pos(val,pos);
                break;
            }
            case 4:
            {
                int result;
                result=l1.del_beg();
                if(result!=1)
                {
                    printf("the deleted element is:%d\n",result);
                }
                else
                {
                    printf("the list is empty\n");
                    printf("deletion failed!!\n");
                }
                break;
            }
            case 5:
            {
                int result;
                result=l1.del_end();
                if(result!=1)
                {
                    printf("the deleted element is:%d",result);
                }
                else
                {
                    printf("the list is empty\n");
                    printf("deletion failed!!\n");
                }
                break;
            }
            case 6:
            {
                int pos;
                printf("enter the position of element where you want to delete:");
                scanf("%d",&pos);
                int result;
                result=l1.del_pos(pos);
                if(result!=1)
                {
                    printf("the deleted element is:%d\n",result);
                }
                else
                {
                    printf("deletion failed!!\n");
                }
                break;
            }
            case 7:
            {
                int val;
                printf("enter the value that needs to be searched:");
                scanf("%d",&val);
                int result;
                result=l1.search(val);
                if(result!=-1)
                {
                    printf("the element was found in the position:%d",result);
                }
                else
                {
                    printf("the element was not found in the list\n");
                }
                break;
            }
            case 8:
            {
                l1.display();
                break;
            }
            case 9:
            {
                printf("exiting....");
                return;
            }
            default:
            {
                printf("invalid choice\nplease enter valid choice\n");
                break;
            }
        }
        
    }
}
void list::insert_beg(int val)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        head=newnode;
        head->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
    }
}
void list::insert_end(int val)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        head=newnode;
        head->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
}
void list::insert_pos(int val,int pos)
{
    if(pos<=0)
    {
        printf("the position is invalid.please enter valid position\n");
        return;
    }
    else if(pos==1)
    {
        insert_beg(val);
    }
    else
    {
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=val;
        struct node *temp=head;
        int count =1;
        while(temp->next!=head && count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        if(count<pos-1) 
        {
            printf("position out of bound\n");
            return;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
int list::del_beg()
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        struct node *temp1=head;
        int result=temp1->data;
        if(head->next==head)
        {
            free(head);
            head=NULL;
        }
        else
        {
            struct node *temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            head=head->next;
            temp->next=head;
            free(temp1);
        }
        return result;
    }
}
int list::del_end()
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        struct node *temp=head;
        struct node *temp1=NULL;
        if(head->next==head)
        {
            int result=head->data;
            free(head);
            head=NULL;
            return result;
        }
        else
        {
            while(temp->next!=head)
            {
                temp1=temp;
                temp=temp->next;
            }
            int result=temp->data;
            temp1->next=head;
            free(temp);
            return result;
        }
    }
}
int list::del_pos(int pos)
{
    if(pos<=0)
    {
        printf("the position is invalid.please enter valid position\n");
    }
    else if(pos==1)
    {
        return del_beg();
    }
    else
    {
        struct node *temp=head;
        struct node *temp1=head;
        int count=1;
        while(temp->next!=head && count<pos)
        {
            temp1=temp;
            temp=temp->next;
            count++;
        }
        if(count<pos)
        {
            printf("position is out of bound\n");
            return -1;
        }
        int result=temp->data;
        temp1->next=temp->next;
        free(temp);
        return result;
    }
}
int list::search(int val)
{
    if(head==NULL)
    {
        printf("the list is empty\n");
        return -1;
    }
    else
    {
        struct node *temp=head;
        int count=1;
        do
        {
            if(temp->data==val)
            {
                return count;
            }
            temp=temp->next;
            count++;
        }while(temp!=head);
    }
    return -1; 
}
void list::display()
{
    if(head==NULL)
    {
        printf("the circular linked list is empty\n");
        return;
    }
   struct node *temp=head;
    do
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
