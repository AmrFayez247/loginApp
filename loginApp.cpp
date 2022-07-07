// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: loginApp.cpp
// Last modification Date: 25/04/2022
// Author1 and ID and Group: Omar Ayman - 20210262 - S16
// Author2 and ID and Group: Amr Fayez - 20210278 - S16
// Author3 and ID and Group: Ahmed Khaled - 20210016 - S16
// Teaching Assistant: Nesma Mohamed - Yousra Ayman
// Purpose: Login database for an app
#include "loginHeader.h"
#include "loginFunc.cpp"


int main()
{
    cout <<"\n";
    system("cls");
    cout << "----Welcome User----\n";
    loadOuterDB();
    mainMenu();
    return 0;
}