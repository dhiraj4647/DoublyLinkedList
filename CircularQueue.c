//Circular Queue follows FIFO rule
#include<stdio.h>
#define size 5
int cqueue[size];
int front=-1, rear=-1;
void enqueue(int);
int dequeue(void);
void display(void);
int underflow(void);
int overflow(void);
void main()
{
	int ch,item;
	printf("***Circular Queue Operations***\n");
	while(1)
	{
		printf("1. Insert \n");
		printf("2. Delete \n");
		printf("3. Display \n");
		printf("4. Exit \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1    :	if(!overflow())
					{
						printf("Enter item to insert : ");
						scanf("%d",&item);
						enqueue(item);
					}
					else
					{
						printf("Queue is Full\n\n");
					}
					break;

			case 2    :	if(!underflow())
					{
						int ele = dequeue();
				   		printf("Deleted : %d\n\n",ele);
					}
					else
					{
						printf("Queue is Empty\n\n");
					}
					break;

			case 3    :	if(!underflow())
					{
						printf("The queue is : \n");
						display();
					}
					else
					{
						printf("No elements to display \n");
					}
					break;

			case 4    :	exit(1);
			default   :	printf("Your choice is wrong \n\n");
		}
	}
}
void enqueue(int data){
  if(front==-1){
      front=rear=0;
  }
  else if(rear==size-1) {
      rear=0;
  }
  else {
      rear++;
  }
  cqueue[rear]=data;
}

int dequeue(void){
int data=cqueue[front];
if(front==size-1){
      front=0;
}
else if(front==rear){
      front=rear=-1;
}
else {
      front++;
}
return data;
}

void display(void){
int i;
if(front<=rear){
      for(i=front;i<=rear;i++){
            printf("%d\t",cqueue[i]);
      }
}
else {
      for(i=front;i<size-1;i++){
            printf("%d\t",cqueue[i]);
      }
      for(i=0;i<=rear;i++){
            printf("%d\t",cqueue[i]);
      }
}

}


int underflow(void){
if(front==-1&&rear==-1){
      return 1;
}
else return 0;
}
int overflow(void){
if((front==0&&rear==size-1)||front==rear+1)
return 1;
else return 0;
}

