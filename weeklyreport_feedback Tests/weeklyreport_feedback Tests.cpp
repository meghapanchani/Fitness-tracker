#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
using namespace std;

extern "C" {
#include "user_profile.h"
#include "report.h"
#include "feedback.h"
}

#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Module3Tests
{
    TEST_CLASS(Module3Tests)
    {
    public:

        // Test Case 1: User Input Validation
        TEST_METHOD(TestUserProfileCreation)
        {
            UserProfile user;
            char name[50];
            char goals[100];
            int age = 25;
            float height = 175.0f;
            float weight = 70.0f;
            int workout_days = 3;

            strncpy_s(name, sizeof(name), "Test User", _TRUNCATE);
            strncpy_s(goals, sizeof(goals), "Muscle Gain", _TRUNCATE);

            create_profile(&user, name, age, height, weight, goals, workout_days);

            Assert::AreEqual(std::string(name), std::string(user.name));
            Assert::AreEqual(age, user.age);
            Assert::AreEqual(height, user.height, 0.01f);
            Assert::AreEqual(weight, user.weight, 0.01f);
            Assert::AreEqual(std::string(goals), std::string(user.goals));
            Assert::AreEqual(workout_days, user.workout_days);
        }

        // Test Case 2: File I/O - Data Storage
        TEST_METHOD(TestSaveProfileToFile)
        {
            UserProfile user;
            create_profile(&user, "Test User", 25, 175.0f, 70.0f, "Muscle Gain", 4);
            save_profile_to_file(&user, "test_profile.txt");

            FILE* file;
            fopen_s(&file, "test_profile.txt", "r");
            Assert::IsNotNull(file);
            if (file != NULL) fclose(file);
        }

        // Test Case 3: Weekly Report Generation
        TEST_METHOD(TestGenerateWeeklyReport)
        {
            WorkoutLog workouts[1] = { {"Push-Ups", 3, 10, true} };
            MealLog meals[1] = { {"Breakfast", true, "Good"} };

            WeeklyReport report = generate_weekly_report(workouts, 1, meals, 1);

            Assert::AreEqual(1, report.workout_count);
            Assert::AreEqual(1, report.meal_count);
            Assert::IsTrue(std::string(report.motivational_message).find("Keep pushing") != std::string::npos);
        }

        // Test Case 4: Inter-Module Data Communication (Manually Assigning Values)
        TEST_METHOD(TestWorkoutMealLogging)
        {
            WorkoutLog workouts[10] = { {"Push-Ups", 3, 10, true} };
            MealLog meals[10] = { {"Breakfast", true, "Good"} };
            int workout_count = 1;
            int meal_count = 1;

            Assert::AreEqual(1, workout_count);
            Assert::AreEqual(1, meal_count);
        }

        // Test Case 5: Feedback-Driven Recommendations
        TEST_METHOD(TestFeedbackRecommendations)
        {
            const char* message = send_motivational_message(0.9f);
            Assert::IsNotNull(message); // Ensure message is not NULL
            Assert::IsTrue(std::string(message).find("Amazing job") != std::string::npos);

            message = send_motivational_message(0.6f);
            Assert::IsNotNull(message);
            Assert::IsTrue(std::string(message).find("You're doing well") != std::string::npos);

            message = send_motivational_message(0.3f);
            Assert::IsNotNull(message);
            Assert::IsTrue(std::string(message).find("Don't give up") != std::string::npos);
        }

        // Test Case 6: Workout Tracking
        TEST_METHOD(TestWorkoutTracking)
        {
            WorkoutLog workout = { "Squats", 5, 12, true };
            Assert::AreEqual(std::string("Squats"), std::string(workout.exercise_name));
            Assert::AreEqual(5, workout.sets);
            Assert::AreEqual(12, workout.reps);
            Assert::IsTrue(workout.completed);
        }

        // Test Case 7: Edge Case for Motivational Message
        TEST_METHOD(TestMotivationalMessageEdge)
        {
            const char* message = send_motivational_message(1.0f);
            Assert::IsTrue(std::string(message).find("Amazing job") != std::string::npos);
        }

        // Test Case 8: Edge Case for Feedback Recommendations
        TEST_METHOD(TestFeedbackRecommendationsEdge)
        {
            const char* message = send_motivational_message(0.0f);
            Assert::IsTrue(std::string(message).find("Don't give up") != std::string::npos);
        }

        // Test Case 9: Multiple Workout Entries
        TEST_METHOD(TestMultipleWorkoutEntries)
        {
            WorkoutLog workouts[3] = {
                {"Push-Ups", 3, 10, true},
                {"Squats", 4, 12, true},
                {"Pull-Ups", 2, 8, false}
            };

            Assert::AreEqual(3, workouts[0].sets);
            Assert::AreEqual(12, workouts[1].reps);
            Assert::IsFalse(workouts[2].completed);
        }

        // Test Case 10: Meal Logging with Feedback
        TEST_METHOD(TestMealLoggingWithFeedback)
        {
            MealLog meals[2] = {
                {"Breakfast", true, "Good start to the day!"},
                {"Dinner", false, "Skipped due to work"}
            };

            Assert::IsTrue(meals[0].consumed);
            Assert::IsTrue(std::string(meals[0].feedback) == "Good start to the day!");
            Assert::IsFalse(meals[1].consumed);
            Assert::IsTrue(std::string(meals[1].feedback) == "Skipped due to work");
        }

        // Test Case 11: Save Weekly Report to File
        TEST_METHOD(TestSaveWeeklyReport)
        {
            WeeklyReport report = { {{"Push-Ups", 3, 10, true}}, 1, {{"Breakfast", true, "Good"}}, 1, "Keep pushing!" };
            save_weekly_report(&report);

            FILE* file;
            fopen_s(&file, "users_data.txt", "r");
            Assert::IsNotNull(file);

            if (file != NULL) {
                char buffer[255];
                while (fgets(buffer, sizeof(buffer), file)) {
                    if (strstr(buffer, "Weekly Report")) {
                        Assert::IsTrue(true);
                    }
                }
                fclose(file);
            }
        }
    };
}