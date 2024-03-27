#include <iostream>
#include <Windows.h>
#define HEIGHT 4
#define WIDTH 4

enum ConsoleColor {
    BLUE = 9,
    RED = 4,
    GREEN = 2,
    YELLOW = 14,
    ORANGE = 6,
    PINK = 3,
    PURPLE = 5
};
using namespace std;

class Figure abstract {
protected:
    char arr[HEIGHT][WIDTH];
    ConsoleColor color;
    string name;
public:
    virtual void SetArr() = 0;
    virtual void SetColor() = 0;
    virtual void SetName() = 0;
    void ShowFigure() {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++)
            {
                if (arr[i][j] != '*') {
                    SetConsoleTextAttribute(h, color);
                    cout << arr[i][j];
                }
                else
                {
                    SetConsoleTextAttribute(h, 7);
                    cout << '*';
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

class OFigure : public Figure {
public:
    void SetArr()override {
        arr[0][0] = '*';
        arr[0][1] = '*';
        arr[0][2] = '*';
        arr[0][3] = '*';
        arr[1][0] = '*';
        arr[1][1] = '@';
        arr[1][2] = '@';
        arr[1][3] = '*';
        arr[2][0] = '*';
        arr[2][1] = '@';
        arr[2][2] = '@';
        arr[2][3] = '*';
        arr[3][0] = '*';
        arr[3][1] = '*';
        arr[3][2] = '*';
        arr[3][3] = '*';
    }

    void SetColor()override {
        color = GREEN;
    }

    void SetName()override {
        name = "O Figure";
    }
};

class IFigure : public Figure {
public:
    void SetArr()override {
        arr[0][0] = '*';
        arr[0][1] = '@';
        arr[0][2] = '*';
        arr[0][3] = '*';
        arr[1][0] = '*';
        arr[1][1] = '@';
        arr[1][2] = '*';
        arr[1][3] = '*';
        arr[2][0] = '*';
        arr[2][1] = '@';
        arr[2][2] = '*';
        arr[2][3] = '*';
        arr[3][0] = '*';
        arr[3][1] = '@';
        arr[3][2] = '*';
        arr[3][3] = '*';
    }

    void SetColor()override {
        color = BLUE;
    }

    void SetName()override {
        name = "I Figure";
    }
};

class SFigure : public Figure {
public:
    void SetArr()override {
        arr[0][0] = '*';
        arr[0][1] = '*';
        arr[0][2] = '*';
        arr[0][3] = '*';
        arr[1][0] = '*';
        arr[1][1] = '*';
        arr[1][2] = '@';
        arr[1][3] = '@';
        arr[2][0] = '*';
        arr[2][1] = '@';
        arr[2][2] = '@';
        arr[2][3] = '*';
        arr[3][0] = '*';
        arr[3][1] = '*';
        arr[3][2] = '*';
        arr[3][3] = '*';
    }

    void SetColor()override {
        color = RED;
    }

    void SetName()override {
        name = "S Figure";
    }
};

class ZFigure : public Figure {
    void SetArr()override {
        arr[0][0] = '*';
        arr[0][1] = '*';
        arr[0][2] = '*';
        arr[0][3] = '*';
        arr[1][0] = '*';
        arr[1][1] = '@';
        arr[1][2] = '@';
        arr[1][3] = '*';
        arr[2][0] = '*';
        arr[2][1] = '*';
        arr[2][2] = '@';
        arr[2][3] = '@';
        arr[3][0] = '*';
        arr[3][1] = '*';
        arr[3][2] = '*';
        arr[3][3] = '*';
    }
    
    void SetColor()override {
        color = GREEN;
    }

    void SetName() {
        name = "Z Figure";
    }
};

class LFigure : public Figure {
    void SetArr()override {
        arr[0][0] = '*';
        arr[0][1] = '@';
        arr[0][2] = '*';
        arr[0][3] = '*';
        arr[1][0] = '*';
        arr[1][1] = '@';
        arr[1][2] = '*';
        arr[1][3] = '*';
        arr[2][0] = '*';
        arr[2][1] = '@';
        arr[2][2] = '*';
        arr[2][3] = '*';
        arr[3][0] = '*';
        arr[3][1] = '@';
        arr[3][2] = '@';
        arr[3][3] = '*';
    }

    void SetColor()override {
        color = ORANGE;
    }

    void SetName() {
        name = "Z Figure";
    }
};

class JFigure : public Figure {
    void SetArr()override {
        arr[0][0] = '*';
        arr[0][1] = '*';
        arr[0][2] = '@';
        arr[0][3] = '*';
        arr[1][0] = '*';
        arr[1][1] = '*';
        arr[1][2] = '@';
        arr[1][3] = '*';
        arr[2][0] = '*';
        arr[2][1] = '*';
        arr[2][2] = '@';
        arr[2][3] = '*';
        arr[3][0] = '*';
        arr[3][1] = '@';
        arr[3][2] = '@';
        arr[3][3] = '*';
    }

    void SetColor()override {
        color = PINK;
    }

    void SetName() {
        name = "J Figure";
    }
};

class TFigure : public Figure {
    void SetArr()override {
        arr[0][0] = '*';
        arr[0][1] = '*';
        arr[0][2] = '*';
        arr[0][3] = '*';
        arr[1][0] = '*';
        arr[1][1] = '*';
        arr[1][2] = '*';
        arr[1][3] = '*';
        arr[2][0] = '@';
        arr[2][1] = '@';
        arr[2][2] = '@';
        arr[2][3] = '*';
        arr[3][0] = '*';
        arr[3][1] = '@';
        arr[3][2] = '*';
        arr[3][3] = '*';
    }

    void SetColor()override {
        color = PURPLE;
    }

    void SetName() {
        name = "J Figure";
    }
};


class Creator abstract {
public:
    virtual Figure* CreateFigure() = 0;
};

class OCreator : public Creator {
    Figure* CreateFigure()override {
        Figure* oFigure = new OFigure();
        oFigure->SetArr();
        oFigure->SetColor();
        oFigure->SetName();
        return oFigure;
    }
};

class ICreator : public Creator {
    Figure* CreateFigure()override {
        Figure* iFigure = new IFigure();
        iFigure->SetArr();
        iFigure->SetColor();
        iFigure->SetName();
        return iFigure;
    }
};

class SCreator : public Creator {
    Figure* CreateFigure()override {
        Figure* sFigure = new SFigure();
        sFigure->SetArr();
        sFigure->SetColor();
        sFigure->SetName();
        return sFigure;
    }
};

class ZCreator :public Creator {
    Figure* CreateFigure()override {
        Figure* zFigure = new ZFigure();
        zFigure->SetArr();
        zFigure->SetColor();
        zFigure->SetName();
        return zFigure;
    }
    
};

class LCreator :public Creator {
    Figure* CreateFigure()override {
        Figure* lFigure = new LFigure();
        lFigure->SetArr();
        lFigure->SetColor();
        lFigure->SetName();
        return lFigure;
    }

};

class JCreator :public Creator {
    Figure* CreateFigure()override {
        Figure* jFigure = new JFigure();
        jFigure->SetArr();
        jFigure->SetColor();
        jFigure->SetName();
        return jFigure;
    }

};

class TCreator :public Creator {
    Figure* CreateFigure()override {
        Figure* tFigure = new TFigure();
        tFigure->SetArr();
        tFigure->SetColor();
        tFigure->SetName();
        return tFigure;
    }

};


Figure* Client(Creator* pDev)
{
    return pDev->CreateFigure();
}

int main()
{
    Creator* creator = new OCreator();
    Figure* figure = Client(creator);
    figure->ShowFigure();
    delete creator;
    delete figure;

    creator = new ICreator();
    figure = Client(creator);
    figure->ShowFigure();
    delete creator;
    delete figure;

    creator = new SCreator();
    figure = Client(creator);
    figure->ShowFigure();
    delete creator;
    delete figure;


    creator = new ZCreator();
    figure = Client(creator);
    figure->ShowFigure();
    delete creator;
    delete figure;

    creator = new LCreator();
    figure = Client(creator);
    figure->ShowFigure();
    delete creator;
    delete figure;

    creator = new JCreator();
    figure = Client(creator);
    figure->ShowFigure();
    delete creator;
    delete figure;

    creator = new TCreator();
    figure = Client(creator);
    figure->ShowFigure();
    delete creator;
    delete figure;



    return 0;

}

