#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Making Structure for hetrogenous data
struct Employee
{
    int emp_id;
    char name[50];
    char designation[50];
};

void addEmployee(struct Employee employees[], int *numEmployees)
{
    // printf("Enter the number of employees you want to add : ");
    // int num;
    // scanf("%d", &num);
    // employees = (struct Employee*)realloc(employees,num * sizeof(struct Employee)); // Dynamic allocation of memory
    printf("Enter Employee ID: ");
    scanf("%d", &employees[*numEmployees].emp_id);
    char buff[10];
    sprintf(buff, "%d", employees[*numEmployees].emp_id);
    FILE* AD;
    AD = fopen("Emp_DataBase1.txt", "r");
    char line[100];
    while(fgets(line, 100, AD))
    {
        if(strstr(line, buff) != NULL)
        {
            printf("Already Exists\n"); //This is to check whether the employee ID is already is exist with the Given ID
            return;
        }
    }
    fclose(AD);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", employees[*numEmployees].name);

    printf("Enter Employee Designation: ");
    scanf(" %[^\n]s", employees[*numEmployees].designation);

    FILE *fpp;                      // Storing Data of all employees into Emp_DataBase1.txt file
    fpp = fopen("Emp_DataBase1.txt", "a");
    if (fpp == NULL)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        fprintf(fpp, "Employee ID : %d\nEmployee Name : %s\nEmployee Designation : %s\n\n", employees[*numEmployees].emp_id, employees[*numEmployees].name, employees[*numEmployees].designation);
    }
    fclose(fpp);
    (*numEmployees)++;
    printf("Employee added successfully!\n");
}

void updateEmployee(struct Employee employees[], int numEmployees, int emp_id)
{
    char update1[100], update2[100];
    printf("Enter new name: ");
    scanf(" %[^\n]s", update1);

    printf("Enter new designation: ");
    scanf(" %[^\n]s", update2);

    char buff[10];
    sprintf(buff, "%d", emp_id);
    char a[100];
    FILE *fpp;
    FILE *fq;
    fpp = fopen("Emp_DataBase1.txt", "r");
    fq = fopen("DATA.txt", "w");
    if (fpp == NULL || fq == NULL)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        char temp[100];
        while (fgets(temp, 100, fpp))
        {
            if (strstr(temp, buff) != NULL)
                break;
            fputs(temp, fq); // Copy lines before the updated employee data
        }
        fgets(a, 100, fpp);
        fgets(a, 100, fpp);

        fprintf(fq, "Employee ID : %d\nEmployee Name : %s\nEmployee Designation : %s\n", emp_id, update1, update2);

        // Copy the remaining data from fpp to fq
        while (fgets(temp, 100, fpp) != NULL)
        {
            fputs(temp, fq);
        }
    }
    fclose(fpp);
    fclose(fq);
    // Copy the contents of fq back into fpp
    fpp = fopen("Emp_DataBase1.txt", "w");
    fq = fopen("DATA.txt", "r");
    if (fpp == NULL || fq == NULL)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        char temp[100];
        while (fgets(temp, 100, fq) != NULL)
        {
            fputs(temp, fpp);
        }
    }
    fclose(fpp);
    fclose(fq);
    remove("DATA.txt"); // Remove the DATA.txt file
    printf("Employee information updated successfully!\n");
}

void deleteEmployee(struct Employee employees[], int numEmployees, int emp_id){
    char buff[10];
    sprintf(buff, "%d", emp_id);
    char a[100];
    FILE *fpp;
    FILE *fq;
    fpp = fopen("Emp_DataBase1.txt", "r");
    fq = fopen("DATA.txt", "w");
    if (fpp == NULL || fq == NULL)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        char temp[100];
        while (fgets(temp, 100, fpp))
        {
            if (strstr(temp, buff) != NULL)
                break;
            fputs(temp, fq); // Copy lines before the deleted employee data
        }
        fgets(a, 100, fpp);
        fgets(a, 100, fpp);
        // Copy the remaining data from fpp to fq
        while (fgets(temp, 100, fpp) != NULL)
        {
            fputs(temp, fq);
        }
    }
    fclose(fpp);
    fclose(fq);
    // Copy the contents of fq back into fpp
    fpp = fopen("Emp_DataBase1.txt", "w");
    fq = fopen("DATA.txt", "r");
    if (fpp == NULL || fq == NULL)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        char temp[100];
        while (fgets(temp, 100, fq) != NULL)
        {
            fputs(temp, fpp);
        }
    }
    fclose(fpp);
    fclose(fq);
    remove("DATA.txt"); // Remove the DATA.txt file
    printf("Employee deleted successfully!\n");
}

