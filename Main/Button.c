/*****************************************************/
#ifndef BUTTON_H
#include "Button.h"
#include <conio.h>
#define BUTTON_PRESSED_UP 72
#define BUTTON_PRESSED_DOWN 80
#define BUTTON_PRESSED_ENTER 13
#define BUTTON_PRESSED_BACKSPACE 8
#endif
/*****************************************************/
static void BUTTON_Read(void);
/*****************************************************/
BUTTON_t Button = BUTTON_STATE_IDLE;
/*****************************************************/
void BUTTON_Init(void){
    Button = BUTTON_STATE_IDLE;
}
/*****************************************************/
void BUTTON_Update(void){
    BUTTON_Read();
}
/*****************************************************/
static void BUTTON_Read(void){
    char Buff;
    Buff = getch();
    switch(Buff){
        case BUTTON_PRESSED_UP:
             Button = BUTTON_STATE_UP;
             break;
        case BUTTON_PRESSED_DOWN:
             Button = BUTTON_STATE_DOWN;
             break;
        case BUTTON_PRESSED_ENTER:
             Button = BUTTON_STATE_ENTER;
             break;
        case BUTTON_PRESSED_BACKSPACE:
             Button = BUTTON_STATE_BACKSPACE;
             break;
        default:
             Button = BUTTON_STATE_IDLE;
             break;
    }
}
/*****************************************************/
