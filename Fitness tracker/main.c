#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_profile.h"
#include "report.h"
#include "feedback.h"

int main() {
    UserProfile user;
    int workout_count = 0, meal_count = 0;
    char name[50], goals[100];
    int age, workout_days;
    float height, weight;

    WorkoutLog* workouts = malloc(50 * sizeof(WorkoutLog));
    MealLog* meals = malloc(50 * sizeof(MealLog));

    if (workouts == NULL || meals == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Collect user input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter your age: ");
    scanf_s("%d", &age);
    (void)getchar();

    printf("Enter your height (cm): ");
    scanf_s("%f", &height);
    (void)getchar();

    printf("Enter your weight (kg): ");
    scanf_s("%f", &weight);
    (void)getchar();

    printf("Enter your workout goals: ");
    fgets(goals, sizeof(goals), stdin);
    goals[strcspn(goals, "\n")] = '\0';

    printf("Enter number of workout days per week: ");
    scanf_s("%d", &workout_days);
    (void)getchar();

    // Create user profile
    create_profile(&user, name, age, height, weight, goals, workout_days);
    display_profile(&user);
    save_profile_to_file(&user, "user_profile.txt");

    // Track workouts
    char choice;
    printf("\nDo you want to log workouts? (y/n): ");
    scanf_s(" %c", &choice, 1);
    (void)getchar();

    while (choice == 'y' || choice == 'Y') {
        track_workout_progress(workouts, &workout_count);
        printf("Log another workout? (y/n): ");
        scanf_s(" %c", &choice, 1);
        (void)getchar();
    }

    // Track meals
    printf("\nDo you want to log meals? (y/n): ");
    scanf_s(" %c", &choice, 1);
    (void)getchar();

    while (choice == 'y' || choice == 'Y') {
        track_meal_adherence(meals, &meal_count);
        printf("Log another meal? (y/n): ");
        scanf_s(" %c", &choice, 1);
        (void)getchar();
    }

    // Generate and save report
    WeeklyReport report = generate_weekly_report(workouts, workout_count, meals, meal_count);
    save_weekly_report(&report);

    // Send motivational message
    float consistency_score = (float)(workout_count + meal_count) / 10.0f;
    printf("\n%s\n", send_motivational_message(consistency_score));

    free(workouts);
    free(meals);

    return 0;
}