#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    double w[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
    double tab1[13] = { 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 };
    double tab4[13] = { 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1 };
    double tabT1[13] = { 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1 };
    double tabT4[13] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1 };
    double d1 = 1, d4 = 0;
    double E1 = 0, E4 = 0;
    double ni = 0.5;
    double s = 0, y = 0, B = 0.5, y2 = 0;

    do {
        //podajemy 1
        s = 0;
        for (int i = 0; i < 13; i++) {
            s += tab1[i] * w[i];
        }

        y = 1 / (1 + exp(-B * s));
        y2 = B * (1 - y * y);

        for (int i = 0; i < 13; i++) {
            w[i] = w[i] + ni * (d1 - y) * y2 * tab1[i];
        }

        E1 = 0.5 * (d1 - y) * (d1 - y);

        //////////////////////////////
        //podajemy 4
        s = 0;
        for (int i = 0; i < 13; i++) {
            s += tab4[i] * w[i];
        }
        y = 1 / (1 + exp(-B * s));
        y2 = B * (1 - y * y);

        for (int i = 0; i < 13; i++) {
            w[i] = w[i] + ni * (d4 - y) * y2 * tab4[i];
        }

        E4 = 0.5 * (d4 - y) * (d4 - y);

        cout << "E: " << E1 + E4 << endl;
    } while (E1 + E4 > 0.001);

    //Sprawdzenie 1
    s = 0;
    for (int i = 0; i < 13; i++) {
        s += tabT1[i] * w[i];
    }
    y = 1 / (1 + exp(-B * s));
    y2 = B * (1 - y * y);
    cout << "1: y= " << y << endl;

    //Sprawdzenie 2
    s = 0;
    for (int i = 0; i < 13; i++) {
        s += tabT4[i] * w[i];
    }
    y = 1 / (1 + exp(-B * s));
    y2 = B * (1 - y * y);
    cout << "2: y= " << y << endl;
};