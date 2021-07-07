/*****************************************************/
#ifndef BUTTON_H
#define BUTTON_H
typedef enum{
    BUTTON_STATE_UP = 0,
    BUTTON_STATE_DOWN,
    BUTTON_STATE_IDLE,
    BUTTON_STATE_ENTER,
    BUTTON_STATE_BACKSPACE
}BUTTON_t;
extern BUTTON_t Button;
void BUTTON_Init(void);
void BUTTON_Update(void);
#endif /** BUTTON_H **/
/*****************************************************/
