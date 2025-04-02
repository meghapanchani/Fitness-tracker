//meal_plan.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "meal_plan.h"


// Meal options categorized by BMI
// These arrays store meals for different weight categories (underweight, normal, overweight)
// Each meal category contains breakfast, lunch, and dinner for a week (7 days)

char* underweight_meals_veg[7][3] =
{
    {"Paneer & Spinach Stuffed Paratha", "Mixed Nuts & Milk", "Chickpea curry with roti"},
    {"Greek Yogurt with Granola & Mixed Berries", "Tofu & Veggies", "Rice with lentil curry"},
    {"Grilled Paneer with veggie", "Fruit Smoothie", "Vegetable Stir-Fry with rice"},
    {"Chia Pudding with dry fruits/chocolate", "Dal & Spinach Rice", "Hummus Pocket with falafel"},
    {"Quinoa Breakfast Bowl with Almonds/ Dates/Fruits", "Stuffed Peppers", "Cauliflower with roti"},
    {"Protein Pancakes with Peanut Butter & Honey", "Chickpea Salad", "Rice and Dal"},
    {"Avocado Toast", "Mushroom & Spinach Rice", "Panner and potato paratha"}
};

char* underweight_meals_nonveg[7][3] =
{
    {"Boiled Eggs & Toast", "Omelette", "Chicken with roti"},
    {"Half-Fry with salads", "Salmon with Quinoa", "Beef Stir Fry"},
    {"Chicken & Spinach Omelette with Whole Wheat Toast", "Protein Shake", "Chicken with Steamed Veggies"},
    {"Breakfast Burrito with Scrambled Eggs, Chicken, & Salsa", "Shrimp & Brown Rice", "Omelette"},
    {"Chicken & Cheese Stuffed Sandwich", "Yogurt with granola and seed", "Steak & Broccoli"},
    {"Chicken & Quinoa Breakfast Bowl", "Seafood Soup", "Baked Soup"},
    {"Grilled Fish & Mashed Sweet Potato Bowl with Egg", "Egg Whites & Salad", "Grilled Chicken"}
};

char* normal_meals_veg[7][3] =
{
    {"Chia Pudding with Nuts & Dates", "Avocado Toast", "Lentil curry with roti"},
    {"Paneer & Spinach Stuffed Paratha", "Chickpea Salad", "Vegetable Biryani"},
    {"Stuffed Peppers with panner", "Tofu Curry & Roti", "Hummus wrap with protien"},
    {"Vegetable Sandwich with tofu", "Nutri Shake", "Rice with Dal"},
    {"Yogurt with seeds/ganola/fruits", "Quinoa salad with chickpeas, cucumber & olive dressing", "Sautéed Veggies with roti"},
    {"Whole wheat toast with peanut butter & banana slices", "brown rice with curry", "Steamed Vegetables"},
    {"Avocado & tomat sandwich", "Lentil Soup", "panner curry with roti"}
};

char* normal_meals_nonveg[7][3] =
{
    {"Boiled Eggs & Avocado Toast", "Protein Smoothie", "Chicken curry and rice"},
    {"Oats with almond milk, walnuts & protein powder", "Grilled Chicken & Veggies", "Veggieor Any meat & Brown Rice wrap"},
    {"Omelette & Whole Grain Toast", "Baked potato with veggie/cheese", "Steak & Salad"},
    {"Chicken Salad", "Boiled Egg Whites", "Grilled Turkey"},
    {"Protein pancakes with maple syrup & fruits", "Veggie wrap", "Steamed Vegetables with Roated chicken"},
    {"Boiled Chicken", "rice with egg", "Steak & Veggies"},
    {"Egg Scramble with peanut butter sandwich", "Salmon & Avocado", "Chicken Broth Soup and rice"}
};

char* overweight_meals_veg[7][3] =
{
    {"Detox Juice", "Cucumber and veggie with dressing Salad", "Roasted Panner"},
    {"Grilled Vegetables", "Mixed Bean Salad", "Steamed Broccoli with rice and dressing"},
    {"Fruit Bowl", "Low-Cal Soup", "Roasted Cauliflower with dressing"},
    {"Protien Shake", "Steamed Beans ", "Carrot & Beet Juice with quinoa salad"},
    {"Green Smoothie", "Baked Zucchini", "Mushroom Stir Fry with soup"},
    {"Herbal Tea", "Chia pudding with nuts & coconut milk", "Steamed Beans with Broccoli/paneer salad"},
    {"Warm Lemon Water with nuts", "Grilled Asparagus", "Vegetable and beans bowl with soup"}
};

char* overweight_meals_nonveg[7][3] =
{
    {"Egg Whites & Green Tea", "chicken Salad", "Shrimp & Asparagus Stir-Fry with Brown Rice"},
    {"Fresh Detox Juice", "Steamed Fish", "Egg fried rice"},
    {"Fruits juice", "Grilled chicken", "Beans Salad with rice "},
    {"Lemon & Herb Juice", "Kale Salad with quinoa", "Tandoori Chicken with Cucumber & Mint Yogurt"},
    {"Smoothie", "Yogurt with berries", "Bone Broth Soup with veggie"},
    {"Egg Omelette", "Protien Shake", "Baked Chicked with salad"},
    {"Salmon & Lemon", "Avacado salad", "Veggie and chicken wrap"}
};


// Alternative meal options
char* alternative_meals_veg[3][3] =
{
    {"Fresh Fruit Juice", "Roasted Paneer with Veggie", "Veggie Curry with Roti"},
    {"Quinoa Salad", "Yogurt with Berries", "Paneer Curry with Roti"},
    {"Smoothie", "Yogurt with Fruit and Chia", "Rice and Dal"}
};

