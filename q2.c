#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Employee {
    char name[50];
    int id;
    float salary;
};

void writeToFile(const char *filename, struct Employee employees[], int n) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("ERROR.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fwrite(&employees[i], sizeof(struct Employee), 1, file);
    }

    fclose(file);
}


float readFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb"); 
    if (file == NULL) {
        printf("Unable to open file for reading.\n");
        exit(1);
    }

    struct Employee employee;
    float totalSalary = 0;
    while (fread(&employee, sizeof(struct Employee), 1, file)) {
        totalSalary += employee.salary;
    }

    fclose(file); 
    return totalSalary;
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        getchar(); 

        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        printf("Employee ID: ");
        scanf("%d", &employees[i].id);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    const char *filename = "employee_records.dat";
    writeToFile(filename, employees, n);
    float totalSalary = readFromFile(filename);

    printf("\nTotal salary expense of the company: %.2f\n", totalSalary);

    return 0;
}
