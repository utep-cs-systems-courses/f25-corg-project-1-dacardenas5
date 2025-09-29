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
  char *pointer = str;
  while((pointer = token_start(pointer))){//makes pointer the start of word
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

char **tokenize(char *s){//returns array of strings (tokens)
 int amountTokens = count_tokens(s);//gets the amount of tokens
 char **arr = (char **)malloc((amountTokens+1) * sizeof(char *));//each is a string & has end 
 int i = 0;
 char *p = s;//copy to not mess up s

 while((p = token_start(p))){//start of each token
     char *tokenEnd = token_terminator(p);//end of curr token
     arr[i] = copy_str(p,(tokenEnd-p));//sets the array to the token string
     i++;
     p = tokenEnd;//sets up for the next start
 }
 arr[i] = NULL;//the end is null so we know its done tokenizing
 return arr;
}

void print_tokens(char **tokens){
  for(int i = 0;tokens[i];i++){//till its null
    printf("%s \n",tokens[i]);
  }
}

void free_tokens(char **tokens){
  for(int i = 0; tokens[i]; i++){
    free(tokens[i]);
  }
  free(tokens);
}
