#include<stdio.h>
#include<stdlib.h>
int n=5,top=-1,*p;

void main(){
int i,j,z,x;
p=(int *)malloc(n*sizeof(int));

while(1){
      puts("1.Push");
      puts("2.pop");
      puts("3.Display");
      puts("4.exit");
      printf("Enter the choice");scanf("%d",&i);
      switch(i){
      case 1:printf("Enter the element");
            scanf("%d",&x);
            push(x);
      break;
      case 2:z=pop();
             printf("%d\n",z);
      break;
      case 3:display();
      break;
      case 4:exit(0);
      break;
      default:printf("Enter the Correct Choice");
      }

}
}
void push(int data){
if(top<5){
      top++;
      *(p+top)=data;
}
else {
      p=(int*)realloc(p,n+1);
      top++;
      *(p+top)=data;
}}
int pop(){int data;
if(top<5){
 data=*(top+p);
}
else{
data=*(top+p);
p=(int*)realloc(p,n-1);
}
top--;
return data;
}
void display(){
for(int i=top;i>=0;i--){
      printf("%d\t",*(i+p));
}
}
