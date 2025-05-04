#include<cstdio>
#include<cstdlib>
#include"stack.h"
void operation(char*);

//Main Function to implement the given operation 
int main()
{
    char str[100];
    scanf("%s",str);
    operation(str);
}

//Function to implement the given operation
void operation(char* str)
{
    stack s1;
  for(int i=0;str[i]!='\0';i++)
  {
    if(str[i]=='+')
    {
        s1.pop();
    }
    else
    {
        s1.push(str[i]);
    }
  }
  
  stack s2;
    while (!s1.isEmpty()) {
        s2.push(s1.pop());  
    }

    
    while (!s2.isEmpty()) {
        printf("%c", s2.pop());
    }
    printf("\n");
    
}
