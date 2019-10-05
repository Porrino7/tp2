#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "empleado.h"
#define TAM 1000


/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param list[] Employee Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee list[],int len)
{
    int flag=-1;
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=1;
    }
    flag=1;

    return flag;

}

/** \brief add in a existing list of employees the values received as parameters
 *         in the first empty position
 * \param list[] employee
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(eEmployee list[], int len, int id, char name[51],char lastName[51],float salary,int sector)
{
    int indice = searchFree(list, len);
    int todoOk=-1;

    system("cls");
    printf("****Alta Empleado****\n\n");

    if(indice==-1)
    {
        printf("Sistema lleno\n");
    }
    else
    {
        list[indice].id=id;
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        list[indice].salary=salary;
        list[indice].sector=sector;
        list[indice].isEmpty=0;

        todoOk = 0;
        printf("Alta exitosa!!\n\n");
    }
    return todoOk;

}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeId(eEmployee list[], int len, int id)
{
    int lastId=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0 && list[i].id==id)
        {
            printf("%d %10s %10s %16.2f %3d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
            lastId=i;
            break;
        }
    }
    return lastId;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee list[], int len, int id)
{
    int flag=-1;
    for(int i=0; i<len; i++)
    {
        if(list[i].id==id)
        {
            list[i].isEmpty=1;
            flag=0;
            break;
        }
    }
    return flag;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list[] Employee
 * \param len int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee list[], int len, int order)
{
    eEmployee auxiliar;
    int flag=-1;

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(order==0)
            {
                if(strcmp(list[i].lastName,list[j].lastName)>0)
                {
                    auxiliar=list[i];
                    list[i]=list[j];
                    list[j]=auxiliar;
                    flag=0;
                }
                else
                {
                    if(strcmp(list[i].lastName,list[j].lastName)==0)
                    {
                        if(list[j].sector < list[i].sector)
                        {
                            auxiliar=list[i];
                            list[i]=list[j];
                            list[j]=auxiliar;
                            flag=0;
                        }
                    }
                }
            }
            else if(order==1)
            {
                if(strcmp(list[j].lastName,list[i].lastName)>0)
                {
                    auxiliar=list[j];
                    list[j]=list[i];
                    list[i]=auxiliar;
                    flag=0;
                }
                else
                {
                    if(strcmp(list[j].lastName,list[i].lastName)==0)
                    {
                        if(list[i].sector < list[j].sector)
                        {
                            auxiliar=list[j];
                            list[j]=list[i];
                            list[i]=auxiliar;
                            flag=0;
                        }
                    }
                }
            }
        }
    }

    return flag;
}

/** \brief print the content of employees array
 *
 * \param list[] Employee
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee list[],int length)
{
    int flag=-1;
    printf("ID\tNOMBRE\tAPELLIDO\tSALARIO\t  SECTOR\n");
    for(int i=0; i<length; i++)
    {
        if(list[i].isEmpty==0)
        {
            findEmployeeById(list,length,list[i].id);
            flag=0;
        }
    }
    return flag;
}

/** \brief pide datos para pasar al removeEmployee
 *
 * \param list[] eEmployee
 * \param len int
 * \return int
 *
 */
int funtionRemoveEmployee(eEmployee list[], int len)
{
    int idEmployeeRemove;
    int flag1=0;
    int flagId=0;
    char confirmacion;
    int resultado;

    int validaNumeroEmpleados;
    validaNumeroEmpleados = searchEmloyeeActive(list,len);
    if(validaNumeroEmpleados >=1)
    {

        printf("****Baja Empleado****\n\n");
        printEmployees(list,len);
        printf("Ingrese el ID del empleado a eliminar:\n");
        flag1 = scanf("%d",&idEmployeeRemove);
        flagId = validationOfId(list,len,idEmployeeRemove);
        if(flag1 && flagId)
        {
            printf("El Empleado es: \nID   NOMBRE       APELLIDO      SALARIO    SECTOR\n");
            findEmployeeById(list,len,idEmployeeRemove);

            printf("Confirme eliminacion. Ingrese n para anular: ");
            fflush(stdin);
            confirmacion = getche();
            if(confirmacion !='n')
            {
                resultado = removeEmployee(list,len,idEmployeeRemove);
                if(resultado == 0)
                {
                    printf("\nBaja exitosa!!!\n");
                }
                else
                {
                    printf("\n No pudo concretarce la baja\n");
                }
            }
            else
            {
                printf("\nOperacion anulada\n");

            }
        }
        else
        {
            printf("\nEl ID ingresado no existe\n");
        }
    }
    else
    {
        printf("Primero ingrese al punto 1, no hay empleados para eliminar\n\n");
    }

    return 0;
}

