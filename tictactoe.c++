#include<iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string n1,n2;

int row, column; 
char token = 'x';
bool tie = false;

void fun1() {
    cout << "   |   |   \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " \n";
    cout << "   |   |   \n";
}

void fun2() {
    int digit;

    if (token == 'x') {
        cout << n1 << " please enter position: ";
        cin >> digit;
    } else if (token == 'o') {
        cout << n2 << " please enter position: ";
        cin >> digit;
    }

    // Map the digit to a row and column
    switch (digit)
    {
    case 1: row=0;column=0;
            break;
    case 2: row=0;column=1;
            break;
    case 3: row=0;column=2;
            break;
    case 4: row=1;column=0;
            break;
    case 5: row=1;column=1;
            break;
    case 6: row=1;column=2;
            break;
    case 7: row=2;column=0;
            break;
    case 8: row=2;column=1;
            break;
    case 9: row=2;column=2;
            break;
    default:cout<<"Invalid input..\nEnter values 1 to 9 only..!";
            fun2();
            return;
    }

    // Check if the selected spot is available
    if (space[row][column] != 'x' && space[row][column] != 'o') {
        space[row][column] = token;
        token = (token == 'x') ? 'o' : 'x';
    } else {
        cout << "The spot is already occupied!\n";
        fun2();
    }
}

bool fun3() {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }

    // Check diagonals for a win
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || 
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != 'o') {
                return false; // Game is still going on
            }
        }
    }
    
    tie = true;
    return true;
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);

    cout << n1 << " is player 1 and will play first.\n";
    cout << n2 << " is player 2 and will play second.\n";

    while (!fun3()) {
        fun1();
        fun2();
    }

    fun1(); // Print the final state of the board

    if (tie) {
        cout << "It's a draw!\n";
    } else if (token == 'x') {
        cout << n2 << " wins!\n"; // If token is 'x', it means 'o' made the winning move
    } else {
        cout << n1 << " wins!\n"; // If token is 'o', it means 'x' made the winning move
    }

    return 0;
}
