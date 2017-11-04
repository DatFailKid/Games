#include <iostream>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_GREY "\x1b[37m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_TEXT_BOLD     "\x1b[1m"

using namespace std;

void game();
void set();
void help();
void stat();

int win, loss, tie;
char menu;

char player;
char rock='a';
char paper='s';
char scissors='d';

int bot;
int brock=0;
int bpaper=1;
int bscissors=2;

int main() {
    cout << ANSI_COLOR_RESET"Rock Paper Scissors!" << endl;
    cout << "Play         (a)"
            "\nSettings     (s)"
            "\nInstructions (d)"
            "\nStats        (w)" << endl;
    cin >> menu;
    if (menu=='a') {
        cout << "Loading Game..." << endl;
        game();
    }
    if (menu=='s') {
        cout << "Opening Settings..." << endl;
        set();
    }
    if (menu=='d') {
        cout << "Getting Help..." << endl;
        help();
    }
    if (menu=='w') {
        cout << "Getting Stats..." << endl;
        stat();
    }
    return 0;
}

void game() {
    getchar();
    cout << ANSI_COLOR_RESET"Ready?" << endl;
    getchar();
    srand (time(NULL));
    cout << "Rock, Paper, Scissors..." << endl;
    cin >> player;
    bot=rand()%3;
    if (player==rock && bot==brock) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Rock | Rock" << endl;
        getchar();
        cout << ANSI_COLOR_GREY"It's a tie!" << endl;
        tie=tie+1;
        cout << "Play again? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            return game();
        }
        if (menu!='y') {
            cout << "I'm assuming you mean 'no'" << endl;
            getchar();
            main();
        }
    }
    if (player==rock && bot==bpaper) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Rock | Paper" << endl;
        getchar();
        cout << ANSI_COLOR_RED"You lost!" << endl;
        loss=loss+1;
        cout << "Play again? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            return game();
        }
        if (menu!='y') {
            cout << "I'm assuming you mean 'no'" << endl;
            getchar();
            main();
        }
    }
    if (player==rock && bot==bscissors) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Rock | Scissors" << endl;
        getchar();
        cout << ANSI_COLOR_GREEN"You won!" << endl;
        win=win+1;
        cout << "Play again? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            return game();
        }
        if (menu!='y') {
            cout << "I'm assuming you mean 'no'" << endl;
            getchar();
            main();
        }
    }
    if (player==paper && bot==bscissors) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Paper | Scissors" << endl;
        getchar();
        cout << ANSI_COLOR_RED"You lost!" << endl;
        loss=loss+1;
        cout << "Play again? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            return game();
        }
        if (menu!='y') {
            cout << "I'm assuming you mean 'no'" << endl;
            getchar();
            main();
        }
    }
    if (player==paper && bot==bpaper) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Paper | Paper" << endl;
        getchar();
        cout << ANSI_COLOR_GREY"It's a tie!" << endl;
        tie=tie+1;
        cout << "Play again? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            return game();
        }
        if (menu!='y') {
            cout << "I'm assuming you mean 'no'" << endl;
            getchar();
            main();
        }
    }
    if (player==paper && bot==brock) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Paper | Rock" << endl;
        getchar();
        cout << ANSI_COLOR_GREEN"You won!" << endl;
        win=win+1;
        cout << "Play again? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            return game();
        }
        if (menu!='y') {
            cout << "I'm assuming you mean 'no'" << endl;
            getchar();
            main();
        }
    }
    if (player==scissors && bot==brock) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Scissors | Rock" << endl;
        getchar();
        cout << ANSI_COLOR_RED"You lost!" << endl;
        loss=loss+1;
        cout << "Play again? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            return game();
        }
        if (menu!='y') {
            cout << "I'm assuming you mean 'no'" << endl;
            getchar();
            main();
        }
    }
    if (player==scissors && bot==bpaper) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Scissors | Paper" << endl;
        getchar();
        cout << ANSI_COLOR_GREEN"You won!" << endl;
        win=win+1;
        cout << "Play again? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            return game();
        }
        if (menu!='y') {
            cout << "I'm assuming you mean 'no'" << endl;
            getchar();
            main();
        }
    }
    if (player==scissors && bot==bscissors) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Scissors | Scissors" << endl;
        getchar();
        cout << ANSI_COLOR_GREY"It's a tie!" << endl;
        tie=tie+1;
        cout << "Play again? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            return game();
        }
        if (menu!='y') {
            cout << "I'm assuming you mean 'no'" << endl;
            getchar();
            main();
        }
    }
}

