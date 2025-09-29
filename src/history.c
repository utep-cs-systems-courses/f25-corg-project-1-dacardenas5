#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.c"

List *init_history(){
  List *list = (List *)malloc(sizeof(List));//memory allocation of new list
  list->root= NULL;//the start has nothing
  return list;//return the start of the list
}

void add_history(List *list,char *str){
  Item *item = (Item *)malloc(sizeof(Item));//memory allocation of new item

  if(list->root == NULL){
    item->id = 1;
  } else {
    Item *curr = list->root;
    while(curr->next != NULL){
      curr = curr->next;
    }
    item->id = curr->id +1;
  }

  int strLength = 0;
  while(str[strLength]!= '\0'){//gets the length of the string
    strLength++;
  }
  item->str = copy_str(str,strLength);  //copies the string
  item->next = NULL;
  
  if(list->root == NULL){
    list->root = item;
  } else {
    Item *curr = list->root;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = item;
  }
}

char *get_history(List *list,int id){
  Item *curr = list->root;
  while(curr){
    if(curr->id == id){//loops until it matches the id
      return curr->str;
    }
    curr = curr->next;
  }
  return NULL;
}

void print_history(List *list){//prints the id and then the string
  Item *curr = list-> root;
  while(curr){
    printf("%d: %s\n",curr->id,curr->str);
    curr = curr->next;
  }
}

void free_history(List *list){//temp keeps track of the curr
  Item *curr = list->root;
  while(curr){
    Item *temp = curr;
    curr = curr->next;
    free(temp->str);
    free(temp);
  }
  free(list);
}
  
