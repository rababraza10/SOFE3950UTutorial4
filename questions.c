/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2026, <GROUP NUMBER>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"
#include <stdbool.h>



struct question {
    char* category;
    char* question;
    char* answer;
    int value;
    bool answered;
    
};

#define NUM_QUESTIONS 5

struct question questions[NUM_QUESTIONS];


// Initializes the array of questions for the game
void initialize_game(void)
{
    questions[0] = (struct question){
        "Computer Science",
        "This data structure follows FIFO order.",
        "What is a queue?",
        100,
        false
    };

    questions[1] = (struct question){
        "Computer Science",
        "This sorting algorithm has average time complexity O(n log n).",
        "What is merge sort?",
        200,
        false
    };

    questions[2] = (struct question){
        "Math",
        "This is the derivative of x^2.",
        "What is 2x?",
        100,
        false
    };

    questions[3] = (struct question){
        "Physics",
        "This law states F = ma.",
        "What is Newton's Second Law?",
        200,
        false
    };

    questions[4] = (struct question){
        "General Knowledge",
        "This country has the largest population in the world.",
        "What is China?",
        100,
        false
    };
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}
