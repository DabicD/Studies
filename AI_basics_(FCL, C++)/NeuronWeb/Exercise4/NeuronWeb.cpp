#include<iostream>
#include<cmath>

using namespace std;

double beta = 0.5;

double f(double s)
{
    return 1 / (1 + exp(-beta * s));
}

int main()
{
    double w[2][36] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

    //LITERA S
    double tab1[36] = { 1, 
        0, 1, 1, 1, 0, 
        1, 0, 0, 0, 1, 
        1, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    };

    //LITERA T
    double tab4[36] = { 1,
        1, 1, 1, 1, 1,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0
    };

    //LITERA Y
    double tab7[36] = { 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 0, 1, 0,
        0, 1, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0
    };

    //LITERA X
    double tab10[36] = { 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1
    };

    double d1[2] = { 1,1 }, d4[2] = { 1,0 }, d7[2] = { 0,0 }, d10[2] = { 0,1 };
    double E, E4, E7, E10;
    double ni = 0.1;
    double s1, s2, y1, y2;
    double y1p = 0, y2p = 0;

    do
    {
        E = 0;
        //digit 1 as input
        s1 = 0;
        s2 = 0;
        for (int i = 0; i < 36; i++)
        {
            s1 += tab1[i] * w[0][i];
            s2 += tab1[i] * w[1][i];
        }
        y1 = f(s1);
        y2 = f(s2);
        y1p = beta * y1 * (1 -y1);
        y2p = beta * y2 * (1 - y2);

        for (int i = 0; i < 36; i++)
        {
            w[0][i] = w[0][i] + ni * (d1[0] - f(s1)) * y1p * tab1[i];
            w[1][i] = w[1][i] + ni * (d1[1] - f(s2)) * y2p * tab1[i];
        }

        E = 0.5 * (d1[0] - y1) * (d1[0] - y1) + 0.5 * (d1[1] - y2) * (d1[1] - y2);


        //digit 4 as input
        E4 = 0;
        s1 = 0;
        s2 = 0;
        for (int i = 0; i < 36; i++)
        {
            s1 += tab4[i] * w[0][i];
            s2 += tab4[i] * w[1][i];
        }
        y1 = f(s1);
        y2 = f(s2);
        y1p = beta * y1 * (1 - y1);
        y2p = beta * y2 * (1 - y2);
        for (int i = 0; i < 36; i++)
        {
            w[0][i] = w[0][i] + ni * (d4[0] - f(s1)) * y1p * tab4[i];
            w[1][i] = w[1][i] + ni * (d4[1] - f(s2)) * y2p * tab4[i];
        }
        E4 = 0.5 * (d4[0] - y1) * (d4[0] - y1) + 0.5 * (d4[1] - y2) * (d4[1] - y2);

        //digit 7 as input
        E7 = 0;
        s1 = 0;
        s2 = 0;
        for (int i = 0; i < 36; i++)
        {
            s1 += tab7[i] * w[0][i];
            s2 += tab7[i] * w[1][i];
        }
        y1 = f(s1);
        y2 = f(s2);
        y1p = beta * y1 * (1 - y1);
        y2p = beta * y2 * (1 - y2);
        for (int i = 0; i < 36; i++)
        {
            w[0][i] = w[0][i] + ni * (d7[0] - f(s1)) * y1p * tab7[i];
            w[1][i] = w[1][i] + ni * (d7[1] - f(s2)) * y2p * tab7[i];
        }
        E7 = 0.5 * (d7[0] - y1) * (d7[0] - y1) + 0.5 * (d7[1] - y2) * (d7[1] - y2);

        //digit 10 as input
        E10 = 0;
        s1 = 0;
        s2 = 0;
        for (int i = 0; i < 36; i++)
        {
            s1 += tab10[i] * w[0][i];
            s2 += tab10[i] * w[1][i];
        }
        y1 = f(s1);
        y2 = f(s2);
        y1p = beta * y1 * (1 - y1);
        y2p = beta * y2 * (1 - y2);
        for (int i = 0; i < 36; i++)
        {
            w[0][i] = w[0][i] + ni * (d10[0] - f(s1)) * y1p * tab10[i];
            w[1][i] = w[1][i] + ni * (d10[1] - f(s2)) * y2p * tab10[i];
        }
        E10 = 0.5 * (d10[0] - y1) * (d10[0] - y1) + 0.5 * (d10[1] - y2) * (d10[1] - y2);

        cout << "Estyx =" << E7 + E + E4 +E10 << endl;
    } while (E7 + E + E4 + E10> 0.001);

    cout << "OdpowiedŸ dla S:" << endl;
    s1 = 0;
    s2 = 0;
    for (int i = 0; i < 36; i++)
    {
        s1 += tab1[i] * w[0][i];
        s2 += tab1[i] * w[1][i];
    }
    y1 = f(s1);
    y2 = f(s2);
    cout << y1 << "\t" << y2 << endl;

    cout << "OdpowiedŸ dla T:" << endl;
    s1 = 0;
    s2 = 0;
    for (int i = 0; i < 36; i++)
    {
        s1 += tab4[i] * w[0][i];
        s2 += tab4[i] * w[1][i];
    }
    y1 = f(s1);
    y2 = f(s2);
    cout << y1 << "\t" << y2 << endl;

    cout << "OdpowiedŸ dla Y:" << endl;
    s1 = 0;
    s2 = 0;
    for (int i = 0; i < 36; i++)
    {
        s1 += tab7[i] * w[0][i];
        s2 += tab7[i] * w[1][i];
    }
    y1 = f(s1);
    y2 = f(s2);
    cout << y1 << "\t" << y2 << endl;

    cout << "OdpowiedŸ dla X:" << endl;
    s1 = 0;
    s2 = 0;
    for (int i = 0; i < 36; i++)
    {
        s1 += tab10[i] * w[0][i];
        s2 += tab10[i] * w[1][i];
    }
    y1 = f(s1);
    y2 = f(s2);
    cout << y1 << "\t" << y2 << endl;
};
