#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "card.h"
#include <string.h>
#include <ctype.h>

#define maxnamesize 24
#define minnamesize 20



EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	uint8_t name[30] = { 0 };
	gets(cardData->cardHolderName);
	uint8_t namelength = strlen(cardData->cardHolderName);

	for (uint8_t i = minnamesize; i > maxnamesize; i++)
	{
		if (!isalpha(name[i]) && name[i] != " ")
		{
			printf("ACTUAL RESULT:WRONG_NAME\n");
			return WRONG_NAME;
		}
	}

	 if(namelength == '/0')
	{
		return WRONG_NAME;
	}
	else if (namelength > maxnamesize || namelength < minnamesize)
	{
		printf("ACTUAL RESULT:WRONG_NAME\n");
		return WRONG_NAME;
	}
	else
	{
		printf("ACTUAL RESULT:name ok\n");
		return CARD_OK;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	//printf("Enter your card expire date ");
	gets(cardData->cardExpirationDate);

	if(cardData->cardExpirationDate=='/0')
	{
		printf("ACTUAL RESULT: WRONG EXPIRE DATE\n");
		return WRONG_EXP_DATE;
	}
	uint8_t explength = strlen(cardData->cardExpirationDate);
	 if(explength !=5 )
	{
		printf("ACTUAL RESULT: WRONG EXPIRE DATE\n");
		return WRONG_EXP_DATE;
	}
	 else if (cardData->cardExpirationDate[2] != '/' || cardData->cardExpirationDate[3]<2 || cardData->cardExpirationDate[4]<2)
	 {
		 printf("ACTUAL RESULT: WRONG EXPIRE DATE\n");
		 return WRONG_EXP_DATE;
	 }
	 
	 
		 printf("ACTUAL RESULT:DATE IS OK\n");
		 return CARD_OK;
	 
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	//printf("Enter your PAN number that is between 16 and 19 numbers");
	uint8_t i = 0;
	gets(cardData->primaryAccountNumber);
	uint8_t panlength = strlen(cardData->primaryAccountNumber);
	for (i = 0; i < panlength; i++)
	{
		if (cardData->primaryAccountNumber[i] < '0' || cardData->primaryAccountNumber[i] > '9') {
			//printf("ACTUAL RESULT: Wrong PAN format. Please enter only numeric characters.\n");
			return WRONG_PAN;
		}
	}
	if (panlength < 16 || panlength >19)
	{
		//printf("ACTUAL RESULT: wrong pan number\n");
		return WRONG_PAN;
	}
  	else
	{
			//printf("ACTUAL RESULT: PAN IS CORRECT\n");
			return CARD_OK;
	}
	
}


//tets

void getCardHolderNameTest(void)
{ 
	ST_cardData_t name;

	printf("TESTER NAME :nada ehab\n");
	printf("Function Name: getCardHolderName\n");
	printf("Test case 1 \nExpected Result: wrong name \nInput data\n");
	getCardHolderName(&name);
	printf("\n");


	printf("TESTER NAME :nada ehab nada ehab nada ehab nada nada\n");
	printf("Function Name: getCardHolderName\n");
	printf("Test case 2 \nExpected Result: wrong name \nInput data\n");
	getCardHolderName(&name); 
	printf("\n");

	printf("TESTER NAME :nada ehab fathy ghorab123\n");
	printf("Function Name: getCardHolderName\n");
	printf("Test case 3 \nExpected Result: wrong name\nInput data\n");
	getCardHolderName(&name);
	printf("\n");

	printf("TESTER NAME :nada ehab fathy ghorab\n");
	printf("Function Name: getCardHolderName\n");
	printf("Test case 4 \nExpected Result: name ok \nInput data\n");
	getCardHolderName(&name);
	

}

void getCardExpiryDateTest(void)
{
	ST_cardData_t EXPIREDATE;
	printf("Tester Name: NADA EHAB\n");
	printf("Function Name: getCardExpiryDate\n");
	printf("Test case 1: 25/05/2025 \nExpected Result: wrong expire date \nInput data\n");
	getCardExpiryDate(&EXPIREDATE);
	printf("\n");

	printf("Tester Name: NADA EHAB\n");
	printf("Function Name: getCardExpiryDate\n");
	printf("Test case 2: 255 \nExpected Result: wrong expire date \nInput data\n");
	getCardExpiryDate(&EXPIREDATE);
	printf("\n");

	printf("Tester Name: NADA EHAB\n");
	printf("Function Name: getCardExpiryDate\n");
	printf("Test case 3: 05-25 \nExpected Result: wrong expire date \nInput data\n");
	getCardExpiryDate(&EXPIREDATE);
	printf("\n");

	printf("Tester Name: NADA EHAB\n");
	printf("Function Name: getCardExpiryDate\n");
	printf("Test case 4: 05/19 \nExpected Result: wrong expire date \nInput data\n");
	getCardExpiryDate(&EXPIREDATE);
	printf("\n");


	printf("Tester Name: NADA EHAB\n");
	printf("Function Name: getCardExpiryDate\n");
	printf("Test case 5: 05/25 \nExpected Result: DATE IS OK \nInput data\n");
	getCardExpiryDate(&EXPIREDATE);
	printf("\n");
}

void getCardPANTest(void)
{
	ST_cardData_t PANNUM;
	printf("Tester Name: NADA EHAB\n");
	printf("Function Name: getCardPAN\n");
	printf("Test case 1: 2345678 \nExpected Result: wrong pan number \nInput data\n");
	getCardPAN(&PANNUM);
	printf("\n");

	printf("Tester Name: NADA EHAB\n");
	printf("Function Name: getCardPAN\n");
	printf("Test case 2: 23456789123456789123456 \nExpected Result: wrong pan number \nInput data\n");
	getCardPAN(&PANNUM);
	printf("\n");

	printf("Tester Name: NADA EHAB\n");
	printf("Function Name: getCardPAN\n");
	printf("Test case 3: 2345678912345678912ght \nExpected Result: wrong pan number \nInput data\n");
	getCardPAN(&PANNUM);
	printf("\n");

	printf("Tester Name: NADA EHAB\n");
	printf("Function Name: getCardPAN\n");
	printf("Test case 4:1234567123456781 \nExpected Result: PAN IS CORRECT\nInput data\n");
	getCardPAN(&PANNUM);
	printf("\n");


}