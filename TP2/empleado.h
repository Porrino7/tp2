typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

eEmployee newEmployee(int id, char name[51], char lastName[51], float salary, int sector);

int menu();

int initEmployees(eEmployee list[],int len);

int searchFree(eEmployee list[], int len);//busca libre

int addEmployee(eEmployee list[], int len, int id, char name[51],char lastName[51],float salary,int sector);

int findEmployeeById(eEmployee list[], int len, int id);

int removeEmployee(eEmployee list[], int len, int id);

int harcodearEmpleados(eEmployee list[],int len, int id);

int printEmployees(eEmployee list[],int len);

int modifyEmployee(eEmployee list[], int len);

int sortEmployees(eEmployee list[], int len, int order);

int getEmployee(eEmployee aux,eEmployee list[],int len,int id);

int validationOfId(eEmployee list[],int len,int id);

int searchAverage(eEmployee list[],int len);

int funtionRemoveEmployee(eEmployee list[], int len);

int menuInform();

int funtionSortEmployees(eEmployee list[],int len);

int searchEmloyeeActive(eEmployee list[], int len);
