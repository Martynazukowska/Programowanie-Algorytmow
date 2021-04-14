#include "sorting/sorting.hpp"

void bubbleSort(std::vector<int>& tab)
{
    // TODO: implement
}

void insertSort(std::vector<int>& tab)
{
    int counter=tab.size();
    int pomocniczy,j;
     for(int i=1; i<counter; i++)
     {
            pomocniczy = tab[i]; 
            j = i-1;
             while(j>=0 && tab[j]>pomocniczy) 
             {
                        tab[j+1] = tab[j]; 
                        --j;
             }
             tab[j+1] = pomocniczy; 
     }  
}

void heapSort(std::vector<int>& tab)
{
    // TODO: implement
}

void quickSort(std::vector<int>& tab ,int pierwszy, int ostatni)
{
    int i=pierwszy-1;
    int j= ostatni+1;
    int pomocny =tab[(pierwszy+ostatni)/2];
    while (1)
    {
        while (pomocny>tab[++i])
        {
            ;
        }
        while (pomocny<tab[--j])
        {
            ;
        }
        if(i<=j)
        {
            int temp=tab[i];
            tab[i]=tab[j];
            tab[j]=temp;
        }
        else
        {
            break;
        }        
    }
    if(j>pierwszy)
    {
        quickSort(tab,pierwszy,j);
    }
    if (i<ostatni)
    {
        quickSort(tab,i,ostatni);
    }
}

void scal_tablice(std::vector<int>& tab, int pierwszy, int srodek, int ostatni) // dodatkowa funkcja aby ulatwic mergeSort
{
    std::vector<int> Posortowany(tab.size());
    int i = pierwszy, j = srodek + 1;
    for (int i = pierwszy; i <= ostatni; i++)
        Posortowany[i] = tab[i]; // tworze tablice pomocnicza

    for (int k = pierwszy; k <= ostatni; k++)
    {
        if (i <= srodek)
            if (j <= ostatni)
                if (Posortowany[j] < Posortowany[i])
                    tab[k] = Posortowany[j++];
                else
                    tab[k] = Posortowany[i++];
            else
                tab[k] = Posortowany[i++];
        else
            tab[k] = Posortowany[j++];
    }
}
void mergeSort(std::vector<int>& tab,int pierwszy,int ostatni)
{
    if (ostatni <= pierwszy)
    {
        ;
    }
    else
    {
        int srodek = (pierwszy + ostatni) / 2;

        mergeSort(tab, pierwszy, srodek);
        mergeSort(tab, srodek + 1, ostatni);

        scal_tablice(tab, pierwszy, srodek, ostatni);
    }
}
    

void bucketSort(std::vector<int>& tab)
{
    // TODO: implement
}
