#include <iostream>
#include <string>
using namespace std;

//pro. ex. q1
class Account
{
private:
    string name_, accNum_;
    double balance_;

    void get_Name(void)
    {
        cout << "Enter the name the bank account is under: ";
        cin >> name_;
    }
    void get_Balance(void)
    {
        cout << "Enter you account's initial balance: ";
        cin >> balance_;
    }
    void get_AccNum(void)
    {
        cout << "Enter the account number: ";
        cin >> accNum_;
    }

public:
    Account(const string &name, double balance = 0.0);
    Account(double balance);
    Account(void);

    void show(void) const;
    void deposit(double val)
    {
        balance_ += val;
    }
    void deposit(void);
    void withdraw(double val)
    {
        balance_ -= val;
    }
    void withdraw(void);
};
Account::Account(const string &name, double balance)
{
    name_ = name;
    balance_ = balance;
    get_AccNum();
}
Account::Account(double balance)
{
    get_Name();
    balance_ = balance;
    get_AccNum();
}
Account ::Account()
{
    get_Name();
    get_Balance();
    get_AccNum();
}
void Account::show(void) const
{
    cout << "The account is under the name " << name_ << endl;
    cout << "The account number is " << accNum_ << endl;
    streamsize prec = cout.precision(2);
    cout << fixed;
    cout << "The account has balance $" << balance_ << endl;
    cout.precision(prec);
}
void Account::deposit()
{
    double val;
    cout << "Enter a value to deposit: ";
    cin >> val;
    deposit(val);
}
void Account::withdraw()
{
    double val;
    cout << "Enter a value to withdraw: ";
    cin >> val;
    withdraw(val);
}

//pro. ex. q2
class Person
{
private:
    static const int LIMIT = 25;
    char fname[LIMIT]; // Person’s first name
    string lname;      // Person’s last name
public:
    Person()
    {
        lname = "";
        fname[0] = '\0';
    }                                                    // #1
    Person(const string &ln, const char *fn = "Heyyou"); // #2
    // the following methods display lname and fname
    void Show(void) const;       // firstname lastname format
    void FormalShow(void) const; // lastname, firstname format
};
//My stuff from here down
Person::Person(const string &ln, const char *fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
}
void Person::Show(void) const
{
    cout << fname << ' ' << lname;
}
void Person::FormalShow(void) const
{
    cout << lname << ", " << fname;
}

//pro. ex. q6
class Move
{
private:
    double x;
    double y;

public:
    Move(double a = 0, double b = 0); // sets x, y to a, b
    void showmove(void) const;        // shows current x, y values
    Move add(const Move &m) const;
    // this function adds x of m to x of invoking object to get new x,
    // adds y of m to y of invoking object to get new y, creates a new
    // move object initialized to new x, y values and returns it
    void reset(double a = 0, double b = 0); // resets x,y to a, b
};
//my work from here down
Move::Move(double a, double b)
{
    reset(a, b);
}
void Move::showmove(void) const
{
    cout << "You current (x, y) values are: ("
         << x << ", " << y << ')' << endl;
}
Move Move::add(const Move &m) const
{
    Move nMove(m.x + x, m.x + y);
    return nMove;
}
void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
double getX(void)
{
    double chg_x;
    cout << "Enter your change x: ";
    cin >> chg_x;
    return chg_x;
}
double getY(void)
{
    double chg_y;
    cout << "Enter your change for y: ";
    cin >> chg_y;
    return chg_y;
}

//pro. ex. q7
#define NAME_LEN 19
#define START_CI 50
class Plorg
{
private:
    char name[NAME_LEN];
    int ci;

public:
    Plorg(const char *nm = "Plorga")
    {
        strncpy(name, nm, NAME_LEN);
        ci = START_CI;
    }
    void changeCI(int n_ci)
    {
        ci = n_ci;
    }
    void show(void) const
    {
        cout << "The plorg's name is " << name << endl;
        cout << "The plorg's CI is " << ci << endl;
    }
};

//pro. ex. q8
#include "list.hpp"
void show(int &x)
{
    cout << x << ' ';
}
int main(void)
{
    //pro. ex. q1
    /*cout << "Inittializing joe's broke account" << endl;
    Account joe("Joe Joey"); //name dedicated to Mr. Mabrey
    int act = 0;
    while (act != 4)
    {
        cout << endl
             << "Enter the number for the operation you want to perform" << endl;
        cout << "1: reveal information about the account" << endl;
        cout << "2: deposit money" << endl;
        cout << "3: withdraw money (be careful!)" << endl;
        cout << "4: Stop managing joe" << endl;
        cout << "Enter you choice here: ";
        cin >> act;
        switch (act)
        {
        case 1:
            joe.show();
            break;
        case 2:
            joe.deposit();
            break;
        case 3:
            joe.withdraw();
            break;
        case 4:
            break;
        default:
            cout << "You entered an invalid input! Try again" << endl;
            break;
        }
    }
    cout << "Joe's account ended" << endl
         << endl;*/

    //pro ex. q2
    /*cout << "Starting Joe person activity" << endl;
    Person joe1;
    Person joe2("Joe");
    Person joe3("Joe", "Joey");
    joe1.FormalShow();
    cout << " has no name, id, or life" << endl;
    joe2.Show();
    cout << " has a couple of friend but doesn't have a real job" << endl;
    joe3.FormalShow();
    cout << " is a formal and well documented man" << endl;
    system("sleep 2");
    cout << "Joe person programming ended" << endl
         << endl;*/

    //pro. ex. q6
    /*cout << "Starting move program" << endl;
    Move one(getX(), getY());
    one.showmove();
    cout << "How many times do you want to do addition: ";
    int repeat;
    cin >> repeat;
    Move two;
    for (int i = 0; i < repeat; i++)
    {
        two.reset(getX(), getY());
        one = one.add(two);
        one.showmove();
    }
    system("sleep 2");
    cout << "Move program endend" << endl
         << endl;*/

    //pro. ex. q7
    /*cout << "Starting plorg program" << endl;
    //cin.ignore()
    cout << "Enter you plorg's name (the max length is " << NAME_LEN << "): ";
    char name[NAME_LEN];
    cin.getline(name, NAME_LEN);
    //Plorg p(name[0] != '\0' ? name : void); //??
    Plorg p(name);       //??
    if (name[0] == '\0') //??
        p = Plorg();     //??
    p.show();
    cout << "Enter you plorg's CI: ";
    int ci;
    cin >> ci;
    p.changeCI(ci);
    p.show();
    cout << "You finished playing with plorgs" << endl
         << endl;*/

    //pro. ex. q8
    //DOESN't WORK in diffrent functions
    cout << "Starting list program" << endl;
    List<int> l;
    int comand;
    do
    {
        cout << "Chose a command from the options below" << endl;
        cout << "1: Add a member to your list" << endl;
        cout << "2: Show you list" << endl;
        cout << "3: Exit game" << endl;
        cout << "Enter a command: ";
        cin >> comand;
        switch (comand)
        {
        case 1:
            if (l.isFull())
                cout << "List is full, can't add any members" << endl;
            else
            {
                int num;
                cout << "Enter the number you want to add to the list: ";
                cin >> num;
                l.push(num);
            }
            break;
        case 2:
            if (l.isEmpty())
                cout << "Nothing to show, list is empty" << endl;
            else
            {
                cout << "List displayed below:" << endl;
                l.visit(show);
                cout << endl;
            }
        case 3:
            break;
        default:
            cout << "Invalid comand! Try again" << endl;
            break;
        }
    } while (comand != 3);
    cout << "Thanks for using my list" << endl
         << endl;

    return 0;
}