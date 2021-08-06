#include<stdio.h>
#define size 5
int deque[size] , front=-1 , rear=-1 ;
void insertFront();
void insertRear();
void deleteFront(void);
void deleteRear(void);
void display(void);
int isOverflow(void);
int isUnderflow(void);
void main()
{
	int choice , ele ;
	while(1)
	{
		printf("/*Deque operations**/\n");
		printf("1.InsertFront\n");
		printf("2.InsertRear\n");
		printf("3.DeleteFront\n");
		printf("4.DeleteRear\n");
		printf("5.Display\n");
		printf("6.Quit\n");

		printf("Enter your choice : ");
		scanf("%d", &choice);

		

		switch(choice)
		{
			case 1		:	insertFront(ele);
						break ;

			case 2		:	insertRear(ele);
						break ;

			case 3		:	deleteFront();
						break ;

			case 4		:	deleteRear();
						break ;

			case 5		:	display();
						break ;

			case 6		:	exit(1);
			defualt	:	printf("Invalid choice...\n\n");
		}
	}
}
void insertFront(){
if(isOverflow()){int data;
      printf("Queue is Full\n");
      return 0;
}
printf("Enter the element");
scanf("%d",&data);
if(front==-1){
      front=rear=0;

}
else if(front==0){
      front=size-1;
}
else {
      front--;
}
deque[front]=data;
}


void insertRear(){int data;
if(isOverflow()){
      printf("Queue is Full\n");
      return 0;
}
printf("Enter the element");
scanf("%d",&data);
if(rear==-1){
      rear=0;
}
else if(rear==size-1){
      rear=0;
}
else {
      rear++;
}
deque[rear]=data;
}


void deleteFront(){
if(isUnderflow()){printf("Queue is Empty\n");
return;}
printf("Deleted element is %d\n",deque[front]);
if(front==rear)front=rear=-1;
else if(front==size-1){
      front=0;
}
else {
      front++;
}
}
void deleteRear(void){
if(isUnderflow()){
      printf("Queue is empty\n");
      return 0;
}
printf("Deleted element is %d",deque[rear]);
if(rear==front){
    front=rear=-1;
}
else if(rear==0){
      rear=size-1;
}
else {
      rear--;
}
}
int isOverflow(void){
if(((front==0)&&(rear==size-1))||front==rear+1){
      return 1;
}
else return 0;
}
int isUnderflow(){
if(front==-1||rear==-1){
      return 1;
}
else return 0;
}

void display(void){
int i;
	if(front == -1)
	{
		printf("No elements to display\n\n");
	}
	else if(front<=rear)
	{
		for(i=front ; i<=rear ; i++)
		{
			printf("Element %d : %d \n", i+1, deque[i]);
		}
		printf("\n");
	}
	else
	{
		for(i=front ; i<=size-1; i++)
		{
			printf("Element %d : %d \n",i+1,deque[i]);
		}
		for(i=0 ; i<=rear ; i++)
		{
			printf("Element %d : %d \n",i+1,deque[i]);
		}
		printf("\n");
	}
}
