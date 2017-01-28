#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool monty_hall() {
    unsigned char *random_byte = malloc(1);
    int prize_door;
    bool win_value;

    FILE *f;
    if ((f = fopen("/dev/urandom", "rb")) == NULL) {
        fprintf(stderr, "There was a problem opening urandom.\n");
        exit(-1);
    }

    // PICK PRIZE DOOR
    do {
        fread(random_byte, sizeof(random_byte), 1, f);
    } while (*random_byte == 0xFF);

    // initialize doors with cars and goats
    // 3 possible states
    // byte between 0x00 and 0x54
    if (*random_byte <= 0x54) {
        // first door has car
        prize_door = 1;
    // byte between 0x55 and 0xA9
    } else if (*random_byte <= 0xA9) {
        // second door has car
        prize_door = 2;
    // byte between 0xAA and 0xFE
    } else {
        // third door has car
        prize_door = 3;
    }

    // PICK FIRST DOOR GUESS
    do {
        fread(random_byte, sizeof(random_byte), 1, f);
    } while (*random_byte == 0xFF);

    // place the first door guess
    // byte between 0x00 and 0x54
    if (*random_byte <= 0x54) {
        // guess the first door
        // if the guess is correct
        if (prize_door == 1) {
            // switching wrong
            // staying right
            win_value = false;
        // if the guess is wrong
        } else {
            // switching right
            // staying wrong
            win_value = true;
        }
    // byte between 0x55 and 0xA9
    } else if (*random_byte <= 0xA9) {
        // guess the second door
        // if the guess is correct
        if (prize_door == 2) {
            // switching wrong
            // staying right
            win_value = false;
        // if the guess is wrong
        } else {
            // switching right
            // staying wrong
            win_value = true;
        }
    // byte between 0xAA and 0xFE
    } else {
        // guess the thrid door
        // if the guess is correct
        if (prize_door == 3) {
            // switching wrong
            // staying right
            win_value = false;
        // if the guess is wrong
        } else {
            // switching right
            // staying wrong
            win_value = true;
        }
    }

    fclose(f);
    return win_value;
}

int main(int argc, char *argv[]) {
    long num_tests;
    int num_correct = 0;
    int num_wrong = 0;

    if (argc == 2) {
        char *end;
        if ((num_tests = strtol(argv[1], &end, 10)) == 0) {
            fprintf(stderr, "There was an error converting argument to an integer! Exiting ...\n");
            exit(-1);
        }
    } else {
        printf("No argument was passed indicating number of tests, defaulting to 100\n");
        num_tests = 100;
    }

    for (int i=0; i < num_tests; i++) {
        if (monty_hall()) {
            num_correct++;
        } else {
            num_wrong++;
        }

        printf("Wins: %d Losses: %d Win Percent %lf\n", num_correct, num_wrong, (double)num_correct/(num_correct+num_wrong));
    }
    return 0;
}
