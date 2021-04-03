#include <iostream>

using namespace std;

class HeapSort
{
private:
    unsigned int k;	//Amount of number to sort, at beginning
    unsigned int xx;	//Amount of numbers entering the table
    int* tab;

    unsigned int lastparent();
    unsigned int lkid(unsigned int x);
    unsigned int rkid(unsigned int x);
    void swap(unsigned int x, unsigned int y);

protected:
    void maxheap(unsigned int x); //x=parent

public:
    //konstruktory, destruktor
    HeapSort();
    HeapSort(const HeapSort& x);
    ~HeapSort();

    //Sety
    void setk(unsigned int x);

    //Gety
    unsigned int getk();

    //Metody
    void view();
    void sort(int o = -1);
    void adddata(int value);

    //Przeciazenia
    HeapSort& operator=(const HeapSort& x);



};

int main()
{
    unsigned int N,k;
    int data;

    std::cin >> N;
    std::cin >> k;
    HeapSort HS;
    HS.setk(k);

    for (unsigned int j = k; j > 0; j--)
    {
        std::cin >> data;
        HS.adddata(data);
    }
    HS.view();
    HS.sort(1);
    std::cout << endl;

    for (unsigned int i = N; i > 1; i--)
    {
        std::cin >> k;
        HeapSort HS;
        HS.setk(k);

        for (unsigned int j = k; j > 0; j--) 
        {
            std::cin >> data;
            HS.adddata(data);
        }
        HS.view();
        HS.sort(1);
    }
    return 0;
}

unsigned int HeapSort::lastparent()
{
    return (k/2)-1;
}

unsigned int HeapSort::lkid(unsigned int x)
{
    return (x*2)+1;
}

unsigned int HeapSort::rkid(unsigned int x)
{
    return (x*2)+2;
}

void HeapSort::swap(unsigned int x,unsigned int y)
{
    int z = tab[x];
    tab[x] = tab[y];
    tab[y] = z;
}

void HeapSort::maxheap(unsigned int x)
{
    if (tab[lkid(x)] > tab[x] && lkid(x) < xx)
        swap(x, lkid(x));
    if (tab[rkid(x)] > tab[x] && rkid(x) < xx)
        swap(x, rkid(x));
}

HeapSort::HeapSort()
    :
    k(1)
    ,xx(0)
    ,tab(new int[k])
{
    tab[0] = 0;
}

HeapSort::HeapSort(const HeapSort& x)
    :
    k(x.k)
    ,xx(x.xx)
{
    tab = new int[k];

    for (unsigned int i = 0; i < k; i++)
    {
        tab[i] = x.tab[i];
    }

}

HeapSort::~HeapSort()
{
    delete[]tab;
}

void HeapSort::setk(unsigned int x)
{
    k = x;
    delete[] tab;
    xx = 0;
    tab = new int[k];

    for (unsigned int i = 0; i < k; i++)
    {
        tab[i] = 0;
    }
}

unsigned int HeapSort::getk()
{
    return k;
}

void HeapSort::view()
{
    if (0 < xx)
        std::cout << tab[0];
    for (unsigned int i = 1; i < xx; i++)
        std::cout << " "<<tab[i];
    std::cout << endl;
}

void HeapSort::sort(int o)
{
    int xSave = xx;
    for (unsigned int j = 0; j < k;j++) {
        swap(0, xx - 1);
        xx--;
        for (int j = (xx / 2) - 1; j >= 0; j--)
        for (int i = (xx / 2) - 1; i >= 0; i--)
            maxheap(i);
        if (o != -1 && xx>1)
            view();
    }
    xx = xSave;
    if (o != -1)
        view();
}

void HeapSort::adddata(int value)
{
    if (xx < k)
    {
        tab[xx] = value;
        xx++;
        for(int i=(xx/2)-1;i>=0;i--)
        maxheap(i);
    }
    else
    {
        //std::cout << "\nFail: Cannot add more values to this object.\n";
    }
}

HeapSort& HeapSort::operator=(const HeapSort& x)
{
    if (this == &x)
        return *this;
    else
    {
        k = x.k;
        xx = x.xx;
        delete[]tab;
        tab = new int[k];

        for (unsigned int i = 0; i < k; i++)
        {
            tab[i] = x.tab[i];
        }

        return *this;
    }
}

