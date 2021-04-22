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
        Posortowany[i] = tab[i]; 

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
    
    // int n1=srodek-pierwszy+1;
    // int n2=ostatni-srodek;

    // std::vector<int>Left;
    // std::vector<int>Right;

    // for(int i=0;i<n1;i++)
    // {
    //     Left.push_back(tab[pierwszy+i]);
    // }

    // for(int i=0;i<n2;i++)
    // {
    //     Right.push_back(tab[srodek+1+i]);
    // }


    
    // int i=0,j=0,x=0;

    // while(i+pierwszy<=srodek && j+srodek+1<=ostatni)
    // {
    //     if(Left[i]>=Right[j])
    //     {
    //         tab[(x++)+pierwszy]=Right[j++];
    //     }
    //     else
    //     {
    //         tab[(x++)+pierwszy]=Left[i++];
    //     }
    // }

    // if(i+pierwszy<srodek)
    // {
    //     while(i+pierwszy<=srodek)
    //     {
    //         tab[(x++)+pierwszy]=Left[i++];
    //     }
    // }
    // else if(j+srodek+1<ostatni)
    // {
    //     while(j+srodek+1<=ostatni)
    //     {
    //         tab[(x++)+pierwszy]=Right[j++];
    //     }
    // }

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

