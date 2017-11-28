#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char setInput();

void getSentence(ifstream &fin, string str);

char getCont();

void writeSentences(ofstream &fout);

bool checkFirst(string sentence);

int main()
{
    string str;
    ofstream fout;
    ifstream fin;
    char input;

    fin.open ("sample.txt");
    if(fin.is_open()){
        do{
            input = setInput();
            if(input == 'r') {
                getSentence(fin, str);
                continue;
            }
            else if(input == 'w') {
                fout.open("sample.txt", ios::app);
                writeSentences(fout);
                fout.close();
                continue;
            }
        }while(input != 'q' && !fin.eof());
    }
    fin.close();
    return 0;
}

char setInput() {
    cout << "Read --- r" << endl;
    cout << "Write -- w" << endl;
    cout << "Quit --- q" << endl;

    char choice;
    cin >> choice;
    return choice;
}

void getSentence(ifstream &fin, string str) {
    char input;
    do {
        for(int i = 0; i < 10; i++) {
                getline(fin, str);
                cout << str << endl;
                cout << endl;
        }
        input = getCont();
    }while(input != 'n' && !fin.eof());

}

char getCont() {
    char choice;
    cout << "Continue y/n?" << endl;
    cin >> choice;
    return choice;
}

void writeSentences(ofstream &fout) {
    string sentences;
    bool check;
    do {
        getline(cin, sentences);
        fout << sentences << endl;
        check = checkFirst(sentences);

    }while(check != true);
}

bool checkFirst(string sentence) {
    if(sentence[0] == '\\') {
        return true;
    }
    return false;
}
