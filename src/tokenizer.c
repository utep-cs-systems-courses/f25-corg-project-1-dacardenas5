#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){//if its a space char and not a \0
  return ((c == ' ' || c == '\t') && c != '\0'); 
}

int non_space_char(char c){//if its not a space char or \0
  return (c != ' ' && c != '\t' && c != '\0');
}

char *token_start(char *str){
  while (space_char(*str) && *str){//while its a space move forward
    str++;
  }
  return (*str ? str : NULL);//null if no more tokens/no tokemns
}

char *token_terminator(char *token){
  while (non_space_char(*token) && *token){//while its not a space and non zero
    token++;
  }
  return token;
}

int count_tokens(char *str){
  int count = 0;
  char *pointer = *str;
  while((pointer = token_start(pointer)){//makes pointer the start of word
      count++;
      pointer = token_terminator(pointer);//sets pointer the end of word
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *copy = (char *)malloc(len + 1); //allocate memory for the length + 1 for the zero term
  for(int i = 0; i < len; i++){
    copy[i] = inStr[i];
  }
  copy[len] = '\0';//add the zero terminator at the end of the copy
  return copy;
}
