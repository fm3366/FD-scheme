#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include<string>
struct Team
{
	std::string ClubName;
	int GoalsScoared;
	int GoalsCanceled;
};
struct statistics
{
	int goals;
	int assists;
	bool yellow_card;
	bool red_card;
	float rank;
};
struct penalty
{
	int WasPenalty;
	int PenGoals;
};
class FieldPlayer
{
protected:
	std::string SurName;
	int points;
	statistics Stat;
	bool IsOnMatch;
	penalty Pen;
	Team playerClub;
	float cost;
public:
	FieldPlayer()
	{
		SurName = "Maksimov";
		points = 0;
		IsOnMatch = false;
		Stat.goals = 0;
		Stat.assists = 0;
		Stat.yellow_card = false;
		Stat.red_card = false;
		Stat.rank  = 0;
		Pen.WasPenalty = 0;
		Pen.PenGoals = 0;
		playerClub.ClubName = "Man Utd";
		playerClub.GoalsCanceled = 0;
		playerClub.GoalsScoared = 0;
		cost = 0;
	}
	FieldPlayer(int Points, bool OnMatch, int Goals, int Asis, bool IsYellow, bool IsRed, float Rank, int WasPen, int Penalty, std::string Name,
		std::string NameClub, int scored, int canceled, float Pcost)
	{
		SurName = Name;
		points = Points;
		IsOnMatch = OnMatch;
		Stat.goals = Goals;
		Stat.assists = Asis;
		Stat.yellow_card = IsYellow;
		Stat.red_card = IsRed;
		Stat.rank = Rank;
		Pen.WasPenalty = WasPen;
		Pen.PenGoals = Penalty;
		playerClub.ClubName = NameClub;
		playerClub.GoalsCanceled = canceled;
		playerClub.GoalsScoared = scored;
		cost = Pcost;
	}
	FieldPlayer(const FieldPlayer &x)
	{
		SurName = x.SurName;
		points = x.points;
		IsOnMatch = x.IsOnMatch;
		Stat.goals = x.Stat.goals;
		Stat.assists = x.Stat.assists;
		Stat.yellow_card = x.Stat.yellow_card;
		Stat.red_card = x.Stat.red_card;
		Stat.rank = x.Stat.rank;
		Pen.WasPenalty = x.Pen.WasPenalty;
		Pen.PenGoals = x.Pen.PenGoals;
		playerClub.ClubName = x.playerClub.ClubName;
		playerClub.GoalsCanceled = x.playerClub.GoalsCanceled;
		playerClub.GoalsScoared = playerClub.GoalsScoared;
		cost = x.cost;
	}
	FieldPlayer& operator=(const FieldPlayer &x)
	{
		SurName = x.SurName;
		points = x.points;
		IsOnMatch = x.IsOnMatch;
		Stat.goals = x.Stat.goals;
		Stat.assists = x.Stat.assists;
		Stat.yellow_card = x.Stat.yellow_card;
		Stat.red_card = x.Stat.red_card;
		Stat.rank = x.Stat.rank;
		Pen.WasPenalty = x.Pen.WasPenalty;
		Pen.PenGoals = x.Pen.PenGoals;
		playerClub.ClubName = x.playerClub.ClubName;
		playerClub.GoalsCanceled = x.playerClub.GoalsCanceled;
		playerClub.GoalsScoared = playerClub.GoalsScoared;
		cost = x.cost;
		return *this;
	}
	void StatRank()
	{
		int plusPoint;
		plusPoint = Stat.goals * 10 + Stat.assists * 10 + (int)Stat.rank - (Pen.WasPenalty - Pen.PenGoals)*5 ;
		if (Stat.yellow_card == true)
			plusPoint = plusPoint - 3;
		if (Stat.red_card == true)
			plusPoint = plusPoint - 5;
		if (playerClub.GoalsCanceled = playerClub.GoalsScoared)
			plusPoint = plusPoint + 2;
		if (playerClub.GoalsScoared - playerClub.GoalsCanceled>= 3)
			plusPoint = plusPoint + 5;
		if (playerClub.GoalsScoared - playerClub.GoalsCanceled >= 0)
			plusPoint = plusPoint + 5;
		points = points + plusPoint;
	}
	void ResetOnMatch()
	{
		if (IsOnMatch == false)
			points = 0;
	}
	friend class FutTeam;
};
class DefendPlayer : public FieldPlayer
{
	public:
		void Capitan()
		{
			points = points * 2;
		}
		virtual void StatRank()
		{
			int plusPoint;
			plusPoint = Stat.goals * 10 + Stat.assists * 10 + (int)Stat.rank - (Pen.WasPenalty - Pen.PenGoals) * 5;
			if (Stat.yellow_card == true)
				plusPoint = plusPoint - 1;
			if (Stat.red_card == true)
				plusPoint = plusPoint - 5;
			if (playerClub.GoalsCanceled = playerClub.GoalsScoared)
				plusPoint = plusPoint + 2;
			if (playerClub.GoalsScoared - playerClub.GoalsCanceled >= 3)
				plusPoint = plusPoint + 5;
			if (playerClub.GoalsScoared - playerClub.GoalsCanceled >= 0)
				plusPoint = plusPoint + 5;
			if (playerClub.GoalsCanceled == 0)
				plusPoint = plusPoint + 5;
			points = points + plusPoint;
		}

};
class Goalkeeper: protected DefendPlayer
{
	virtual void StatRank()
	{
		int plusPoint;
		plusPoint = Stat.goals * 10 + Stat.assists * 10 + (int)Stat.rank + (Pen.WasPenalty - Pen.PenGoals) * 10;
		if (Stat.yellow_card == true)
			plusPoint = plusPoint - 1;
		if (Stat.red_card == true)
			plusPoint = plusPoint - 5;
		if (playerClub.GoalsCanceled = playerClub.GoalsScoared)
			plusPoint = plusPoint + 2;
		if (playerClub.GoalsScoared - playerClub.GoalsCanceled >= 3)
			plusPoint = plusPoint + 5;
		if (playerClub.GoalsScoared - playerClub.GoalsCanceled >= 0)
			plusPoint = plusPoint + 5;
		if (playerClub.GoalsCanceled == 0)
			plusPoint = plusPoint + 5;
		points = points + plusPoint;
	}
};

