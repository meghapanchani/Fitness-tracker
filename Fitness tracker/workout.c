
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workout.h"

WorkoutPlan* workoutPlan = NULL;  // Dynamically allocated workout plan

// Predefined exercise lists
const char* fullBody[] = { "Bench Press", "Shoulder Press", "Lat Pulldown", "Horizontal Pull", "Reverse Pec Fly", "Chest Fly", "Rope Triceps", "Dumbbell Curl", "Lunges", "Leg Press", "Leg Curl", "Leg Extension" };
const char* chestShoulderTriceps[] = { "Bench Press", "Shoulder Press", "Chest Fly", "Lateral Raises", "Triceps Pushdown", "Rope Triceps" };
const char* backBiceps[] = { "Lat Pulldown", "Horizontal Pull", "Straight Arm Pulldown", "Reverse Pec Fly", "Dumbbell Curl", "Rope Hammer Curl" };
const char* legs[] = { "Squats", "Lunges", "Leg Press", "Calf Raise", "Leg Extension", "Leg Curl", "Treadmill Sprint" };
const char* day4Combo[] = { "Bench Press", "Shoulder Press", "Lat Pulldown", "Horizontal Pull", "Lateral Raises", "Rope Triceps", "Dumbbell Curl", "Rope Hammer Curl" };


// Dynamically generate workout plan based on user input
void generateWorkoutPlan(int workout_days)
{
    workoutPlan = (WorkoutPlan*)malloc(workout_days * sizeof(WorkoutPlan));
    if (!workoutPlan)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("\nYour Weekly Workout Plan:\n");

    for (int i = 0; i < workout_days; i++)
    {
        if (workout_days == 1)
        {
            strcpy_s(workoutPlan[i].day, sizeof(workoutPlan[i].day), "Full Body");
            workoutPlan[i].num_exercises = 12;
            for (int j = 0; j < 12; j++)
            {
                strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), fullBody[j]);
            }
        }
        else if (workout_days == 2)
        {
            const char* days[] = { "Chest, Shoulders, Triceps & Back, Biceps", "Legs" };
            strcpy_s(workoutPlan[i].day, sizeof(workoutPlan[i].day), days[i]);
            workoutPlan[i].num_exercises = (i == 0) ? 8 : 7; 

            for (int j = 0; j < workoutPlan[i].num_exercises; j++)
            {
                if (i == 0)  // Day 1 Upper Body 
                {
                    const char* upperBody[] = { "Bench Press", "Shoulder Press", "Lat Pulldown", "Horizontal Pull", "Lateral Raises", "Rope Triceps", "Dumbbell Curl", "Rope Hammer Curl" };
                    strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), upperBody[j]);
                }
                else { // Day 2 Legs
                    strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), legs[j]);
                }
            }
        }
        else if (workout_days == 3)
        {
            const char* days[] = { "Chest, Shoulders, Triceps", "Back, Biceps", "Legs" };
            strcpy_s(workoutPlan[i].day, sizeof(workoutPlan[i].day), days[i]);
            workoutPlan[i].num_exercises = (i == 2) ? 7 : 6;
            for (int j = 0; j < workoutPlan[i].num_exercises; j++)
            {
                strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), (i == 2) ? legs[j] : (i == 0 ? chestShoulderTriceps[j] : backBiceps[j]));
            }
        }
        else if (workout_days == 4)
        {
            const char* days[] = { "Chest, Shoulders, Triceps", "Back, Biceps", "Legs", "Chest, Shoulders, Triceps & Back, Biceps" };
            strcpy_s(workoutPlan[i].day, sizeof(workoutPlan[i].day), days[i]);

            if (i == 0)
            {
                workoutPlan[i].num_exercises = 6;
                for (int j = 0; j < 6; j++)
                    strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), chestShoulderTriceps[j]);
            }
            else if (i == 1)
            {
                workoutPlan[i].num_exercises = 6;
                for (int j = 0; j < 6; j++)
                    strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), backBiceps[j]);
            }
            else if (i == 2)
            {
                workoutPlan[i].num_exercises = 7;
                for (int j = 0; j < 7; j++)
                    strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), legs[j]);
            }
            else
            {
                workoutPlan[i].num_exercises = 8;
                for (int j = 0; j < 8; j++)
                    strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), day4Combo[j]);
            }
        }
        else if (workout_days == 4 || workout_days == 5)
        {
            const char* days[] = { "Chest, Shoulders, Triceps", "Back, Biceps", "Legs", "Chest, Shoulders, Triceps", "Back, Biceps" };
            strcpy_s(workoutPlan[i].day, sizeof(workoutPlan[i].day), days[i]);

            if (i == 0 || i == 3)
            {
                workoutPlan[i].num_exercises = 6;
                for (int j = 0; j < 6; j++)
                    strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), chestShoulderTriceps[j]);
            }
            else if (i == 1 || i == 4)
            {
                workoutPlan[i].num_exercises = 6;
                for (int j = 0; j < 6; j++)
                    strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), backBiceps[j]);
            }
            else if (i == 2)
            {
                workoutPlan[i].num_exercises = 7;
                for (int j = 0; j < 7; j++)
                    strcpy_s(workoutPlan[i].exercises[j].name, sizeof(workoutPlan[i].exercises[j].name), legs[j]);
            }
        }

        printf("Day %d: %s\n", i + 1, workoutPlan[i].day);
    }
}


