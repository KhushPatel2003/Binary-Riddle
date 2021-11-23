// Sample code for ECE 198
//KHUSH AND OMAR

#include <stdbool.h> // booleans, i.e. true and false
#include <stdio.h>   // sprintf() function
#include <stdlib.h>  // srand() and random() functions

#include "ece198.h"
#include <TIME.H>

#include "LiquidCrystal.h"

void LCD_print(char answer[]) {
    setCursor(0,0);
    print(answer);
}

//LED FUNCTION THAT TAKES IN BOOL VLAUE TO TURN OF LED
void led(bool correct)
{
    //Initialized pins
    InitializePin(GPIOA, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);

    if (correct)
    { // green led turns on
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        HAL_Delay(500);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    }
    else
    { // red led turns on
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
        HAL_Delay(500);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
    }
}

bool check_answer(char answer[], int q_num)
{
    char master_answers[10][8] = {
        {'0', '0', '1', '1', '0', '0', '0', '1'}, //Q1
        {'0', '0', '0', '0', '1', '1', '0', '0'}, //Q2
        {'0', '0', '0', '0', '0', '1', '1', '1'}, //Q3
        {'0', '0', '1', '1', '0', '1', '1', '1'}, //Q4
        {'0', '0', '0', '0', '0', '0', '1', '0'}, //Q5
        {'0', '0', '0', '0', '0', '0', '0', '0'}, //Q6
        {'0', '0', '0', '0', '0', '0', '0', '1'}, //Q7
        {'0', '1', '0', '0', '0', '1', '1', '0'}, //Q8
        {'0', '0', '0', '0', '0', '1', '0', '0'}, //Q9
        {'0', '0', '0', '0', '1', '0', '0', '0'}  //Q10
    };

    for (int k = 0; k < 8; ++k)
    {
        if (master_answers[q_num][k] != answer[k])
        {
            return false;
        }
    }

    return true;
}

void input()
{
    //led(correct);
    InitializePin(GPIOA, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);
    InitializePin(GPIOC, GPIO_PIN_7, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);

    char answer[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};
    int index = 0;
    int q_num = 0;
    int timeStart = clock();

    while (true)
    {

        if ((clock() - timeStart) / CLOCKS_PER_SEC >= 5)
        { // time in seconds
            break;
        }

        // enter functionality
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6))
        {
            bool correct = check_answer(answer, q_num);
            q_num++;
            if (q_num == 11)
            {
                break;
            }
            led(correct);
            index = 0;

            clear();
            for (int k=0; k<8; ++k) {
                answer[k] = ' ';
            }

            HAL_Delay(250);
        }

        // enter value '1'
        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7))
        {
            answer[index] = '1';
            if (index != 8)
            {
                index++;
            }
            LCD_print(answer);

            // char buff[1000];
            // sprintf(buff, "press 1\n");
            // sprintf(buff, "\n");
            // SerialPuts(buff);

            HAL_Delay(250);
        }

        // enter value '0'
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9))
        {
            answer[index] = '0';
            if (index != 8)
            {
                index++;
            }
            LCD_print(answer);

            // char buff[1000];
            // sprintf(buff, answer);
            // sprintf(buff, "\n");
            // SerialPuts(buff);

            HAL_Delay(250);
        }

        // delete value
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8))
        {
            if (index != 0)
            {
                index--;
                answer[index] = ' ';
            }
            LCD_print(answer);

            // char buff[1000];
            // sprintf(buff, answer);
            // sprintf(buff, "\n");
            // SerialPuts(buff);

            HAL_Delay(250);
        }
    }
}

void beginGame(){
    setCursor(0, 0);
    print("Welcome to"); 
    setCursor(0, 1);
    print("Binary Riddle!");// display a count in the second row of the display  
    HAL_Delay(4000);
    clear();
}

/*
void Timer()
{
    while (true)
    {
        char buff[1000];
        sprintf(buff, "0 Pressed");
        sprintf(buff, '\n');
        SerialPuts(buff);
    }
}
*/

int main(void)
{
    HAL_Init(); // initialize the Hardware Abstraction Layer

    // Peripherals (including GPIOs) are disabled by default to save power, so we
    // use the Reset and Clock Control registers to enable the GPIO peripherals we're using.

    __HAL_RCC_GPIOA_CLK_ENABLE(); // enable port A (for the on-board LED, for example)
    __HAL_RCC_GPIOB_CLK_ENABLE(); // enable port B (for the rotary encoder inputs, for example)
    __HAL_RCC_GPIOC_CLK_ENABLE(); // enable port C (for the on-board blue pushbutton, for example)

    // initialize the pins to be input, output, alternate function, etc

    //                  InitializePin(GPIOA, GPIO_PIN_5, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0); // initialize the pin that the on-board LED is on
    // note: the on-board pushbutton is fine with default values (input, and no pull-up resistor required since there's one on the board)

    // set up for serial communication to the host computer
    // (anything we write to the serial port will appear in the console in VSCode)

    SerialSetup(9600);
    // char buff[1000];
    // sprintf(buff, "0 Pressed \n");
    // SerialPuts(buff);

    // as mentioned above, only one of the following code sections will be used
    // (depending on which of the #define statements at the top of this file has been uncommented)
    //led(false);

    InitializePin(GPIOB, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);
    LiquidCrystal(GPIOB, GPIO_PIN_8 /*G*/, GPIO_PIN_9 /*G*/, GPIO_PIN_10 /*G*/, GPIO_PIN_3 /*G*/,GPIO_PIN_4 /*G*/, GPIO_PIN_5 /*G*/, GPIO_PIN_6);
    beginGame();
    input();
}

void SysTick_Handler(void)
{
    HAL_IncTick(); // tell HAL that a new tick has happened
    // we can do other things in here too if we need to, but be careful
}