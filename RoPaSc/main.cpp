#include <iostream>

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
    cout << "Rock Paper Scissors!" << endl;
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
    cout << "Ready?" << endl;
    getchar();
    srand (time(NULL));
    cout << "Rock, Paper, Scissors..." << endl;
    cin >> player;
    bot=rand()%3;
    cout << player << endl;
    cout << bot << endl;
    if (player==rock && bot==brock) {
        cout << "Shoot!" << endl;
        getchar();
        cout << "Rock | Rock" << endl;
        getchar();
        cout << "It's a tie!" << endl;
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
    cout << "SETTINGS" << endl;
    cout << "Reset Stats (a)" << endl;
    cout << "Return to menu (q)" << endl;
    cin >> menu;
    if (menu=='a') {
        cout << "[SETTINGS] > Reset Stats" << endl;
        cout << "Are you sure you want to reset your Stats? (y/n)" << endl;
        cin >> menu;
        if (menu=='y') {
            win=0;
            loss=0;
            tie=0;
            if (win==0 && loss==0 && tie==0) {
                cout << "Your stats have been reset" << endl;
                return set();
            }
        }
        if (menu=='n') {
            cout << "Stat reset cancelled" << endl;
            return set();
        }
        if (menu!='y' && menu!='n') {
            cout << "I do not know what that means..." << endl;
            return set();
        }
    }
    if (menu=='q') {
        cout << "Returning to Menu..." << endl;
        main();
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
    cout << "STATS" << endl;
    cout << "Wins:   " << win << endl;
    cout << "Losses: " << loss << endl;
    cout << "Ties:   " << tie << endl;
    cout << "Press 'Enter' to return to the Main Menu" << endl;
    getchar();
    main();
}