#include <iostream>
#include <string>
#include <cctype>
#include <random>
using namespace std;

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(1, 100);
   

    cout << "Press any key or Q for quit: " << endl;
    string input;
    while (getline(cin, input) && input != "Q") {
        // Game parameters
        int attemptCount = 5;
        int wastedAttempt = 0; 
        int currentNum;

        cout << "Let's Play" << endl;
        cout << "You must write num from 1 to 100" << endl;
        cout << "You have only " << attemptCount << " attempt" << endl;
        cout << "Good Luck" << endl;
        
        currentNum = random(gen);

        while(wastedAttempt < attemptCount){
            cout << "Attempt number " << wastedAttempt + 1 << ":";
            int selectNum; cin >> selectNum;
            if (cin.fail() || selectNum < 1 || selectNum > 100) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please, write num from 1 to 100" << endl;
                continue;
            }

            wastedAttempt++;
            if (selectNum == currentNum)
            {
                cout << "You are win!" << endl;
                cout << "Wasted attempt: " << wastedAttempt << endl;
                break;
            }
        }
        if (wastedAttempt >= attemptCount)
            cout << "You are Lost" << endl;
        input.clear();
        cout << "Press any key or Q for quit: " << endl;
        getline(cin, input);
    }

    cout << "Good Bye";
}
