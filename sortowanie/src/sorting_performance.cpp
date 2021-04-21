#include "timer.hpp"
#include "sorting/sorting.hpp"
#include <thread>
#include <cstdlib>
#include <iostream>

#define ZAKRES       50
#define ILOSC      /* 10000 */10000 /*1000000s*/

using namespace std::chrono_literals;

void wypelnij(std::vector<int> &tab,int zmienna)
{
    int x;
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
    for(int j=(tab.size()*x);j<tab.size();j++)
    {
        tab[j]=tab2[j];
    } 
}
const float procent_sortowania[6]={0.25,0.5,0.75,0.95,0.99,0.997};



int main(int argc, char* argv[])
{
    // TODO: implement perf tests
    // Timer usage example
    
    std::vector<int> tab(ILOSC);
    std::vector<int> pom(ILOSC);
    std::vector<int> posortowana(ILOSC);

    int zmienna=tab.size();
    long int czas; 


    wypelnij(tab,zmienna);

    pom=tab;

    Timer timer;

    timer.start();
    quickSort(tab, 0, zmienna-1);
    std::this_thread::sleep_for(3s);
    timer.stop();
    std::cout << "Waited quickSort for " << timer.sInterval() << "s\n";

     for(int j=0;j<6;j++)    //petla odpowiadajaca za zmienianie i sortowanie tablicy "posortowanej"
    {
        Timer timer1;
        posortowana=pom;
        Sortowanie(posortowana,tab,procent_sortowania[j]);
        std::cout<<"Sortowanie przez Quick vectora posortowanego w " << procent_sortowania[j]*100 << "%...\n";
        timer1.precision();
        timer1.start();
        insertSort(posortowana);
        std::this_thread::sleep_for(3s);
        timer1.stop();
        std::cout << "Waited for " << timer1.sInterval()<< czas << "s\n";
    }

        std::cout<<"\n";
        

    
    wypelnij1(tab,zmienna);
    pom=tab;

    Timer timer2;
    timer2.start();
    quickSort(tab,0,zmienna-1);
    std::this_thread::sleep_for(3s);
    timer2.stop();
    std::cout << "Waited for " << timer2.sInterval() << "s\n";

    std::cout<<"\n";
    std::cout<<"\n";

    wypelnij(tab,zmienna);
    pom=tab;

    Timer timer3;
    timer3.start();
    mergeSort(tab,0,zmienna-1);
    std::this_thread::sleep_for(3s);
    timer3.stop();
    std::cout << "Waited przez scalanie for " << timer3.sInterval() << "s\n";

     for(int j=0;j<6;j++)    //petla odpowiadajaca za zmienianie i sortowanie tablicy "posortowanej"
    {
        Timer timer1;
        posortowana=pom;
        Sortowanie(posortowana,tab,procent_sortowania[j]);
        std::cout<<"Sortowanie przez Merge vectora posortowanego w " << procent_sortowania[j]*100 << "%...\n";
        timer1.precision();
        timer1.start();
        mergeSort(posortowana,0,zmienna-1);
        std::this_thread::sleep_for(3s);
        timer1.stop();
        std::cout << "Waited  merge for " << timer1.sInterval()<< czas << "s\n";
    }
    std::cout<<"\n";
    std::cout<<"\n";

    wypelnij(tab,zmienna);
    pom=tab;

    Timer timer4;
    timer4.start();
    insertSort(tab);
    std::this_thread::sleep_for(3s);
    timer4.stop();
    std::cout << "Waited insert for " << timer4.sInterval() << "s\n";

     for(int j=0;j<6;j++)    //petla odpowiadajaca za zmienianie i sortowanie tablicy "posortowanej"
    {
        Timer timer1;
        posortowana=pom;
        Sortowanie(posortowana,tab,procent_sortowania[j]);
        std::cout<<"Sortowanie przez Insert vectora posortowanego w " << procent_sortowania[j]*100 << "%...\n";
        timer1.precision();
        timer1.start();
        insertSort(posortowana);
        std::this_thread::sleep_for(3s);
        timer1.stop();
        std::cout << "Waited  for " << timer1.sInterval()<< czas << "s\n";
    }

    return 0;
}
