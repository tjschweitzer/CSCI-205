#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "LinkedStack.h"
#include "Item.h"

void initialize(stack* s){

	s->top = NULL;
	s->size=0;
}


void push(stack* s,char* str){

  item *new_item = (item *) malloc(sizeof(item));
  strcpy(new_item->data,str);
  new_item->nextNodePtr=s->top;
  s->size++;
  s->top=new_item;
}


void pop(stack* s, char* str){
	if(s->size ==0){
		return;
	}
	item *memo = (item *) malloc(sizeof(item));
	*memo=*s->top;
	strcpy(str,memo->data); 
	s->top=memo->nextNodePtr;
	s->size--;
	free(memo);
}


void peek(stack* s, char* str){
	if(s->size ==0){
	  return;
	}
	strcpy(str,s->top->data);

}


bool is_empty(stack* s){
	return (s->top!=NULL);
}


int get_length(stack* s){
	return s->size;
}

void display(stack* s){
	if (s->size==0){
		return;
	}
	item *memo = (item *) malloc(sizeof(item));
	do{
		memo=s->top;
		printf("%s\n",memo->data);
		s->top=memo->nextNodePtr;
	}while (s->top!=NULL);
}


