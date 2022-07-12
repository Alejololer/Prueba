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

/*
    Un issue: El procedimiento para graficar la barra tiene ciertos desajustes en el calculo de la variable
    o, por lo que no mostraba el porcentaje 100, por lo que debí usar valores float, esto hace que en
    ciertos procentajes la barra se vea igual, por eso mismo se tuvo que arreglar el display de la 
    barra en 4%, esto es sobre todo ya que para continuar con la animación la barra debe llegar a un cierto
    porcentaje para avanzar (Por eso este issue se nota cuando el salto de porcentaje es de 5% y no de 4%,
    debido a las aproximaciones que los int realizan). 
    Definitivamente hay una manera más optimizada de graficar la barra.
    Un bug: Debido a que el programa carece de inputs del usuario, a menos que el fichero se corrompa de 
    alguna manera el error no debería presentar bugs.
    Un error: Si el fichero no se encuentra en la ruta seleccionada, el programa se tendrá que cerrar por
    la verificación
*/
