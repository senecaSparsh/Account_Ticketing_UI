#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "account.h"

#include "commonHelpers.h"

void getAccount(struct Account* acc)
{
	printf("Account Data: New Record\n");
	printf("----------------------------------------\n");
    printf("Enter the account number: ");
     acc->accnum= getInteger();

    printf("Enter the account type (A=Agent | C=Customer): ");
    acc->acctype = getCharOption("AC");
    printf("\n");

}

void getUserLogin(struct UserLogin* info)
{
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");
    int c = 0, i = 0;
    printf("Enter user login(10 chars max) : ");
    getCString(info->accountHolder, 1, 10);


    printf("Enter the display name (30 chars max): ");
    getCString(info->loginname, 1,30);


    printf("Enter the password (must be %d chars in length): ", 8);
    getCString(info->passward, 8, 8);
    printf("\n");

}

void getDemographic(struct Demographic* demo)
{
    printf("Demographic Data Input\n");
    printf("----------------------------------------\n");

    int year = 0, min_year = 0, max_year = 0;
    year = currentYear();
    max_year = year - 18;
    min_year = year - 110;

    // Add the necessary code to get user input for each Demographic member:
    printf("Enter birth year (current age must be between 18 and 110): ");

    demo->birthyear = getIntFromRange(min_year, max_year);

    printf("Enter the household Income: $");
    demo->income = getPositiveDouble();

    printf("Enter the country (%d chars max.): ", 30);
    getCString(demo->country, 1, 30);
    printf("\n");


}