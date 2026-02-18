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
 #include <stdbool.h>
 #include "questions.h"
 #include "players.h"
 #include "jeopardy.h"
 
 // Put macros or constants here using #define
 #define BUFFER_LEN 256
 #define NUM_PLAYERS 4
 
 // Put global environment variables here
 
 // Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
 void tokenize(char *input, char **tokens)
 {
     int i = 0;
     char *token = strtok(input, " ");
 
     while (token != NULL)
     {
         tokens[i++] = token;
         token = strtok(NULL, " ");
     }
 }
 
 // Displays the game results for each player, their name and final score, ranked from first to last place
 void show_results(player *players, int num_players)
 {
     // sort players by score (descending)
     for (int i = 0; i < num_players - 1; i++)
     {
         for (int j = 0; j < num_players - i - 1; j++)
         {
             if (players[j].score < players[j + 1].score)
             {
                 player temp = players[j];
                 players[j] = players[j + 1];
                 players[j + 1] = temp;
             }
         }
     }
 
     printf("\n===== FINAL RESULTS =====\n");
     for (int i = 0; i < num_players; i++)
     {
         printf("%d. %s - $%d\n",
                i + 1,
                players[i].name,
                players[i].score);
     }
 }
 
 
 int main(int argc, char *argv[])
 {
     // An array of 4 players, may need to be a pointer if you want it set dynamically
     player players[NUM_PLAYERS];
     
     // Input buffer and and commands
     char buffer[BUFFER_LEN] = { 0 };
     char category[BUFFER_LEN];
     char answer[BUFFER_LEN];
     int value;
 
     // Display the game introduction and initialize the questions
     initialize_game();
 
     printf("Welcome to Jeopardy!\n");
 
     // Prompt for players names
     for (int i = 0; i < NUM_PLAYERS; i++)
     {
         printf("Enter name for Player %d: ", i + 1);
         fgets(buffer, BUFFER_LEN, stdin);
         buffer[strcspn(buffer, "\n")] = 0;
 
         strcpy(players[i].name, buffer);
         players[i].score = 0;
     }
     
     // initialize each of the players in the array
     // (done above)
 
     // Perform an infinite loop getting command input from users until game ends
     while (1)
     {
         // Execute the game until all questions are answered
         bool finished = true;
 
         for (int i = 0; i < NUM_QUESTIONS; i++)
         {
             if (!questions[i].answered)
             {
                 finished = false;
                 break;
             }
         }
 
         if (finished)
         {
             // Display the final results and exit
             show_results(players, NUM_PLAYERS);
             break;
         }
 
         // Call functions from the questions and players source files
         display_categories();
 
         int player_index;
 
         printf("\nSelect player (1-4): ");
         fgets(buffer, BUFFER_LEN, stdin);
         player_index = atoi(buffer) - 1;
 
         if (player_index < 0 || player_index >= NUM_PLAYERS)
         {
             printf("Invalid player number.\n");
             continue;
         }
 
         printf("Enter category: ");
         fgets(category, BUFFER_LEN, stdin);
         category[strcspn(category, "\n")] = 0;
 
         printf("Enter value: ");
         fgets(buffer, BUFFER_LEN, stdin);
         value = atoi(buffer);
 
         if (already_answered(category, value))
         {
             printf("That question has already been answered.\n");
             continue;
         }
 
         display_question(category, value);
 
         printf("\nYour answer: ");
         fgets(answer, BUFFER_LEN, stdin);
         answer[strcspn(answer, "\n")] = 0;
 
         if (valid_answer(category, value, answer))
         {
             printf("Correct!\n");
             update_score(players, NUM_PLAYERS,
                          players[player_index].name,
                          value);
         }
         else
         {
             printf("Incorrect!\n");
             update_score(players, NUM_PLAYERS,
                          players[player_index].name,
                          -value);
         }
     }
 
     return EXIT_SUCCESS;
 }