void displayAllEmployees()
{
    FILE *fpp;
    fpp = fopen("Emp_DataBase1.txt", "r");
    if (fpp == NULL)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        char ch = fgetc(fpp);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = fgetc(fpp);
        }
    }
    fclose(fpp);
}
void generateEmployeeReport(int emp_id)
{
    char buff[10];
    sprintf(buff, "%d", emp_id);
    char a[100], b[100], c[100];
    FILE *fpp;
    FILE *fq;
    fpp = fopen("Emp_DataBase1.txt", "r");
    fq = fopen("Employee's_Report.txt", "w");
    if (fpp == NULL || fq == NULL)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        char temp[100];
        while (fgets(temp, 100, fpp))
        {
            if (strstr(temp, buff) != NULL)
                break;
        }
        strcpy(a, temp);
        fgets(b, 100, fpp);
        fgets(c, 100, fpp);

        fseek(fq, 0, SEEK_SET); // Move the file pointer to the beginning of the file
        fputs(a, fq);
        fputs(b, fq);
        fputs(c, fq);
    }
    fclose(fpp);
    fclose(fq);
    // char buff[10];
    // sprintf(buff, "%d", emp_id);
    // char a[100], b[100], c[100];
    // FILE *fpp;
    // fpp = fopen("Emp_DataBase1.txt", "r");
    // if (fpp == NULL)
    // {
    //     printf("Unable to open the file\n");
    // }
    // else
    // {
    //     char temp[100];
    //     while (fgets(temp, 100, fpp))
    //     {
    //         if (strstr(temp, buff) != NULL)
    //             break;
    //     }
    //     strcpy(a, temp);
    //     fgets(b, 100, fpp);
    //     fgets(c, 100, fpp);

    //     printf("\tYour Requested report is\n\t%s\t%s\t%s", a, b, c);
    //     fclose(fpp);
    // }
    // FILE *fp;
    // if (fp == NULL)
    // {
    //     printf("Unable to open the file\n");
    // }
    // else
    // {
    //     fp = fopen("Employee's Reprt.txt", "w");
    //     fprintf(fp, "%s\n%s\n%s", a, b, c);
    // }
}

int main()
{
    // struct Employee employees[100];
    printf("Enter the number of employees you want to add : ");
    int num;
    scanf("%d", &num);
    struct Employee *employees = malloc(num * sizeof(struct Employee)); // Dynamic allocation of memory
    int numEmployees = 0;
    int choice, emp_id;

    while (1) // Making loop always true so that ooptions are given after doing any job on this Employee Management System
    {
        printf("Employee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Update Employee Information\n");
        printf("3. Delete Employees\n");
        printf("4. Display All Employees\n");
        printf("5. Generate Specfic Employee Report\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee(employees, &numEmployees);
            break;

        case 2:
            printf("Enter Employee ID to update information: ");
            scanf("%d", &emp_id);
            updateEmployee(employees, numEmployees, emp_id);
            break;
        
        case 3:
            printf("Enter Employee ID to delete: ");
            scanf("%d", &emp_id);
            deleteEmployee(employees, numEmployees, emp_id);
            break;

        case 4:
            displayAllEmployees();
            break;

        case 5:
            printf("Enter Employee ID : ");
            scanf("%d", &emp_id);
            generateEmployeeReport(emp_id);
            break;

        case 6:
            printf("Thankyou for using the Employee Management System.\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}