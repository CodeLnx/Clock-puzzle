#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

string getCurrentTime() {
    time_t currentTime = time(0);
    tm *localTime = localtime(&currentTime);
    char timeString[10];
    snprintf(timeString, sizeof(timeString), "%02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    return string(timeString);
}

void displayClock(int level) {
    string time = getCurrentTime();
    if (level == 1) {
        cout << "\033[1;32m" << "Clock (Level 1): " << time << "\033[0m" << endl;
    } else if (level == 2) {
        cout << "\033[1;34m" << "Clock (Level 2): " << time << "\033[0m" << endl;
    } else if (level == 3) {
        cout << "\033[1;31m" << "Clock (Level 3): " << time << "\033[0m" << endl;
    }
}

bool checkPuzzleAnswer(int level) {
    string answer;
    if (level == 1) {
        cout << "Puzzle 1: What is 2 + 2? ";
        cin >> answer;
        return answer == "4";
    } else if (level == 2) {
        cout << "Puzzle 2: What is the capital of France? ";
        cin >> answer;
        return answer == "Paris" || answer == "paris";
    } else if (level == 3) {
        cout << "Puzzle 3: Spell 'programming' backward: ";
        cin >> answer;
        return answer == "gnimmargorp";
    }
    return false;
}

int main() {
    int level = 1;
    bool puzzleSolved = false;

    while (level <= 3) {
        system("clear");
        displayClock(level);
        cout << "\nSolve the puzzle to progress to the next level.\n";

        puzzleSolved = checkPuzzleAnswer(level);

        if (puzzleSolved) {
            cout << "\nCorrect! Moving to Level " << level + 1 << "...\n";
            this_thread::sleep_for(chrono::seconds(2));
            level++;
        } else {
            cout << "\nWrong answer! Try again.\n";
            this_thread::sleep_for(chrono::seconds(2));
        }
    }

    cout << "\n🎉 Congratulations! You completed all levels! 🎉\n";
    return 0;
}
