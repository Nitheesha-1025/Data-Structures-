#include<cstdio>
#include<cstdlib>
#include<ctype.h>
#include"stack.h"

#define size 100
char infix[size],postfix[size];

void convert_infix();
int precedence(char );
int evaluate_postfix();

//Main function to implement convertion of infix to postfix and evaluate postfix operation
int main()
{
    int opt;
    while(1)
    {
        printf("Choose between the following\n1.Get Infix\n2.Convert Infix\n3.Evaluate Post Fix\n4.Exit\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                    printf("Enter the string you want to Convert\n");
                    scanf("%s",infix);
                    break;
            case 2:
                    convert_infix();
                    printf("Postfix Expression: %s\n", postfix);  

                    break;
            case 3:
                    int ans;
                    ans=evaluate_postfix();
                    printf("The result after evaluation postfix is %d\n",ans);
                    break;
            case 4:
                    printf("Exiting program\n");
                    return 0;
            default:
                    printf("Invalid option\n");

        }
    }
}

//Function to return an integer value according to the precedence of a operator
int precedence(char c)
{
    if (c == '+' || c == '-')
     return 1;
    if (c == '*' || c == '/' || c=='%') 
     return 2;
    if (c == '=')
     return 0;  
    return -1;
}

//Function to implement convertion from Infix to Postfix 
void convert_infix()
{
    int j=0;
    stack s1;
    for(int i=0;infix[i]!='\0';i++)
    {
        if(isalnum(infix[i]))
        {
          postfix[j++]=infix[i];
        }
        else if(infix[i]=='(')
        {
            s1.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(!(s1.isEmpty())&& s1.peek()!='(')
            {
              postfix[j++]=s1.pop();
            }
            s1.pop();
        }
        else
        {
            while(!(s1.isEmpty()) && precedence(infix[i])<=precedence(s1.peek()))
            {
                postfix[j++]=s1.pop();
            }
            s1.push(infix[i]);
        }
        
    }
    while(!(s1.isEmpty()))
        {
            postfix[j++]=s1.pop();
        }
    postfix[j]='\0';
}

//Function to evaluate postfix expression and return the result 
int evaluate_postfix()
{
    stack s1;
    for(int i=0;postfix[i]!='\0';i++)
    {
    if(isalnum(postfix[i]))
    {
        s1.push(int(postfix[i]-'0'));
    }
    else 
    {
      int num2=s1.pop();
      int num1=s1.pop();
      switch(postfix[i])
      {
        case '*':
                 s1.push(num1*num2);
                 break;
        case '+':
                 s1.push(num1+num2);
                 break;
        case '/':
                 s1.push(num1/num2);
                 break;
        case '-':
                 s1.push(num1-num2);
                 break;
        case '%':
                 s1.push(num1%num2);
                 break;
        case '=':
                 s1.push(num1);
                 break;
      }

    }
}
return s1.pop();
}

