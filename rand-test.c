#include <stdio.h>
#include <stdlib.h>

void print_byte(unsigned char *c) {
    int i;
    for (i=0; i < 8; i++) {
        // checks if the msb is 1 or 0
        printf("%d", !!((*c << i) & 0x80));
    }
    printf("\n");
}

int main() {
    int num_tests = 100000;
    int cnt1, cnt2, cnt3 = 0;
    int total;

    unsigned char *random_byte = malloc(1);

    FILE *f;
    if ((f = fopen("/dev/urandom", "rb")) == NULL) {
        fprintf(stderr, "There was a problem opening urandom.\n");
        exit(-1);
    }

    for (int i=0; i < num_tests; i++) {
        do {
            fread(random_byte, sizeof(random_byte), 1, f);
        } while (*random_byte == 0xFF);

        // byte between 0x00 and 0x54
        if (*random_byte <= 0x54) {
            cnt1 ++;
        // byte between 0x55 and 0xA9
        } else if (*random_byte <= 0xA9) {
            cnt2 ++;
        // byte between 0xAA and 0xFE
        } else {
            cnt3 ++;
        }

        print_byte(random_byte);

        total = cnt1 + cnt2 + cnt3;
        printf("1:%lf 2:%lf 3:%lf\n", (double)cnt1/total, (double)cnt2/total, (double)cnt3/total); 
    }
    fclose(f);
}
