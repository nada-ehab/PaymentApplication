#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "terminal.h"
#include <string.h>
#include <ctype.h>

#define MAXtransdate 10

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("Enter the transaction date \n");
	gets(termData->transactionDate);
	uint8_t transacationdatelength = strlen(termData->transactionDate);

	if ((termData->transactionDate[6] <'2')  || (transacationdatelength!=MAXtransdate))
	{
		printf("ACTUAL RESULT: Wrong transaction date\n");
		return WRONG_DATE;
	}

	else if (termData->transactionDate[2] != '/' && termData->transactionDate[5] != '/')
	{
		printf("ACTUAL RESULT: Wrong transaction date\n");
		return WRONG_DATE;
	}
	
	else
	{
		printf("ACTUAL RESULT: correct transaction date\n");
		return TERMINAL_OK;
	}
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	uint8_t TransYear[2], TransMonth[2];
	uint8_t ExpdYear[2], ExpdMonth[2];

	TransYear[0] = termData->transactionDate[8];
	TransYear[1] = termData->transactionDate[9];
	ExpdYear[0] = cardData->cardExpirationDate[3];
	ExpdYear[1] = cardData->cardExpirationDate[4];

	if ( ExpdYear[1] < TransYear[1])
	{
		printf("ACTUAL RESULT: your card is expired\n");
		return EXPIRED_CARD;
	}

	else if (TransYear[0] == ExpdYear[0] && TransYear[1] == ExpdYear[1])
	{
		TransMonth[0] = termData->transactionDate[3];
		TransMonth[1] = termData->transactionDate[4];
		ExpdMonth [0] = cardData->cardExpirationDate[0];
		ExpdMonth [1] = cardData->cardExpirationDate[1];


		if (TransMonth[0] > ExpdMonth[0] && TransMonth[1] > ExpdMonth[1])
		{
			
			return EXPIRED_CARD;
		}
		printf("ACTUAL RESULT: your card is expired\n");
	}
	else
	{
		printf("ACTUAL RESULT: the date is correct\n");
		return CARD_OK;
	}
	
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{   printf("enter the transaction amount\n");
   
     float amount = 0;
     scanf_s("%f", &amount);

	if(amount <=0)
	{ 
		//printf("ACUAL RESULT: invalid amount\n");
		return INVALID_AMOUNT;
	}
	else
	{
		termData->transAmount = amount;
		//printf("ACTUAL RESULT: valid amount\n");
		return TERMINAL_OK;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	
	if (maxAmount <= 0)
	{
		printf("Actual result : INVALID_MAX_AMOUNT\n ");
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		termData->maxTransAmount = maxAmount;
		//printf("Actual result : VALID_MAX_AMOUNT\n ");
		return TERMINAL_OK;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{

	if (termData->transAmount > termData->maxTransAmount)
	{
		printf("EXceed max amount\n");
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		printf("valid amount\n");
		return TERMINAL_OK;
	}
}



void getTransactionDateTest(void)
{
	ST_terminalData_t trandate;
	printf("Tester Name: nada ehab\n");
	printf("Function Name: getTransactionDate\n");
	printf("Test case 1:123456  \nExpected Result: wrong transaction date \nInput data\n");
	getTransactionDate(&trandate);
	printf("\n");

	printf("Tester Name: nada ehab\n");
	printf("Function Name: getTransactionDate\n");
	printf("Test case 2:25-05/2025  \nExpected Result: wrong transaction date \nInput data\n");
	getTransactionDate(&trandate);
	printf("\n");

	printf("Tester Name: nada ehab\n");
	printf("Function Name: getTransactionDate\n");
	printf("Test case 3:25/05/3139  \nExpected Result: wrong transaction date \nInput data\n");
	getTransactionDate(&trandate);
	printf("\n");

	printf("Tester Name: nada ehab\n");
	printf("Function Name: getTransactionDate\n");
	printf("Test case 4:25/05/2025  \nExpected Result: transaction date is right \nInput data\n");
	getTransactionDate(&trandate);
	printf("\n");




}

void isCardExpriedTest(void)
{
	ST_cardData_t expd;
	ST_terminalData_t transcate;
	printf("Tester Name: nada ehab\n");
	printf("Function Name:  isCardExpried\n");
	printf("Test case 1: TRANSACTION YEAR> EXPD year  \nExpected Result: your card is expired \nInput data\n");
	printf("enter the expire date\n");
	getCardExpiryDate(&expd);
	getTransactionDate(&transcate);
	isCardExpired(&expd, &transcate);
	printf("\n");

	printf("Test case 2: same year different months  \nExpected Result: your card is expired \nInput data\n");
	printf("enter the expire date\n");
	getCardExpiryDate(&expd);
	getTransactionDate(&transcate);
	isCardExpired(&expd, &transcate);
	printf("\n");

	printf("Test case 3: valid date  \nExpected Result:the date is correct  \nInput data\n");
	printf("enter the expire date\n");
	getCardExpiryDate(&expd);
	getTransactionDate(&transcate);
	isCardExpired(&expd, &transcate);
	printf("\n");

	

}

void getTransactionAmountTest(void)
{
	ST_terminalData_t amount;

	printf("Tester Name : NADA EHAB\n");
	printf("Function name : getTransactionAmount\n");
	printf("Test Case 1 : 0\nExpected Result : invalid amoutn\nInput Data : ");
	getTransactionAmount(&amount);
	printf("\n");

	printf("Test Case 2 : negative number \nExpected Result : invalid amount\nInput Data : ");
	getTransactionAmount(&amount);
	printf("\n");

	printf("Test Case 3 : positive float number \nExpected Result : valid amount\nInput Data : ");
	getTransactionAmount(&amount);
	printf("\n");
}

void setMaxAmountTest(void)
{
	ST_terminalData_t maxtramount;
	printf("Tester Name : NADA EHAB\n");
	printf("Function name : setMaxAmountTest\n");
	printf("Test Case 1 : 0 \nExpected Result : invalid max amount\nInput Data : ");
	setMaxAmount(&maxtramount, 0);
	printf("\n");

	printf("Test Case 2 : -10000.00 \nExpected Result : invalid max amount\nInput Data : ");
	setMaxAmount(&maxtramount, -10000.00);
	printf("\n");


	printf("Test Case 3 : 10000.00 \nExpected Result : valid max amount\nInput Data : ");
	setMaxAmount(&maxtramount, 10000.00);
	printf("\n");
}

void isBelowMaxAmountTest(void)
{
	ST_terminalData_t termdata;
	printf("Tester Name : NADA EHAB\n");
	printf("Function name : isBelowMaxAmount\n");
	printf("Test Case 1 : 1000000.00\nExpected Result : EXceed max amount\nInput Data : ");
	setMaxAmount(&termdata, 10000.00);
	getTransactionAmount(&termdata);
	isBelowMaxAmount(&termdata);
	printf("\n");


	printf("Test Case 2 : 3450.00\nExpected Result : valid amount \nInput Data : ");
	setMaxAmount(&termdata, 10000.00);
	getTransactionAmount(&termdata);
	isBelowMaxAmount(&termdata);
	printf("\n");

}