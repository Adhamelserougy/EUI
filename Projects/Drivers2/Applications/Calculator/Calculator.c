#include <Applications/Calculator/Calculator.h>

static const volatile u8 Keypad_Matrix[4][4] =
        { { '1', '2', '3', '+' }, { '4', '5', '6', '-' },
          { '7', '8', '9', '*' }, { 0, '0', '=', '/' } };
static volatile u8 Result[arrsize];
static volatile u8 Result_Size;
static volatile u8 flag;
static volatile u8 Pressed_Buttons[arrsize];
static volatile u8 Button_Count;
static volatile s32 Operands[arrsize];
static volatile u8 Operands_Count;
static volatile u8 Operators[arrsize];
static volatile u8 Operators_Count;

void Calculator_App(void)
{
    Init_GPIO();
    LCD_Init();
    flag = 0;
    while (1)
    {
        Get_Buttons();
        Operands_Count = 0;
        Operators_Count = 0;
        Result_Size = 0;
        Filter_Input();
        Calculator();
        LCD_Send_Command(LCD_Second_Line);
        toString();
        Clear_Data();
        Delay_ms(4000);
        LCD_Send_Command(LCD_Clear);
        Button_Count = 0;
    }
}

static void Get_Buttons(void)
{
    Keypad_Init();
    Button_Count = 0;
    while (1)
    {
        if (flag)
        {
            if (Pressed_Buttons[Button_Count - 1] == '=')
            {
                LCD_Send_Data('=');
                flag = 0;
                return;
            }
            else if (Pressed_Buttons[Button_Count - 1] == 0)
            {
                LCD_Send_Command(LCD_Clear);
                Button_Count = 0;
                flag = 0;
            }
            else
            {
                LCD_Send_Data(Pressed_Buttons[Button_Count - 1]);
                flag = 0;
            }
        }
    }
}

static void Init_GPIO(void)
{
    GPIO_Clock_Init(PortA);
    GPIO_Clock_Init(PortB);
    GPIO_Clock_Init(PortC);
    GPIO_Clock_Init(PortD);
    GPIO_Clock_Init(PortE);
    GPIO_Clock_Init(PortF);
    GPIO_InitTypeDef GPIO_Init_Struct = { D0 | D1 | D2, Output, NOPULL };
    GPIO_Init(GPIOA, &GPIO_Init_Struct);
    GPIO_Init_Struct.Pin = D3 | D6 | D7;
    GPIO_Init(GPIOB, &GPIO_Init_Struct);
    GPIO_Init_Struct.Pin = D4 | D5 | RS;
    GPIO_Init(GPIOE, &GPIO_Init_Struct);
    GPIO_Init_Struct.Pin = E;
    GPIO_Init(GPIOF, &GPIO_Init_Struct);
    GPIO_Init_Struct.Pin = H1 | H2 | H3 | H4;
    GPIO_Init(GPIOD, &GPIO_Init_Struct);
    GPIO_Init_Struct.Pin = V1 | V2 | V3 | V4;
    GPIO_Init_Struct.Mode = Input;
    GPIO_Init_Struct.Pull = PULL_UP;
    GPIO_Init(GPIOC, &GPIO_Init_Struct);
    GPIO_Init_InterruptTypeDef Int_Init = { V1 | V2 | V3 | V4, Edge,
                                            Falling_Edge_GPIO };
    GPIO_Interrupt_Init(GPIOC, &Int_Init);
    GPIO_Int_Register(PortC, Calculator_Handler_Callback);
    NVIC_Enable(GPIOC_Int);
}

static void Calculator(void)
{
    u8 flag = 0;
    u8 i;
    for (i = 0; i < Operators_Count; i++)
    {
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

static void Sort_Operands(u8 index)
{
    u8 i;
    for (i = index; i < Operands_Count - 1; i++)
    {
        float temp = Operands[i];
        Operands[i] = Operands[i + 1];
        Operands[i + 1] = temp;
    }
}

static void Sort_Operators(u8 index)
{
    u8 i;
    for (i = index; i < Operators_Count - 1; i++)
    {
        u8 temp = Operators[i];
        Operators[i] = Operators[i + 1];
        Operators[i + 1] = temp;
    }
}

static void Filter_Input(void)
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
                Operands[Operands_Count] = (float) (Operands[Operands_Count]
                        * (-1));
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
                Operands[Operands_Count] = (float) Operands[Operands_Count]
                        * (-1);
                Negative_Flag = 0;
            }
            Operands_Count++;
            return;
        }
        else
        {
            Operands[Operands_Count] = (float) (Operands[Operands_Count] * 10
                    + (Pressed_Buttons[i] - '0'));
        }
    }
}

static void Clear_Data(void)
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

static void toString(void)
{
    u8 flag = 0;
    s32 data = Operands[0];
    if (data == 0)
    {
        LCD_Send_Data('0');
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
        LCD_Send_Data(Result[i - 1]);

    }
}

static void Calculator_Handler_Callback(u8 Pin)
{
    u8 Interrupt_Source = Pin>>4;
    u8 column = 0;
    while (Interrupt_Source != 0)
    {
        column++;
        Interrupt_Source >>= 1;
    }
    Interrupt_Source = GPIO_Read(GPIOC, V1 | V2 | V3 | V4) >> 4;

    u8 row;
    u8 data;

    GPIO_Write(GPIOB, H1, H1);
    row = 0;

    GPIO_Write(GPIOB, H1, 0);
    GPIO_Write(GPIOC, H2, H2);
    data = GPIO_Read(GPIOC, V1 | V2 | V3 | V4) >> 4;
    row = Interrupt_Source == data ? 1 : 0;

    GPIO_Write(GPIOC, H2, 0);
    GPIO_Write(GPIOC, H3, H3);
    data = GPIO_Read(GPIOC, V1 | V2 | V3 | V4) >> 4;
    row = Interrupt_Source == data ? 2 : 0;

    GPIO_Write(GPIOC, H3, 0);
    GPIO_Write(GPIOC, H4, H4);
    data = GPIO_Read(GPIOC, V1 | V2 | V3 | V4) >> 4;
    row = Interrupt_Source == data ? 3 : 0;

    GPIO_Write(GPIOC, H4, 0);

    Pressed_Buttons[Button_Count++] = Keypad_Matrix[row][column - 1];
    flag = 1;
    Delay_ms(100);
}
