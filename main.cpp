#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void readlinefromfile(ifstream fin);

int main()
{
    ifstream fin;
    fin.open("textFile.txt");

    char more;
    do {
        for (int i = 0; i < 10; i++) {
            readlinefromfile(fin);
        }
        cout << "continue (y/n)?";
        cin >> more;
        while(more != 'n' && more != 'y')
        {
            cout << "continue (y/n)?";
            cin >> more;
        }
    } while (more != 'n');
    return 0;
}

void readlinefromfile(ifstream fin)
{
    string str;
    if(fin.is_open()) {
        if(fin.eof()) {
            fin.close();
        }
        else {
            getline(fin, str);
            cout << str << endl;
        }
    }
    else {
        cout << "Unable to read from file!" << endl;
    }
}
