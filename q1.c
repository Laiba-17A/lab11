#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

struct Department {
    char deptName[50];
    struct Employee employees[10];  
    int totalEmployees;  
};

float TotalSalary(struct Department dept) {
    float totalSalary = 0;
    for (int i = 0; i < dept.totalEmployees; i++) {
        totalSalary += dept.employees[i].salary;
    }
    return totalSalary;
}

int main() {
    struct Department dept;
   
    printf("Enter department name: ");
    gets(dept.deptName);
    printf("Enter the number of employees in the department: ");
    scanf("%d", &dept.totalEmployees);
    
    for (int i = 0; i < dept.totalEmployees; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        
        printf("Name: ");
        getchar();  
        gets(dept.employees[i].name);
        printf("Employee ID: ");
        scanf("%d", &dept.employees[i].id);
        printf("Salary: ");
        scanf("%f", &dept.employees[i].salary);
    }
    float totalSalary = TotalSalary(dept);
    printf("\nTotal salary of all employees in the %s department: %.2f\n", dept.deptName, totalSalary);
    return 0;
}
