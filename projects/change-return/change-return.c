/************************************************
 * change return                                *
 *                                              *
 *  -> take in a price and the payed money      *
 *      and calculate the change                *
 *  -> additionally calculate how many of the   *
 *      different coins and banknotes you       *
 *      need to return
 ************************************************/


/* includes */
#include <stdio.h>
#include <math.h>


/* declarations */
float Difference(float, float);
void ChangeReturn(float, float);

/* main / wrapper function */
int main()
{
    /* take in price and the payed money and 
     * calculate the difference
     * */
    float price, money_payed;  

    printf("Enter a price(EUR): ");
    scanf("%f", &price);
    printf("Enter the money(EUR) you pay: ");
    scanf("%f", &money_payed);
   
    ChangeReturn(price, money_payed);

    return 0;
}


/* definitions */
/* calculate the rounded difference o between two values */
float Difference(float value_one, float value_two)
{
    return (roundf((value_one - value_two) * 100) / 100);
}


/* calculate the change return */
void ChangeReturn(float price, float money_payed)
{
    float difference = Difference(money_payed, price);
    
    /* run until enough money was payed */
    while(difference < 0)
    {
        float additional_money = 0.0;

        printf("Sorry, you have to pay %5.2f Euros more.\n", (difference * -1));
        printf("Additional money(EUR): ");
        scanf("%f", &additional_money);

        money_payed = money_payed + additional_money;
        difference = Difference(money_payed, price);
    }
    
    /* EUR */
    const float MONEY[] = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};

    const int amount_of_money_types = sizeof(MONEY) / sizeof(MONEY[0]);

    /* money to return */
    float return_money[amount_of_money_types];
    
    /* calculate the exact payback money
     * how many of every coin and banknote 
     * */
    for(int i = 0; i < 15; i++)
    {
        return_money[i] = floorf(difference / MONEY[i]);
        difference = Difference(difference, (return_money[i] * MONEY[i]));

        if(difference == 0.0)
        {
            break;
        }
    }
    
    /* print change return */
    printf("Here is your change: \n");

    for (int j = 0; j < 15; j++)
    {
        if(return_money[j] >= 1)
        {
            printf("%5.0f x %5.2f EUR\n", return_money[j], MONEY[j]);
        }
    }
  
    printf("\nThank you very much.\n");
}