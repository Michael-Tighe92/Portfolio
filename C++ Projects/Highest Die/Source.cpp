//Highest Die
//Programmed by: Michael Tighe
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
//Function prototypes
void Switching_Sides(bool & menu, bool & switch_sides);
void Ranking(int Cash_start);
int main()
{
	//Variables
	//Player's die and CPU's die
	int Player_die, CPU_die;
	//Starting amount of cash
	int Cash_start = 100;
	//Betting/Wager the amount of cash
	int Bet_amt;
	//User input through menu
	int User_input;
	//Boolean value for draws/menu/betting which will therefore loop
	bool menu = 0, betting=0, switch_sides=0;
	char letter;
	//seed
	srand(time(0));
	cout<<"*******************************Highest Die**************************************";
	cout<<"*                       Programmed by: Michael Tighe.                          *";
	cout<<"********************************************************************************"<<endl;
	cout<<"Hello and welcome to Highest Die! Please select an option from the given menu."<<endl;
	cout<<"(Must be either a 1 or a 2): "<<endl;
	cout<<"1.) Play Highest Die."<<endl;
	cout<<"2.) Instructions and rules on how to play Highest Die."<<endl;
	cin>>User_input;
	switch(User_input)
	{
	case 1: 
	while(menu == 0)
	{
	while(betting == 0)
	{
		cout<<"Total Cash: $"<<Cash_start<<endl;
		cout<<"Please place your bet/wager!: $";
		cin>>Bet_amt;
		cout<<endl;
		if(Bet_amt==0)
		{
			cout<<"Exiting game..."<<endl;
			cout<<"Total cash that you have earned: $"<<Cash_start<<endl;
			Ranking(Cash_start);
			system("pause");
			return 0;
		}
		if(Bet_amt>Cash_start)
		{
			cout<<"You don't have enough money to make this bet!"<<endl;
			cout<<"Try again!"<<endl;
		}
		else
			//This will jump back to the while loop again
			betting=1;
	}

	//Player rolls first!
	while(switch_sides==0)
	{
		//Player's die value is recorded here
		Player_die = rand() % 6 + 1;
		//CPU's die value is recorded here
		CPU_die = rand() % 6 + 1;
		//Displays Player's die value
		cout<<"Player's die: ";
		cout<<Player_die<<endl<<endl;
		if(Player_die == 1)
		{
			cout<<"I'm sorry! You lost by default since you rolled a 1!"<<endl;
			cout<<"You lost $"<<Bet_amt<<endl;
			Cash_start=Cash_start-Bet_amt;
			break;
		}
		if(Player_die == 6)
		{
			cout<<"Congrats! You won by default since you rolled a 6!"<<endl;
			cout<<"You won $"<<Bet_amt<<endl;
			Cash_start=Cash_start+Bet_amt;
			break;
		}
		//Dispalys CPU's die value
		cout<<"   CPU's die: ";
		cout<<CPU_die<<endl<<endl;
		
		
		//Singles calculation with Player winning.
		if(Player_die>CPU_die)
		{
			cout<<"Congrats! You won the match!"<<endl;
			cout<<"You won $"<<Bet_amt<<endl;
			Cash_start=Cash_start+Bet_amt;
			break;
		}
		//Singles calculation with CPU winning 
		if(CPU_die>Player_die)
		{
			cout<<"I'm sorry! You lost the match!"<<endl;
			cout<<"You lost $"<<Bet_amt<<endl;
			Cash_start=Cash_start-Bet_amt;
			break;
		}
		//Draw calculation 
		if(Player_die==CPU_die)
		{
			cout<<"Congrats! You won the match since it was a draw and you rolled first!"<<endl;
			cout<<"You won $"<<Bet_amt<<endl;
			Cash_start=Cash_start+Bet_amt;
			break;
		}
	}
	
	//CPU rolls first!
	while(switch_sides==1)
	{
		//CPU's die value is recorded here
		CPU_die = rand() % 6 + 1;
		//Player's die value is recorded here
		Player_die = rand() % 6 + 1;
		//Displays CPU's die value
		cout<<"   CPU's die: ";
		cout<<CPU_die<<endl<<endl;
		if(CPU_die == 1)
		{
			cout<<"Congrats! You won by default since CPU rolled a 1!"<<endl;
			cout<<"You won $"<<Bet_amt<<endl;
			Cash_start=Cash_start+Bet_amt;
			break;
		}
		if(CPU_die == 6)
		{
			cout<<"I'm sorry! You lost by default since CPU rolled a 6!"<<endl;
			cout<<"You lost $"<<Bet_amt<<endl;
			Cash_start=Cash_start-Bet_amt;
			break;
		}
		//Dispalys Player's die value
		cout<<"Player's die: ";
		cout<<Player_die<<endl<<endl;
		
		
		//Singles calculation with Player winning.
		if(Player_die>CPU_die)
		{
			cout<<"Congrats! You won the match!"<<endl;
			cout<<"You won $"<<Bet_amt<<endl;
			Cash_start=Cash_start+Bet_amt;
			break;
		}
		//Singles calculation with CPU winning 
		if(CPU_die>Player_die)
		{
			cout<<"I'm sorry! You lost the match!"<<endl;
			cout<<"You lost $"<<Bet_amt<<endl;
			Cash_start=Cash_start-Bet_amt;
			break;
		}
		//Draw calculation
		if(Player_die==CPU_die)
		{
			cout<<"I'm sorry! You lost the match since it was a draw and CPU rolled first!"<<endl;
			cout<<"You lost $"<<Bet_amt<<endl;
			Cash_start=Cash_start-Bet_amt;
			break;
		}
	}

	if(Cash_start>0)
	{
		//This will determine if the player or CPU starts first
		Switching_Sides(menu,switch_sides);
		//This will jump back to the while loop
		betting = 0;
	}
	else
	{
		cout<<"Sorry but you ran out of money!"<<endl;
		cout<<"G A M E O V E R ! ! !"<<endl;
		cout<<"Exiting program..."<<endl;
		system("pause");
		return 0;
	}
	}
		break;
	case 2:
		cout<<"***Instructions/rules on how to play Highest Die***"<<endl;
		cout<<"1.) The player starts with $100."<<endl;
		cout<<"2.) The player must make a bet/wager out of their current amount of cash."<<endl;
		cout<<"3.) The object of the game is to roll a higher number over the other player."<<endl;
		cout<<"4.) If there is a draw then the player who rolled first wins by default."<<endl;
		cout<<"5.) If you roll a 6 then you automatically win."<<endl;
		cout<<"6.) If you roll a 1 then you automatically lose."<<endl;
		cout<<"7.) Each match will change the order on who rolls first."<<endl;
		cout<<"8.) To exit the game just bet 0!"<<endl;
		cout<<"9.) If you run out of money then the game is over and you will restart with"<<endl;
		cout<<"The initial $100"<<endl;
		system("pause");
		return 0;
	default:
		cout<<"Error! You did not enter the correct number given to you!" <<endl;
		break;
	}
}

