#include <stdio.h>
#include <stdlib.h>

void monty_hall() {
    unsigned char *random_byte = malloc(1);

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
    // byte between 0x55 and 0xA9
    } else if (*random_byte <= 0xA9) {
        // second door has car
    // byte between 0xAA and 0xFE
    } else {
        // third door has car
    }

    // PICK FIRST DOOR GUESS
    do {
        fread(random_byte, sizeof(random_byte), 1, f);
    } while (*random_byte == 0xFF);

    // place the first door guess
    // byte between 0x00 and 0x54
    if (*random_byte <= 0x54) {
        // guess the first door
    // byte between 0x55 and 0xA9
    } else if (*random_byte <= 0xA9) {
        // guess the second door
    // byte between 0xAA and 0xFE
    } else {
        // guess the thrid door
    }

    fclose(f);
}

int main(int argc, char *argv[]) {
    long num_tests;
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
        monty_hall();
    }
    return 0;
}
