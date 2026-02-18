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
 
 // Initializes the array of questions for the game
 void initialize_game(void)
 {
     // Programming (4 questions)
     strcpy(questions[0].category, "programming");
     strcpy(questions[0].question, "This keyword is used to define a function in C.");
     strcpy(questions[0].answer, "void");
     questions[0].value = 100;
     questions[0].answered = false;
 
     strcpy(questions[1].category, "programming");
     strcpy(questions[1].question, "This operator is used to access structure members through a pointer.");
     strcpy(questions[1].answer, "->");
     questions[1].value = 200;
     questions[1].answered = false;
 
     strcpy(questions[2].category, "programming");
     strcpy(questions[2].question, "This function is used to dynamically allocate memory in C.");
     strcpy(questions[2].answer, "malloc");
     questions[2].value = 300;
     questions[2].answered = false;
 
     strcpy(questions[3].category, "programming");
     strcpy(questions[3].question, "This header file is required for input and output functions.");
     strcpy(questions[3].answer, "stdio.h");
     questions[3].value = 400;
     questions[3].answered = false;
 
     // Algorithms (4 questions)
     strcpy(questions[4].category, "algorithms");
     strcpy(questions[4].question, "This data structure follows FIFO order.");
     strcpy(questions[4].answer, "queue");
     questions[4].value = 100;
     questions[4].answered = false;
 
     strcpy(questions[5].category, "algorithms");
     strcpy(questions[5].question, "This sorting algorithm has average time complexity O(n log n).");
     strcpy(questions[5].answer, "merge sort");
     questions[5].value = 200;
     questions[5].answered = false;
 
     strcpy(questions[6].category, "algorithms");
     strcpy(questions[6].question, "This search algorithm divides the array in half each time.");
     strcpy(questions[6].answer, "binary search");
     questions[6].value = 300;
     questions[6].answered = false;
 
     strcpy(questions[7].category, "algorithms");
     strcpy(questions[7].question, "This data structure follows LIFO order.");
     strcpy(questions[7].answer, "stack");
     questions[7].value = 400;
     questions[7].answered = false;
 
     // Databases (4 questions)
     strcpy(questions[8].category, "databases");
     strcpy(questions[8].question, "This SQL command retrieves data from a table.");
     strcpy(questions[8].answer, "select");
     questions[8].value = 100;
     questions[8].answered = false;
 
     strcpy(questions[9].category, "databases");
     strcpy(questions[9].question, "This SQL command is used to remove a table.");
     strcpy(questions[9].answer, "drop");
     questions[9].value = 200;
     questions[9].answered = false;
 
     strcpy(questions[10].category, "databases");
     strcpy(questions[10].question, "This SQL clause filters records.");
     strcpy(questions[10].answer, "where");
     questions[10].value = 300;
     questions[10].answered = false;
 
     strcpy(questions[11].category, "databases");
     strcpy(questions[11].question, "This type of key uniquely identifies a record.");
     strcpy(questions[11].answer, "primary key");
     questions[11].value = 400;
     questions[11].answered = false;
 }
 
 
 // Displays each of the remaining categories and question dollar values that have not been answered
 void display_categories(void)
 {
     printf("\nAvailable Questions:\n");
 
     for (int i = 0; i < NUM_QUESTIONS; i++)
     {
         if (!questions[i].answered)
         {
             printf("Category: %s | Value: $%d\n",
                    questions[i].category,
                    questions[i].value);
         }
     }
 }
 
 
 // Displays the question for the category and dollar value
 void display_question(char *category, int value)
 {
     for (int i = 0; i < NUM_QUESTIONS; i++)
     {
         if (strcmp(questions[i].category, category) == 0 &&
             questions[i].value == value)
         {
             if (questions[i].answered)
             {
                 printf("This question has already been answered.\n");
                 return;
             }
 
             printf("\nQuestion for %s ($%d):\n",
                    questions[i].category,
                    questions[i].value);
 
             printf("%s\n", questions[i].question);
             return;
         }
     }
 
     printf("Question not found.\n");
 }
 
 
 // Returns true if the answer is correct
 bool valid_answer(char *category, int value, char *answer)
 {
     for (int i = 0; i < NUM_QUESTIONS; i++)
     {
         if (strcmp(questions[i].category, category) == 0 &&
             questions[i].value == value)
         {
             questions[i].answered = true;
 
             if (strcmp(questions[i].answer, answer) == 0)
             {
                 return true;
             }
             else
             {
                 return false;
             }
         }
     }
 
     return false;
 }
 
 
 // Returns true if the question has already been answered
 bool already_answered(char *category, int value)
 {
     for (int i = 0; i < NUM_QUESTIONS; i++)
     {
         if (strcmp(questions[i].category, category) == 0 &&
             questions[i].value == value)
         {
             return questions[i].answered;
         }
     }
 
     return false;
 }