#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
using namespace std;
enum colors{
    BLACK=0,
    BLUE=1,
    GREEN=2,
    CYAN=3,
    RED=4,
    MAGENTA=5,
    BROWN=6,
    LGREY=7,
    DGREY=8,
    LBLUE=9,
    LGREEN=10,
    LCYAN=11,
    LRED=12,
    LMAGENTA=13,
    YELLOW=14,
    WHITE=15
};

void SetColor(int Background, int Text){
    int colorTexto= Text + (Background*16);
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(terminal, colorTexto);    
}

void ShowProgressBar_a(string correo,float let,string ruta)
{
    float len=correo.length();
    int o=(100/len)*let;
    fstream f;
    f.open(ruta, ios_base::app);
    if(!f.is_open())
    {
        cout<<"Error al escribir en el archivo"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<=100;i++) 
    {
        if(i==o)
        {
            SetColor(BLACK,LBLUE);
            int num_char= (i*correo.length())/100;
            f<<"[";
            cout<<"\r[";
            for(int x=1; x<=correo.length(); x++)
            {
                SetColor(BLACK,WHITE);
                if(i==100)
                {
                    cout<<"=";
                    f<<"=";
                }
                else if(i==4)
                {
                    num_char=1;
                    if(x<=num_char)
                    {
                        cout<<"-";
                        f<<"-";
                    }
                    else
                    {
                        cout<<" ";
                        f<<" ";
                    }
                }
                else if(x<=num_char)
                {
                        
                    if(x==num_char)
                    {
                        cout<<"-";
                        f<<"-";
                    }
                   else                    
                    {
                        cout<<"=";
                        f<<"=";
                    }
                }
                else 
                {
                    cout<<" ";
                    f<<" ";
                }
            }
            SetColor(BLACK,LBLUE);
            cout<<"]"<<i<<"% "<<"     "<<"Loading: "<<let<<" de 24     ";
            f<<"]"<<i<<"% "<<"     "<<"Loading: "<<let<<" de 24     ";
            for(int i=0;i<let;i++)
            {
                if(correo[i]=='a'||correo[i]=='e'||correo[i]=='i'||correo[i]=='o'||correo[i]=='u')
                correo[i]=toupper(correo[i]);
                else
                correo[i]=tolower(correo[i]);
	        }
            cout<<correo.substr(0,let)<<endl;
            f<<correo.substr(0,let);
            f<<"\n";
            fflush(stdout);
        }
    }
}
