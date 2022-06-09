#include <conio.h>
#include <iostream>

using namespace std;

const int MAXSIZE = 20;

class STACK
{
private:
    char* data;
    int Top;
public:
    STACK()
    {
        data = new char[MAXSIZE];
        Top = MAXSIZE;
    }

    void MAKENULL()
    {
        Top = MAXSIZE;
    }

    bool EMPTY()
    {
        if (Top == MAXSIZE)
            return true;
        return false;
    }

    void PUSH(char c)
    {
        if (Top == 0)
            cout << "Stack is full" << endl;
        else
        {
            Top--;
            data[Top] = c;
        }
    }

    void POP()
    {
        if (EMPTY())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Top++;
        }
    }

    char TOP()
    {
        if (EMPTY())
            cout << "Stack is empty" << endl;
        else
            return data[Top];
    }

    void PRINT()
    {
        for (int i = Top; i < MAXSIZE; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    STACK S;

    char c;

    S.MAKENULL();

    c = ' ';

    while (c != '=') {
        c = _getch();
        switch (c) {
        case '#':
            cout << "# was pressed" << endl;
            S.POP();
            break;
        case '@':
            cout << "@ was pressed" << endl;
            S.MAKENULL();
            break;
        case '^':
            cout << "^ was pressed" << endl;
            S.PUSH(S.TOP());
            break;
        case '=':
            cout << "End of the program" << endl;
            break;
        default:
            cout << c << " was added" << endl;
            S.PUSH(c);
            break;
        }
        S.PRINT();
    }
    return 0;
}
