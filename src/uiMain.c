#include <stdio.h>
#include <string.h>

int main(){

  puts("Started Program.");
  
  while(1){
    char userInput[100];
    printf("$> ");
    fflush(stdout);

    if((fgets(userInput,sizeof(userInput),stdin)) == NULL){
      break;
    }

    userInput[strcspn(userInput, "\n")] = '\0';

    if(strcmp(userInput,"quit") == 0){
      break;
    }

    printf("%s\n", userInput);
  }

  return 0;
}
