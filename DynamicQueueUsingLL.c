#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
struct Node *front=NULL,*rear=NULL;

void main(){
int i,j,z,x;
while(1){
      puts("1.insert");
      puts("2.Delete");
      puts("3.Display");
      puts("4.exit");
      printf("Enter the choice");scanf("%d",&i);
      switch(i){
      case 1:printf("Enter the element");
            scanf("%d",&x);
            insert(x);
      break;
      case 2:delete();
      break;
      case 3:display();
      break;
      case 4:exit(0);
      break;
      default:printf("Enter the Correct Choice");
      }

}
}
void insert(int value){
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->next=NULL;
node->data=value;
if(front==NULL){
front=rear=node;
}
else {
      rear->next=node;
      rear=node;
}
}
void delete(){
      if(front==NULL)printf("Empty Queue");

      printf("Deleted Element is %d",front->data);
      front=front->next;

}
void display(){
if(front==rear)printf("List is Empty");
else{
      for(struct Node*i=front;i!=NULL;i=i->next){
            printf("%d\t",i->data);
      }
}
}
