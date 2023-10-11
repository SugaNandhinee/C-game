#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lower=1, upper=100, num, guess, attempts=0;
    
    // Initialize random seed
    srand(time(0));
    
    // Generate a random number between lower and upper
    num = (rand() % (upper - lower + 1)) + lower;

    printf("Welcome to the Guess the Number game!\n");
    printf("I've chosen a number between %d and %d. Try to guess it!\n", lower, upper);

    do {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (fgetc(stdin) != '\n'); // Clear the input buffer
            continue;
        }
        attempts++;

        if (guess < lower || guess > upper) {
            printf("Your guess is out of range. Try again.\n");
        } else if (guess < num) {
            printf("Try higher!\n");
        } else if (guess > num) {
            printf("Try lower!\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", num, attempts);
        }
    } while (guess != num);

    return 0;
}
