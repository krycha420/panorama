#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int pierwszy, ostatni, wysokosc, pole, polemax = 0,sumapol = 0, ile = 0, maxnajmni = 0, najmn = 0, segment = 0;
    int tab[100][3];
    int ntab[200];
    ifstream plik;
    plik.open("panorama.txt");

    for(int i =0; i<100; i++)
    {
        plik>>pierwszy>>ostatni>>wysokosc;
        pole = (ostatni- pierwszy+ 1) * wysokosc;
        if (pole>polemax)
        {
            polemax = pole;
        }
        sumapol += pole;
    }

    ifstream plik2;
    plik2.open("panorama.txt");
    for(int i=0; i<100; i++)
    {
        plik2>>pierwszy>>ostatni>>wysokosc;
        if(pierwszy<=3&&ostatni>=3)
        {
            ile++;
            cout <<"NA SEGMENCIE 3 JEST "<< pierwszy <<" " << ostatni<< " "<< wysokosc << endl;
        }

    }
    ifstream plik3;
    plik3.open("panorama.txt");
    for(int i=0; i<100; i++)
    {
        for (int y = 0; y<3; y++)
        {
            plik3>>tab[i][y];
        }

    }

    for(int k =1; k<=200; k++)
    {
        najmn = 0;
        for(int i =0; i<100; i++)
        {
            if(tab[i][0]<= k && tab[i][1]>=k)
            {
                najmn++;
                if(najmn>maxnajmni)
                {
                    maxnajmni = najmn;
                    segment = k;

                }
            }

        }
    }

    cout <<"NAJWIECEJ NA SEGMENCIE NR.  "<< segment <<" A MIANOWICE  " << maxnajmni << endl;
    cout <<"MAKSYMALNE POLE TO "<< polemax <<" SUMA POL TO " << sumapol << endl;

}

