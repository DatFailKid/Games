#include <iostream>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_GREY "\x1b[37m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_TEXT_BOLD     "\x1b[1m"

using namespace std;

void mainmenu();

void game();
void set();
void help();
void stat();

int win, loss, tie;
char menu;

bool normal=true, hard=false, impossible=false, simpossible=false;

char player;
char rock='a';
char paper='s';
char scissors='d';

int bot;
int chance;
int brock=0;
int bpaper=1;
int bscissors=2;

int main() {
    cout << ANSI_TEXT_BOLD ANSI_COLOR_RED"DatFailKid";
    cout << ANSI_COLOR_RESET" Presents..." << endl;
    getchar();
    mainmenu();
}
void mainmenu() {
    cout << ANSI_TEXT_BOLD"Rock Paper Scissors!" << endl;
    cout << ANSI_COLOR_RESET"Play         (a)"
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
}

void game() {
    getchar();
    cout << ANSI_COLOR_RESET"Ready?" << endl;
    getchar();
    srand (time(NULL));
    cout << "Rock, Paper, Scissors..." << endl;
    cin >> player;
    if (normal) {
        bot=rand()%3;
    }
    if (hard) {
        if (player==rock) {
            chance=rand()%3;
            if (chance==0 || chance==1) {
                bot=rand()%3;
            }
            if (chance==2) {
                bot=bpaper;
            }
        }
        if (player==paper) {
            chance=rand()%3;
            if (chance==0 || chance==1) {
                bot=rand()%3;
            }
            if (chance==2) {
                bot=bscissors;
            }
        }
        if (player==scissors) {
            chance=rand()%3;
            if (chance==0 || chance==1) {
                bot=rand()%3;
            }
            if (chance==2) {
                bot=brock;
            }
        }
    }
    if (impossible) {
        if (player==rock) {
            chance=rand()%3;
            if (chance==0) {
                bot=rand()%3;
            }
            if (chance==2 || chance==1) {
                bot=bpaper;
            }
        }
        if (player==paper) {
            chance=rand()%3;
            if (chance==0) {
                bot=rand()%3;
            }
            if (chance==2 || chance==1) {
                bot=bscissors;
            }
        }
        if (player==scissors) {
            chance=rand()%3;
            if (chance==0) {
                bot=rand()%3;
            }
            if (chance==2 || chance==1) {
                bot=brock;
            }
        }
    }
    if (simpossible) {
        if (player==rock) {
            bot=bpaper;
        }
        if (player==paper) {
            bot=bscissors;
        }
        if (player==scissors) {
            bot=brock;
        }
    }
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
            mainmenu();
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
            mainmenu();
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
            mainmenu();
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
            mainmenu();
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
            mainmenu();
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
            mainmenu();
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
            mainmenu();
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
            cout << ANSI_COLOR_RESET"I'm assuming you mean 'no'" << endl;
            getchar();
            mainmenu();
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
            mainmenu();
        }
    }
    if (player!=scissors && player!=paper &&player!=rock) {
        getchar();
        cout << ANSI_COLOR_RESET"That is not a valid choice." << endl;
        getchar();
        return game();
    }
}

