/*****************************************************/
#ifndef DISP_H
#include "Display.h"
#include <windows.h>
#include <stdio.h>
#endif
#ifndef BUTTON_H
#include "Button.h"
#endif // BUTTON_H
#ifndef STUDENT_H
#include "Student.h"
#endif // STUDENT_H
extern int finish;
/*****************************************************/
MESSAGE_t Message_State = MESSAGE_ADD_A_STUDENT;
/*****************************************************/
void DISP_Message(const char* const MESSAGE){
    printf("%s\n", MESSAGE);
}
/*****************************************************/
void DISP_Clear(void){
    system("cls");
}
/*****************************************************/
void DISP_Goto(const POINT_t* const POINT){
    COORD Point;
    Point.X = POINT->x;
    Point.Y = POINT->y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point);
}
/*****************************************************/
void DISP_Color(const unsigned char BACKGROUND, const unsigned char FOREGROUND){
    char Color[] = "color 0F";
    switch(BACKGROUND){
        case 0:
                Color[6] = '0';
                break;
        case 1:
                Color[6] = '1';
                break;
        case 2:
                Color[6] = '2';
                break;
        case 3:
                Color[6] = '3';
                break;
        case 4:
                Color[6] = '4';
                break;
        case 5:
                Color[6] = '5';
                break;
        case 6:
                Color[6] = '6';
                break;
        case 7:
                Color[6] = '7';
                break;
        default:
                Color[6] = '0';
                break;
    }
    switch(FOREGROUND){
        case 8:
                Color[7] = '8';
                break;
        case 9:
                Color[7] = '9';
                break;
        case 10:
                Color[7] = 'A';
                break;
        case 11:
                Color[7] = 'B';
                break;
        case 12:
                Color[7] = 'C';
                break;
        case 13:
                Color[7] = 'D';
                break;
        case 14:
                Color[7] = 'E';
                break;
        case 15:
                Color[7] = 'F';
                break;
        default:
                Color[7] = 'F';
                break;
    }
    system(Color);
}
/*****************************************************/
void DISP_Text_Attribute(const unsigned short ATRRIBUTE){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ATRRIBUTE);
}
/*****************************************************/
void DISP_Init(void){
    POINT_t Point = {0, 0};
    DISP_Goto(&Point);
    Message_State = MESSAGE_ADD_A_STUDENT;
    DISP_Clear();
    DISP_Color(0, 15);
    DISP_Message("Add a Student");
    DISP_Message("Find a Student");
    DISP_Message("Delete a Student");
    DISP_Message("Exit");
    DISP_Stored_Message(Message_State);
}
/*****************************************************/
void DISP_Stored_Message(const MESSAGE_t STORED_MESSAGE){
    POINT_t Point = {0, 0};
    DISP_Color(0, 15);
    switch(STORED_MESSAGE){
        case MESSAGE_ADD_A_STUDENT:
             Point.x = 0;
             Point.y = 0;
             DISP_Goto(&Point);
             DISP_Text_Attribute(BACKGROUND_GREEN);
             DISP_Message("Add a Student");
             DISP_Goto(&Point);
             break;
        case MESSAGE_FIND_STUDENT:
             Point.x = 0;
             Point.y = 1;
             DISP_Goto(&Point);
             DISP_Text_Attribute(BACKGROUND_GREEN);
             DISP_Message("Find a Student");
             DISP_Goto(&Point);
             break;
        case MESSAGE_DELETE_A_STUDENT:
             Point.x = 0;
             Point.y = 2;
             DISP_Goto(&Point);
             DISP_Text_Attribute(BACKGROUND_GREEN);
             DISP_Message("Delete a Student");
             DISP_Goto(&Point);
             break;
        case MESSAGE_EXIT:
             Point.x = 0;
             Point.y = 3;
             DISP_Goto(&Point);
             DISP_Text_Attribute(BACKGROUND_GREEN);
             DISP_Message("Exit");
             DISP_Goto(&Point);
             break;
        default:
             Point.x = 0;
             Point.y = 0;
             DISP_Goto(&Point);
             DISP_Text_Attribute(BACKGROUND_GREEN);
             DISP_Message("Add a Student");
             DISP_Goto(&Point);
             break;
    }
}
/*****************************************************/
void DISP_Update(void){
    switch(Button){
       case BUTTON_STATE_UP:
            switch(Message_State){
                case MESSAGE_ADD_A_STUDENT:
                     DISP_Stored_Message(MESSAGE_EXIT);
                     Message_State = MESSAGE_EXIT;
                     break;
                case MESSAGE_DELETE_A_STUDENT:
                     DISP_Stored_Message(MESSAGE_FIND_STUDENT);
                     Message_State = MESSAGE_FIND_STUDENT;
                     break;
                case MESSAGE_EXIT:
                     DISP_Stored_Message(MESSAGE_DELETE_A_STUDENT);
                     Message_State = MESSAGE_DELETE_A_STUDENT;
                     break;
                case MESSAGE_FIND_STUDENT:
                     DISP_Stored_Message(MESSAGE_ADD_A_STUDENT);
                     Message_State = MESSAGE_ADD_A_STUDENT;
                     break;
                default:
                    /** Do Nothing **/
                    break;
            }
            Button = BUTTON_STATE_IDLE;
            break;
       case BUTTON_STATE_DOWN:
            switch(Message_State){
                case MESSAGE_ADD_A_STUDENT:
                     DISP_Stored_Message(MESSAGE_FIND_STUDENT);
                     Message_State = MESSAGE_FIND_STUDENT;
                     break;
                case MESSAGE_DELETE_A_STUDENT:
                     DISP_Stored_Message(MESSAGE_EXIT);
                     Message_State = MESSAGE_EXIT;
                     break;
                case MESSAGE_EXIT:
                     DISP_Stored_Message(MESSAGE_ADD_A_STUDENT);
                     Message_State = MESSAGE_ADD_A_STUDENT;
                     break;
                case MESSAGE_FIND_STUDENT:
                     DISP_Stored_Message(MESSAGE_DELETE_A_STUDENT);
                     Message_State = MESSAGE_DELETE_A_STUDENT;
                     break;
                default:
                    /** Do Nothing **/
                    break;
            }
            Button = BUTTON_STATE_IDLE;
            break;
       case BUTTON_STATE_ENTER:
            switch(Message_State){
                case MESSAGE_EXIT:
                     system("cls");
                     system("color 0F");
                     finish = 0;
                     break;
                case MESSAGE_ADD_A_STUDENT:
                     system("cls");
                     system("color 0E");
                     printf("Adding Student Mode\n");
                     printf("Press Enter To Add Student Or Backspace To Return...\n >> ");
                     Message_State = ADDING_STUDENT_MODE;
                     break;
                case MESSAGE_FIND_STUDENT:
                     system("cls");
                     system("color 0E");
                     printf("Finding Student Mode\n");
                     printf("Press Enter To Find Student Or Backspace To Return...\n >> ");
                     Message_State = FINDING_STUDENT_MODE;
                     break;
                case MESSAGE_DELETE_A_STUDENT:
                     system("cls");
                     system("color 0C");
                     printf("Deleting Student Mode\n");
                     printf("Press Enter To Delete Student Or Backspace To Return...\n >> ");
                     Message_State = DELETING_STUDENT_MODE;
                     break;
                case ADDING_STUDENT_MODE:
                     STUDENT_Add();
                     /** TODO: **/
                     break;
                case DELETING_STUDENT_MODE:
                     STUDENT_Delete();
                     /** TODO: **/
                     break;
                case FINDING_STUDENT_MODE:
                     STUDENT_Find();
                     break;
                default:
                    /** Do Nothing **/
                    break;
            }
            Button = BUTTON_STATE_IDLE;
            break;
       case BUTTON_STATE_BACKSPACE:
            DISP_Init();
            BUTTON_Init();
            Button = BUTTON_STATE_IDLE;
            break;
       default:
           /** Do Nothing **/
            break;
    }
}
/*****************************************************/
