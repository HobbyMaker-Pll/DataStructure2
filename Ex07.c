#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id, age;
	float salary;
	char gender;
} employee;

void printEmployees(employee* data, int size)
{
	for(int i=0; i<size; i++)
	{
		printf("=-=-=-=-=-=-=-=-=-\n");
		printf(
			"ID: %i\nSalary: %.2f\nAge: %i\nGender: %c\n",
			data[i].id,
			data[i].salary,
			data[i].age,
			data[i].gender
		);
	}
}

void registerEmployee(int id, employee* ret)
{
	ret->id = id;
	printf("Insert salary: \n");
	scanf("%f", &(ret->salary));
	printf("Insert age: \n");
	scanf("%i", &(ret->age));
	printf("Inser gender: \n");
	fflush(stdin);
	scanf("%c", &(ret->gender));
	system("cls");
}

int main_EmployeeAlocation()
{
	employee* employees;
	int size, i;
	
	printf("Insert the number of employees: ");
	scanf("%i", &size);

	employees = (employee*) malloc(sizeof(employee)*size);
	
	for(i=0; i<size; i++) registerEmployee(i, &*(employees+i));

	printEmployees(employees, size);
}
