#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include <algorithm>
using namespace std;
string toLower(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
int main()
{
    int times;
    std::cout << "Enter number of matches to play" << endl;
    std::cout << "ODD NUMBER ONLY!";
    while (true)
    {
        cin >> times;
        if (times % 2!= 0)
            break;
        cout << "ODD NUMBER ONLY!";
    }
    int user_count = 0;
    int computer_count = 0;
    while (times--)
    {
        string user_input;
        cout << "Starting rock-paper-scissors game" << endl;
        cout << "Enter you choice (rock/paper/scissors):  ";
        cin >> user_input;
        string outcomes[3] = {"rock", "paper", "scissors"};
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 2);
        int random = dis(gen);
        string computer_input = outcomes[random];
        cout << "Computer's choice- " << computer_input;

        user_input = toLower(user_input);
        if (user_input == computer_input)
            cout << "Its a draw" << endl;
        else if ((user_input == "rock" && computer_input == "paper") || (user_input == "paper" && computer_input == "scissors") || (user_input == "scissors" && computer_input == "rock"))
        {
            cout << "Computer win" << endl;
            computer_count++;
        }
        else if ((user_input == "paper" && computer_input == "rock") || (user_input == "scissors" && computer_input == "paper") || (user_input == "rock" && computer_input == "scissors"))
        {
            cout << "You win" << endl;
            user_count++;
        }
        else
        {
            std::cout << "INVALID INPUT!";
        }
    }
    cout << "FINAL SCORE::" << endl;
    std::cout << "Your score : " << user_count << endl
              << "Computer's score : " << computer_count;
    if (user_count > computer_count)
    {
        cout << "YOU WIN!!";
    }
    else
    {
        cout << "YOU LOSE!!";
    }

return  0;
}
