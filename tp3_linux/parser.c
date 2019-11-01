#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char bufferId[100];
	char bufferNombre[100];
	char bufferHorasTrabajadas[100];
	char bufferSueldo[100];

	Employee* pAuxListEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],[^\n]\n",
					bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

			pAuxListEmployee = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
		}
		if(pAuxListEmployee != NULL)
		{
			ll_add(pArrayListEmployee, pAuxListEmployee);
			retorno = 0;
		}
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			pEmployee = employee_new();

			fread(pEmployee, sizeof(Employee),1,pFile);

			ll_add(pArrayListEmployee, pEmployee);
		}

		retorno = 0;
	}

    return retorno;
}
