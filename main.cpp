#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

bool readlinefromfile(ifstream &fin);
void read();
void write();
void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    char option;

    cout << "What would you like to do?" << endl;
    cout << "r - read" << endl;
    cout << "w - write" << endl;
    cout << "q - quit" << endl;
    cin >> option;
    switch(option) {
        case 'r':
            read();
            break;
        case 'w':
            write();
            break;
        case 'q':
            break;
    }
}

void read()
{
    ifstream fin;
    bool done = false;
    char more;
    fin.open("textFile.txt");

    do {
        for (int i = 0; i < 10; i++) {
            done = readlinefromfile(fin);
            if(done)
                break;
        }
        cout << "continue (y/n)?";
        cin >> more;
        while(more != 'n' && more != 'y') {
            cout << "continue (y/n)?";
            cin >> more;
        }
    } while (more != 'n' && done != true);
    system("cls");
    menu();
}

void write()
{
    ofstream fout;
    string input;
    fout.open("textFile.txt", ios::app);
    if(fout.is_open())
    {
        getline(cin, input);
        while(input[0] != '\\')
        {
            fout << input << endl;
            getline(cin, input);
        }
        input.erase(0, 1);
        fout << input;
        fout.close();
    }
    else
    {
        cout << "File could not be opened";
    }
}

bool readlinefromfile(ifstream &fin)
{

    string str;
    if(fin.is_open()) {
        if(fin.eof()) {
            fin.close();
            return true;
        }
        else {
            getline(fin, str);
            cout << str << endl;
        }
    }
    else {
        cout << "Unable to read from file!" << endl;
    }

    return false;
}
