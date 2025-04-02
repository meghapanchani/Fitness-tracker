#pragma once
#pragma once
#ifndef USER_PROFILE_H
#define USER_PROFILE_H

// Structure to store user profile details
typedef struct {
    char name[50];
    int age;
    float height;   // in cm
    float weight;   // in kg
    char goals[100];
    int workout_days; // Number of workout days per week
    float bmi; // Computed BMI
} UserProfile;

// Function prototypes
void create_profile(UserProfile* profile, const char* name, int age, float height, float weight, const char* goals, int workout_days);
void calculate_bmi(UserProfile* profile);
void display_profile(const UserProfile* profile);
void save_profile_to_file(const UserProfile* profile, const char* filename);

#endif // USER_PROFILE_H
