#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int pika=0,squart=0,charm=0;
int pika_price=6,charm_price=5,squart_price=5;
void acceptinput();
float calculatediscount(int typen);
float calctotal(float discount);
int minim(int a,int b,int c);
int min(int a,int b);
int main()
{
    clrscr();
    int typen=0;
    double discount=0,discprice=0;
    printf("How many pikachus are you gonna buy");

//  below is the logic to check whether the valid input is given by end user or not
    while(scanf("%d",&pika) !=1)
    {
    printf("please enter the correct value");
    while(getchar() != '\n');
    }
    printf("Number of pikachus you have entered is : %d \n",pika);
    printf("How many charmenders are you gonna buy");
    while(scanf("%d",&charm) !=1)
    {
    printf("please enter the correct value");
    while(getchar() != '\n');
    }
    printf("Number of charmenders you have entered is : %d \n",charm);
    printf("How many squartles are you gonna buy");
    while(scanf("%d",&squart) !=1)
    {
    printf("please enter the correct value");
    while(getchar() != '\n');
    }
    printf("Number of squartles you have entered is : %d \n",squart);
     acceptinput();
      return 0;
}
     void acceptinput()
{
     int type=0;
     float price=0,totalprice=0,discount=0;
     int a,b,c,d;
//  below is the logic to check whether the user has bought three different pokemons and to find out the discount for the same.
    if(pika!=0 && squart!=0 && charm!=0)
	{
		a= minim(pika,squart,charm);
		discount=((pika_price+squart_price+charm_price) * 20.00/100.00);
		price= (pika_price+squart_price+charm_price)-discount;
		totalprice=totalprice + (a*price);
		pika=pika-a;
		squart=squart-a;
		charm=charm-a;

	}

//   below is the logic to check whether the user has bought two different pokemons and to find out the discount for the same.
	if(pika==0 && squart!=0 && charm!=0)
	{
		b=min(squart,charm);
		price= (squart_price+charm_price)-((squart_price+charm_price) * 10.00/100.00);
		totalprice=totalprice + (b*price);
		squart=squart-b;
		charm=charm-b;
	}
	if(squart==0 && pika!=0 && charm!=0)
	{
		c=min(pika,charm);
		price= (pika_price+charm_price)-((pika_price+charm_price) * 10.00/100.00);
		totalprice= totalprice + (c*price);
		pika=pika-c;
		charm=charm-c;

	}
	if(charm==0 && pika!=0 && squart!=0)
	{
		d=min(pika,squart);
		price= (pika_price+squart_price)-((pika_price+squart_price) * 10.00/100.00);
		totalprice= totalprice + (d*price);
		squart=squart-d;
		pika=pika-d;

	}
//   below is the logic to check whether the user has bought one pokemon and to find out the calculate the final price.
	if(pika==0 && charm==0 && squart!=0)
	{

		totalprice=totalprice + (squart_price*squart);
	}
	if(squart==0 && charm==0 && pika!=0)
	{

		totalprice=totalprice + (pika_price*pika);
	}
	if(pika==0 && squart==0 && charm!=0)
	{

		totalprice=totalprice + (charm_price*charm);
	}

	printf("total price of pokemons after discount is = %f",totalprice);
 }
//   logic function to calculate the minimum value between three pokemons
  int minim(int a,int b,int c)
{
    if (a < b)
    {
	if (a < c)
	     return a;
	else
	     return c;
    }

    if (b < c)
	return b;
    else
	return c;
}
//   logic function to calculate the minimum value between two pokemons
int min(int a,int b)
{
    if (a < b)
	return a;
    else
	return b;
}

