#include<conio.h>
#include<stdio.h>
#include<string.h>
int stack[30];
int top=-1;
void push(char x)
{
    top=top+1;
    stack[top]=x;
}
char pop()
{
    return(stack[top--]);

}
main()
{
    char str[100],temp;
    int flag = 1,i=0;
    printf("---------------{[(Parentheses checker)]}-----------");
    printf("\n\n Enter expression  : ");
    gets(str);
    while(str[i]!='\0')
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            push(str[i]);
        if(str[i]==')'||str[i]=='}'||str[i]==']')
            {
               temp=pop();
               printf("\n%c%c",temp,str[i]);
                if(str[i]==')'&& (temp=='{'||temp=='['))
                    flag = 0;
               else if(str[i]=='}'&& (temp=='('||temp=='['))
                    flag = 0;
               else if(str[i]==']'&& (temp=='{'||temp=='('))
                    flag = 0;
            }
            i++;
    }

     if(flag==1)
    {
        printf("\n -----------expression is valid-----------");
    }
    else if(flag==0)
    {
        printf("\n ------------expression is not valid-------------");
    }
}
