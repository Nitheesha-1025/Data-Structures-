#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

//checking whether the number is Armstrong or not
void armstrong(int *num)
{
     int *temp=(int*)malloc(sizeof(int));
      int *n=(int*)malloc(sizeof(int));
       int *k=(int*)malloc(sizeof(int));
        int *sum=(int*)malloc(sizeof(int));
     *temp=*num;
     while((*temp)!=0)
     {
        *temp=(*temp)/10;
        (*n)++;
     }
     *temp=*num;
     while((*temp)!=0)
     {
        *k=(*temp)%10;
        (*sum)+=pow(*k,*n);
        *temp=(*temp)/10;

     }
     if(*sum==*num)
     {
        printf("The number is a armstrong\n");
     }
     else{
        printf("The number is not Armstrong\n");
     }
}

//checking whether the number is Palindrome or not
void palindrome(int *num)
{
    int *temp=(int*)malloc(sizeof(int));
    int *k=(int*)malloc(sizeof(int));
     int *rev=(int*)malloc(sizeof(int));
    *temp=*num;
    while((*temp)!=0)
    {
        *k=(*temp)%10;
        *rev=((*rev)*10)+*k;
        *temp=(*temp)/10;
    }
    if(*rev==*num)
    {
        printf("The number is a Palindrome\n");
    }
    else{
        printf("The number is not a Plaindrome\n");
    }
}

//checking whether the number is Perfect or not
void perfect(int *num)
{
    int *temp=(int*)malloc(sizeof(int));
    int *n=(int*)malloc(sizeof(int));
    int *sum=(int*)malloc(sizeof(int));
    int *i=(int*)malloc(sizeof(int));
    *temp=*num;
     while((*temp)!=0)
     {
        *temp=(*temp)/10;
        (*n)++;
     }
     *temp=*num;
     for(*i=1;*i<*n;(*i)++)
     {
        if((*temp)%(*i)==0)
        {
            (*sum)+=*i;
        }
        *temp=(*temp)/10;
     }
     if((*sum)==(*num))
     {
        printf("The number is a Perfect number\n");
     }
     else{
        printf("The number is not a perfect number\n");
     }
}


int main()
{
    int *opt=(int*)malloc(sizeof(int));
    int *number=(int*)malloc(sizeof(int));
   
    while(1){
    cout<<"Enter the number you want to check\n";
    cin>>(*number);
    cout<<"Enter the choice you want to make\n1.Armstrong number\n2.Palindrome number\n3.Perfect number\n4.exit\n";
    cin>>(*opt);
    switch(*opt)
    {
        case 1:
                armstrong(number); 
                break;
        case 2:
                palindrome(number);
                break;
        case 3:
                perfect(number);

                break;
        case 4:
                
                printf("exit\n");
                return(0);
        default:
                 printf("Invalid Option\n");
                
    }
    }

}
