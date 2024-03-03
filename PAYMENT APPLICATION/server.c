#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "server.h"
#include <string.h>

ST_accountsDB_t accountsDB[255] = { {2000.0, RUNNING, "8989374615436851"},//valid account ,running ,low balance
	{30000.0,BLOCKED,"9876234561234567"}//valid,not low balance,blocked
	,{43589.239,RUNNING,"2384965134765234"},
	{7639.58,RUNNING,"2384759687623475"}, {100000.0, BLOCKED, "5807007076043875"} };

ST_transaction_t transactionsDB[255] = { 0 };



EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
{
	uint8_t i = 0;
	
	for (i = 0; i < 255; i++)
	{
		uint8_t cmppan = strcmp(cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber);
		if (cmppan == 0)
		{
			accountRefrence->primaryAccountNumber == accountsDB[i].primaryAccountNumber;
			//printf("Actual Result : SERVER_OK\n");
			return SERVER_OK;
		}
	}
	accountRefrence = NULL;
	//printf("Actual Result : ACCOUNT_NOT_FOUND\n");
	return ACCOUNT_NOT_FOUND;
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{

	if (accountRefrence->state == BLOCKED)
	{
		printf("ACTUAL RESULT : BLOCKED_ACCOUNT");
		return BLOCKED_ACCOUNT;
	}
	else
	{
		printf("ACTUAL RESULT : SERVER_OK");
		return SERVER_OK;
	}
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	uint8_t i = 0;
	for (i = 0; i < 255; i++)
	{
		if (termData->transAmount <= accountRefrence->balance)
		{
			accountRefrence->balance == accountsDB[i].balance;
			//printf("Actual Result : SERVER_OK\n");
			return SERVER_OK;
		}
	}
	 accountRefrence = NULL;
	//printf("Actual Result : LOW_BALANCED\n");
	return LOW_BALANCE;
}
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	uint8_t i = 0;
	transData->transactionSequenceNumber = i;
	memcpy(transactionsDB[i].cardHolderData.cardHolderName, transData->cardHolderData.cardHolderName, 25);
	memcpy(transactionsDB[i].cardHolderData.primaryAccountNumber, transData->cardHolderData.primaryAccountNumber, 20);
	memcpy(transactionsDB[i].cardHolderData.cardExpirationDate, transData->cardHolderData.cardExpirationDate, 5);

	memcpy(transactionsDB[i].terminalData.transactionDate, transData->terminalData.transactionDate, 10);
	memcpy(&transactionsDB[i].terminalData.transAmount, &transData->terminalData.transAmount, 8);
	transactionsDB[i].transState = transData->transState;
	i++;
	return SERVER_OK;
}
void listSavedTransactions(void)
{
	printf("Transaction Sequence Number:")

}
EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	printf("enter your PAN\n");
	getCardPAN(&transData->cardHolderData);
	ST_accountsDB_t accountRef;

	uint8_t i = 0;
	for (i = 0; i <5; i++)
	{
			if (isValidAccount(&transData->cardHolderData, accountsDB[i].primaryAccountNumber) == ACCOUNT_NOT_FOUND) {
				transData->transState = FRAUD_CARD;
				printf("Actual Result : FRAUD_CARD");
				return FRAUD_CARD;
			}



			getTransactionAmount(&transData->terminalData);
			if (isAmountAvailable(&(transData->terminalData), &accountsDB[i].balance) == LOW_BALANCE)
			{
				transData->transState == DECLINED_INSUFFECIENT_FUND;
				printf("Actual Result : DECLINED_INSUFFECIENT_FUND");
				return DECLINED_INSUFFECIENT_FUND;
			}
			else
			{
			
			}

		   

			
	        
    }
	
	 
	
}






//TEST_FUNCTIONS

void isValidAccountTest(void)
{
	ST_cardData_t data;
	ST_accountsDB_t acc;

	printf("Tester Name : NADA EHAB\n");
	printf("Function name : isValidAccount\n");
	printf("Test Case 1 : 8989374615436851 \nExpected Result : SERVER_OK\nInput Data : ");
	getCardPAN(&data);
	isValidAccount(&data, &acc); 
	printf("\n");

	printf("Test Case 2 : 8934565135672345 \nExpected Result : ACCOUNT_NOT_FOUND\nInput Data : ");
	getCardPAN(&data);
	isValidAccount(&data, &acc);
	printf("\n");

}
void isBlockedAccountTest(void)
{

	printf("Tester Name : NADA EHAB\n");
	printf("Function name : isBlockedAccount\n");
	printf("Test Case 1 : {43589.239,RUNNING,2384965134765234}\nExpected Result : SERVER_OK\n");
	isBlockedAccount(&accountsDB[3]);
	printf("\n");

	printf("\n\nTest Case 2 : {100000.0, BLOCKED, 5807007076043875}\nExpected Result : BLOCKED_ACCOUNT\n");
	isBlockedAccount(&accountsDB[1]);
	printf("\n");
}
void isAmountAvailableTest(void)
{
	ST_cardData_t data;
	printf("Tester Name : NADA EHAB\n");
	printf("Function name : isAmountAvailable\n");
	printf("Test Case 1 : 2500 \nExpected Result : LOW_BALANCE \nInput Data : ");
	getTransactionAmount(&data);
	isAmountAvailable(&data, &accountsDB[0].balance);
	printf("\n");
	
	printf("Test Case 2 : 2500 \nExpected Result : SERVER_OK \nInput Data : ");
	getTransactionAmount(&data);
	isAmountAvailable(&data, &accountsDB[1].balance);
	printf("\n");
}
void saveTransactionTest(void)
{

}



void recieveTransactionDataTest(void)
{
	ST_transaction_t data;
	ST_cardData_t cardadta;
	printf("Tester Name : NADA EHAB\n");
	printf("Function name : recieveTransactionDataTest\n");
	printf("Test Case 1 :  \nExpected Result : FARUD_CARD \nInput Data : ");
	recieveTransactionData(&data);
	printf("\n");
}
