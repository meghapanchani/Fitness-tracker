#include <stdio.h>
#include <string.h>
#include "user_profile.h"

// Function to initialize a user profile
void create_profile(UserProfile* profile, const char* name, int age, float height, float weight, const char* goals, int workout_days) {
    strncpy_s(profile->name, sizeof(profile->name), name, _TRUNCATE);
    profile->age = age;
    profile->height = height;
    profile->weight = weight;
    strncpy_s(profile->goals, sizeof(profile->goals), goals, _TRUNCATE);
    profile->workout_days = workout_days;
    calculate_bmi(profile);
}

// Function to calculate BMI
void calculate_bmi(UserProfile* profile) {
    if (profile->height > 0) {
        float height_m = profile->height / 100.0; // Convert cm to meters
        profile->bmi = profile->weight / (height_m * height_m);
    }
    else {
        profile->bmi = 0.0;
    }
}

// Function to display user profile details
void display_profile(const UserProfile* profile) {
    printf("\nUser Profile:\n");
    printf("Name: %s\n", profile->name);
    printf("Age: %d years\n", profile->age);
    printf("Height: %.2f cm\n", profile->height);
    printf("Weight: %.2f kg\n", profile->weight);
    printf("Workout Days per Week: %d\n", profile->workout_days);
    printf("Goals: %s\n", profile->goals);
    printf("BMI: %.2f (Category: %s)\n", profile->bmi,
        (profile->bmi < 18.5) ? "Underweight" :
        (profile->bmi < 24.9) ? "Normal weight" :
        (profile->bmi < 29.9) ? "Overweight" : "Obese");
}

// Function to save user profile to a file
void save_profile_to_file(const UserProfile* profile, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "Name: %s\n", profile->name);
    fprintf(file, "Age: %d\n", profile->age);
    fprintf(file, "Height: %.2f cm\n", profile->height);
    fprintf(file, "Weight: %.2f kg\n", profile->weight);
    fprintf(file, "Workout Days per Week: %d\n", profile->workout_days);
    fprintf(file, "Goals: %s\n", profile->goals);
    fprintf(file, "BMI: %.2f\n", profile->bmi);

    fclose(file);
    printf("Profile saved successfully to %s\n", filename);
}
