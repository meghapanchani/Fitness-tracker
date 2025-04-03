#include "feedback.h"
#include <stdio.h>

void suggest_alternatives(const char* exercise_disliked, const char* food_disliked) {
    printf("Alternative for %s: Try bodyweight exercises!\n", exercise_disliked);
    printf("Alternative for %s: Try a high-protein meal replacement!\n", food_disliked);
}

const char* send_motivational_message(float consistency_score) {
    if (consistency_score > 0.8)
        return "Amazing job! Keep up the great work!";
    else if (consistency_score > 0.5)
        return "You're doing well! Keep striving!";
    else return "Don't give up! Small steps lead to big results!";
}