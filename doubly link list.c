#include<stdio.h>
struct Node{
int data;
int *right,*left;};
struct Node *start=NULL,*last=NULL;
void createNode();
void Append();
void addfirst();
void addafter();
void display();
int length();
void append();
void deletefirst();
void deleteafter();
void print_reverse();
void sort();
void swap();
void print_address();

int main(){
int ch;

while(1){
puts("1.crateNode");
puts("12.display");
puts("11.length");
puts("10.addfrst");
puts("9.append");
puts("8.addafter");
puts("7.deletefirst");
puts("6.delete after");
puts("5.print reverse");
puts("4.sort");
puts("3.print address");
puts("2.swap");
printf("enter the choice");
scanf("%d",&ch);
switch(ch){
case 1:createNode();
      break;
case 12:display();
      break;
case 11:printf("length=%d\n",length());
      break;
case 10:addfirst();
      break;
case 9:append();
      break;
case 8:addafter();
      break;
case 7:deletefirst();
      break;
case 6:deleteafter();
      break;
case 5:print_reverse();
      break;
case 4:sort();
      break;
case 3: print_address();
       break;
case 2:swap();
       break;
case 13:exit(0);
default:printf("Invalid choice");
        }
}
}
void createNode(){
struct Node *temp;
temp=(struct Node*)malloc(sizeof(struct Node));
printf("enter the data");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(start==NULL){
      start=last=temp;
}
else {
      last->right=temp;
      temp->left=last;
      last=temp;
}
      }
void display(){
struct Node *temp=start;
if(start==NULL){
      printf("List is empty");
}
else{
while(temp)
{
      printf("%d\t",temp->data);
      temp=temp->right;
      }
}
}
int  length(){
int c=0;
struct Node *temp=start;
if(temp!=NULL)
{
      while(temp){
            c++;
            temp=temp->right;
      }

}
return c;
}
void addfirst(){
struct Node *temp;
temp=(struct Node*)malloc(sizeof(struct Node));
printf("enter the data");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(start==NULL){
 last=start=temp;
}
else{
      start->left=temp;
      temp->right=start;
     start=temp;

}
}
void append(){   //to add node at last
struct Node *temp;
temp=(struct Node*)malloc(sizeof(struct Node));
printf("enter the data");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(start==NULL){
      start=last=temp;
}
else{
      last->right=temp;
      temp->left=last;
      last=temp;
}
}
void addafter(){
struct Node *temp;
int loc;
printf("enter the location which you want top add\n");
scanf("%d",&loc);
struct Node *p=start,*q=start;
if(loc==0||loc>length()){
      printf("Invalid choice\n");

}
else{
            temp=(struct Node*)malloc(sizeof(struct Node));
            printf("enter the data");
            scanf("%d",&temp->data);
            temp->left=NULL;
            temp->right=NULL;
            while(loc>1){
                  p=p->right;
                  loc--;
            }
            if(p->right==NULL)
            {
            p->right=temp;
            temp->left=p;
            }
            else {
            q=p->right;
            p->right=temp;
            temp->left=p;
            temp->right=q;
            q->left=temp;
            }}
}
void deletefirst(){
if(start==NULL){
      printf("list is empty");
}
else{
      struct Node*temp=start;
      start=start->right;
      printf("deleted element is %d",temp->data);
      if(start){
      start->left=NULL;}
      temp->right=NULL;
      free(temp);

      }
}
void deleteafter(){
int loc;
printf("enter the location: \t");
scanf("%d",&loc);
if(loc==0||loc>=length()){
      printf("Invalid choice");
}
else{
      struct Node *p;
      struct Node *q,*temp,*z=start;
      p=start;
      while(loc>1){
            p=p->right;
            loc--;
      }
q=temp=p->right;
p->right=q->right;
printf("deleted element is %d\t\n",q->data);
if(q->right){
q=q->right;
q->left=p;
}
q=temp;
q->left=NULL;
q->right=NULL;
free(q);
while(z){
      last=z;
z=z->right;}

}
}
void print_reverse(){
if(start==NULL){
      printf("List is empty");
}
else {
      struct Node *temp;
      temp=last;
      while(temp){
            printf("%d\t",temp->data);
            temp=temp->left;
      }
}
}
void sort(){
if(start==NULL){
      printf("List is empty\n");
}

else{
      struct Node *p=start,*q;

      int c=length();
      int i,j,temp;
      for(i=2;i<=c;i++){q=p->right;
            for(j=0;j<=c-i;j++){
                  if((p->data) >= (q->data))
                  {
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                  }
            q=q->right;}
      p=p->right;}
      printf("data has sorted");
}
}
void print_address(){
if(start==NULL){
      printf("list is empty");
}
else {
   struct Node *p=start;
   struct Node *q=last;
   while(p){
      printf("%d\t%u\n",p->data,p->right);
      p=p->right;
   }
   printf("************\n");
   while(q){
      printf("%d\t%u\n",q->data,q->left);
      q=q->left;
   }
}
}
void swap(){
int loc1, loc2,temp;
printf("enter the location of node to be swapped");
scanf("%d%d",&loc1,&loc2);
if(loc1==0||loc2==0||loc1>length()||loc2>length()||start==NULL)
{
      printf("Invalid Locations or list is empty\n");
}
else{
      struct Node *p=start,*q=start;
      while(loc1>1){
            p=p->right;
            loc1--;
      }
      while(loc2>1){
            q=q->right;
            loc2--;
      }
     temp=p->data;
     p->data=q->data;
     q->data=temp;
}
}
