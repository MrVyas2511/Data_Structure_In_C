#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
char infix[100];
int stack[100];
int top = -1;
int pop()
{

    return stack[top--];

}
void push(int x)
{
    top++;
    stack[top]=x;
}
int is_operator(char x)
{
    if(x=='+'||x=='^'||x=='*'||x=='/'||x=='-')
        return 1;
    else return 0;
}
void evaluate(char infix[])
{
    infix[100] =atoi(infix);
    int i=0,x;
    int val1,val2,temp;

    while(infix[i]!='\0')
    {

        if(is_operator(infix[i])==1)
        {
                val1=pop();
                val2=pop();
                if(infix[i]=='+')
                    temp = val1 + val2;
               else if(infix[i]=='-')
                    temp = val1 - val2;
               else if(infix[i]=='/')
                    temp = val1 / val2;
               else if(infix[i]=='*')
                    temp = val1 * val2;
               else if(infix[i]=='^')
                    temp = val1 ^ val2;


                    push(temp);
        }
        else
        {
            x=infix[i];
            push(x);
        }
             i++;
    }

}
main()
{

    printf("\nEnter the infix expression : ");
    gets(infix);
    puts(infix);
    evaluate(infix);
    printf("%d",pop());
}