class FutTeam
{
	private:
		float TeamCost;
		FieldPlayer* AList;
		FieldPlayer* MList;
		DefendPlayer* DList;
		int Alength;
		int Mlength;
		int Dlength;
		int LastAtP;
		int LastMidP;
		int LastDefP;
	public:
		FutTeam(int def = 4, int midfield = 4, int atak = 2)
		{
			Alength = atak;
			Mlength = midfield;
			Dlength = def;
			LastAtP = 0;
			LastMidP = 0;
			LastDefP = 0;
			AList = new FieldPlayer[Alength];
			MList = new FieldPlayer[Mlength];
			DList = new DefendPlayer[Dlength];
		}
		void AddAPlayer(FieldPlayer &x)
		{
			*(AList+LastAtP) = (x);
			LastAtP = LastAtP + 1;
			TeamCost = TeamCost + x.cost;
		}
		void AddMPlayer(FieldPlayer &x)
		{
			*(MList + LastMidP) = (x);
			LastMidP = LastMidP + 1;
			TeamCost = TeamCost + x.cost;
		}
		void AddDPlayer(DefendPlayer &x)
		{
			*(DList + LastDefP) = (x);
			LastDefP = LastDefP + 1;
			TeamCost = TeamCost + x.cost;
		}
		~FutTeam()
		{
			delete[] AList;
			delete[] MList;
			delete[] DList;
		}
};
using namespace sf;
int main()
{
	int atak, def, midfild;
	std::cout << " Number of Defenders: ";
		std::cin >> def;
		std::cout << " Number of Midfields: ";
		std::cin >> midfild;
		std::cout << " Numder of strikers: ";
		std::cin >> atak;
	FutTeam Team1;
	FutTeam(def, midfild, atak);


	std::cout << "class norm";
	RenderWindow window(VideoMode(1200, 1000), "SFMLworks");
	RectangleShape Player[11];
	Player[0].setSize(Vector2f(100, 100));
	Player[0].setFillColor(Color::Red);
	Player[0].setPosition(550, 890);
	for (int i = 1; i< (1+def); i ++)
	{
		Player[i].setSize(Vector2f(100, 100));
		Player[i].setFillColor(Color::Red);
		Player[i].setPosition(650 - def*100 + (i-1)*200, 640);
	}
	for (int i1 = (1+def); i1 < (1 + def+midfild); i1++)
	{
		Player[i1].setSize(Vector2f(100, 100));
		Player[i1].setFillColor(Color::Red);
		Player[i1].setPosition(650 - midfild * 100 + (i1- def - 1) * 200, 390);
	}
	for (int i2 = (1 + def + midfild); i2 < (1 + def + midfild + atak); i2++)
	{
		Player[i2].setSize(Vector2f(100, 100));
		Player[i2].setFillColor(Color::Red);
		Player[i2].setPosition(650 - atak * 100 + (i2 - def - midfild - 1) * 200, 140);
	}
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		for (int k = 0; k<1 + def + midfild + atak; k++)
		{
			window.draw(Player[k]);
		}
		window.display();
	}
	return 0;
}