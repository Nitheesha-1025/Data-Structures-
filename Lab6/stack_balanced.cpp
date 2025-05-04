#include<cstdio>
#include<cstdlib>
#include"stack.h"

int check_bal(const char* );

//Main function implmentation 
int main()
{
   stack s1;
   int opt;
   while(1)
   {
    printf("Enter your choice between the following\n1.Check Balance\n2.Exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
              char str[100];
              printf("Enter the expression you want to check\n");
              scanf("%s",str);
              int check;
              check=check_bal(str);
              if(check==0)
              {
                printf("It is an unbalanced equation\n");
              }
              else
              {
                printf("It is a balanced reaction\n");
              }
              break;
      case 2:
              printf("Exiting program\n");
              return 0;
      default:
              printf("Invalid option\n");
              break;
    }
   }  
}

// Function to check whether equation is balanced or not
int check_bal(const char* str)
{
  stack s1;
   for(int i=0;str[i]!='\0';i++)
   {
    if(str[i]=='(')
    {
        s1.push('(');
    }
    else if (str[i]==')')
    {
        s1.pop();
    }
    
   }
   return s1.isEmpty();
}


