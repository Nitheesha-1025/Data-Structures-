
#include<cstdio>
#include<cstdlib>
class list{
    private:
             struct node{
                 int data;
                 struct node *next;
             }*head;
             node* gethead() const
             {
                 return head;
             }
            
    public:
             list()
             {
                head=nullptr;
             }
             int insert_asc(int );
             void display();
             int merge(const list &list1,const list &list2);
            };
 
int main()
{
    list l1;
    list l2;
    list l3;
    int opt;
    while(1)
    {
      printf("Enter your choice between the following options\n1.Insertion in acsending order of list1\n2.Insertion in acsending order of list 2\n3.Merging\n4.Display\n5.Exit\n");
      scanf("%d",&opt);
      switch(opt)
      {
        case 1:
                int num;
                printf("Enter the number to list 1\n");
                scanf("%d",&num);
                l1.insert_asc(num);
                break;
        case 2:
                int num1;
                printf("Enter the number to list2\n");
                scanf("%d",&num1);
                l2.insert_asc(num1);
                break;
        case 3:
                l3.merge(l1,l2);
                break;
                
        case 4:
                printf("The first list is:\n");
                l1.display();
                printf("The second list is:\n");
                l2.display();
                printf("The third list is:\n");
                l3.display();
                break;
        case 5:
                return 1;
        default:
                printf("Invalid option\n");
      }
    }
}
int list::insert_asc(int num)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=nullptr;
    newnode->data=num;
    if(head==nullptr || head->data>num)
    {
       newnode->next=head;  
       head=newnode;
       return 1;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=nullptr&&temp->next->data<num)
    {temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return 1;

 }

 int list::merge( const list &list1,  const list &list2) { 
    node* t1 = list1.gethead();
    node* t2 = list2.gethead();
    head = nullptr;
    node* current = nullptr;

    while (t1 != nullptr && t2 != nullptr) {
        node* newNode = new node;
        if (t1->data < t2->data) {
            newNode->data = t1->data;
            t1 = t1->next;
        } else {
            newNode->data = t2->data;
            t2 = t2->next;
        }
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    while (t1 != nullptr) {
        node* newNode = new node{t1->data, nullptr};
        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
        t1 = t1->next;
    }

    while (t2 != nullptr) {
        node* newNode = new node{t2->data, nullptr};
        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
        t2 = t2->next;
    }

    return 1;
}


 void list::display()
    {
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp=head;
            while(temp!=nullptr)
            {
                printf("%d ",temp->data);
                temp=temp->next;
            } 
            printf("\n");
    }
