#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main(){

  List *list = init_history();
  char userInput[256];
  
  puts("Started Program.");
  
  while(1){
    printf("$> ");
    fflush(stdout);

    if((fgets(userInput,sizeof(userInput),stdin)) == NULL){
      break;
    }

    remove_newline(userInput);
    if(str_equal(userInput,"exit")){
      break;
    }
    if(str_equal(userInput,"history")){
      print_history(list);
      continue;
    }

    if(userInput[0] == '!'){
      int id = atoi(&userInput[1]);
      char *cmd = get_history(list,id);
      if(cmd){
	printf("Token: %s\n",cmd);
	char **tokens = tokenize(cmd);
	print_tokens(tokens);
	free_tokens(tokens);
      } else {
	printf("ID inputted has no history");
      }
      continue;
    }
    add_history(list,userInput);

    char **tokens = tokenize(userInput);
    print_tokens(tokens);
    free_tokens(tokens);
  }

  free_history(list);

  return 0;
}

int str_equal(const char *a, const char*b){
  int i = 0;
  while(a[i] && b[i]){
    if(a[i]!=b[i]){
      return 0;
    }
    i++;
  }
  return (a[i]=='\0' && b[i] == '0');//final is the same
}

void remove_newline(char *s){
  for(int i = 0; s[i] != '\0'; i++){
    if(s[i] == '\n'){
      s[i] = '\0';
      break;
    }
  }
}