char* alternative_meals_nonveg[3][3] =
{
    {"Egg Scramble", "Chicken Salad", "Rice with Fish Curry"},
    {"Egg Sandwich", "Rice Bowl", "Roasted Chicken"},
    {"Omelet", "Yogurt with Fruits", "Chicken Curry with Roti"}
};

// Function to generate and save a meal plan
void generateMealPlan(float bmi, int isVeg)
{
    srand(time(0));                            // Seed for randomness
    FILE* file = fopen("meal_plan.txt", "w");  // Open file in write mode

    if (file == NULL)
    {
        printf("Error opening file for saving meal plan.\n");
        return;
    }

    printf("\n**Your 7-Day Randomized Meal Plan** \n");
    fprintf(file, "\n**Your 7-Day Randomized Meal Plan**\n");

    for (int day = 0; day < 7; day++)
    {
        printf("\n **Day %d:**\n", day + 1);
        fprintf(file, "\n **Day %d:**\n", day + 1);

        // Select meals based on BMI category
        char* breakfast, * lunch, * dinner;

        if (bmi < 18.5)  // Underweight
        {
            breakfast = isVeg ? underweight_meals_veg[day][0] : underweight_meals_nonveg[day][0];
            lunch = isVeg ? underweight_meals_veg[day][1] : underweight_meals_nonveg[day][1];
            dinner = isVeg ? underweight_meals_veg[day][2] : underweight_meals_nonveg[day][2];
        }
        else if (bmi < 24.9)  // Normal weight
        {
            breakfast = isVeg ? normal_meals_veg[day][0] : normal_meals_nonveg[day][0];
            lunch = isVeg ? normal_meals_veg[day][1] : normal_meals_nonveg[day][1];
            dinner = isVeg ? normal_meals_veg[day][2] : normal_meals_nonveg[day][2];
        }
        else // Overweight
        {
            breakfast = isVeg ? overweight_meals_veg[day][0] : overweight_meals_nonveg[day][0];
            lunch = isVeg ? overweight_meals_veg[day][1] : overweight_meals_nonveg[day][1];
            dinner = isVeg ? overweight_meals_veg[day][2] : overweight_meals_nonveg[day][2];
        }

        printf(" **Breakfast:** %s\n **Lunch:** %s\n **Dinner:** %s\n", breakfast, lunch, dinner);
        fprintf(file, " **Breakfast:** %s\n **Lunch:** %s\n **Dinner:** %s\n", breakfast, lunch, dinner);
    }

    fclose(file);  // Close the file after writing
    printf("\n Meal plan saved successfully to meal_plan.txt!\n");
}


void provideAlternativeMeal(int isVeg)
{
    char choice;
    int selectedDay;

    // Ask user if they need an alternative meal
    printf("Would you like an alternative meal plan? (Y/N): ");
    while (scanf_s(" %c", &choice, 1) != 1 || (choice != 'Y' && choice != 'N'))
    {
        printf("Invalid input. Please enter 'Y' for Yes or 'N' for No: ");
        while (getchar() != '\n');  // Clear input buffer
    }


    if (toupper(choice) == 'Y')
    {
        printf("Enter the day (1-7) for which you need an alternative meal: ");
        scanf_s("%d", &selectedDay);

        // Validate input
        if (selectedDay < 1 || selectedDay > 7)
        {
            printf("Invalid day! Please enter a number between 1 and 7.\n");
            return;
        }

        // Select a random alternative meal
        srand(time(0));
        int mealIndex = rand() % 3;

        // Open file in append mode
        FILE* file = fopen("meal_plan.txt", "a");
        if (!file)
        {
            printf("Error opening meal_plan.txt for writing.\n");
            return;
        }

        // Display and save the alternative meal
        printf("\nAlternative meal for Day %d:\n", selectedDay);
        fprintf(file, "\nAlternative meal for Day %d:\n", selectedDay);

        if (isVeg)
        {
            printf("  **Breakfast:** %s\n", alternative_meals_veg[mealIndex][0]);
            printf("  **Lunch:** %s\n", alternative_meals_veg[mealIndex][1]);
            printf("  **Dinner:** %s\n", alternative_meals_veg[mealIndex][2]);

            fprintf(file, "  **Breakfast:** %s\n", alternative_meals_veg[mealIndex][0]);
            fprintf(file, "  **Lunch:** %s\n", alternative_meals_veg[mealIndex][1]);
            fprintf(file, "  **Dinner:** %s\n", alternative_meals_veg[mealIndex][2]);
        }
        else
        {
            printf("  **Breakfast:** %s\n", alternative_meals_nonveg[mealIndex][0]);
            printf("  **Lunch:** %s\n", alternative_meals_nonveg[mealIndex][1]);
            printf("  **Dinner:** %s\n", alternative_meals_nonveg[mealIndex][2]);

            fprintf(file, "  **Breakfast:** %s\n", alternative_meals_nonveg[mealIndex][0]);
            fprintf(file, "  **Lunch:** %s\n", alternative_meals_nonveg[mealIndex][1]);
            fprintf(file, "  **Dinner:** %s\n", alternative_meals_nonveg[mealIndex][2]);
        }

        fclose(file); // Close file
        printf("\nAlternative meal saved successfully to meal_plan.txt!\n");
    }
    else
    {
        printf("\nNo alternative meal selected.\n");
    }
}

