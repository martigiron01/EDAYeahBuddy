#include "../headers/interface.h"
#include "../headers/main.h"
#include "../headers/user.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


  char  letterY[5][7] = {
        "*     *",
        " *   * ",
        "  * *  ",
        "   *   ",
        "   *   "
    };

    char letterE[5][7] = {
        "*******",
        "*      ",
        "****** ",
        "*      ",
        "*******"
    };

    char letterA[5][7] = {
        "*******",
        "*     *",
        "*******",
        "*     *",
        "*     *"
    };

    char letterH[5][7] = {
        "*     *",
        "*     *",
        "*******",
        "*     *",
        "*     *"
    };

 char letterB[5][7] = {
        "****** ",
        "*     *",
        "****** ",
        "*     *",
        "****** "
    };

    char letterU[5][7] = {
        "*     *",
        "*     *",
        "*     *",
        "*     *",
        "****** "
    };

    char letterD[5][7] = {
        "****** ",
        "*     *",
        "*     *",
        "*     *",
        "****** "
    };
    char letterDD[5][7] = {
        "****** ",
        "*     *",
        "*     *",
        "*     *",
        "****** "
    };
   char letterYY[5][7] = {
        "*     *",
        " *   * ",
        "  * *  ",
        "   *   ",
        "   *   "
    };


void print_letter(char letter[5][7]){
  int i,j;
  for(i=0;i<5;i++){
    for(j=0;j<7;j++){
       printf("%c\n",letter[i][j]);
    }
  }
}