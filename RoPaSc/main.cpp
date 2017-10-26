#include <iostream>

using namespace std;

void game();
int win, loss, tie;
char menu;
int player;

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
    return 0;
}

void game() {
    getchar();
    cout << "Ready?" << endl;
    getchar();
    cout << "Rock, Paper, Scissors..." << endl;

}