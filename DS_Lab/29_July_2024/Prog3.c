// Q: Write a program to create a structure to store the information of n number of Employees.
// Employee's information includes data members: Emp-id, Name, Designation, basic-salary, hra%, da%. Display the information of employees with gross salary. 
// Use aray of structure.

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int emp_id;
    char name[100];
    char designation[100];
    float basic_salary;
    float hra_percent;
    float da_percent;
    float gross_salary;
};

void calculateGrossSalary(struct Employee *emp) {
    emp->gross_salary = emp->basic_salary + (emp->basic_salary * emp->hra_percent / 100) + (emp->basic_salary * emp->da_percent / 100);
}

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d\n", i + 1);
        printf("Emp-id: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);
        printf("HRA%%: ");
        scanf("%f", &employees[i].hra_percent);
        printf("DA%%: ");
        scanf("%f", &employees[i].da_percent);

        calculateGrossSalary(&employees[i]);
    }

    printf("\nEmployee Details with Gross Salary:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Emp-id: %d\n", employees[i].emp_id);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basic_salary);
        printf("HRA%%: %.2f\n", employees[i].hra_percent);
        printf("DA%%: %.2f\n", employees[i].da_percent);
        printf("Gross Salary: %.2f\n", employees[i].gross_salary);
    }

    free(employees);

    return 0;
}