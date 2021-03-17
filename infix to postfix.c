#include<conio.h>
#include<stdio.h>
char stack[100];
char infix[100],postfix[100]; //global variable declaration
int top = -1;
void push(char x)
{
    top=top+1;
    stack[top]=x;
}
int priority(char x)
{
    if(x=='^')
        return 3;
    else if(x=='*'||x=='/')
        return 2;
    else if(x='+'||x=='-')
        return 1;
    else
        return 0;
}

char pop()
{
    return(stack[top--]);
}
int is_operator(char x)
{

    if(x=='^'||x=='+'||x=='-'||x=='*'||x=='/')
        return 1;
    else
        return 0;
}
infixtopostfix(char infix[])
{
    int i=0,j=0;
    char temp;
    while(infix[i]!='\0')  //one by one reading of character of expression
    {

        if(infix[i]=='(') // condition for '('
             push(infix[i]);

        else if(infix[i]>='A'&&infix[i]<='Z' || infix[i]>='a'&&infix[i]<='z' ) //condition for character
            {
                postfix[j] = infix[i];
                j++;
                puts(postfix);

            }
        else if(is_operator(infix[i])==1) //condition checking for operator
        {
            temp=pop();
            while(priority(temp)>priority(infix[i])) // priority checking of operator
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
            push(temp);
             push(infix[i]);
             puts(postfix);

        }
        else if(infix[i]==')') // condition for ')'
        {
            temp = pop();
            while(temp!='(')
            {
                postfix[j++]=temp;
                temp = pop();
            }
            puts(postfix);


        }
        i++;
    }


    while(top!=-1) //reading left value in stack
    {

        postfix[j]=pop();
        j++;
        puts(postfix);
     }
     postfix[i]='\0'; //assign null value to  char array
}

main()
{

    printf("Enter the infix expression : ");
    gets(infix);      //insert expression
    infixtopostfix(infix); //calling fun
    puts(postfix); //printing postfix expression

}
