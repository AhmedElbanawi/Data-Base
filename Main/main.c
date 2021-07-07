/*****************************************************/
#include <stdio.h>
#ifndef BUTTON_H
#include "Button.h"
#endif // BUTTON_H
#ifndef DISP_H
#include "Display.h"
#include "Student.h"
#include <windows.h>
#endif
#ifndef STUDENT_H
#include "Student.h"
#endif // STUDENT_H
/*****************************************************/
char Run = 1;
/*****************************************************/
int main()
{
    DISP_Init();
    BUTTON_Init();
    STUDENT_Init();
    while(Run){
        BUTTON_Update();
        DISP_Update();
    }
    return 0;
}
/*****************************************************/

