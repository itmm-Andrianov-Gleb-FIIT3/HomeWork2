#include <iostream>
#include <stdio.h>
#include "conio.h"
#include <time.h>


class Fighter {

protected:
	int Health;
	int Damage;
	std::string Weapon;
public:
	Fighter(int _Health, int _Damage, std::string _Weapon) {
		Health = _Health;
		Damage = _Damage;
		Weapon = _Weapon;
	}
};

void Pcw(int WarriorHealth,int WarriorDamage) {
	std::cout << "\n\n\t\t    HEALTH:" << WarriorHealth;
	std::cout << "\n\n\t\t    WEAPON:Halberd ";
	std::cout << "\n\t\t    DAMAGE:" << WarriorDamage;
	std::cout << "\n\n\t\t    SPECIAL ABILITY:ARMOR";
	std::cout << "\n\t\t    ARMOR:A WARRIOR always block 50% of incoming damage.";
}

void Pcr(int RogueHealth,int RogueDamage) {
	std::cout << "\n\n\t\t    HEALTH:" << RogueHealth;
	std::cout << "\n\n\t\t    WEAPON:Rapier ";
	std::cout << "\n\t\t    DAMAGE:" << RogueDamage;
	std::cout << "\n\n\t\t    SPECIAL ABILITY:DODGE";
	std::cout << "\n\t\t    DODGE: With a 50% chance, ROGUE can DODGE  his enemy's attack.";
}

void Attack(float WH, float RH, float RD, float WD, float CRD, float CRW, int Name) {
	
	int DG;
	int CRT;
	
	if (Name == 1) {
		CRT = rand() % 20;
		if (CRT == 20) {
			WH = WH - CRD;
		}
		else {
			WH = WH - RD;
		}
	}
	else if (Name == 2) {
		CRT = rand() % 20;
		DG = rand() % 2;
		if (DG == 1) {
			RH = RH - WD;
		}
		else {
			if (CRT == 20) {
				RH = RH - CRW;
			}
			else {
				RH = RH - WD;
			}
		}
	}
	BattleS(WH, RH, RD, WD, CRD, CRD, Name);
}

void Defence(float WH, float RH, float RD, float WD, float CRD, float CRW, int Name) {
	
	int DG;
	int CRT;
	
	if (Name == 1) {
		DG = rand() % 2;
		if (DG == 1) {
			RH = RH - WD;
		}
	}
	else if (Name == 2) {
		WH = WH - RD;
	}
	BattleS(WH, RH, RD, WD, CRD, CRD, Name);
}

void Move(float WH, float RH, float RD, float WD, float CRD, float CRW, int Name) {
	int MV;
	std::cout << "\n\n\t\t\t 1)ATTACK   2)DEFENCE";
	std::cout << "\n\t\t\t     YOUR MOVE:";
	std::cin >> MV;
	
    if (MV == 1) {
		Attack(WH, RH, RD, WD, CRD, CRW, Name);
	}
	else if (MV == 2) {
		Defence(WH, RH, RD, WD, CRD, CRW, Name);
	}

}

void BattleStatsStart(float WH, float RH, float RD, float WD, float CRD, float CRW,int Name) {

	std::cout << "\n\n\t\t WARRIOR HEALTH:" << WH << "\tROGUE HEALTH:" << RH;

	if (Name == 2) {
		std::cout << "\n\n\t\t\t ROGUE GO FIRST";
		Defence(WH, RH, RD, WD, CRD, CRW, Name);
	}
	else if (Name == 1) {
		Move(WH,RH,RD,WD,CRD,CRW,Name);

	}

}

void BattleS(float WH, float RH, float RD, float WD, float CRD, float CRW, int Name) {

	std::cout << "\n\n\t\t WARRIOR HEALTH:" << WH << "\tROGUE HEALTH:" << RH;

	if (Name == 2) {
		Move(WH, RH, RD, WD, CRD, CRW, Name);
	}
	else if (Name == 1) {
		Move(WH, RH, RD, WD, CRD, CRW, Name);

	}

}

void FF(float RogueHealth, float RogueDamage, float WarriorHealth, float WarriorDamage, int Name) {

	float WH, RH, RD ,WD, CRD, CWD;

	WH = WarriorHealth;
	RH = RogueHealth;
	RD = RogueDamage/2;
	WD = WarriorDamage;
	CRD = RogueDamage;
	CWD = WarriorDamage * 2;

	while (true) {
		 if (Name == 2) {
			system("cls");

			BattleStatsStart(WH,RH,RD,WD, CRD, CWD,Name);

		}
		else if (Name == 1) {
			system("cls");

			BattleStatsStart(WH, RH, RD, WD, CRD, CWD, Name);

		}
	}
}

int main() {
	float WarriorHealth = 70;
	float RogueHealth = 50;
	float WarriorDamage = 20;
	float RogueDamage = 16;
	int Name;
	
	while (true) {
		system("cls");
		std::cout << "\n\n\t\t\tCHOOSE YOUR GHARACTER\n\n\n";
		std::cout << "\t\t\t 1)ROGUE  2)WARRIOR\n";
		std::cout << "\t\t\t    YOUR GHOICE:";
		std::cin >> Name;

		if (Name != 1 && Name != 2)
		{
			std::cout << "\n\t\t\t  INCORRECT CHOISE\n\t\t\t     TRY AGAIN\n\n";
			_getch();
			continue;

		}
		else if (Name == 2) {
			system("cls");

			Fighter WARRIOR(70, 20, "Halberd");
			std::cout << "\n\n\n\t\t\t YOU CHOOSE WARRIOR";
			std::cout << "\n\n\t\t    PARAMETERS OF YOUR CHARACTER:";
			Pcw(WarriorHealth, WarriorDamage);
			_getch();

			system("cls");
			std::cout << "\n\n\n\t\t\t YOUR ENEMY:";
			std::cout << "\n\t\t\t  ROGUE";
			Pcr(RogueHealth, RogueDamage);
			_getch();

			system("cls");
			std::cout << "\n\n\n\t\t\t IT'S TIME TO FIGHT!";
			_getch();

			FF(RogueHealth, RogueDamage, WarriorHealth, WarriorDamage,Name);

			break;
		}
		else if (Name == 1) {
			system("cls");

			Fighter ROGUE(50, 16, "Rapier");
			std::cout << "\n\n\n\t\t\t YOU CHOOSE ROGUE";
			std::cout << "\n\n\t\t    PARAMETERS OF YOUR CHARACTER:";
			Pcr(RogueHealth,RogueDamage);
			_getch();

			system("cls");
			std::cout << "\n\n\n\t\t\t YOUR ENEMY:";
			std::cout << "\n\t\t\t  WARRIOR";
			Pcw(WarriorHealth, WarriorDamage);
			_getch();

			system("cls");
			std::cout << "\n\n\n\t\t\t IT'S TIME TO FIGHT!";
			_getch();

			FF(RogueHealth, RogueDamage, WarriorHealth, WarriorDamage, Name);

			break;
		}
	}

	return 0;
}