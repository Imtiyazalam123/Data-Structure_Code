#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct BST {

          struct BST *left;
          int item;
          struct BST *right;
};
void insert(struct BST **root, int data) {

          struct BST *n, *ptr;
          n = (struct BST*) malloc(sizeof(struct BST));
          n->right = NULL;
          n->left = NULL;
          n->item = data;

          if(*root == NULL)
                    *root = n;
          else {
                    ptr = *root;
                    while(1) {
                           if(ptr->item == data){
                                        printf("\n duplicate values are not allowed !!!.......");
                                        free(n);
                                        break;
                           }
                           else if(ptr->item > data) {
                                        if(ptr->left == NULL) {
                                                  ptr->left = n;
                                                  break;
                                        }
                                        else
                                                  ptr = ptr->left;
                           }
                           else {
                                        if(ptr->right == NULL){
                                                  ptr->right = n;
                                                  break;
                                        }
                                        else
                                                  ptr = ptr->right;
                           }
                    }
          }
}
void deletion(struct BST **root, int data) {

          struct BST *ptr, *parptr, *pred, *parpred;
          ptr = *root;
          if(*root == NULL)
                    printf("\n Underflow... nothing to delete.!!!!!!!!!!!!!!");
          else {
                    parptr = NULL;
                    ptr = *root;
                    while(ptr->item != data && ptr != NULL) {

                              if(ptr->item > data){
                                        parptr = ptr;
                                        ptr = ptr->left;
                              }
                              else {
                                        parptr = ptr;
                                        ptr = ptr->right;
                              }
                    }
                    if(ptr == NULL)
                              printf("\n Data Not Found.....");
                    else {
                              if(ptr->left == NULL && ptr->right == NULL) {
                                        if(parptr == NULL)
                                                  *root = NULL;
                                        else if(ptr == parptr->left)
                                                parptr->left = NULL;
                                        else
                                                  parptr->right = NULL;
                                        free(ptr);
                              }
                              else if(ptr->left == NULL || ptr->right == NULL){

                                        if(parptr == NULL){
                                                  if(ptr->left != NULL)
                                                            *root = ptr->left;
                                                  else
                                                            *root = ptr->right;
                                        }
                                        else if(ptr == parptr->left) {

                                                  if(parptr->left != NULL)
                                                            parptr->left = ptr->left;
                                                  else
                                                            parptr->left = ptr->right;
                                        }
                                        else {
                                                  if(ptr->left != NULL)
                                                            parptr->right = ptr->left;
                                                  else
                                                            parptr->right = ptr->right;
                                        }
                                        free(ptr);
                              }
                              else {
                                        pred = ptr->left;
                                        parpred = ptr;

                                        while (pred->right != NULL){

                                                  parpred = pred;
                                                  pred = pred->right;
                                        }
                                        ptr->item == pred->item;
                                        if(pred == parpred->left) {
                                                  parpred->left = pred->left;
                                        }
                                        else{
                                                  parpred->right = pred->left;
                                        }
                                        free(pred);
                              }
                    }
          }
}
void postOrderTraverse(struct BST *root){
          if(root != NULL){
                    if(root->left != NULL)
                              postOrderTraverse(root->left);
                    if(root->right != NULL)
                              postOrderTraverse(root ->right);
                    printf(" %d", root->item);
          }
}
void preOrderTraverse(struct BST *root) {

          if(root != NULL) {
                    printf(" %d", root->item);
                    if(root->left != NULL)
                              preOrderTraverse(root->left);
                    if(root->right != NULL)
                              preOrderTraverse(root->right);
          }
}
void inorderTraverse(struct BST *root) {

          if(root != NULL) {
                    if(root->left != NULL)
                              inorderTraverse(root->left);
                    printf("%d ", root->item);
                    if(root->right != NULL)
                              inorderTraverse(root->right);
          }
}
int search(struct BST *root, int data) {


               if (root != NULL) {

                              if(root->item == data)
                                        return 1;
                              else if(root->item > data)
                                        search(root->left, data);
                              else if(root->item < data)
                                        search(root->right, data);
                    }
                    return -1;
}
int menu() {

          int choice;
          printf("\n 1. press one for insert in binary search tree ");
          printf("\n 2. press two for traverse BST in post Order");
          printf("\n 3. press three for traverse BST in pre Order");
          printf("\n 4. press four for traverse BST in inorder (sorting order of BST0)");
          printf("\n 5. press five for Exit....");
          scanf("%d", &choice);

          return choice;
}
int main() {
          struct node *root = NULL;
          int data;
          while(1) {
                    system("cls");
                    switch(menu()) {

                              case 1 :
                                        printf("\n Enter Item");
                                        scanf("%d", &data);
                                        insert(&root, data);
                                        break;
                              case 2 :
                                        postOrderTraverse(root);
                                        break;
                              case 3 :
                                        preOrderTraverse(root);
                                        break;
                              case 4 :
                                        inorderTraverse(root);
                                        break;
                              case 5 :
                                        exit(0);
                              default :
                                        printf("\n invalid Choice please enter valid choice");
                    }
                    getch();
          }
          return 0;
}
