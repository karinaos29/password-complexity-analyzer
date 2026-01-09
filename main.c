#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <stdlib.h>

#define PASSWORD_LENGTH 8


int containsLower(char* string, int size, int* score, bool* contains);
int containsUpper(char* string, int size, int* score, bool* contains);
int containsDigits(char* string, int size, int* score, bool* contains);
int containsSpecial(char* string, int size, int* score);
int consecutives(char* string, int size, int* score);


// A complexity score 
//-------------------
// 0-3 weak
// 4-5 medium
// 6-7 strong
// 8+ very strong
//-------------------

/*
Contains lowercase -> +1
Contains uppercase -> +1
Contains digits -> +1
Contains special characters -> +1
Longer than 8 -> +1
Longer than 12 -> +2
Max from this section: 4 points
*/

/*
Weak patterns:
Contains “password” → −2
Contains “qwerty” → −1
Contains “111” or “aaa” → −1
All characters the same → −2
Only digits → −1
Only letters → −1
*/
void readPassword(char* string, int capacity) {
    bool isValid = false;

    while (!isValid) {
        printf("Enter a password: ");
        
        if (fgets(string, capacity, stdin) != NULL) {
            string[strcspn(string, "\n")] = 0;

            if (strlen(string) < PASSWORD_LENGTH) {
                printf("Your password is too short (min %d).\n", PASSWORD_LENGTH);
            } else {
                isValid = true; 
            }
        }
    }
}

int main(){
    int complexity_score = 0;
    int *ptr = &complexity_score;

    bool hasLower = false;      
    bool *lower = &hasLower;

    bool hasUpper = false;      
    bool *upper = &hasUpper;

    bool hasDigits = false;      
    bool *digits = &hasDigits;

    char password[30];

    readPassword(password, sizeof(password));

    containsLower(password, strlen(password), ptr, lower);
    containsUpper(password, strlen(password), ptr, upper);
    containsDigits(password, strlen(password), ptr, digits);
    containsSpecial(password, strlen(password), ptr);
    consecutives(password, strlen(password), ptr);

    //extra long bonus
    if (strlen(password) > 12) {
        complexity_score += 2;
    } else if (strlen(password) > 9) {
        complexity_score += 1;
    }

    //simplicity penalties
    if (*lower && !(*upper) && !(*digits)){
        complexity_score--;
    } else if (!(*lower) && (*upper) && !(*digits)){
        complexity_score--;
    } else if (!(*lower) && !(*upper) && *digits){
        complexity_score--;
    }

    printf("--------------\n");

    switch (complexity_score) {
    case -5 ... 3:
        printf("Strength: \033[1;31mWEAK\033[0m\n");
        break;
    case 4 ... 5:
        printf("Strength: \033[1;33mMEDIUM\033[0m\n");
        break;
    case 6 ... 7:
        printf("Strength: \033[1;32mSTRONG\033[0m\n");
        break;
    default:
       printf("Strength: \033[1;36mVERY STRONG\033[0m\n");
        break;
    }
    printf("--------------\n");
}

int containsLower(char* string, int size, int* score, bool* contains){
    for(int i = 0; i < size; i++){
        if (string[i] >= 'a' && string[i] <= 'z') {
            *score += 1;
            *contains = true;
            return *score;
        }
    }

    return *score;
}

int containsUpper(char* string, int size, int* score, bool* contains){
    for(int i = 0; i < size; i++){
        if (string[i] >= 'A' && string[i] <= 'Z') {
            *score += 1;
            *contains = true;
            return *score;
        }
    }
    return *score;
}

int containsDigits(char* string, int size, int* score, bool* contains){
    for(int i = 0; i < size; i++){
        if (string[i] >= '0' && string[i] <= '9') {
            *score += 1;
            *contains = true;
            return *score;
        }
    }
    return *score;
}

int containsSpecial(char* string, int size, int* score){
    for(int i = 0; i < size; i++){
        if ((string[i] >= '!' && string[i] <= '/') || (string[i] >= ':' && string[i] <= '@')) {
            *score += 1;
        }
    }
    return *score;
}

int consecutives(char* string, int size, int* score){
    int consecutive = 0;
    for(int i = 1; i < size; i++){
        if (string[i] == string[i - 1]) {
            consecutive++;
        } else {
            consecutive = 0;
        }
    }
    if (consecutive > 4){
        *score -= 1;
    }
    return *score;
}




