#include <stdio.h>

void diff(char first_file[], char second_file[]) {
    
}

void get_content(FILE *file, char file_content[]) {
    int c;
    int i = 0;

    while ((c = getc(file)) != EOF) {
        file_content[i] = c;
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("diff: Insufficient parameters\n"); 
        return 1;
    }
    
    if (argc > 3) {
        printf("diff: Extra parameters\n");
        return 1;
    }

    int i = 0;
    const int LIMIT = 100;
    char file_contents[2][LIMIT];
    FILE *file;

    while (--argc > 0) {
        file = fopen(*++argv, "r");

        if (file == NULL) {
            printf("diff: Can't open %s\n", *argv);
            return 1;
        }

        get_content(file, file_contents[i]);
        fclose(file);
        i++;
    }

    diff(file_contents[0], file_contents[1]);

    return 0;
}
