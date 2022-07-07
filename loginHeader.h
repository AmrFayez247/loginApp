#ifndef LOGINHEADER_H
#define LOGINHEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include<vector>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

string registeredUN, registeredPW, registeredPH, registeredEmail;
string userName , userPassword,userPassword2, phoneNumber, Email;
string name, pass, phone, mail;

struct userProfile;
vector<userProfile> users;

void makeDatabase();

void loadOuterDB();

void updateDB();

bool validUserName(string &userName);

bool validEmailAddress(string &phoneNumber);

bool validPhoneNumber(string &emailAddress);

bool validPassword(string &userPassword);

string abash(string c);

void mainMenu();

void Register();

void Login();

void registerEmail();

void registerPassword();

void regsiterPhoneNumber();

void registerUserName();

void changePW();

bool accExist(string pass, string mail);



#endif