// Display warm-up & exercise list
void suggestWarmup(int selected_day, int user_weight)
{
    if (!workoutPlan || selected_day < 1) return;

    int index = selected_day - 1;
    printf("\nWarm-up Guide: Perform 5 minutes of stretching + light cardio.\n");
    printf("\nToday's Workout Plan: %s\n", workoutPlan[index].day);

    for (int i = 0; i < workoutPlan[index].num_exercises; i++)
    {
        workoutPlan[index].exercises[i].sets = 3;
        workoutPlan[index].exercises[i].reps = 10 + (i % 3);
        workoutPlan[index].exercises[i].weight = (float)(user_weight * 0.75);

        printf("  - %s: %d sets x %d reps (%.1f kg)\n",
            workoutPlan[index].exercises[i].name,
            workoutPlan[index].exercises[i].sets,
            workoutPlan[index].exercises[i].reps,
            workoutPlan[index].exercises[i].weight);
    }
}

// Log users workout performance
void logWorkout(int selected_day)
{
    if (!workoutPlan || selected_day < 1) return;

    int index = selected_day - 1;
    FILE* file = fopen("workout_log.txt", "a");

    if (!file)
    {
        printf("Error opening file for logging!\n");
        return;
    }

    printf("\nLog your workout for: %s\n", workoutPlan[index].day);
    fprintf(file, "\nWorkout Log for: %s\n", workoutPlan[index].day);

    for (int i = 0; i < workoutPlan[index].num_exercises; i++)
    {
        int sets = 0, reps = 0;
        float weight = 0.0;

        printf("\n[%s]\n", workoutPlan[index].exercises[i].name);
        printf("  Enter sets completed: ");
        while (scanf_s("%d", &sets) != 1 || sets < 1)
        {
            printf("  Invalid input. Enter again: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        printf("  Enter reps per set: ");
        while (scanf_s("%d", &reps) != 1 || reps < 1)
        {
            printf("  Invalid input. Enter again: ");
            while (getchar() != '\n');
        }

        printf("  Enter weight used (kg): ");
        while (scanf_s("%f", &weight) != 1 || weight < 0)
        {
            printf("  Invalid input. Enter again: ");
            while (getchar() != '\n');
        }

        fprintf(file, "Exercise: %s, Sets: %d, Reps: %d, Weight: %.1f kg\n",
            workoutPlan[index].exercises[i].name, sets, reps, weight);
    }

    fclose(file);
    printf("\n Workout logged successfully!\n");
}


// Free dynamically allocated memory
void freeWorkoutMemory()
{
    if (workoutPlan) {
        free(workoutPlan);
    }
}