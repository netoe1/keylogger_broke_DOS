#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;

int dia,mes,ano,hora,minu,sec;
char aux;

void dadosHora()
{
  time_t timer;
  struct tm *horarioLocal;

  time(&timer); // Obtem informações de data e hora
  horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

   dia = horarioLocal->tm_mday;
   mes = horarioLocal->tm_mon + 1;
   ano = horarioLocal->tm_year + 1900;

   hora = horarioLocal->tm_hour;
   minu  = horarioLocal->tm_min;
   sec  = horarioLocal->tm_sec;
}
void geraArquivo()
{
    ofstream arquivo;

    arquivo.open("arquivo.txt",std::ios_base::app);

    arquivo << "\n" << hora << ":" << minu 
    << ":"  << sec  << ":"  << "---------" <<  dia 
    << "/"  << mes  << "/"  << ano << "\n\n" 
    << "Char: '"    << aux  << "' \n\n";

    arquivo.close();
}   
void loop_program(){
    while(true){
        if(kbhit())
        {
            dadosHora();
            aux = getch();
            geraArquivo();
        }       
    }
}
int main()
{   
    setlocale(LC_ALL,"");
    loop_program();

  return 0;
}