/** \brief busca un id existente
 *
 * \param list[] eEmployee
 * \param len int
 * \param id int
 * \return int devuelve 1 si el ID existe y 0 si el ID no existe.
 *
 */
int validationOfId(eEmployee list[],int len,int id)
{
    int ok;

    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            ok=1;
            break;
        }
        else
        {
            ok=0;
        }
    }

    return ok;
}

/** \brief crea un empleado, pide los datos del usuario, valida y se lo pasa a addEmployee.
 *
 * \param aux eEmployee
 * \param list[] eEmployee
 * \param len int
 * \param id int
 * \return int retorna el resultado de addEmploye.
 *
 */
int getEmployee(eEmployee aux,eEmployee list[],int len,int id)
{
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int validaNumero;

    system("cls");
    printf("****Alta Empleado****\n");

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);
    while(strlen(nombre)<=0)
    {
        printf("Nombre Incorrecto. Ingrese nombre: ");
        gets(nombre);
    }

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(apellido);
    while(strlen(apellido)<=0)
    {
        printf("Apellido Incorrecto. Ingrese apellido: ");
        gets(apellido);
    }

    printf("Ingrese salario: ");
    validaNumero = scanf("%f", &salario);
    while(validaNumero != 1)
    {
        printf("Incorrecto, reingrese salario: ");
        fflush(stdin);
        validaNumero = scanf("%f", &salario);
    }

    printf("Ingrese sector: ");
    validaNumero = scanf("%d",&sector);
    while(validaNumero != 1)
    {
        printf("Incorrecto, ingrese sector: ");
        fflush(stdin);
        validaNumero = scanf("%d",&sector);
    }

    int resultado=addEmployee(list,len,id,nombre,apellido,salario,sector);

    printEmployees(list,len);

    return resultado;
}

int menu()
{
    int opcion;
    int flag=0;


    printf("Elija una opcion\n");
    printf("1- Altas\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informes\n");

    if(scanf("%d",&opcion) && (opcion>=1 && opcion<=4))
    {
        flag=opcion;
    }
    else
    {
        printf("Opcion incorrecta\n");
    }

    return flag;
}


int menuInform()
{
    int opcion;
    int flag=0;


    printf("1- Listado de los empleados ordenados alfabeticamente por Apellido y Sector. \n");
    printf("2- Total y promedio de los salarios, y cantidad de empleados que superan el salario promedio.\n");

    if(scanf("%d",&opcion) && (opcion == 1 || opcion == 2))
    {
        flag = opcion;
    }
    else
    {
        printf("Opcion incorrecta\n");
    }

    return flag;
}



int funtionSortEmployees(eEmployee list[],int len)
{
    int orden;
    int validaNumeroEmpleados;
    validaNumeroEmpleados = searchEmloyeeActive(list,len);
    if(validaNumeroEmpleados >=1)
    {

        printf("Ingrese el orden:\n1- Ascendente 2- Descendente: ");
        if(scanf("%d",&orden) && (orden == 1 || orden == 2))
        {
            sortEmployees(list,len,orden-1);
            printEmployees(list,len);
        }
        else
        {
            printf("\nOpcion incorrecta\n");
        }
    }
    else
    {
        printf("Ingrese primero al punto 1, no hay empleados para ordenar\n\n");
    }
    return 0;
}



int searchFree(eEmployee list[], int len)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            indice=i;

            break;
        }
    }
    return indice;
}


eEmployee newEmployee(int id, char name[51], char lastName[51], float salary, int sector)
{
    eEmployee employee;
    employee.id=id;
    strcpy( employee.name, name);
    strcpy( employee.lastName, lastName);
    employee.salary=salary;
    employee.sector=sector;
    employee.isEmpty=0;

    return employee;
}



int harcodearEmpleados(eEmployee list[],int len, int id)
{
    int cantidad=3;
    char nombre[][51]= {"juan","lisardo","mateo","adriano","raul","juan","pedro","silvina","marta","gabriel"};
    char apellido[][51]= {"domingues","romero","messi","pedroso","vera","martinez","tevez","diaz","nogueira","gates"};
    float salario[]= {40000,23590,40000,29574,60890,47563,32944,27521,25998,25651};
    int sector[]= {1,5,1,3,3,1,4,2,3,1};
    int lastId;

    for(int i=0; i<cantidad; i++)
    {
        if(list[i].id<=cantidad)
        {
            strcpy(list[i].name,nombre[i]);
            strcpy(list[i].lastName,apellido[i]);
            list[i].salary=salario[i];
            list[i].sector=sector[i];
            list[i].id=id;
            list[i].isEmpty=0;
            id++;
            lastId=i+1;
        }
    }

    return lastId;
}



