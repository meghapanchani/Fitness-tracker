
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user_profile.h"
#include "workout.h"
#include "meal_plan.h"


int main() {
    UserProfile user;
    char name[50], goals[100];
    int age, workout_days, today_day, user_weight;
    float height, weight;
    int isVeg;

    // Collect user input
    do {
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        if (!isOnlyLetters(name)) {
            printf("Invalid input! Name should contain only letters and spaces.\n");
        }
    } while (!isOnlyLetters(name));


    do {
        printf("Enter your age: ");
        if (scanf_s("%d", &age) != 1 || age < 1 || age > 120) {
            printf("Invalid age! Please enter a number between 1 and 120.\n");
            while (getchar() != '\n');      // Clear invalid input
        }
        else {
            break;
        }
    } while (1);

    do {
        printf("Enter your height in cm: ");
        if (scanf_s("%f", &height) != 1 || height < 30.0 || height > 500.0) {
            printf("Invalid height! Please enter a number between 30 and 500.\n");
            while (getchar() != '\n');
        }
        else {
            break;
        }
    } while (1);

    do {
        printf("Enter your weight in kg from 20: ");
        if (scanf_s("%f", &weight) != 1 || weight < 20.0 || weight > 300.0) {
            printf("Invalid weight! Please enter a number between 20 and 300.\n");
            while (getchar() != '\n');
        }
        else {
            break;
        }
    } while (1);

    while (getchar() != '\n');


    do {
        printf("Enter your workout goals: ");
        fgets(goals, sizeof(goals), stdin);
        goals[strcspn(goals, "\n")] = '\0';

        if (!isOnlyLetters(goals)) {
            printf("Invalid input! Workout goals should only contain letters and spaces.\n");
        }
    } while (!isOnlyLetters(goals));


    printf("Enter number of workout days per week (1-5): ");
    while (scanf_s("%d", &workout_days) != 1 || workout_days < 1 || workout_days > 5)
    {
        printf("Sorry! Maximum workout days allowed is 5. Please enter a valid number (1-5): ");
        while (getchar() != '\n');
    }

    if (workout_days == 4 || workout_days == 5)
    {
        printf("\n I recommend taking **2 rest days** to allow your muscles to recover.\n");
    }

    // Create and save user profile
    create_profile(&user, name, age, height, weight, goals, workout_days);
    display_profile(&user);
    save_profile_to_file(&user, "user_profile.txt");



    // Generate the Workout Plan (Dynamically Allocated)
    generateWorkoutPlan(workout_days);


    printf("\nEnter today's workout day (1-%d): ", workout_days);
    scanf_s("%d", &today_day);

    if (today_day < 1 || today_day > workout_days) {
        printf("\nInvalid selection! Please enter a day between 1 and %d.\n", workout_days);
        return 1;
    }

    // Ask for weight after selecting today's workout
    printf("\nEnter your weight (kg) for workout calculations: ");
    while (scanf_s("%d", &user_weight) != 1 || user_weight <= 25) {
        printf("Invalid weight! Please enter a positive and more than 25 number: ");
        while (getchar() != '\n');
    }


    // Ensure correct mapping of exercises based on selection
    suggestWarmup(today_day, user_weight);

    // Loggin the user workout 
    logWorkout(today_day);

    // Ask Meal Preference
    printf("\n **What type of meal do you prefer?**\n");
    printf("1. Vegetarian\n2. Non-Vegetarian\nEnter choice (1 or 2): ");

    while (scanf_s("%d", &isVeg) != 1 || (isVeg != 1 && isVeg != 2)) {
        printf("\n Invalid input! Please enter **1 for Vegetarian** or **2 for Non-Vegetarian**: ");
        while (getchar() != '\n'); // Clear invalid input
    }


    // Generate 7-Day Meal Plan Based on BMI
    generateMealPlan(user.bmi, isVeg == 1);


    // Ask user for alternative meal
    provideAlternativeMeal(isVeg);


    // Free dynamically allocated memory
    freeWorkoutMemory();


    return 0;
}
