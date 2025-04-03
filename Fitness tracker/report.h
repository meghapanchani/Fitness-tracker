#pragma once

#include <stdbool.h>
#include <stdio.h>

// structure to store workout progress
typedef struct {
    char exercise_name[50];
    int sets;
    int reps;
    bool completed;
} WorkoutLog;

// store meal adherence
typedef struct {
    char meal_type[50];
    bool consumed;
    char feedback[100];
} MealLog;

// weekly report
typedef struct {
    WorkoutLog workout[50];
    int workout_count;
    MealLog meals[50];
    int meal_count;
    char motivational_message[200];
} WeeklyReport;

void track_workout_progress(WorkoutLog logs[], int* count);
void track_meal_adherence(MealLog logs[], int* count);
WeeklyReport generate_weekly_report(WorkoutLog workouts[], int workout_count, MealLog meals[], int meal_count);
void save_weekly_report(WeeklyReport* report);
