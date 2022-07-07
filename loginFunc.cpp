#include "loginHeader.h"

struct userProfile
{
    string name, phone, mail, pass;
};

void makeDatabase()
{
    userProfile temp= {registeredUN, registeredPH, registeredEmail, registeredPW};
    users.push_back(temp);
    updateDB();
}

void updateDB(){
    fstream myFile;
    myFile.open("DB.txt", ios::out);
    for(int i=0; i<users.size(); i++){
        myFile<<users[i].name<<endl;
        myFile<<users[i].phone<<endl;
        myFile<<users[i].mail<<endl;
        myFile<<users[i].pass<<endl;
    }
}

void loadOuterDB(){
    fstream myFile;
    string line;
    myFile.open("DB.txt", ios::in);
    if(!myFile.fail()){
        int i=0;
        vector<string> tempDB;
        userProfile loadAcc;
        while(getline(myFile, line)){
            tempDB.push_back(line);
        }
        for(int j=0; j<tempDB.size();j+=4){
            loadAcc = {tempDB[j], tempDB[j+1], tempDB[j+2], tempDB[j+3]};
            users.push_back(loadAcc);
        }
    }
    myFile.close();
}

string atbash(string c){
    string res;
    for (int i = 0; i < c.length(); i++)
    {
        // if the letter is a small case, convert it to capital case and invert it to the desired letter.
        if ((int) c[i] > 90)
        {
            int(y) = 187 - (int) c[i];
            // cout << char(y);
            res.push_back(char(y));

        }
        // if the letter is a capital case, invert it to the desired letter.
        else if ((int) c[i] <= 90)
        {
            // if the program detects a space, it prints the same with no changes made to it.
            if ((int) c[i] == 32)
            {
                cout << " ";
                continue;

            }

            int(x) = 155 - (int) c[i];
            // cout << char(y);
            res.push_back(char(x));
        }
    }
    return res;
}

bool validUserName (string &userName)
{
    regex validUserName ("[a-zA-Z](_(?!(\\.|_))|\\.(?!(_|\\.))|[a-zA-Z]){4,18}[a-zA-Z]");
    return regex_match (userName, validUserName);
}

bool validPhoneNumber(string& phoneNumber)
{
    regex validPhoneNumber ("[0]+[1]+\\d{9}");
    return regex_match (phoneNumber, validPhoneNumber);
}

bool validEmailAddress(string& emailAddress)
{
    regex validEmailAddress ("[a-zA-Z0-9]+[._-]?[a-zA-Z0-9]+[@]+?[\\w]+[.]?[\\w]+");
    return regex_match (emailAddress, validEmailAddress);
}

bool validPassword(string& registeredPW)
{
    int length;
    length = registeredPW.length();
 
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
 
    for (int i = 0; i < length; i++) {
        if (islower(registeredPW[i]))
            hasLower = true;
        if (isupper(registeredPW[i]))
            hasUpper = true;
        if (isdigit(registeredPW[i]))
            hasDigit = true;
        if (!isalnum(registeredPW[i]))
            specialChar = true;
    }
 
    if (hasLower && hasUpper && hasDigit &&
        specialChar && (length >= 8))
    {
        cout << "Password strength: Strong" << endl;
        return true;
    }
    else if (((hasLower || hasUpper) &&
             specialChar && hasDigit && (length >= 8)) || (hasLower && hasUpper && (specialChar || hasDigit)))
    {
        cout << "Password strength: Medium" << endl;
        return true;
    }
    else
    {
        cout << "Password strength: Weak" << endl;
        return false;
    }
}

void changePW()
{
    Login();
    registerPassword();
    if (userPassword2!=registeredPW) {
        cout<< "The Passwords doesn't match\nPlease enter right information\n";
        changePW();
    } else{
        for(int i=0; i<users.size(); i++) {
            if(users[i].pass==userPassword){
                registeredPW= atbash(registeredPW);
                users[i].pass = registeredPW;
            }
        }
        cout<<"Password Changed!"<<endl;
        updateDB();
        mainMenu();
    }
}

