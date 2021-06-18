#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class DLL {

          private :
                    struct node {

                              node *prev;
                              int item;
                              node *next;
                    } ;
          node *start;
          public:
                    DLL(){
                              start = NULL;
                    }

                    void viewList() {

                              node *n;
                              n = start;
                              while(n) {

                                        cout<<n->item<<"  ";
                                        n = n->next;
                              }
                    }
                    void removeFirst() {

                              node *r;
                              if(start != NULL) {

                                        r = start;
                                        if(r->next != NULL)
                                                  start->next->prev = NULL;
                                        start = start->next;
                                        delete r;
                              }
                    }
                    void removeLast() {

                              node *t;
                              if(start != NULL) {

                                       if(start->next == NULL) {

                                                delete start;
                                                start = NULL;
                                       }
                                       else{
                                                  t = start;
                                                  while(t->next != NULL)
                                                            t = t->next;
                                                  t->prev->next = NULL;
                                                  delete t;
                                       }
                              }
                    }
                    void insertAtFirst(int data) {

                              node *n;
                              n = new node;
                              n->item = data;
                              n->next = start;
                              n->prev = NULL;
                              if(start != NULL)
                                        start->prev = n;
                              start = n;
                    }
                    void insertAtLast(int data) {

                              node *n, *t;
                              n = new node;
                              n->next = NULL;
                              n->item = data;
                              if(start == NULL) {
                                        n->prev = NULL;
                                        start = n;
                              }
                              else {
                                        t = start;
                                        while(t->next != NULL)
                                                  t = t->next;
                                        n->prev = t;
                                        t->next = n;
                                        delete t;
                              }

                    }

};

int menu() {

          int choice;
          cout<<"\n 1. Insert item at Firsts";
          cout<<"\n 2. Insert item at Last";
          cout<<"\n 3. remove item from Firsts";
          cout<<"\n 4. Insert item from Last";
          cout<<"\n 5. For Exit";
          cout<<"\n\n Enter your Choice";
          cin>>choice;
          return choice;

}
int main() {

          DLL myList;
          int data;
          while(true) {

                    system("cls");
                    myList.viewList();
                    switch(menu()) {

                    case 1 :
                              cout<<"\n Enter item value for insert at first";
                              cin>>data;
                              myList.insertAtFirst(data);
                              break;
                    case 2 :
                              cout<<"\n Enter item Value for Insert at last";
                              cin>>data;
                              myList.insertAtLast(data);
                    case 3 :
                              myList.removeFirst();
                              break;
                    case 4 :
                              myList.removeLast();
                              break;
                    case 5:
                              exit(0);
                    default :
                              cout<<"\n Invalid Choice....";
                    }
                   // getch();
          }
          return 0;
}
