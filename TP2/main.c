

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "empleado.h"

#define TAM 1000 // cantidad de empleados.



int main()
{
    eEmployee listEmployees[TAM];
    initEmployees(listEmployees,TAM);
    int ultimoId=1;
    int respuesta;
    char seguir;
    eEmployee auxEmploye;

    do
    {

        switch(menu())
        {
        case 1:

            respuesta = getEmployee(auxEmploye,listEmployees,TAM,ultimoId);
            if(respuesta == 0)
            {
                ultimoId++;
            }
            break;

        case 2:
            modifyEmployee(listEmployees,TAM);

            break;

        case 3:
            funtionRemoveEmployee(listEmployees,TAM);

            break;

        case 4:

            switch(menuInform())//Menu para el ordenamiento de los informes
            {
            case 1:
                funtionSortEmployees(listEmployees,TAM);
                break;
            case 2:
                searchAverage(listEmployees,TAM);
                break;
            }

        }
        printf("Para salir ingrese 'n'\n");
        fflush(stdin);
        seguir=getche();
        system("cls");
    }
    while(seguir!='n');

    return 0;
}

