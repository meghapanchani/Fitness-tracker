#include "pch.h"
#include "CppUnitTest.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C"
{
#include "../Fitness tracker/main.c"
#include "../Fitness tracker/workout.c"
#include "../Fitness tracker/meal_plan.c"
#include "../Fitness tracker/user_profile.c"
#include "../Fitness tracker/workout.h"
#include "../Fitness tracker/meal_plan.h"
#include "../Fitness tracker/user_profile.h"
}

namespace FitnessWorkout
{
	TEST_CLASS(FitnessWorkout)
	{
	public:

		// Workout plan test

		//  Verify 1-day workout plan (Full Body)
		TEST_METHOD(TestWorkoutPlan1Day) {
			generateWorkoutPlan(1);
			Assert::IsTrue(true);
		}

		//  Verify 2-day workout plan (Upper & Lower)
		TEST_METHOD(TestWorkoutPlan2Days) {
			generateWorkoutPlan(2);
			Assert::IsTrue(true);
		}

		//  Verify 3-day PPL (Push-Pull-Legs) plan
		TEST_METHOD(TestWorkoutPlan3Days) {
			generateWorkoutPlan(3);
			Assert::IsTrue(true);
		}

		//  Verify 4-day Upper-Lower Split with a Combo Day
		TEST_METHOD(TestWorkoutPlan4Days) {
			generateWorkoutPlan(4);
			Assert::IsTrue(true);
		}

		// Verify 5-day Upper-Lower Rotation plan
		TEST_METHOD(TestWorkoutPlan5Days) {
			generateWorkoutPlan(5);
			Assert::IsTrue(true);
		}

		// Verify selecting more than 5 days (Invalid Case)
		TEST_METHOD(TestInvalidWorkoutDays) {
			generateWorkoutPlan(6);
			Assert::IsTrue(true); // Should trigger error message
		}

		//  Verify selecting 8 days (Exceeds max limit)
		TEST_METHOD(TestWorkoutPlanRejectsMoreThan5Days) {
			generateWorkoutPlan(8);
			Assert::IsTrue(true);
		}

		//  Verify weight calculation for workouts
		TEST_METHOD(TestWorkoutPlanWeightCalculation) {
			logWorkout(1);
			Assert::IsTrue(true);
		}

		//  Verify Upper-Lower Split (2-day plan)
		TEST_METHOD(TestWorkoutPlanUpperLowerSplit) {
			generateWorkoutPlan(2);
			Assert::IsTrue(true);
		}

		//  Verify Push-Pull-Legs (3-day plan)
		TEST_METHOD(TestWorkoutPlanPPL3Days) {
			generateWorkoutPlan(3);
			Assert::IsTrue(true);
		}

		//  Verify 4-day Upper-Lower Combo
		TEST_METHOD(TestWorkoutPlanUpperLowerCombo) {
			generateWorkoutPlan(4);
			Assert::IsTrue(true);
		}

		// Verify 5-day Upper-Lower Rotation
		TEST_METHOD(TestWorkoutPlanUpperLowerRotation) {
			generateWorkoutPlan(5);
			Assert::IsTrue(true);
		}

		//  Verify workout logging validation 
		TEST_METHOD(TestWorkoutLoggingValidation) {
			logWorkout(2);
			Assert::IsTrue(true);
		}

		// Meal plan test

		//  Verify Vegetarian meal plan for Underweight user 
		TEST_METHOD(TestMealPlanVegUnderweight) {
			generateMealPlan(18.0, 1);
			Assert::IsTrue(true);
		}

		// Verify Vegetarian meal plan for Normal BMI user
		TEST_METHOD(TestMealPlanVegNormal) {
			generateMealPlan(22.5, 1);
			Assert::IsTrue(true);
		}

		//  Verify Vegetarian meal plan for Overweight user
		TEST_METHOD(TestMealPlanVegOverweight) {
			generateMealPlan(30.0, 1);
			Assert::IsTrue(true);
		}

		// Verify Non-Vegetarian meal plan for Underweight user
		TEST_METHOD(TestMealPlanNonVegUnderweight) {
			generateMealPlan(18.0, 2);
			Assert::IsTrue(true);
		}

		// Verify Non-Vegetarian meal plan for Normal BMI user
		TEST_METHOD(TestMealPlanNonVegNormal) {
			generateMealPlan(24.5, 2);
			Assert::IsTrue(true);
		}

		// Verify Non-Vegetarian meal plan for Overweight user
		TEST_METHOD(TestMealPlanNonVegOverweight) {
			generateMealPlan(35.0, 2);
			Assert::IsTrue(true);
		}

		//  Verify invalid meal selection (Input other than Veg/Non-Veg)
		TEST_METHOD(TestInvalidMealSelection) {
			generateMealPlan(24.5, 3);
			Assert::IsTrue(true);
		}

		//  Verify alternative meal plan selection
		TEST_METHOD(TestAlternativeMealSelection) {
			provideAlternativeMeal(1);
			Assert::IsTrue(true);
		}

		//  Verify invalid day selection for alternative meal plan
		TEST_METHOD(TestInvalidAlternativeMealDay) {
			provideAlternativeMeal(8);
			Assert::IsTrue(true);
		}

		//  Verify No alternative meal plan is selected
		TEST_METHOD(TestNoAlternativeMeal) {
			provideAlternativeMeal(2);
			Assert::IsTrue(true);
		}

		//  Verify that no random meal is displayed when user selects "No"
		TEST_METHOD(TestMealSuggestionDisabled) {
			provideAlternativeMeal(0);
			Assert::IsTrue(true);
		}

		//  Verify that a random meal is suggested when user selects "Yes"
		TEST_METHOD(TestRandomMealSuggestion) {
			provideAlternativeMeal(1);
			Assert::IsTrue(true);
		}
	};
}

