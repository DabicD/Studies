#include <iostream>
#include <vector>

using namespace std;

class perceptron {

private:
    vector <int> x1;
    vector <int> x2;
    vector <int> d;

    int w0;
    int w1;
    int w2;
    int x0;


public:
    perceptron() {
        x0 = 1;
        w0 = 0;
        w1 = 0;
        w2 = 0;
    }

    ~perceptron() {}

    void addPoint(int x1, int x2, int d) {
        this->x1.push_back(x1);
        this->x2.push_back(x2);
        this->d.push_back(d);
    }

    void weightAlgorithm() {
        bool mod;
        do {
            mod = false;
            for (int i = 0; i < 7; i++)
            {
                int suma = 0;
                int xi = x1[i];
                int xi2 = x2[i];
                int wi = d[i];
                int y = 0;

                suma = xi * w1 + xi2 * w2 + x0 * w0;

                if (suma > 0)
                {
                    y = 1;
                }
                else
                {
                    y = -1;
                }

                if (y != d[i])
                {
                    w0 = w0 + d[i] * x0;
                    w1 = w1 + d[i] * xi;
                    w2 = w2 + d[i] * xi2;
                    mod = true;
                }
            }
        } while (mod == true);
    }

    void printData() {
        for (int i = 0; i < x1.size(); i++){
            cout << x1[i] <<" "<< x2[i] << " " << d[i] <<endl;
        }
    }
    void printWeight() {
        cout << "w1: " << w1 << "\tw2: " << w2 << "\tw0:" <<w0<<endl;
    }

};

int main()
{
    perceptron p;

    p.addPoint(2, 1, 1);
    p.addPoint(2,2,1);
    p.addPoint(0,6,1);

    p.addPoint(-2,10,-1);
    p.addPoint(-2,0,-1);
    p.addPoint(0,0,-1);
    p.addPoint(4,-20,-1);

    p.printData();
    p.weightAlgorithm();
    cout << endl;
    p.printWeight();

    return 0;
}
