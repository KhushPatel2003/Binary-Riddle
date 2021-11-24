// Sample code for ECE 198
//KHUSH AND OMAR

#include <stdbool.h> // booleans, i.e. true and false
#include <stdio.h>   // sprintf() function
#include <stdlib.h>  // srand() and random() functions

#include "ece198.h"
#include <TIME.H>
#include <time.h>

#include "LiquidCrystal.h"
void Timer() {
    int start_time_secs = 604;
    int start_time_mins = 10;
    int current_mins = 0;
    int current_millisecs = 0;
    int current_secs = 0;
    int conditional_time = 0;
    while (true) {
        current_secs = HAL_GetTick()/1000;
        current_secs = start_time_secs - current_secs;
        if (current_secs >= 600) {
            setCursor(11,0);
            print("10");

            conditional_time = current_secs - 600;
            char new_time[1];
            sprintf(new_time, "%d", conditional_time);
            setCursor(14,0);
            print(new_time);
        }
        if ((600 > current_secs) && (current_secs >= 540)) {
            setCursor(11,0);
            print("09");

            conditional_time = current_secs - 540;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        if ((540 > current_secs) && (current_secs >= 480)) {
            setCursor(11,0);
            print("08");

            conditional_time = current_secs - 480;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        if ((480 > current_secs) && (current_secs >= 420)) {
            setCursor(11,0);
            print("07");

            conditional_time = current_secs - 420;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        if ((420 > current_secs) && (current_secs >= 360)) {
            setCursor(11,0);
            print("06");

            conditional_time = current_secs - 360;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        if ((360 > current_secs) && (current_secs >= 300)) {
            setCursor(11,0);
            print("05");

            conditional_time = current_secs - 300;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        if ((300 > current_secs) && (current_secs >= 240)) {
            setCursor(11,0);
            print("04");

            conditional_time = current_secs - 240;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        if ((240 > current_secs) && (current_secs >= 180)) {
            setCursor(11,0);
            print("03");

            conditional_time = current_secs - 180;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        if ((180 > current_secs) && (current_secs >= 120)) {
            setCursor(11,0);
            print("02");

            conditional_time = current_secs - 120;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        if ((120 > current_secs) && (current_secs >= 60)) {
            setCursor(11,0);
            print("01");

            conditional_time = current_secs - 60;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        if ((60 > current_secs) && (current_secs >= 0)) {
            setCursor(11,0);
            print("00");

            conditional_time = current_secs - 0;
            if (conditional_time < 10) {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print("0");
                setCursor(15,0);
                print(new_time);
            }
            else {
                char new_time[1];
                sprintf(new_time, "%d", conditional_time);
                setCursor(14,0);
                print(new_time);
            }
        }
        setCursor(13,0);
        print(":");
    }
}

void GameEnd(int score) {

    clear();

    char new_score[3];
    sprintf(new_score, "%d", score);
    setCursor(0,0);
    print("Score:");
    setCursor(6,0);
    print(new_score);

    if (score == 100) {
        setCursor(0, 1);
        print("You Won!");
    }
    else if (score >= 50) {
        setCursor(0, 1);
        print("Nice Try");
    }
    else if (score < 50) {
        setCursor(0, 1);
        print("You Suck!");
    }    
}

void LCD_print(char answer[], int score, int qnum) {
    setCursor(12,1);
    print(" ");

    char new_score[3];
    sprintf(new_score, "%d", score);

    char new_qnum[2];
    sprintf(new_qnum, "%d", qnum);

    setCursor(0,0);
    print("Score:");

    setCursor(6,0);
    print(new_score);

    setCursor(0,1);
    print("Q");

    if (qnum != 10){
        setCursor(1,1);
        print(new_qnum);

        setCursor(2,1);
        print(":");

        setCursor(3,1);
        print(answer);
    } else {
        setCursor(1,1);
        print(new_qnum);

        setCursor(3,1);
        print(":");

        setCursor(4,1);
        print(answer);
    }
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

    char answer[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int q_num = 0;
    int score = 0;

    LCD_print(answer, score, (q_num+1));

    while (true)
    {
        Timer();
        // enter functionality
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6))
        {
            bool correct = check_answer(answer, q_num);
            led(correct);
            
            
            q_num++;
            if (q_num == 10){
                GameEnd(score);
                break;
            }
 
            index = 0;
            for (int k=0; k<8; ++k) {
                answer[k] = ' ';
            }

            if (correct){score+=10;}

            clear();
            LCD_print(answer, score, (q_num+1));

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
            LCD_print(answer, score, (q_num+1));

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
            LCD_print(answer, score, (q_num+1));

            // char buff[1000];
            // sprintf(buff, answer);
            // sprintf(buff, "\n");
            // SerialPuts(buff);

            HAL_Delay(250);
        }

        // delete value
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8))
        { 
            if (index != 0){
                index--;
                answer[index]= ' ';
            } 
            /*
            else if (index != 0)
            {
                index--;
                answer[index] = ' ';
            }
            */
            LCD_print(answer, score, (q_num+1));

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
//comment added