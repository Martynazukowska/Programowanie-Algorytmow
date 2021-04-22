#include "timer.hpp"
#include "sorting/sorting.hpp"
#include <thread>
#include <cstdlib>
#include <iostream>

#define ZAKRES       50
#define ILOSC      /* 10000 */100/*1000000s*/ 

using namespace std::chrono_literals;

void wypelnij(std::vector<int> &tab,int zmienna)
{
    int x=0;
    for (int j = 0; j < zmienna; j++)
    {
        x = rand() % ZAKRES;
        tab[j]=x;
    }
}
void wypelnij1(std::vector<int> &tab,int zmienna)
{
    for (int j = 0; j < zmienna; j++)
    {
        tab[j]=1;
    }
}

void Sortowanie (std::vector<int> &tab, std::vector<int> &tab2, float x) 
{

    int znienna=tab.size();
    std::cout<<"\n";
    for(int j=znienna-(znienna*x);j<znienna;j++)
    {
        tab[j]=tab2[j];
    } 
    // std::cout<<"\n";
    // for(int i=0;i<znienna;i++)
    // {
    //     std::cout<<tab[i]<<"\t";
    // }

}
const float procent_sortowania[4]={0.25,0.5,0.75,0.95};





int main(int argc, char* argv[])
{
    // TODO: implement perf tests
    // Timer usage example
    
    std::vector<int> tab(ILOSC); //nasz vektor na ktorym bedziemy działać
    std::vector<int> pom(ILOSC); // vektor pomocniczy do przechowywania NIEposortowanych wartości 
    std::vector<int> posortowana(ILOSC); //vektor potzrebny do przesortowywania np w 25 %

    int zmienna=tab.size();
    long int czas; 


    wypelnij(tab,zmienna); // wypełniamy vektor tab losowymi wartościami 
    pom=tab; // również pom (ale TYMI SAMYMI)

    Timer timer;

    timer.start();
    quickSort(tab, 0, zmienna-1); // juz tab posortowany 
    std::this_thread::sleep_for(3s);
    timer.stop();
    std::cout << "Waited quickSort for " << timer.sInterval() << "s\n";



    
     for(int j=0;j<4;j++)    //petla odpowiadajaca za zmienianie i sortowanie tablicy "posortowanej"
    {
    
        posortowana=pom;     //przyjmujemy ze vektor posortowana wszystkie elementy NIEPOSORTOWANE 
        Timer timer1;
        Sortowanie(posortowana,tab,procent_sortowania[j]);  //wiedząc o tym ze tab jest posortowane, a posortowana NIE, w tej funckji zamieniamy np 25% vektora posortowanej na vektor tab
        std::cout<<"Sortowanie przez Quick vectora posortowanego w " << procent_sortowania[j]*100 << "%...\n";
        timer1.start();
        quickSort(posortowana,0,zmienna-1); // sortowanie vektora juz posortowanego w pewnej części 
        std::this_thread::sleep_for(3s);
        timer1.stop();
        std::cout << "Waited for " << timer1.sInterval()<< czas << "s\n";
    }

    tab=pom;

        std::cout<<"\n";


    
    wypelnij1(tab,zmienna); // wypełnienie vektora samymi jedynkami 

    Timer timer2;
    timer2.start();
    quickSort(tab,0,zmienna-1); // przesortowanie vektora o jednaj wartosci 
    std::this_thread::sleep_for(3s);
    timer2.stop();
    std::cout << "Waited for " << timer2.sInterval() << "s\n";

    std::cout<<"\n";
    std::cout<<"\n";


    tab=pom; //znowu przyjmujemy nasz vektor jako wczesniejszy nieposortowany pom

    Timer timer4;
    timer4.start();
    insertSort(tab); //juz tab posortowany
    std::this_thread::sleep_for(3s);
    timer4.stop();
    std::cout << "Waited insert for " << timer4.sInterval() << "s\n";

     for(int j=0;j<4;j++)    //petla odpowiadajaca za zmienianie i sortowanie tablicy "posortowanej"
    {

        posortowana=pom;    //przyjmujemy ze vektor posortowana wszystkie elementy NIEPOSORTOWANE 
        Timer timer1;
        Sortowanie(posortowana,tab,procent_sortowania[j]); // //wiedząc o tym ze tab jest posortowane, a posortowana NIE, w tej funckji zamieniamy np 25% vektora posortowanej na vektor tab
        std::cout<<"Sortowanie przez Insert vectora posortowanego w " << procent_sortowania[j]*100 << "%...\n";
        timer1.start();
        insertSort(posortowana); // sortowanie vektora juz posortowanego w pewnej części 
        std::this_thread::sleep_for(3s);
        timer1.stop();
        std::cout << "Waited  for " << timer1.sInterval()<< czas << "s\n";
    }

    std::cout<<"\n";

    tab=pom; // znowu tab nieposortowane

    Timer timer3;
    timer3.start();
    mergeSort(tab,0,zmienna-1); // juz tak 
    std::this_thread::sleep_for(3s);
    timer3.stop();

    std::cout << "Waited przez scalanie for " << timer3.sInterval() << "s\n";
     for(int j=0;j<4;j++)    //petla odpowiadajaca za zmienianie i sortowanie tablicy "posortowanej"
    {

        posortowana=pom;  //przyjmujemy ze vektor posortowana wszystkie elementy NIEPOSORTOWANE 
        Timer timer1;
        Sortowanie(posortowana,tab,procent_sortowania[j]); //wiedząc o tym ze tab jest posortowane, a posortowana NIE, w tej funckji zamieniamy np 25% vektora posortowanej na vektor tab
        std::cout<<"Sortowanie przez Merge vectora posortowanego w " << procent_sortowania[j]*100 << "%...\n";
        timer1.start();
        mergeSort(posortowana,0,zmienna-1); // sortowanie vektora juz posortowanego w pewnej części 
        std::this_thread::sleep_for(3s);
        timer1.stop();
        std::cout << "Waited  merge for " << timer1.sInterval()<< czas << "s\n";
    }
    std::cout<<"\n";
    std::cout<<"\n";

    
    return 0;
}
