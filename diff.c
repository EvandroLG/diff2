#include <stdio.h>
#include <string.h>

#define LIMIT 100
#define MAX_LINES 10

int get_lines(char string[], char lines[][LIMIT]) {
    int c;
    int i = 0;
    int size_lines = 0;
    int k = 0;

    while ((c = string[i]) != 0) {
        if (c == '\n') {
            lines[size_lines][k] = 0;
            size_lines++;
            k = 0;
        } else {
            lines[size_lines][k] = c;
            k++;
        }

        i++;
    }

    return size_lines;
}

void diff(char first_file[], char second_file[]) {
    char lines_first[MAX_LINES][LIMIT];
    int size = get_lines(first_file, lines_first);

    char lines_second[MAX_LINES][LIMIT];
    get_lines(second_file, lines_second);

    for (int i = 0; i < size; i++) {
        if (strcmp(lines_first[i], lines_second[i]) != 0) {
            printf("line %i\n", (i+1));
            printf("< %s\n", lines_first[i]);
            printf("> %s\n", lines_second[i]);
        }
    }
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
