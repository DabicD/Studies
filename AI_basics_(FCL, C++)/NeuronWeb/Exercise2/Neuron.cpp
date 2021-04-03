#include <iostream>
#include <vector>

using namespace std;

int main()
{
    double w[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
    double tab1[13] = { 1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1 };
    double tab4[13] = { 1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1 };
    double test1[13] = {1, -1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1};
    double test4[13] = {1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1};
    double d1 = 1, d4 = -1;
    double E1 = 0, E4 = 0;
    double ni = 0.1;
    double s = 0, y = 0, B = 0.5;

    do {
        //podajemy 1
        s = 0;
        for (int i = 0; i < 13; i++) {
            s += tab1[i] * w[i];
        }
        y = (1 - exp(-B * s)) / (1 + exp(-B * s));

        for (int i = 0; i < 13; i++) {
            w[i] += (ni * d1 * tab1[i]);
        }

        E1 = 0.5 * (d1 - y) * (d1 - y);
        //////////////////////////////
        //podajemy 4
        s = 0;
        for (int i = 0; i < 13; i++) {
            s += tab4[i] * w[i];
        }
        y = (1 - exp(-B * s)) / (1 + exp(-B * s));

        for (int i = 0; i < 13; i++) {
            w[i] += (ni * d4 * tab4[i]);
        }

        E4 = 0.5 * (d4 - y) * (d4 - y);

        cout << "E: " << E1 + E4 << endl;
    } while (E1 + E4 > 0.0000000005);

    //Sprawdzenie 1
    s = 0;
    for (int i = 0; i < 13; i++) {
        s += tab1[i] * w[i];
    }
    y = (1 - exp(-B * s)) / (1 + exp(-B * s));
    cout << "y1: " << y << endl;

    //Sprawdzenie 4
    s = 0;
    for (int i = 0; i < 13; i++) {
        s += tab4[i] * w[i];
    }
    y = (1 - exp(-B * s)) / (1 + exp(-B * s));
    cout << "y4: " << y << endl;

    //Sprawdzenie t1
    s = 0;
    for (int i = 0; i < 13; i++) {
        s += test1[i] * w[i];
    }
    y = (1 - exp(-B * s)) / (1 + exp(-B * s));
    cout << "test1: " << y << endl;

    //Sprawdzenie t4
    s = 0;
    for (int i = 0; i < 13; i++) {
        s += test4[i] * w[i];
    }
    y = (1 - exp(-B * s)) / (1 + exp(-B * s));
    cout << "test4: " << y << endl;
};