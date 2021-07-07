/*****************************************************/
#ifndef STUDENT_H
#define STUDENT_H
#define STUDENT_MAX_NUMBER 100
typedef struct{
    char Name[100];
    int Id;
}STUDENT_t;
extern STUDENT_t Student[STUDENT_MAX_NUMBER];
void STUDENT_Init(void);
void STUDENT_Add(void);
void STUDENT_Delete(void);
void STUDENT_Find(void);
#endif // STUDENT_H

/*****************************************************/