void set() {
    cout << ANSI_TEXT_BOLD"SETTINGS" << endl;
    cout << ANSI_COLOR_RESET"Reset Stats    (a)" << endl;
    cout << "Set choices    (s)" << endl;
    cout << "Return to menu (q)" << endl;
    cin >> menu;
    if (menu=='a') {
        cout << ANSI_TEXT_BOLD"[SETTINGS]"
                "\n    > Reset Stats" << endl;
        cout << ANSI_COLOR_RESET"Are you sure you want to reset your Stats? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            win=0;
            loss=0;
            tie=0;
            if (win==0 && loss==0 && tie==0) {
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n    > [Reset Stats]"
                        "\n        > Yes" << endl;
                cout << ANSI_COLOR_RESET"Your stats have been reset" << endl;
                return set();
            }
        }
        if (menu=='n') {
            cout << ANSI_TEXT_BOLD"[SETTINGS]"
                    "\n    > [Reset Stats]"
                    "\n        > No" << endl;
            cout << ANSI_COLOR_RESET"Stat reset cancelled" << endl;
            return set();
        }
        if (menu!='y' && menu!='n') {
            cout << ANSI_TEXT_BOLD"[SETTINGS]"
                    "\n    > [Reset Stats]"
                    "\n        > No?" << endl;
            cout << ANSI_COLOR_RESET"I do not know what that means..." << endl;
            return set();
        }
    }
    if (menu=='q') {
        cout << "Returning to Menu..." << endl;
        main();
    }
    if (menu=='s') {
        cout << ANSI_TEXT_BOLD"[SETTINGS]"
                "\n    > Set choices" << endl;
        cout << ANSI_COLOR_RESET"Which would you like to change?" << endl;
        cout << "Rock               (a)" << endl;
        cout << "Paper              (s)" << endl;
        cout << "Scissors           (d)" << endl;
        cout << "Exit 'Set choices' (q)" << endl;
        cin >> menu;
        if (menu=='a') {
            cout << ANSI_TEXT_BOLD"[SETTINGS]"
                    "\n    > [Set choices]"
                    "\n        > Rock" << endl;
            cout << ANSI_COLOR_RESET"Rock is currently set to '" << rock << "'" << endl;
            cout << ANSI_COLOR_RESET"Scissors is currently set to '" << scissors << "'" << endl;
            cout << ANSI_COLOR_RESET"Paper is currently set to '" << paper << "'" << endl;
            cout << "Press a key to set as 'Rock'" << endl;
            cin >> rock;
            if (rock==paper) {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n    > [Set choices]"
                        "\n        > [Rock]"
                        "\n            > Whoops!" << endl;
                cout << ANSI_COLOR_RESET"Paper has that same key!" << endl;
                rock=' ';
                cout << "Rock has been disabled" << endl;
                getchar();
                return set();
            }
            if (rock==scissors) {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n    > [Set choices]"
                        "\n        > [Rock]"
                        "\n            > Whoops!" << endl;
                cout << ANSI_COLOR_RESET"Scissors has that same key!" << endl;
                rock=' ';
                cout << "Rock has been disabled" << endl;
                getchar();
                return set();
            }
            else {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n    > [Set choices]"
                        "\n        > [Rock]"
                        "\n            > Change Successful!" << endl;
                cout << ANSI_COLOR_RESET"Rock has been set to '" << rock << "'" << endl;
                getchar();
                return set();
            }
        }
        if (menu=='s') {
            cout << ANSI_TEXT_BOLD"[SETTINGS]"
                    "\n    > [Set choices]"
                    "\n        > Paper" << endl;
            cout << ANSI_COLOR_RESET"Paper is currently set to '" << paper << "'" << endl;
            cout << ANSI_COLOR_RESET"Scissors is currently set to '" << scissors << "'" << endl;
            cout << ANSI_COLOR_RESET"Rock is currently set to '" << rock << "'" << endl;
            cout << "Press a key to set as 'Paper'" << endl;
            cin >> paper;
            if (paper==rock) {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n   > [Set choices]"
                        "\n       > [Paper]"
                        "\n           > Whoops!" << endl;
                cout << ANSI_COLOR_RESET"Rock has that same key!" << endl;
                paper=' ';
                cout << "Paper has been disabled" << endl;
                getchar();
                return set();
            }
            if (paper==scissors) {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n   > [Set choices]"
                        "\n       > [Paper]"
                        "\n           > Whoops!" << endl;
                cout << ANSI_COLOR_RESET"Scissors has that same key!" << endl;
                paper=' ';
                cout << "Paper has been disabled" << endl;
                getchar();
                return set();
            }
            else {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n    > [Set choices]"
                        "\n        > [Paper]"
                        "\n           > Change Successful!" << endl;
                cout << ANSI_COLOR_RESET"Paper has been set to '" << paper << "'" << endl;
                getchar();
                return set();
            }
        }
        if (menu=='d') {
            cout << ANSI_TEXT_BOLD"[SETTINGS] "
                    "\n   > [Set choices] "
                    "\n       > Scissors" << endl;
            cout << ANSI_COLOR_RESET"Scissors is currently set to '" << scissors << "'" << endl;
            cout << ANSI_COLOR_RESET"Rock is currently set to '" << rock << "'" << endl;
            cout << ANSI_COLOR_RESET"Paper is currently set to '" << paper << "'" << endl;
            cout << "Press a key to set as 'Scissors'" << endl;
            cin >> scissors;
            if (scissors==rock) {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n   > [Set choices]"
                        "\n       > [Scissors] "
                        "\n           > Whoops!" << endl;
                cout << ANSI_COLOR_RESET"Rock has that same key!" << endl;
                scissors=' ';
                cout << "Scissors has been disabled" << endl;
                getchar();
                return set();
            }
            if (scissors==paper) {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n   > [Set choices] "
                        "\n       > [Scissors] "
                        "\n          > Whoops!" << endl;
                cout << ANSI_COLOR_RESET"Paper has that same key!" << endl;
                scissors=' ';
                cout << "Scissors has been disabled" << endl;
                getchar();
                return set();
            }
            else {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n   > [Set choices] "
                        "\n       > [Scissors] "
                        "\n           > Change Successful!" << endl;
                cout << ANSI_COLOR_RESET"Scissors has been set to '" << scissors << "'" << endl;
                getchar();
                return set();
            }
        }
        if (menu=='q') {
            return set();
        }
    }
}

void help() {
    cout << "HELP" << endl;
    cout << "'Rock, Paper, Scissors' works the same"
            "\nway the game works in real life" << endl;
    getchar();
    cout << "To choose one, pick 'Rock', 'Paper', or"
            "\n'Scissors' by entering 'a', 's', or"
            "\n'd' (Or whatever letters you assigned"
            "\neach choice in the Settings)" << endl;
    getchar();
    cout << "The bot will then pick an option as well." << endl;
    getchar();
    cout << "Your wins, losses, and ties will be"
            "\ncounted up, and can be viewed in the"
            "\n'Stats' menu." << endl;
    getchar();
    cout << "Unfortunately, until DatFailKid adds the"
            "\nability for the stats to be saved on"
            "\nthe computer, your stats will be reset"
            "\nwhen you exit the game." << endl;
    getchar();
    main();
}

void stat() {
    getchar();
    cout << "STATS" << endl;
    cout << "Wins:   " << win << endl;
    cout << "Losses: " << loss << endl;
    cout << "Ties:   " << tie << endl;
    cout << "Press 'Enter' to return to the Main Menu" << endl;
    getchar();
    main();
}