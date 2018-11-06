//
//  p5.c
//  Assignment5
//
//  Created by Daniel on 11/6/18.
//  Copyright © 2018 Daniel. All rights reserved.
//

#include <stdio.h>

int employeeCount()
{
    char c;
    int how_many;
    
    printf ("\nEnter the number of employees (1-50):");
    scanf("%i", &how_many);
    while ((c = getchar() != '\n') && c != EOF);
    
    if (how_many < 1 || how_many > 50)
        printf("\nIncorrect number of employees, please re-enter.\n");
    
    return how_many;
}

int enterEmployeeId(int x)
{
    int id;
    char c;
    
    printf ("\nEnter the Id Number for employee %i: ", x+1);
    scanf ("%d", &id);
    while ((c = getchar() != '\n') && c != EOF);
    if (id < 0)
        printf("\nIncorrect Id Number, please re-enter.\n");
    
    return id;
}

int enterEmployeeHours(int x)
{
    float hours_worked;
    char c;
    
    printf ("Enter the number of hours employee %i worked: ", x + 1);
    scanf ("%f", &hours_worked);
    while ((c = getchar() != '\n') && c != EOF);
    
    if (hours_worked < 0)
        printf("\nIncorrect number of hours, please re-enter.\n");
    
    return hours_worked;
}

int enterEmployeeRate(int x)
{
    float hourly_rate;
    char c;
    
    printf ("Enter the hourly rate of employee %i: ", x + 1);
    scanf ("%f", &hourly_rate);
    while ((c = getchar() != '\n') && c != EOF);
    
    if (hourly_rate < 0)
        printf("\nIncorrect hourly rate, please re-enter.\n");
    
    return hourly_rate;
}

int calculateOvertime(float hourly_rate, float hours_worked)
{
    float gross_pay, overtime_pay;
    
    overtime_pay =  hourly_rate * 1.5 * (hours_worked - 40);
    gross_pay = (40 * hourly_rate) + overtime_pay;
    
    return gross_pay;
}

int calculateGrossPay(float hours_worked, float hourly_rate)
{
    float gross_pay;
    
    gross_pay = hours_worked * hourly_rate;
    
    return gross_pay;
}

int calculateFederalTax(float gross_pay)
{
    float tax_rate = .20, federal_tax;
    
    federal_tax = gross_pay * tax_rate;
    
    return federal_tax;
}

int calculateNetPay(float gross_pay, float federal_tax)
{
    
    float net_pay;
    
    net_pay = gross_pay - federal_tax;
    
    return net_pay;
}

int calculateGrossTotals(float gross_pay, float gross_pay_total)
{
    gross_pay_total += gross_pay;
    
    return gross_pay_total;
}

int calculateTaxTotals(float federal_tax, float federal_tax_total)
{
    federal_tax_total += federal_tax;
    
    return federal_tax_total;
}

int calculateNetTotals(float net_pay, float net_pay_total)
{
    net_pay_total += net_pay;
    
    return net_pay_total;
}

void printTitle(void)
{
    int x;
    
    printf ("\n\n");
    
    for (x = 1; x < 17; x++) printf(" ");
    
    printf ("Payroll Report\n");
    
    printf ("                          ");
}

void printEmployeePay(int id, float gross_pay, float federal_tax, float net_pay)
{
    
    printf ("\n");
    printf("\t\tEmployee %3d\n", id);
    
    printf ("\t\tGross Pay:   $%14.2f\n", gross_pay);
    printf ("\t\tFederal Tax: $%14.2f\n", federal_tax);
    printf ("\t\tNet Pay:     $%14.2f\n", net_pay);
}

void printResults(float gross_pay_total, float federal_tax_total, float net_pay_total)
{
    printf ("\n\n");
    printf ("                           Report Totals\n");
    printf ("                           -------------\n\n");
    printf ("\t\tGross Pay:   $%14.2f\n", gross_pay_total);
    printf ("\t\tFederal Tax: $%14.2f\n", federal_tax_total);
    printf ("\t\tNet Pay:     $%14.2f\n\n\n\n", net_pay_total);
}

int main(void)
{

    int x, how_many = 0, employeeId[50], compsize = 0;
    char c, comp_name[30];
    
    float employeeGrossPay[50], employeeFederalTax[50], employeeNetPay[50];
    float GrossTotal = 0, TaxTotal = 0, NetTotal = 0;
    float hours_worked[50], hourly_rate[50];
    
    printf ("\nWelcome to the Payroll Calculator\n\n");
    
    printf ("\nEnter the company name:");
    scanf("%30[^\n]", comp_name);
    while ((c = getchar() != '\n') && c != EOF);
    
    do
    {
        how_many = employeeCount();
        
    } while (how_many < 1 || how_many > 50);
    
    for (x = 0; x < how_many; x++)
    {
        do
        {
            employeeId[x] = enterEmployeeId(x);
            
        } while (employeeId[x] < 0);
        
        do
        {
            hours_worked[x] = enterEmployeeHours(x);
            
        } while (hours_worked[x] < 0);
        
        do
        {
            hourly_rate[x] = enterEmployeeRate(x);
            
        } while (hourly_rate[x] < 0);
        
        
        if (hours_worked[x] > 40)
        {
            employeeGrossPay[x] = calculateOvertime(hourly_rate[x], hours_worked[x]);
        }
        else
        {
            employeeGrossPay[x] = calculateGrossPay(hours_worked[x], hourly_rate[x]);
        }
        
        employeeFederalTax[x] = calculateFederalTax(employeeGrossPay[x]);
        
        employeeNetPay[x] = calculateNetPay(employeeGrossPay[x], employeeFederalTax[x]);
        
        GrossTotal = calculateGrossTotals(employeeGrossPay[x], GrossTotal);
        
        TaxTotal = calculateTaxTotals(employeeFederalTax[x], TaxTotal);
        
        NetTotal = calculateNetTotals(employeeNetPay[x], NetTotal);
    }
    
    printTitle();
    
    x=0;
    while(comp_name[x] != '\0')// \0 is the string terminator - at the end of every char string
    {
        compsize++; // gets the length of the company name
        x++;
    }//end while

    for(x = 1; x < (30 - compsize)/2; x++)
          printf(" ");// skips half of the white space to center the underlining

    printf ("%s\n", comp_name);
    printf ("                          "); // 26 blanks

    for(x = 1; x < (30 - compsize)/2; x++)
      printf(" ");// skips half of the white space to center the underlining
     for(x = 1; x <= compsize; x++)// prints as many dashes as the length of the company name
            printf ("-");
    
    for (x = 0; x < how_many; x++)
    {
        printEmployeePay(employeeId[x], employeeGrossPay[x], employeeFederalTax[x], employeeNetPay[x]);
    }
    
    printResults(GrossTotal, TaxTotal, NetTotal);
    
    return 0;
} // End Main


