/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>
 
 #define NUM_QUESTIONS 5
 #define MAX_INPUT 256
 
 struct question {
     char* category;
     char* question;
     char* answer;
     int value;
     bool answered;
 };
 
 struct question questions[NUM_QUESTIONS];
 int score = 0;
 
 

 
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
 
 

 
 void display_categories(void)
 {
     printf("\nAvailable Questions:\n");
 
     for (int i = 0; i < NUM_QUESTIONS; i++) {
         if (!questions[i].answered) {
             printf("Category: %s | Value: $%d\n",
                    questions[i].category,
                    questions[i].value);
         }
     }
 }
 
 
 
 void display_question(char *category, int value)
 {
     for (int i = 0; i < NUM_QUESTIONS; i++) {
 
         if (strcmp(questions[i].category, category) == 0 &&
             questions[i].value == value) {
 
             if (questions[i].answered) {
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
 
 

 
 bool valid_answer(char *category, int value, char *answer)
 {
     for (int i = 0; i < NUM_QUESTIONS; i++) {
 
         if (strcmp(questions[i].category, category) == 0 &&
             questions[i].value == value) {
 
             questions[i].answered = true;
 
             if (strcmp(questions[i].answer, answer) == 0) {
                 score += questions[i].value;
                 return true;
             } else {
                 score -= questions[i].value;
                 return false;
             }
         }
     }
 
     return false;
 }
 
 

 
 bool already_answered(char *category, int value)
 {
     for (int i = 0; i < NUM_QUESTIONS; i++) {
 
         if (strcmp(questions[i].category, category) == 0 &&
             questions[i].value == value) {
 
             return questions[i].answered;
         }
     }
 
     return false;
 }
 
 

 
 bool game_over(void)
 {
     for (int i = 0; i < NUM_QUESTIONS; i++) {
         if (!questions[i].answered)
             return false;
     }
     return true;
 }
 
 

 
 int main(void)
 {
     initialize_game();
 
     char category[MAX_INPUT];
     int value;
     char answer[MAX_INPUT];
 
     printf("Welcome to Jeopardy!\n");
 
     while (!game_over()) {
 
         display_categories();
 
         printf("\nEnter category: ");
         fgets(category, MAX_INPUT, stdin);
         category[strcspn(category, "\n")] = 0;
 
         printf("Enter value: ");
         scanf("%d", &value);
         getchar(); 
 
         if (already_answered(category, value)) {
             printf("That question has already been answered.\n");
             continue;
         }
 
         display_question(category, value);
 
         printf("\nYour answer: ");
         fgets(answer, MAX_INPUT, stdin);
         answer[strcspn(answer, "\n")] = 0;
 
         if (valid_answer(category, value, answer)) {
             printf("Correct!\n");
         } else {
             printf("Incorrect!\n");
         }
 
         printf("Current Score: $%d\n", score);
     }
 
     printf("\nGame Over!\n");
     printf("Final Score: $%d\n", score);
 
     return 0;
 }