
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "account.h"
#include "accountTicketingUI.h"

void displayAccountSummaryHeader(void)
{
	printf("Acct# Acct.Type Birth\n");
	printf("----- --------- -----\n");

}

void displayAccountDetailHeader(void)
{
	printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");

}

void displayAccountSummaryRecord(struct Account* account)
{
    char AGENT[6] = "AGENT";
    char CUSTOMER[10] = "CUSTOMER";
    // Give this formatting to the student
  

    if (account->acctype == 'A')
    {
        printf("%05d %-9s %5d", account->accnum, AGENT, account->demo.birthyear);
        printf("\n");
    }
    else
    {
        printf("%05d %-9s %5d", account->accnum, CUSTOMER, account->demo.birthyear);
        printf("\n");
    }


}


void displayAccountDetailRecord(struct Account* account)
{
    char AGENT[6] = "AGENT";
    char CUSTOMER[10] = "CUSTOMER";
    // Give this formatting to the student
    account->login.passward[1] = '*';
    account->login.passward[3] = '*';
    account->login.passward[5] = '*';
    account->login.passward[7] = '*';

    if (account->acctype == 'A')
    {
        printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s", account->accnum, AGENT, account->demo.birthyear, account->demo.income, account->demo.country, account->login.loginname, account->login.accountHolder, account->login.passward);
        printf("\n");
    }
    else
    {
        printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s", account->accnum, CUSTOMER, account->demo.birthyear, account->demo.income, account->demo.country, account->login.loginname, account->login.accountHolder, account->login.passward);
        printf("\n");
    }

}