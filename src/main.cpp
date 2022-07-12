#include <iostream>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include "..\lib\ProgressBar.h"
int main()
{   const string ruta="resource\\log.txt";
    const string correo="carlos.aleman@epn.edu.ec";
    for(int i=0;i<=24;i++)
    {
        ShowProgressBar_a(correo,i,ruta);
    }
    cout<<"\n";
}


