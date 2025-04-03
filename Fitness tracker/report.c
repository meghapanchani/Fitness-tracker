#include "report.h"
#include <stdio.h>
#include <string.h>

void track_workout_progress(WorkoutLog logs[], int* count) {
    printf("Enter the exercise name: ");
    fgets(logs[*count].exercise_name, sizeof(logs[*count].exercise_name), stdin);
    printf("Enter sets: ");
    scanf_s("%d", &logs[*count].sets);
    printf("Enter reps: ");
    scanf_s("%d", &logs[*count].reps);
    printf("Completed? (1 for Yes, 0 for No): ");
    scanf_s("%d", (int*)&logs[*count].completed);
    (*count)++;
}

void track_meal_adherence(MealLog logs[], int* count) {
    printf("Enter meal type: ");
    fgets(logs[*count].meal_type, sizeof(logs[*count].meal_type), stdin);
    printf("Consumed? (1 for Yes, 0 for No): ");
    scanf_s("%d", (int*)&logs[*count].consumed);
    while (getchar() != '\n');
    printf("Feedback: ");
    fgets(logs[*count].feedback, sizeof(logs[*count].feedback), stdin);
}

WeeklyReport generate_weekly_report(WorkoutLog workouts[], int workout_count, MealLog meals[], int meal_count) {
    WeeklyReport report;
    report.workout_count = workout_count;
    report.meal_count = meal_count;
    strncpy_s(report.motivational_message, sizeof(report.motivational_message), "Keep pushing! Progress is made daily!", _TRUNCATE);
    return report;
}

void save_weekly_report(WeeklyReport* report) {
    const char* filename = "users_data.txt";
    FILE* file = fopen(filename, "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Weekly Report\nWorkout Count: %d\nMeal Count: %d\nMotivation: %s\n\n",
        report->workout_count, report->meal_count, report->motivational_message);

    fclose(file);
    printf("Weekly report saved to %s successfully.\n", filename);
}