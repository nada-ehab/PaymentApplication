#include <stdio.h>
#include <stdlib.h>
#include"card.h"
#include <string.h>

#define maxnamesize 24
#define minnamesize 20



EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("please enter your name ensuring that the name is between 20 and 24 characters in length ");
	gets(cardData->cardHolderName);
	printf("\n");
	uint8_t namelength = strlen(cardData->cardHolderName);
	if(namelength == '/0')
	{
		return WRONG_NAME;
	}
	else if(namelength > maxnamesize || namelength < minnamesize)
	{
		return WRONG_NAME;
	}
	else
	{
		return CARD_OK;
	}
}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	printf("Enter your card expire date ");
	gets(cardData->cardExpirationDate);
	printf("\n");

	if(cardData->cardExpirationDate=='/0')
	{
		return WRONG_EXP_DATE;
	}
	uint8_t explength = strlen(cardData->cardExpirationDate);
	if(explength !=5 )
	{
		return WRONG_EXP_DATE;
	}
	else
	{
		return CARD_OK;
	}

}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("Enter your PAN number that is between 16 and 19 numbers");
	gets(cardData->primaryAccountNumber);
	printf("\n");

	if(cardData->primaryAccountNumber == '/0')
	{
		return WRONG_PAN;
	}

	uint8_t panlength = strlen(cardData->primaryAccountNumber);
	if(panlength <16 || panlength >19 )
	{
		return WRONG_PAN;
	}
	else
	{
		return CARD_OK;
	}
}


//tets

void getCardHolderNameTest(void)
{
	ST_cardData_t name;

	printf("TESTER NAME :nada ehab \n");
	printf("Function Name: getCardHolderName \n");

	printf("Test case 1 \n Expected Result: wrong name \n Input data\n");
	getCardHolderName(&name);
}