int modifyEmployee(eEmployee list[], int len)
{
    int validaNumeroEmpleados;
    validaNumeroEmpleados = searchEmloyeeActive(list,len);
    if(validaNumeroEmpleados >=1)
    {

        printf("%d",searchEmloyeeActive(list,len));
        printf("****Modificar Empleado****\n\n");
        char seguirModificacion;
        int opcionId;
        char opcionModificar;
        char nombre[51];
        char apellido[51];
        float salario;
        int sector;
        int validaNumero;
        int idAModificar;
        int validaSiEsNumero;

        printEmployees(list,len);
        printf("Ingrese el numero de ID a modificar: ");
        validaSiEsNumero = scanf("%d",&opcionId);

        if(validationOfId(list,len,opcionId) && validaSiEsNumero)
        {
            printf("El usuario ingresado es: \n");

            idAModificar=findEmployeeById(list,len,opcionId);

            printf("\nDesea modificar este usuario? elija s o n \n");
            fflush(stdin);
            scanf("%c",&seguirModificacion);

            if(seguirModificacion=='s')
            {
                printf("Para modificar nombre ingrese s: \n");
                fflush(stdin);
                scanf("%c",&opcionModificar);

                if(opcionModificar=='s')
                {
                    printf("Ingrese el nuevo nombre: ");
                    fflush(stdin);
                    gets(nombre);
                    strcpy(list[idAModificar].name,nombre);
                    printf("Nombre modificado con exito\n");

                }
                printf("Para modificar apellido ingrese s: ");
                fflush(stdin);
                scanf("%c",&opcionModificar);

                if(opcionModificar=='s')
                {
                    printf("Ingrese el nuevo apellido: ");
                    fflush(stdin);
                    gets(apellido);
                    strcpy(list[idAModificar].lastName,apellido);
                    printf("Apellido modificado con exito\n");
                }
                printf("Para modificar el salario ingrese s: ");
                fflush(stdin);
                scanf("%c",&opcionModificar);

                if(opcionModificar=='s')
                {
                    printf("Ingrese el nuevo salario: ");
                    validaNumero = scanf("%f",&salario);
                    while(validaNumero != 1)
                    {
                        printf("Incorrecto, reingrese salario: ");
                        fflush(stdin);
                        validaNumero = scanf("%f", &salario);
                    }
                    list[idAModificar].salary=salario;
                    printf("Salario modificado con exito\n");
                }
                printf("Para modificar el sector ingrese s: ");
                fflush(stdin);
                scanf("%c",&opcionModificar);

                if(opcionModificar=='s')
                {
                    printf("Ingrese el nuevo sector: ");
                    scanf("%d",&sector);
                    list[idAModificar].sector=sector;
                    printf("sector modificado con exito\n");
                }
            }
        }
        else
        {
            printf("ID incorrecto\n");
        }
    }
    else
    {
        printf("Primero ingrese en el punto 1, no hay empleados para modificar\n\n");
    }
    return 0;
}


/** \brief promedia
 *
 * \param list[] eEmployee
 * \param len int
 * \return int
 *
 */
int searchAverage(eEmployee list[],int len)
{
    float sumaTotal=0;
    float promedio;
    int contadorEmpleados=0;
    int contadorSuperanPromedio=0;
    int validaCantidadEmpleados;

    validaCantidadEmpleados = searchEmloyeeActive(list,len);

    if(validaCantidadEmpleados>=2)
    {


        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                sumaTotal+=list[i].salary;
                contadorEmpleados++;
            }
        }
        promedio=sumaTotal/(float)contadorEmpleados;
        for(int i=0; i<len; i++)
        {
            if(list[i].salary > promedio && list[i].isEmpty==0)
            {
                contadorSuperanPromedio++;
            }
        }
        printf("El total de salarios es: %.2f\n",sumaTotal);
        printf("El promedio de salarios es: %.2f\n",promedio);
        printf("La cantidad de empleados que superan el promedio son: %d\n",contadorSuperanPromedio);
    }
    else
    {
        if(validaCantidadEmpleados<=2 && validaCantidadEmpleados>0)
        {
            printf("Debe ingresar al menos 2 empleados");
        }
        else
        {
            printf("Primero ingrese al punto 1\n\n");
        }

    }
    return 0;
}


/** \brief busca si hay empleados cargados y activos
 *
 * \param list[] eEmployee
 * \param len int
 * \return int retorna el numero de empleados cargados
 *
 */
int searchEmloyeeActive(eEmployee list[], int len)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            indice=i;
        }
    }

    return indice+1;
}

