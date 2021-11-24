//KHUSH AND OMER

#include <stdbool.h> // booleans, i.e. true and false
#include <stdio.h>   // sprintf() function
#include <stdlib.h>  // srand() and random() functions

#include "ece198.h"
#include <TIME.H>
#include <time.h>

#include "LiquidCrystal.h"

//When the Game is ended, this function will call!
void GameEnd(int score) {
    //clear the screen
    clear();

    //initalize character array to store int score
    char new_score[3];
    sprintf(new_score, "%d", score);
    
    //display score to screen
    setCursor(0,0);
    print("Score:");
    setCursor(6,0);
    print(new_score);

    //Messages sent from code to user depending on thier score
    if (score == 100) { //highest
        setCursor(0, 1);
        print("You Won!");
    }
    else if (score >= 50) { //medium
        setCursor(0, 1);
        print("Nice Try");
    }
    else if (score < 50) { //poor 
        setCursor(0, 1);
        print("You Suck!");
    }    
}

//This will print to the LCD the current score, time and question number
void LCD_print(char answer[], int score, int qnum) {
    setCursor(12,1);
    print(" ");

    //convert int score to char array
    char new_score[3];
    sprintf(new_score, "%d", score);

    //convert q# to char array
    char new_qnum[2];
    sprintf(new_qnum, "%d", qnum);

    //print score
    setCursor(0,0);
    print("Score:");

    setCursor(6,0);
    print(new_score);

    //print question number 
    setCursor(0,1);
    print("Q");

    if (qnum != 10){
        setCursor(1,1);
        print(new_qnum);

        setCursor(2,1);
        print(":");

        //print answer
        setCursor(3,1);
        print(answer);
    } else {
        setCursor(1,1);
        print(new_qnum);

        setCursor(3,1);
        print(":");

        //print answer
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

//Recieves charcter array and question number, then determines if the answer is right based on 2D array which holds all master answers.
bool check_answer(char answer[], int q_num)
{   
    //answer array containing all answers
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

    //compare answer to solution
    for (int k = 0; k < 8; ++k)
    {   
        //see if any digits do not match each other
        if (master_answers[q_num][k] != answer[k])
        {
            //return false if answer and solution are not the same
            return false;
        }
    }

    //return true if the answer and solution is the smae
    return true;
}

void game_loop()
{
    //initalize pins used in main loop
    InitializePin(GPIOA, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);
    InitializePin(GPIOC, GPIO_PIN_7, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);

    //answer array that user will be inputting their characters into 
    char answer[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    //current index that the user is on 
    int index = 0;
    //what number the question is on 
    int q_num = 0;
    int score = 0;

    //timer-related variables
    int start_time_secs = 604;
    int start_time_mins = 10;
    int current_mins = 0;
    int current_millisecs = 0;
    int current_secs = 0;
    int conditional_time = 0;

    //display initial state of game ie. answer = '', score = 0 
    LCD_print(answer, score, (q_num+1));

    while (true)
    {
        // if enter is pressed button 
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6))
        {
            //check if answer is corrrect
            bool correct = check_answer(answer, q_num);
            //output corresponding color based on answer
            led(correct);

            //increment score if won
            if (correct){
                score+=10;
            }
            
            //move to next answer
            q_num++;
            //if its reached the end of the list
            if (q_num == 10){
                //end of the game, display final score and break from loop
                GameEnd(score);
                break;
            }
 
            //reset answer array for new user inputs 
            index = 0;
            for (int k=0; k<8; ++k) {
                answer[k] = ' ';
            }

            //clear lcd display and print out updated info to screen
            clear();
            LCD_print(answer, score, (q_num+1));

            //delay to factor in button press length
            HAL_Delay(250);
        }

        // entered value '1' button
        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7))
        {
            //set the current spot in answer array to 1
            answer[index] = '1';

            //makes sure that array does not go out of bounds
            if (index != 8)
            {   //move to next spot in array
                index++;
            }
            //print updated result
            LCD_print(answer, score, (q_num+1));

            //delay to facotr in button press length
            HAL_Delay(250);
        }

        // enter value '0' button
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9))
        {
            //sets current answer index to zero
            answer[index] = '0';
            //moves to next spot in answer array
            if (index != 8)
            {
                //move up an index
                index++;
            }
            //print out updated results 
            LCD_print(answer, score, (q_num+1));

            //delay to factor in length of button press
            HAL_Delay(250);
        }

        // delete value button 
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8))
        { 
            //if not on last index to avoid index error
            if (index != 0){
                //move back an index
                index--;
                //sets value to empty
                answer[index]= ' ';
            } 
            //print updated value
            LCD_print(answer, score, (q_num+1));

            //delay to factor in length of button press
            HAL_Delay(250);
        }

        //Timer function -> 
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
        if (current_secs < 0) {
            clear();
            setCursor(0,0);
            print("Times Up,");
            setCursor(6,1);
            print("Granny!");
            HAL_Delay(4000);
            clear();
            break;
        }
    }
}

void beginGame(){
    //print text to screen
    setCursor(0, 0);
    print("Welcome to"); 
    setCursor(0, 1);
    print("Binary Riddle!");
    //display for 4 seconds then erase
    HAL_Delay(4000);
    clear();
}

int main(void)
{
    HAL_Init(); // initialize the Hardware Abstraction Layer

    __HAL_RCC_GPIOA_CLK_ENABLE(); // enable port A (for the on-board LED, for example)
    __HAL_RCC_GPIOB_CLK_ENABLE(); // enable port B (for the rotary encoder inputs, for example)
    __HAL_RCC_GPIOC_CLK_ENABLE(); // enable port C (for the on-board blue pushbutton, for example)

    SerialSetup(9600);

    //initialize pins used in code for LEDs and buttons
    InitializePin(GPIOB, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);
    //initialize LCD screen
    LiquidCrystal(GPIOB, GPIO_PIN_8 /*G*/, GPIO_PIN_9 /*G*/, GPIO_PIN_10 /*G*/, GPIO_PIN_3 /*G*/,GPIO_PIN_4 /*G*/, GPIO_PIN_5 /*G*/, GPIO_PIN_6);
    //begin the game animation screen
    beginGame();
    //run main loop
    game_loop();
}

void SysTick_Handler(void)
{
    HAL_IncTick(); // tell HAL that a new tick has happened
    // we can do other things in here too if we need to, but be careful
}