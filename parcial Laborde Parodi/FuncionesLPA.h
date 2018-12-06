#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getString(char input[],char message[],char eMessage[], int lowLimit, int hiLimit);

void MuestraMenu(char texto[]);
void MenuPrincipal();

#endif // employee_H_INCLUDED
