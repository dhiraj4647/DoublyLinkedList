#include<stdio.h>
void insert(int data);
void delete(void);
void display();
struct Node{
int data;
struct Node*next;
};
struct Node *root=NULL;

void main()
{
	int ch,item,num;
	printf("***Circular Linked List Operations***\n");
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
			case 1    :	printf("Enter the element value:\t");
                              scanf("%d",&num);
                              insert(num);

					break;

			case 2    :	delete();

					break;

			case 3    :	display();
			            break;

			case 4    :	exit(1);
			default   :	printf("Your choice is wrong \n\n");
		}
	}
}
void insert(int data){
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
if(root==NULL){
      root=node;
      node->next=node;
}
else {
      struct Node *temp=root;
      while(temp->next!=root){
            temp=temp->next;
      }
      temp->next=node;
      node->next=root;
}
}

void delete(void){
int loc,i=1,j=1;
struct Node *p=root,*q=root;
printf("Enter the Location to be Deleted:\t");
scanf("%d",&loc);
while(p->next!=root){
      i++;
      p=p->next;
}
if(loc>i){
      printf("Invalid Location\n");

}
else {
     p=root;q=root;
     while(j<loc){
      p=q;
      q=q->next;
      j++;
     }
     p->next=q->next;
     printf("Deleted Element is %d:\t",q->data);
     q->next=NULL;
     free(q);
}
}

void display(){
struct Node *temp=root;
if(temp==NULL){
      printf("List is empty\n");
}
else{
     do{
      printf("%d\t",temp->data);
      temp=temp->next;
     }while(temp->next!=root);
     printf("%d\n",temp->data);
}
}
