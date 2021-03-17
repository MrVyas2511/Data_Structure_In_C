 #include<conio.h>
 #include<stdio.h>
 #include<stdlib.h>

 main()
 {

     char str[100],substr[100];
     int pos,size,j=0,i;
     printf("Enter the string =");
     gets(str);
     printf("\nEnter the poission from where you wann to take substring=");
     scanf("%d",&pos);
     printf("\n enter the size of substring=");
     scanf("%d",&size);

     for(int i=0;i<=size;i++)
     {
         substr[i]=str[pos];
         pos++;
     }
     substr[i]='\0';
     puts(str);
     puts(substr);


 }
