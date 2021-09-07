#include "diary_database.h"

#include <ncursesw/curses.h>

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX_BUFFER_SIZE 255
#define DIARY_DB_FILENAME "diary.txt"

void addDiaryLog(diaryLog diaryLogToAdd)
{
    FILE *diaryFile;
    diaryFile = fopen(DIARY_DB_FILENAME, "a");

    if (diaryFile == NULL)
    {
        endwin();

        fprintf(stderr, "File %s don't exists\n", DIARY_DB_FILENAME);
        exit(1);
    }

    fprintf(diaryFile, "TIME: %s\n", diaryLogToAdd.time);
    fprintf(diaryFile, "%s\n\n", diaryLogToAdd.diaryLog);

    fclose(diaryFile);
}

void readDiaryLogs(void)
{
    char buff[MAX_BUFFER_SIZE];
    FILE *diaryFile;
    diaryFile = fopen(DIARY_DB_FILENAME, "r");

    if (diaryFile == NULL)
    {
        endwin();

        fprintf(stderr, "File %s don't exists\n", DIARY_DB_FILENAME);
        exit(1);
    }

    clear();
    refresh();

    while (fgets(buff, MAX_BUFFER_SIZE, diaryFile) != NULL)
    {  
        refresh();
        printw("%s", buff);
    }

    printw("\nPress any key to continue...\n");
    getch();

    clear();

    fclose(diaryFile);
}