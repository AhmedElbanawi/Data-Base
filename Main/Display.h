/*****************************************************/
#ifndef DISP_H
#define DISP_H
typedef struct{
    unsigned int x, y;
}POINT_t;
typedef enum{
    MESSAGE_ADD_A_STUDENT = 0,
    MESSAGE_DELETE_A_STUDENT,
    MESSAGE_EXIT,
    MESSAGE_FIND_STUDENT,
    ADDING_STUDENT_MODE,
    DELETING_STUDENT_MODE,
    FINDING_STUDENT_MODE

}MESSAGE_t;
extern MESSAGE_t Message_State;
/*****************************************************/
void DISP_Init(void);
void DISP_Update(void);
void DISP_Clear(void);
void DISP_Message(const char* const MESSAGE);
void DISP_Goto(const POINT_t* const POINT);
void DISP_Color(const unsigned char BACKGROUND, const unsigned char FOREGROUND);
void DISP_Text_Attribute(const unsigned short ATRRIBUTE);
void DISP_Stored_Message(const MESSAGE_t STORED_MESSAGE);
#endif // DISP_H
/*****************************************************/
