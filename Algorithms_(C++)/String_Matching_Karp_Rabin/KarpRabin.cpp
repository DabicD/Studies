#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

int main()
{
    SetConsoleCP(1250);
    int basic = 256;
    unsigned int count;
    bool endlajn = false;
    cin >> count;
    cin.ignore();
    for (unsigned int caso = 0; caso < count; caso++) 
    {
        //////////////////////////////
        //Zmienne
        string path, patern;
        int key=0;
        int LP = 181;
        vector <int> toCheck;
        //////////////////////////////
        //OTWIERANIE PLIKU+ zapis do stringa
        //cin.ignore(MAX_INT,"\n");
        getline(cin, path);
        //cin.sync();
        ifstream file;
        file.open(path);
        if(file.good()!=true)
        {
            cout << "Path doesn't exist";
            return 0;
        }

        string text,xxx;

        while (getline(file, xxx))
        {
            text = text + xxx;
        }

        //////////////////////////////                
        //Pobieranie paternu i kodowanie go
        getline(cin, patern);

        for (unsigned int i = 0; i < patern.length(); i++)
        {
            key = (key * basic + (int)patern[i] + LP) % LP;
        }

        int constValueOfMinusek=1;
        for (unsigned int i = 0; i < patern.length() - 1; i++)
        {
            constValueOfMinusek = (constValueOfMinusek * basic) % LP;
        }

        ///////////////////////////////
        //H0                                          
        int currentVal=0;
        for (unsigned int i = 0; i < patern.length(); i++)
        {
            currentVal = ((currentVal * basic) + (int)text[i] + LP) % LP;
        }

        ///////////////////////////////
        //H1,H2,H3...                         
        for (unsigned int i = 0; i + patern.length()-1 < text.length(); i++)
        {
	    if (currentVal < 0)
	    {
            	currentVal = currentVal + LP;
	    }
            if (key == currentVal)
            {
                toCheck.push_back(i);
            }

            currentVal = (((currentVal - ((int)text[i] * constValueOfMinusek)%LP) * basic) + (int)text[i + patern.length()] + LP) % LP;
        }
        ////////////////////////////////
        //final
        
        vector <int> finalAnswer;
        int ok = 0;
        for (unsigned int i = 0; i < toCheck.size(); i++)
        {
            ok = 0;
            if (patern.length() != 1)
            {
                for (unsigned int j = 0; j < patern.length(); j++)
                {
                    if (text[(toCheck[i] + j)] == patern[j])
                    {
                        ok++;
                        if (ok == patern.length())
                            finalAnswer.push_back(toCheck[i]);
                    }
                    else { break; }
                }
            }
            else if(patern.length()==(unsigned int)1)
            {
                if (text[toCheck[i]] == patern[0])
                    finalAnswer.push_back(toCheck[i]);
            }
        }      

        if (endlajn == true)
        {
            cout << "\n";
        }

        bool  spacebares = false;
        for (unsigned int xaxa = 0; xaxa < finalAnswer.size(); xaxa++)
        {
            if (spacebares == true)
                cout << " ";
            cout << finalAnswer[xaxa];
            spacebares = true;
        }
                                         
        ///////////////////////////////                 
        //SPRZATANIE
        endlajn = true;
        file.close();
    }
    return 0;
}
