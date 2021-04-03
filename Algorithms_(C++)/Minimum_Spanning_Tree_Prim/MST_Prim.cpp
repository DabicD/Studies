#include <iostream>
#include <vector>

using namespace std;


int minIndex(int* key, bool* mstSet,int V);

int main()
{
    int V;      //ok
    int E;      //ok
    int from;
    int where;
    int passagers;

    //WPROWADZANIE ILOSCI MIAST I LICZBY POLACZEN

    cin >> V;   //ilosc miast
    if (V <= 0) // liczba miast nie moze byc rowna 0 lub mniej
        return 0;

    cin >> E;   //liczba polaczen
    if (E <= 0) // liczba miast nie moze byc rowna 0 lub mniej
        return 0;

    //TWORZENIE I INICJALIZACJA TABLICY NA GRAF
    int** graph = new int* [V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    //WPROWADZANIE POLACZEN MIEDZY MIASTAMI
    for (int i = 0; i < E; i++)
    {
        int x1, x2, distance; //ok
        cin >> x1 >> x2 >> distance;

        //z miasta 1 do miasta 2
        graph[x1 - 1][x2 - 1] = distance;
        //z miasta 2 do miasta 1
        graph[x2 - 1][x1 - 1] = distance;
    }

    //zmiana znaku 
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = (-1) * (int)graph[i][j];
        }
    }

    ////////////////////////////PRIM_ALGHORITM///////////////////////////////////////
    int* parent = new int[V];   // parent[2]= rodzic miasta o inteksie 2
    int* key = new int[V];      // key[2]= droga DO miasta o indeksie 2 od rodzica
    bool* mstSet = new bool[V]; //wierzcholki

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    //USTAWIANIE ROOTA
    key[0] = 0;
    parent[0] = -1;

    //MST
    for (int i = 0; i < V-1; i++)
    {
        int u = minIndex(key, mstSet,V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    //zmiana znaku v2
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = (-1) * (int)graph[i][j];
        }
    }

    //////////////////////////////////////////////////
    bool newLine = false;
    while (true)
    {
        //SKAD DOKAD TURYSTOW
        cin >> from >> where;

        //SPRAWDZANIE ZER
        if (from == 0 && where == 0)
        {
            break;
        }
        //jesli nie zakonczylismy zerami to lecimy dalej z liczba pasazerow
        cin >> passagers;

        int counter = 0;
        from--; where--;

        //DZIALANIE (Droga miedzy punktami po MST i wyliczanie MAX przewozow)
        int ix = where;

        vector <int> Vec1X;
        vector <int> Vec2X;
        bool iterationT = 0;
        while (ix != from)
        {
            if (parent[ix] == -1)
            {
                if (iterationT == 1)
                    break;

                int temp = where;
                where = from;
                from = temp;
                ix = where;        //parent[where] poprawka
                iterationT=1;

                continue;
            }

            if (iterationT == 0) //przed zamiana
                Vec1X.push_back(ix);
            else                //po zamianie
                Vec2X.push_back(ix);

            ix = parent[ix];
        }
        /////////////////////////////////////////////
        //USUWA TOZSAME ELEMENTY W VEKTORACH. LACZNIE ZE WSPOLNYM PRZODKIEM.
        bool pop = false;
        if (iterationT == 1 && (int)Vec1X.size() != 0) { //oteratopmT==1 to zaczy ze istnieje v2
            if(Vec1X.back() == Vec2X.back())
                pop = true;

            for (int i = 0; Vec1X.back() == Vec2X.back(); i++)
            {
                Vec1X.pop_back();   //droga drugiego
                Vec2X.pop_back();   //droga pierwszego
            }
        }
        
        //couter drogi
        for (int i = 0; i < (int)Vec1X.size(); i++) 
        {

            int uselessintegeer = (int)graph[Vec1X[i]][parent[Vec1X[i]]] - 1;
            if (uselessintegeer==0)
            {
                break;
            }
            int temp2 = (passagers / uselessintegeer);
            int temp1 = (temp2*uselessintegeer);

            if (passagers != temp1 && counter < ((int)temp2 + 1))
            {
                counter = ((int)temp2 + 1);
            }
            else if (passagers == temp1 && counter < (int)temp2)
            {
                counter = (int)temp2;
            }
        }
      
        for (int i = 0; i < (int)Vec2X.size(); i++) 
        {
            if (pop == false)
            {
                counter = 0;
                pop = true;
            }
            int uselessintegeer = (int)graph[Vec2X[i]][parent[Vec2X[i]]] - 1;
            if (uselessintegeer == 0)
            {
                break;
            }

            int temp2 = (passagers / uselessintegeer);
            int temp1 = (temp2 * uselessintegeer);


            if (passagers != temp1 && counter < ((int)temp2 + 1))
            {
                counter = ((int)temp2 + 1);
            }
            else if (passagers == temp1 && counter < (int)temp2)
            {
                counter = (int)temp2;
            }
        }
        

        /////////////////////////////////////////////
        //OUTPUT
        if (newLine == true)
            cout << endl;
        else 
            newLine = true;
        cout << counter;
    }
    ///////////////////////////////////////////////////////////////////////////

    //SPRZATANIE
    for (int i = 0; i < V; i++)
    {
        delete [] graph[i];
    }
    delete[] graph;

    delete[] parent;
    delete[] key;
    delete[] mstSet;

    return 0;
}


int minIndex(int* key, bool* mstSet,int V)
{
    int min = INT_MAX;
    int minIndex = 0;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}
