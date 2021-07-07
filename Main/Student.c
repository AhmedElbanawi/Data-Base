/*****************************************************/
#ifndef STUDENT_H
#include "Student.h"
#include <stdio.h>
#endif // STUDENT_H
/*****************************************************/
STUDENT_t Student[STUDENT_MAX_NUMBER];
int STUDENT_Max_Number = STUDENT_MAX_NUMBER;
static char Flag = 1;
static int Is_Char(const int SYMBOLE);
/*****************************************************/
void STUDENT_Init(void){
    unsigned int i;
    for(i = 0; i < STUDENT_MAX_NUMBER; i++){
        Student[i].Id = -1;
    }
    STUDENT_Max_Number = STUDENT_MAX_NUMBER;
}
/*****************************************************/
void STUDENT_Delete(void){
    unsigned int Id;
    printf("Press Enter To Delete Student Or Backspace To Return...\n >> ");
    printf(" Enter Student ID: ");
    if(1 == Flag){
       scanf("%u", &Id);
       Flag = 0;
    }else{
        scanf("%*c%u", &Id);
    }
    if(Id < STUDENT_MAX_NUMBER && !Is_Char(Id)){
        printf(" Deleting Student .... Done\n");
        Student[Id].Id = -1;
    }else{
        printf(" Error Student ID Does not Exist\n");
    }
    printf("Press Enter To Delete Student Or Backspace To Return...\n >> ");
}
/*****************************************************/
void STUDENT_Add(void){
    unsigned int Id;
    printf("Press Enter To Add Student Or Backspace To Return...\n >> ");
    printf(" Enter Student ID: ");
    if(1 == Flag){
       scanf("%u", &Id);
       Flag = 0;
    }else{
        scanf("%*c%u", &Id);
    }
    if(Id < STUDENT_MAX_NUMBER && -1 == Student[Id].Id && !Is_Char(Id)){
        Student[Id].Id = Id;
        printf(" >>  Enter Student Name: ");
        scanf("%s", Student[Id].Name);
    }else{
        printf(" Error Student Id Is Not Valid...\n");
    }
    printf("Press Enter To Add Student Or Backspace To Return...\n >> ");
}
/*****************************************************/
void STUDENT_Find(void){
    unsigned int Id;
    printf("Press Enter To Find Student Or Backspace To Return...\n >> ");
    printf(" Enter Student ID: ");
    if(1 == Flag){
       scanf("%u", &Id);
       Flag = 0;
    }else{
        scanf("%*c%u", &Id);
    }
    if(Id < STUDENT_MAX_NUMBER && -1 != Student[Id].Id && !Is_Char(Id)){
        printf(" >>  %s\n", Student[Id].Name);
    }else{
        printf(" Error Student Id Is Not Valid...\n");
    }
    printf("Press Enter To Find Student Or Backspace To Return...\n >> ");
}
/*****************************************************/
static int Is_Char(const int SYMBOLE){
    if(SYMBOLE >= 'A' && SYMBOLE <= 'z'){
        return 1;
    }
    return 0;
}
/*****************************************************/
