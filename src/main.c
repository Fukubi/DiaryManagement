#include <stdio.h>

#include <ncursesw/curses.h>

#include "diary_database.h"
#include "diarylog.h"

#define EXIT_OPTION 0
#define ADD_TO_DIARY_OPTION 1
#define LIST_DIARY_LOGS_OPTION 2

void createOption(const char *label, int isSelected)
{
    if (!isSelected)
        printw(label);
    else
    {
        attron(A_BOLD);
        printw("> ");
        attron(A_UNDERLINE);
        printw(label);
        attroff(A_UNDERLINE);
        attroff(A_BOLD);
    }
}

int main(int argc, char *argv[])
{
    int option = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);

    while (1)
    {
        int keyPressed;

        refresh();

        printw("=======================\n");
        printw("Diary Management System\n");
        printw("=======================\n\n");

        createOption("Exit\n", option == EXIT_OPTION);
        createOption("Add to diary\n", option == ADD_TO_DIARY_OPTION);
        createOption("List diary logs\n", option == LIST_DIARY_LOGS_OPTION);

        keyPressed = getch();

        if (keyPressed == KEY_DOWN && option + 1 <= LIST_DIARY_LOGS_OPTION)
            option++;
        else if (keyPressed == KEY_UP && option - 1 >= EXIT_OPTION)
            option--;
        
        if (keyPressed == '\n')
        {
            if (option == EXIT_OPTION)
                break;
            if (option == ADD_TO_DIARY_OPTION)
            {
                diaryLog logToAdd = { "", "" };

                echo();
                clear();

                printw("Time of the log: ");

                scanw("%9[^\n]s", logToAdd.time);
                setbuf(stdin, NULL);

                printw("Log: ");
                scanw("%254[^\n]s", logToAdd.diaryLog);

                noecho();

                addDiaryLog(logToAdd);
            }
            if (option == LIST_DIARY_LOGS_OPTION)
                readDiaryLogs();
        }

        clear();
    }

    endwin();
    return 0;
}