#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "graphs/adjacency_list_graph.hpp"
#include "graphs/adjacency_matrix_graph.hpp"

void Wygeneruj_Graf(float gestosc)
{
    std::ofstream wpisz("/home/martyna/Studia/Sem_4/Pamsi/lab1/pamsi1/PAMSIGrafy/build/a.txt"); 

    srand(time(NULL));
    int ilosc_wierzcholkow=ILOSC_WIERZCHOLKOW;
    int krawedzie;
    krawedzie=ilosc_wierzcholkow*(ilosc_wierzcholkow-1)*gestosc;
    wpisz<<ilosc_wierzcholkow<<" "<<krawedzie;

    int pierwszy_wierz=0;
    int koniec,poczatek;

    AdjacencyMatrixGraph Pom;
    std::vector<int> pom_pom_macierzy;

    for (int i = 0; i < ilosc_wierzcholkow; i++)
    {
        pom_pom_macierzy.push_back(0);
    }
    

    for(int i=0;i<ilosc_wierzcholkow;i++)
       {
           Pom.elemnt.push_back(pom_pom_macierzy);
       }

    for(int i=0;i<ilosc_wierzcholkow;i++)
    {
        for(int j=0;j<ilosc_wierzcholkow;j++)
        {
            Pom.elemnt[i][j]=0;
        }
    }
    if(gestosc<=0.5)
    {
        for(int i=0;i<ilosc_wierzcholkow;i++)
        {
            koniec=rand()%ilosc_wierzcholkow;
            if(koniec==i)
                --i;
            else
               Pom.elemnt[i][koniec]=(rand()%9)+1;

        }
        for(int j=0;j<krawedzie-ilosc_wierzcholkow;)
        {

            poczatek=rand()%ilosc_wierzcholkow;
            koniec=rand()%ilosc_wierzcholkow;
            if(poczatek!=koniec&&Pom.elemnt[poczatek][koniec]==0)
            {
               Pom.elemnt[poczatek][koniec]=(rand()%9)+1;
               j++;
            }

        }
    }
    else
    {
        for(int i=0;i<ilosc_wierzcholkow;i++)
            for(int j=0;j<ilosc_wierzcholkow;j++)
            {
                if(i!=j)
                    Pom.elemnt[i][j]=(rand()%9)+1;
            }
        for(int i=0;i<(1-gestosc)*krawedzie;i++)
        {
            poczatek=rand()%ilosc_wierzcholkow;
            koniec=rand()%ilosc_wierzcholkow;
            if(poczatek==koniec)
                --i;
            else if(Pom.elemnt[poczatek][koniec]==0)
                --i;
            else
                Pom.elemnt[poczatek][koniec]=0;
        }

    }
    wpisz<<"\n";
    for (int i = 0; i < ilosc_wierzcholkow; i++)
    {
        for (int j = 0; j < ilosc_wierzcholkow; j++)
        {
            if(Pom.Czy_istnieje_polaczenie(i,j))
            {
                wpisz<<i<<" "<<j<<" "<<Pom.elemnt[i][j]<<"\n";
            }
        }
        
    }
    wpisz<<"\n";
    
    wpisz.close();

}

int main(int argc, char* argv[])
{
    std::cout<< "Tu wykonujemy testy efektywności algorytmów"<<std::endl;

    AdjacencyMatrixGraph Graf_Macierz;
    AdjacencyListGraph Graf_Lista;

    Wygeneruj_Graf(0.25);
    std::ifstream plik;
    plik.open( "/home/martyna/Studia/Sem_4/Pamsi/lab1/pamsi1/PAMSIGrafy/build/a.txt" );
    
    // auto Graf_M=Graf_Macierz.createGraph(plik);
    // auto Graf_L=Graf_Lista.createGraph(plik);
    plik.close();

    


    


    

    
    return 0;
}