void Switching_Sides(bool & menu, bool & switch_sides)
{
		menu=0;
			if(switch_sides==0)
			{
				cout<<"Switching sides..."<<endl;
				cout<<"CPU now rolls first!"<<endl<<endl;
				switch_sides=1;
			}
			else
			{
				cout<<"Switching sides..."<<endl;
				cout<<"Player now rolls first!"<<endl<<endl;
				switch_sides=0;
			}
}

void Ranking(int Cash_start)
{
	if(Cash_start<200)
	{
		cout<<"Rank 1: "<<endl;
		cout<<"You can do better then that!"<<endl;
	}
	if(Cash_start>=200 && Cash_start<400)
	{
		cout<<"Rank 2: "<<endl;
		cout<<"Good Job!"<<endl;
	}
	if(Cash_start>=400 && Cash_start<1000)
	{
		cout<<"Rank 3: "<<endl;
		cout<<"Awesome!"<<endl;
	}
	if(Cash_start>=1000 && Cash_start<5000)
	{
		cout<<"Rank 4: "<<endl;
		cout<<"Amazing! Keep up the good work!"<<endl;
	}
	if(Cash_start>=5000 && Cash_start<10000)
	{
		cout<<"Rank 5: "<<endl;
		cout<<"Magnificent! Just one more rank left!"<<endl;
	}
	if(Cash_start>=10000)
	{
		cout<<"Rank MAX: "<<endl;
		cout<<"You are a grandmaster! Congratulations on all your hard work!"<<endl;
	}
}