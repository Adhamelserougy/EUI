#include "Calculator.h"

u8 Result[arrsize];
u8 Result_Size;
extern volatile u8 Pressed_Buttons[17];
extern volatile u8 Button_Count;
volatile s32 Operands[arrsize];
volatile u8 Operands_Count;
volatile u8 Operators[arrsize];
volatile u8 Operators_Count;

void app(void)
{
    Operands_Count = 0;
    Operators_Count = 0;
    Result_Size = 0;
    Filter_Input();
    Calculator();
    Send_Command(Second_Line);
    toString();
    Clear_Data();
    Delay(4000);
    Send_Command(Clear);
    Button_Count = 0;
}

void Calculator(void)
{
    u8 flag = 0;
    u8 i;
    for (i = 0; i < Operators_Count; i++)
    {
//        if (flag)
//        {
//            i = 0;
//            flag = 0;
//        }
        if (Operators[i] == '*')
        {
            Operands[i + 1] *= Operands[i];
            Operands[i] = 0;
            Operators[i] = 0;
            Sort_Operands(i);
            Sort_Operators(i);
            Operands_Count--;
            Operators_Count--;
            i--;
        }
        else if (Operators[i] == '/')
        {
            Operands[i + 1] = Operands[i] / Operands[i + 1];
            Operands[i] = 0;
            Operators[i] = 0;
            Sort_Operands(i);
            Sort_Operators(i);
            Operands_Count--;
            Operators_Count--;
            i--;
        }
        else
            ;
    }
    for (i = 0; i < Operands_Count; i++)
    {
        if (flag)
        {
            i = 0;
            flag = 0;
        }
        if (Operators[i] == '+')
        {
            Operands[i + 1] += Operands[i];
            Operands[i] = 0;
            Operators[i] = 0;
            Sort_Operands(i);
            Sort_Operators(i);
            Operands_Count--;
            Operators_Count--;
            flag = 1;
        }
        else if (Operators[i] == '-')
        {
            Operands[i + 1] = Operands[i] - Operands[i + 1];
            Operands[i] = 0;
            Operators[i] = 0;
            Sort_Operands(i);
            Sort_Operators(i);
            Operands_Count--;
            Operators_Count--;
            flag = 1;
        }
        else
            ;
    }
}

void Sort_Operands(u8 index)
{
    u8 i;
    for (i = index; i < Operands_Count - 1; i++)
    {
        Float temp = Operands[i];
        Operands[i] = Operands[i + 1];
        Operands[i + 1] = temp;
    }
}

void Sort_Operators(u8 index)
{
    u8 i;
    for (i = index; i < Operators_Count - 1; i++)
    {
        u8 temp = Operators[i];
        Operators[i] = Operators[i + 1];
        Operators[i + 1] = temp;
    }
}

void Filter_Input(void)
{
    u8 Negative_Flag = 0;
    u8 i;
    for (i = 0; i < Button_Count; i++)
    {
        if (Pressed_Buttons[i] == '-' && i == 0)
        {
            Negative_Flag = 1;
        }
        else if (Pressed_Buttons[i] == '+' | Pressed_Buttons[i] == '-'
                | Pressed_Buttons[i] == '*' | Pressed_Buttons[i] == '/')
        {
            if (Negative_Flag)
            {
                Operands[Operands_Count] = (Float) Operands[Operands_Count]
                        * (-1);
                Negative_Flag = 0;
            }
            if (Pressed_Buttons[i] == '-'
                    && (Pressed_Buttons[i - 1] == '+'
                            | Pressed_Buttons[i - 1] == '-'
                            | Pressed_Buttons[i - 1] == '*'
                            | Pressed_Buttons[i - 1] == '/'))
            {
                Negative_Flag = 1;
            }
            else
            {
                Operators[Operators_Count] = Pressed_Buttons[i];
                Operators_Count++;
                Operands_Count++;
            }
        }
        else if (Pressed_Buttons[i] == '=')
        {
            if (Negative_Flag)
            {
                Operands[Operands_Count] = (Float) Operands[Operands_Count]
                        * (-1);
                Negative_Flag = 0;
            }
            Operands_Count++;
            return;
        }
        else
        {
            Operands[Operands_Count] = (Float) (Operands[Operands_Count] * 10
                    + (Pressed_Buttons[i] - '0'));
        }
    }
}

void Clear_Data(void)
{
    u8 i;
    for (i = 0; Operands[i] != 0 && i < arrsize; i++)
    {
        Operands[i] = 0;
    }
    for (i = 0; Operators[i] != 0 && i < arrsize; i++)
    {
        Operators[i] = 0;
    }
    for (i = 0; Pressed_Buttons[i] != 0 && i < 17; i++)
    {
        Pressed_Buttons[i] = 0;
    }
    for (i = 0; Result[i] != 0 && i < arrsize; i++)
    {
        Result[i] = 0;
    }
}

void toString(void)
{
    u8 flag = 0;
    s32 data = Operands[0];
    if (data == 0)
    {
        Send_Data('0');
        return;
    }
    u8 i;
    if (data < 0)
    {
        flag = 1;
    }
    for (i = 0; data; i++)
    {
        s8 mod;
        if (flag)
        {
            mod = (data % 10) * (-1);
        }
        else
        {
            mod = data % 10;
        }

        Result[i] = mod + '0';
        data = data / 10;
        Result_Size++;

    }
    if (flag)
    {
        Result[i] = '-';
        Result_Size++;
    }
    for (i = Result_Size; i > 0; i--)
    {
        Send_Data(Result[i - 1]);

    }
}
