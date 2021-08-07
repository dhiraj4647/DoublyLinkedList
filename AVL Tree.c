#include<stdio.h>
#include<stdlib.h>
struct Node* insert(struct Node *,int );
int height(struct Node *node);
int balfact(struct Node *node);
struct Node* LL(struct Node *node);
struct Node* RL(struct Node *node);
struct Node* LR(struct Node *node);
struct Node* RR(struct Node *node);
struct Node* rotateRight(struct Node *x);
struct Node* rotateLeft(struct Node *x);
struct Node* preorder(struct Node*node);
struct Node{
int data,ht;
struct Node *right,*left;
};
struct Node *root=NULL;
int lh,rh;
void main(){
root=insert(root,10);
root=insert(root,20);
root=insert(root,30);
root=insert(root,25);
root=insert(root,78);
preorder(root);

}
struct Node* insert(struct Node *node,int x){
if(node==NULL){
      node=(struct Node*)malloc(sizeof(struct Node));
      node->right=NULL;
      node->left=NULL;
      node->data=x;
}
else {
      if(x>node->data){
            node->right=insert(node->right,x);
            if(balfact(node)==-2){
                  if(x>node->right->data){
                       node=RR(node);
                  }
                  else {
                      node=RL(node);
                  }
            }

      }
      else if(x<node->data){
            node->left=insert(node->left,x);
            if(balfact(node)==2){
                  if(node->left->data>x){
                        node=LL(node);
                  }
                  else {
                        node=LR(node);
                  }
            }
      }

}
node->ht=height(node);
return node;
}
int height(struct Node *node){
      if(node==NULL){
            return 0;
      }
      if(node->right==NULL){
            rh=0;
      }
      else{
            rh=1+node->right->ht;
      }
      if(node->left==NULL){
            lh=0;
      }
      else{
            lh=1+node->left->ht;
      }
      if(lh>rh){
            return lh;
      }
      else return rh;
}
int balfact(struct Node *node){
if(node==NULL){
            return 0;
      }
      if(node->right==NULL){
            rh=0;
      }
      else{
            rh=1+node->right->ht;
      }
      if(node->left==NULL){
            lh=0;
      }
      else{
            lh=1+node->left->ht;
      }


return lh-rh;
}
struct Node* LL(struct Node *node){
node=rotateRight(node);
return node;
}
struct Node* LR(struct Node *node){
node=rotateLeft(node);
node=rotateRight(node);
return node;
}
struct Node* RR(struct Node *node){
node=rotateLeft(node);
return node;
}
struct Node* RL(struct Node *node){
node=rotateRight(node);
node=rotateLeft(node);
return node;
}
struct Node* rotateRight(struct Node *x){
      struct Node*y;
y=x->left;
x->left=y->right;
y->right=x;
x->ht=height(x);
y->ht=height(y);
return y;
}
struct Node* rotateLeft(struct Node *x){

struct Node *y;
y=x->right;
x->right=y->left;
y->left=x;
x->ht=height(x);
y->ht=height(y);
return y;
}
struct Node* preorder(struct Node*node){
if(node==NULL)return 0;
printf("%d\t",node->data);
preorder(node->left);
preorder(node->right);
}