void registerEmail()
{
    cout << "Email Address: ";
    cin >> registeredEmail;
    if(!validEmailAddress(registeredEmail))
    {
        cout << "Please enter a valid email address\n";
        registerEmail();
    }
    for(int i=0;i<users.size();i++){
        if(registeredEmail==users[i].mail){
            cout<< "This email has already been registered\n";
            cout << "Please enter a valid email address\n";
            registerEmail();
        }
    }

}

void registerUserName()
{
    cout <<"Username: " ;
    cin >> registeredUN;
    if(!validUserName(registeredUN))
    {
        cout << "Please enter a valid username\n";
        registerUserName();
    }
    else
    {
        for(int i=0;i<users.size();i++){
            if(registeredUN==users[i].name){
                cout << "This username has already been registered!\n";
                cout << "Please enter a new username\n";
                registerUserName();
            }
        }
    }
    
}

void registerPassword()
{
    cout << "--The password must contain atleast 8 characters!--\n";
    cout << "--atleast (1) digit, atleast (1) letter, atleast (1) digit or symbol--\n\n";
    cout << "New Password: ", cin >> registeredPW;
    if(!validPassword(registeredPW))
    {
        registerPassword();
    }
    else
    {
        cout << "Please enter the password again: ", cin >> userPassword2;
    }
}

void registerPhoneNumber()
{
    cout << "Phone number: ", cin >> registeredPH ;
    validPhoneNumber(registeredPH);
    if (!validPhoneNumber(registeredPH))
    {
        cout<< "Please enter a valid phone number" << endl;
        registerPhoneNumber();
    } else{
        for(int i=0;i<users.size();i++){
            if(registeredPH==users[i].phone){
                cout << "This phone number has already been registered!\n";
                cout << "Please enter a new phone number\n";
                registerPhoneNumber();
            }
        }
    }
}

void Register()
{
    registerEmail();
    registerUserName();
    registerPassword();
    if (userPassword2==registeredPW)
    {        
        registerPhoneNumber();
    }
    else if (userPassword2!=registeredPW)
    {
        cout<< "The Passwords doesn't match\nPlease enter right information\n";
        Register();
    }
    registeredPW= atbash(registeredPW);
    makeDatabase();
    cout << "Successfully registered!" << endl;
    mainMenu();
}


bool accExist(string pass, string mail){
    for (int i = 0; i < users.size(); i++){
        if(mail==users[i].mail && pass==users[i].pass){
            return true;
        }
    }
    return false;
}

void Login()
{   
    int attempt = 0;
    while(attempt < 3) 
    {     
        Email="", userPassword="";
        cout << "Email Address: " , cin >> Email;
        int chr;
        cout << "Password: ";
        chr = getch();
        while (chr != 13)
        {
            userPassword.push_back(chr);
            cout << '*';
            chr = getch();
        }
        userPassword= atbash(userPassword);
        if(!accExist(userPassword, Email)){
            attempt++;
            if(attempt==3){
                cout<<endl<<"No more attempts left"<<endl;
                cout<<"Goodbye!"<<endl;
            } else {
                cout<<"\nThis data is not registered, you have "<<3-attempt<<" attempts left!"<<endl;
            }
        } else{
            cout << "\nSuccessfully Logged in!"<<endl;
            break;
        }
    }
}

void mainMenu()
{
    char choice;
    cout << "1-Register\n2-Login\n3-Change Password\n0-Exit\n  ===> ";
    cin >> choice;
    if (choice == '1'){
        cout << "---REGISTER----" << endl;
        Register();
    }
    else if (choice == '2'){
        cout << "----LOGIN----" << endl;
        Login();
        mainMenu();
    }
    else if (choice == '3'){
        cout << "----CHANGE PASSWORD----" << endl;
        changePW();
    }
    else if (choice == '0')
        cout << "Thank You!" << endl;
    else
    {
        cout << "Please enter a valid choice!\n";
        mainMenu();
    }
}