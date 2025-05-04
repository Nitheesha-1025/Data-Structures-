#include<cstdio>
#include<cstdlib>
//class to implement stack 
class stack{
    private:
             struct node{
                   char data;
                   struct node* next;
             }*top;
    public:
             stack()
             {
                top=nullptr;
             }
             int push(char);
             char pop();
             char peek();
             void display();
             int isEmpty();
}; 

//Function to check whether the stack is empty or not 
int stack::isEmpty()
{
    return top==nullptr;
} 

//Function to insert element into the stack 
int stack::push(char num)
{
   struct node* newnode=(struct node*)malloc(sizeof(struct node*));
   newnode->data=num;
   newnode->next=top;
   top=newnode;
   return 1;
}

//Function to remove the last inserted element from the stack
char stack::pop()
{
    char del_elt;
    if(top==nullptr)
    {
        return '0';
    }
    struct node* del_node=top;
    del_elt=top->data;
    top=top->next;
    free(del_node);
    return del_elt;
}

//Function to print the last inserted element
char stack::peek()
{
    if(top==nullptr)
    {
        return '0';
    }
    char c;
    c=top->data;
    return c;
}

//Function to display the stack 
void stack::display()
{
   if(top==nullptr)
   {
    printf("The list is empty\n");
   }
   else{
    struct node* temp=top;
    printf("The stack looks like\n");
    while(temp!=nullptr)
    {
        printf(" %c\n",temp->data);
        temp=temp->next;
    }
   }

}