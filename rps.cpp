#include "std_lib_facilities.h"

vector<int> nums{ 3 }; //this will hold fibonacci numbers.

int fibo() //to generate series upto seed given.
{
	if (nums.size() == 1) //this is required for inserting 2nd number or else program will crash.
	{
		nums.push_back(nums[0] + 2); 
	}
	else
	{
		nums.push_back(nums[nums.size() - 1] + nums[nums.size() - 2]); //pushing latest and latest - 1th element as new number in series.
	}
	return nums[nums.size() - 1]; //returning last number.
}

void generate_seed(int seed)
{
	if (seed < 0) //negative numbers will cause logic error so make positive.
	{
		seed = -seed;
	}
	seed %= 10; // making the seed not more than 10
	if (seed == 0)
	{
		return; //wasn't necessary but returning here itself will save time.
	}
	for (int i = 0; i < seed; ++i)
	{
		fibo(); //further logic.
	}
}

int main()
{
	int seed{ 0 }, user_score{ 0 }, computer_score{ 0 }, draws{ 0 }, user_choice_number{ 0 }, computer_choice_number{ 0 };
	string choice{}, computer_choice{}, result{};

	cout << "Enter seed:";
	cin >> seed;

	generate_seed(seed); //giving a seed for randomness of selection.

	cout << "Enter rock, paper or scissor:";
	while (cin >> choice)
	{
		//converting string in form of number representation.
		if (choice == "rock" || choice == "r")
		{
			user_choice_number = 0;
		}
		else if (choice == "paper" || choice == "p")
		{
			user_choice_number = 1;
		}
		else if (choice == "scissor" || choice == "s")
		{
			user_choice_number = 2;
		}
		else
		{
			cout << "Bad operator.\n";
			cin.clear();
			continue; //ask again.
		}

		computer_choice_number = fibo() % 3; //modulus of number under 10 and 3 to give 1,2 or 0.

		switch (computer_choice_number) //this will have either 1,2 or 0
		{
		case 0:
			computer_choice = "rock";
			break;
		case 1:
			computer_choice = "paper";
			break;
		case 2:
			computer_choice = "scissor";
			break;
		default:
			break;
		}

		if (computer_choice_number == user_choice_number) //computer and you having same choice. paper and paper, rock and rock, scissor and scissor.
		{
			cout << "Match Draw!\n";
			++draws;//increasing draw score.
		}
		else
		{
			result = "I win!\n";//setting as default.

			if (user_choice_number == 0 && computer_choice_number == 2)//rock beats scissor
			{
				result = "You win!\n";
				++user_score;
			}
			else if (user_choice_number == 1 && computer_choice_number == 0)//paper beats rock
			{
				result = "You win!\n";
				++user_score;
			}
			else if (user_choice_number == 2 && computer_choice_number == 1)//scossor beats paper
			{
				result = "You win!\n";
				++user_score;
			}
			else
			{
				++computer_score;
			}
			cout << "\nYou said:" << choice << "\tComputer said:" << computer_choice << "\t" << result << "\n";
			cout << "Your score:" << user_score << "\tComputer Score:" << computer_score << "\n\n";
		}
		cout << "Let's play another game:";
	}

	keep_window_open();
}