#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "../headers/data.h"
#include "../headers/user.h"
#include "../headers/preferences.h"
#include "../headers/posts.h"
#include "../headers/interface.h"

int line_count(const char* filename){

  //The last line does not contain '\n'
  int lines = 1;
  char character;
  FILE* fp = fopen(filename, "r");
  
  //Error opening file
  if(fp == NULL) return 0;

  //Loop that goes through the entire file until the end copying characters to character
  while((character = fgetc(fp)) != EOF){

    //Add 1 to lines when encountering line breaks
    if(character == '\n'){
      lines++;
    }
  }
  fclose(fp);
  return lines;
}

void import_data(userArray* array, char* users_filename, char* posts_filename, Dictionary* dictionary){

  //We count the number of lines in the user file
  int num_users = line_count(users_filename);
  FILE* fp = fopen(users_filename, "r");

  //Parameters to read from the file:
  int id;
  char username[MAX_LENGTH];
  char name[MAX_LENGTH];
  char mail_adress[MAX_LENGTH];
  char description[MAX_DESCRIPTION];
  int age;
  int sex;
  int body_weight;
  int height;
  int city_id;
  int gym_id;
  int workout_days;
  int time_preference;
  int muscle_preference;

  //We create each user of the file
  for(int i = 0; i < num_users; i++){

    //We use %[-]%*c to determine whether to read description text up to the first hyphen
    fscanf(fp, "%d %s %s %s %[^-]%*c", &id, username, name, mail_adress, description);
    fscanf(fp, "%d %d %d %d %d %d %d %d %d", &age, &sex, &body_weight, &height, &city_id,
    &gym_id, &workout_days, &time_preference, &muscle_preference);

    create_user(username, mail_adress, array);
    User* user = search_user(username, array);
    strcpy(user->name, name);
    strcpy(user->description, description);
    user->age = age;
    user->sex = sex;
    user->body_weight = body_weight;
    user->height = height;
    user->city_id = city_id;
    user->gym_id = gym_id;
    user->workout_days = workout_days;
    user->time_preference = time_preference;
    user->muscle_preference = muscle_preference;
    
  }
  fclose(fp);

  //We count the number of lines in the posts file
  int num_posts = line_count(posts_filename);
  FILE * fp2 = fopen(posts_filename, "r");

  char username_post[100];
  char post[100];
  char caracter;
  int i = 0;
  int foundBracket = 0;
  int foundClaudator = 0;

  // Check if the file could be opened successfully
  if (fp2 == NULL) {
    printf("The file could not be opened.\n");
    return;
  }
  for(int j = 0; j<num_posts; j++){
    // Go through the file character by character until you reach the end
    while ((caracter = fgetc(fp2)) != EOF) {
      // If the character '[' is found, the reading of the username starts
      if (caracter == '[') {
        foundBracket = 1;
        i = 0;
        continue;
        }
  
      // If the character ']' is found, the reading of the username is finished
      if (foundBracket && caracter == ']') {
        foundBracket = 0;
        username_post[i] = '\0';
        i = 0;
        continue;
      }
  
      // If the character '[' is found for the second time, the reading of the post starts
      if (caracter == '{') {
        foundClaudator = 1;
        i = 0;
        continue;
      }
  
      if (foundClaudator && caracter == '}') {
        foundClaudator = 0;
        post[i] = '\0';
        i = 0;
        continue;
      }
  
      // If another character is found while reading the username or the post, it is saved in the respective variable
      if (foundBracket) {
        username_post[i] = caracter;
        i++;
      } 
      if (foundClaudator) {
        post[i] = caracter;
        i++;
      }

      if (caracter == '\n'){
        break;
      }
    }
    
    User* user2 = (User*) malloc(sizeof(User));
    user2 = search_user(username_post, array);
    push_post(user2->posts, post, dictionary);
  }
  // Close the file
  fclose(fp2);

}

void save_user(User* user, char* filename){
  
  int lines = line_count(filename);
  FILE* fp = fopen(filename, "a");

  //Opening error
  if(fp == NULL){
    printf("\nError opening file!\n");
    return;
  } 
  
  //We write the user data in the first available line
  //We use a hyphen to mark the end of the description text
  fprintf(fp, "\n%d %s %s %s %s- %d %d %d %d %d %d %d %d %d", lines, user->username, user->name,
    user->mail_adress, user->description, user->age, user->sex, user->body_weight, user->height, user->city_id,
    user->gym_id, user->workout_days, user->time_preference, user->muscle_preference);
  
   //We close the file
  fclose(fp);
}

void save_post(char* post, User* user, char* filename){

  int lines = line_count(filename);
  FILE* fp = fopen(filename, "a");

  //Opening error
  if(fp == NULL){
    printf("\nError opening file!\n");
    return;
  }
  //We obtain date and time of publication
  char actual_date[50];
  time_t actual_time;
  
  struct tm *date;
  date = localtime(&actual_time);
  
  actual_time = time(NULL);
  struct tm *times = localtime(&actual_time);
  
  strftime(actual_date, sizeof(actual_date), "%Y/%m/%d", date);
  
  //We write the user data in the first available line
  //We use a hyphen to mark the end of the description text
  fprintf(fp, "\n%d. [%s] %s %d:%d {%s}", lines, user->username, actual_date, times->tm_hour + 2, times->tm_min, post);
  //We close the file
  fclose(fp);
}