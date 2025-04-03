#ifndef WORKOUT_H
#define WORKOUT_H

#define MAX_EXERCISES 12
#define MAX_DAYS 5

// Structure to store exercise details
typedef struct
{
    char name[50]; // Name of the exercise
    int sets;       // Number of sets to perform
    int reps;       // Number of repetitions per set
    float weight;   // Weight used for the exercise
} Exercise;

// Structure to store user workout plan
typedef struct
{
    char day[50];                         // Name of the workout day
    int num_exercises;                   // Number of exercises for that day
    Exercise exercises[MAX_EXERCISES];  // Array of exercises
} WorkoutPlan;

// Function prototypes
void generateWorkoutPlan(int workout_days);             // Generates a customized workout plan
void suggestWarmup(int selected_day, int user_weight); // Suggests a warm-up routine based on workout day and user weight
void logWorkout(int selected_day);                      // Allows the user to log their workout
void freeWorkoutMemory();                               // Frees dynamically allocated memory for the workout plan

#endif // WORKOUT_H