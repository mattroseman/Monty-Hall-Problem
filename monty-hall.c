#include <stdio.h>
#include <stdlib.h>

void monty_hall() {
    void *random_byte = malloc(1);

    FILE *f;
    if ((f = fopen("/dev/urandom", "rb")) == NULL) {
        fprintf(stderr, "There was a problem opening urandom.\n");
        exit(-1);
    }
    fread(&random_byte, sizeof(random_byte), 1, f);
    fclose(f);

    // initialize doors with cars and goats
    // 3 possible states
    // 
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