void set() {
    cout << ANSI_TEXT_BOLD"SETTINGS" << endl;
    cout << ANSI_COLOR_RESET"Reset                   (a)" << endl;
    cout << "Set choices             (s)" << endl;
    cout << "Set Computer Difficulty (d)" << endl;
    cout << "Return to menu          (q)" << endl;
    cin >> menu;
    if (menu=='a') {
        cout << ANSI_TEXT_BOLD"[SETTINGS]"
                "\n    > Reset " << endl;
        cout << ANSI_COLOR_RESET"What do you want to reset?" << endl;
        cout << "Choice Controls   (a)" << endl;
        cout << "Stats             (s)" << endl;
        cout << "Choices and Stats (d)" << endl;
        cout << "Exit 'Reset'      (q)" << endl;
        cin >> menu;
        if (menu=='a') {
            cout << ANSI_TEXT_BOLD"[SETTINGS]"
                    "\n     > [RESET]"
                    "\n         > Sure?" << endl;
            cout << ANSI_COLOR_RESET"Are you sure you want to reset your"
                    "\nchoice controls to default? (y/n)" << endl;
            cin >> menu;
            if (menu=='y') {
                rock='a', paper='s', scissors='d';
                if (rock=='a' && paper=='s' && scissors=='d') {
                    getchar();
                    cout << ANSI_TEXT_BOLD"[SETTINGS]"
                            "\n     > [RESET]"
                            "\n         > [SURE?]"
                            "\n             > Controls reset" << endl;
                    cout << ANSI_COLOR_RESET"Controls reset!" << endl;
                    getchar();
                    return set();
                }
            }
            if (menu!='y') {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n     > [RESET]"
                        "\n         > [SURE?]"
                        "\n             > Controls reset Cancelled" << endl;
                cout << ANSI_COLOR_RESET"Your Controls have not been reset" << endl;
                getchar();
                return set();
            }
        }
        if (menu=='s') {
            cout << ANSI_TEXT_BOLD"[SETTINGS]"
                    "\n     > [RESET]"
                    "\n         > Sure?" << endl;
            cout << ANSI_COLOR_RESET"Are you sure you want to reset your"
                    "\nstats? (y/n)" << endl;
            cin >> menu;
            if (menu=='y') {
                win=0, loss=0, tie=0;
                if (win==0 && loss==0 && tie==0) {
                    getchar();
                    cout << ANSI_TEXT_BOLD"[SETTINGS]"
                            "\n     > [RESET]"
                            "\n         > [SURE?]"
                            "\n             > Stats reset" << endl;
                    cout << ANSI_COLOR_RESET"Stats reset!" << endl;
                    getchar();
                    return set();
                }
            }
            if (menu!='y') {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n     > [RESET]"
                        "\n         > [SURE?]"
                        "\n             > Stats reset Cancelled" << endl;
                cout << ANSI_COLOR_RESET"Your Stats have not been reset" << endl;
                getchar();
                return set();
            }
        }
        if (menu=='d') {
            cout << ANSI_TEXT_BOLD"[SETTINGS]"
                    "\n     > [RESET]"
                    "\n         > Sure?" << endl;
            cout << ANSI_COLOR_RESET"Are you sure you want to reset your"
                    "\nStats AND set your choice controls to default? (y/n)" << endl;
            cin >> menu;
            if (menu=='y') {
                rock='a', paper='s', scissors='d';
                tie=0, win=0, loss=0;
                if (rock=='a' && paper=='s' && scissors=='d' & tie==0 && loss==0 && win==0) {
                    getchar();
                    cout << ANSI_TEXT_BOLD"[SETTINGS]"
                            "\n     > [RESET]"
                            "\n         > [SURE?]"
                            "\n             > reset Complete" << endl;
                    cout << ANSI_COLOR_RESET"Controls and Stats reset!" << endl;
                    getchar();
                    return set();
                }
            }
            if (menu!='y') {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS]"
                        "\n     > [RESET]"
                        "\n         > [SURE?]"
                        "\n             > Reset Cancelled" << endl;
                cout << ANSI_COLOR_RESET"Your Controls and Stats have not been reset" << endl;
                getchar();
                return set();
            }
        }
        if (menu=='q') {
            return set();
        }
    }
    if (menu=='q') {
        cout << "Returning to Menu..." << endl;
        mainmenu();
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
    if (menu=='d') {
        cout << ANSI_TEXT_BOLD"[SETTINGS] "
                "\n     > Computer Difficulty" << endl;
        cout << ANSI_COLOR_RESET"What do you want the computer's difficulty to be set to?" << endl;
        if (normal && !hard && !impossible && !simpossible) {
            cout << "The difficulty is already set to 'Normal'" << endl;
        }
        if (!normal && hard && !impossible && !simpossible) {
            cout << "The difficulty is already set to 'Hard'" << endl;
        }
        if (!normal && !hard && impossible && !simpossible) {
            cout << "The difficulty is already set to 'Impossible'" << endl;
        }
        if (!normal && !hard && !impossible && simpossible) {
            cout << "The difficulty is already set to 'Super Impossible'" << endl;
        }
        cout << "Normal      (a)"
                "\nHard        (s)"
                "\nImpossible  (d)" << endl;
        cout << "Exit 'Computer"
                "\nDifficulty' (q)" << endl;
        cin >> menu;
        if (menu=='a') {
            cout << ANSI_TEXT_BOLD"[SETTINGS] "
                    "\n     > [Computer Difficulty]"
                    "\n         > Normal?" << endl;
            cout << ANSI_COLOR_RESET"Normal: The Computer randomly picks"
                    "\nRock, Paper, or Scissors" << endl;
            cout << "Are you sure you want to set the computer's difficulty to 'Normal'? (y/n)" << endl;
            cin >> menu;
            if (menu=='y') {
                getchar();
                normal=true;
                hard=false;
                impossible=false;
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n     > [Computer Difficulty]"
                        "\n         > [Normal?]"
                        "\n             > Difficulty changed!" << endl;
                cout << ANSI_COLOR_RESET"The difficulty has been changed to 'Normal'" << endl;
                getchar();
                return set();
            }
            if (menu!='y') {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n     > [Computer Difficulty]"
                        "\n         > [Normal?]"
                        "\n             > Change cancelled" << endl;
                cout << ANSI_COLOR_RESET"Difficulty change cancelled" << endl;
                getchar();
                return set();
            }
        }
        if (menu=='s') {
            cout << ANSI_TEXT_BOLD"[SETTINGS] "
                    "\n     > [Computer Difficulty]"
                    "\n         > Hard?" << endl;
            cout << ANSI_COLOR_RESET"Hard: The Computer is slightly more "
                    "\ninclined to pick whatever can defeat"
                    "\nyour choice" << endl;
            cout << "Are you sure you want to set the computer's difficulty to 'Hard'? (y/n)" << endl;
            cin >> menu;
            if (menu=='y') {
                getchar();
                normal=false;
                hard=true;
                impossible=false;
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n     > [Computer Difficulty]"
                        "\n         > [Hard?]"
                        "\n             > Difficulty changed!" << endl;
                cout << ANSI_COLOR_RESET"The difficulty has been changed to 'Hard'" << endl;
                getchar();
                return set();
            }
            if (menu!='y') {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n     > [Computer Difficulty]"
                        "\n         > [Hard?]"
                        "\n             > Change cancelled" << endl;
                cout << ANSI_COLOR_RESET"Difficulty change cancelled" << endl;
                getchar();
                return set();
            }
        }
        if (menu=='d') {
            cout << ANSI_TEXT_BOLD"[SETTINGS] "
                    "\n     > [Computer Difficulty]"
                    "\n         > Impossible?" << endl;
            cout << ANSI_COLOR_RESET"Impossible: The Computer is more inclined"
                    "\nto pick whatever can defeat your"
                    "\nchoice" << endl;
            cout << "Are you sure you want to set the computer's difficulty to 'Impossible'? (y/n)" << endl;
            cin >> menu;
            if (menu=='y') {
                getchar();
                normal=false;
                hard=false;
                impossible=true;
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n     > [Computer Difficulty]"
                        "\n         > [Impossible?]"
                        "\n             > Difficulty changed!" << endl;
                cout << ANSI_COLOR_RESET"The difficulty has been changed to 'Impossible'" << endl;
                getchar();
                cout << "Good Luck, you're gonna need it." << endl;
                getchar();
                return set();
            }
            if (menu!='y') {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n     > [Computer Difficulty]"
                        "\n         > [Impossible?]"
                        "\n             > Change cancelled" << endl;
                cout << ANSI_COLOR_RESET"Difficulty change cancelled" << endl;
                getchar();
                return set();
            }
        }
        if (menu=='f') {
            cout << ANSI_TEXT_BOLD"[SETTINGS] "
                    "\n     > [Computer Difficulty]"
                    ANSI_COLOR_RED ANSI_TEXT_BOLD"\n         > Super Impossible?!" << endl;
            cout << ANSI_COLOR_RESET"Super Impossible: If you win, you hacked"
                    "\nthe game" << endl;
            cout << "Are you sure you want to set the computer's difficulty to 'Super Impossible'?! (y/n)" << endl;
            cin >> menu;
            if (menu=='y') {
                getchar();
                normal=false;
                hard=false;
                impossible=false;
                simpossible=true;
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n     > [Computer Difficulty]"
                        ANSI_COLOR_RED ANSI_TEXT_BOLD"\n         > [Super Impossible?!]"
                        ANSI_COLOR_RESET ANSI_TEXT_BOLD"\n             > Difficulty changed!" << endl;
                cout << ANSI_COLOR_RESET"The difficulty has been changed to 'Super Impossible'" << endl;
                getchar();
                cout << "Don't come crying to me if you lose!" << endl;
                getchar();
                return set();
            }
            if (menu!='y') {
                getchar();
                cout << ANSI_TEXT_BOLD"[SETTINGS] "
                        "\n     > [Computer Difficulty]"
                        ANSI_COLOR_RED ANSI_TEXT_BOLD"\n         > [Super Impossible?]"
                        ANSI_COLOR_RESET ANSI_TEXT_BOLD"\n             > Change cancelled" << endl;
                cout << ANSI_COLOR_RESET"Difficulty change cancelled. Smart move." << endl;
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
    cout << ANSI_TEXT_BOLD"HELP" << endl;
    cout << ANSI_COLOR_RESET"'Rock, Paper, Scissors' works the same"
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
    mainmenu();
}

void stat() {
    getchar();
    cout << ANSI_TEXT_BOLD"STATS" << endl;
    cout << ANSI_COLOR_RESET"Wins:   " << win << endl;
    cout << "Losses: " << loss << endl;
    cout << "Ties:   " << tie << endl;
    cout << "Press 'Enter' to return to the Main Menu" << endl;
    getchar();
    mainmenu();
}