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
	std::cout << "\n\t\t    DODGE: With a 67% chance, ROGUE can DODGE  his enemy's attack.";
	std::cout << "\n\t\t    ARMOR:A ROGUE always block 33% of incoming damage.";
}

void VS(float WH, float RH, float RD, float WD, float CRD, float CRW, int Name) {
	
	system("cls");
	


		if (WH >= (RH - 30)) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH << WARRIOR HEALTH";
		}
		else if ((WH < (RH - 30)) && WH > RH) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH < WARRIOR HEALTH";
		}
		else if (WH == RH) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH == WARRIOR HEALTH";
		}
		else if (WH < RH && (RH < (WH - 30))) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH > WARRIOR HEALTH";
		}
		else if ((RH >= (WH - 30))) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH >> WARRIOR HEALTH";
		}



		if (WD >= (RD * 4)) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE << WARRIOR DAMAGE";
		}
		else if ((WD < (RD * 4)) && WD > RD) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE < WARRIOR DAMAGE";
		}
		else if (WD == RD) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE == WARRIOR DAMAGE";
		}
		else if (WD < RD && (RD < (WD * 2))) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE > WARRIOR DAMAGE";
		}
		else if ((RD >= (WD * 2 ))) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE >> WARRIOR DAMAGE";
		}



	_getch();
}

void Attack(float WH, float RH, float RD, float WD, float CRD, float CWD, int Name) {

	system("cls");

	int DG;
	int CRT;


	if (Name == 1) {
		CRT = rand() % 20;
		if (CRT == 20) {
			WH = (WH - CRD);
			std::cout << "\n\n\t\t\t CRIT!" << "\n\nYOU HAVE DOON " <<  CRD << " DAMAGE";
		}
		else {
			WH = (WH - RD);
			std::cout << "\n\n\t\t\t YOU HAVE DONE " << RD << " DAMAGE";
		}
	}
	else if (Name == 2) {
		CRT = rand() % 20;
		DG = rand() % 3;
		if (DG != 1) {
			std::cout << "\n\n\t\t\t\t DODGE!";
		}
		else {
			if (CRT == 20) {
				RH = (RH - CWD);
				std::cout << "\n\n\t\t\t CRIT!" << "\n\nYOU HAVE DONE " << CWD << " DAMAGE";
			}
			else {
				RH = (RH - WD);
				std::cout << "\n\n\t\t\t YOU HAVE DONE " << WD << " DAMAGE";
			}
		}
	}
	_getch();
}

void Defence(float WH, float RH, float RD, float WD, float CRD, float CWD, int Name) {

	system("cls");

	int DG;

	if (Name == 1) {
		DG = rand() % 3;
		if (DG == 1) {
			RH = (RH - WD);
			std::cout << "\n\n\t\t\t YOU HAVE TAKEN "<< WD << " DAMAGE";
		}
		else {
			std::cout << "\n\n\t\t\t\t DODGE!";
		}
	}
	else if (Name == 2) {
		WH = (WH - RD);
		std::cout << "\n\n\t\t\t YOU HAVE TAKEN " << RD << " DAMAGE";
	}
	_getch();
}

void BattleStatsStart(float WH, float RH, float RD, float WD, float CRD, float CWD, int Name) {

	system("cls");

	int MV;

	std::cout << "\n\n\t\t WARRIOR HEALTH:" << WH << "\tROGUE HEALTH:" << RH;

	std::cout << "\n\n\t\t\t 1)ATTACK   2)DEFENCE";
	std::cout << "\n\t\t\t     YOUR MOVE:";
	std::cin >> MV;

	if (MV == 1) {
		Attack(WH, RH, RD, WD, CRD, CWD, Name);
		Defence(WH, RH, RD, WD, CRD, CWD, Name);
	}
	else if (MV == 2) {
		Defence(WH, RH, RD, WD, CRD, CWD, Name);
	}
	else {
		system("cls");
		std::cout << "\n\n\n\n\t\t\t TRY AGAIN";
		_getch();
	}

}

void FF(float RogueHealth, float RogueDamage, float WarriorHealth, float WarriorDamage, int Name) {

	float WH, RH, RD, WD, CRD, CWD;

	WH = WarriorHealth;
	RH = RogueHealth;
	RD = RogueDamage / 2;
	WD = WarriorDamage / 1.5;
	CRD = RogueDamage;
	CWD = WD * 2;

	while (true) {
		if (Name == 2) {
			while (WH > 0 && RH >0) {
				system("cls");

				VS(WH, RH, RD, WD, CRD, CWD, Name);
				BattleStatsStart(WH, RH, RD, WD, CRD, CWD, Name);
			}
		}
		else if (Name == 1) {
			while (WH > 0 && RH > 0) {
				system("cls");

				VS(WH, RH, RD, WD, CRD, CWD, Name);
				BattleStatsStart(WH, RH, RD, WD, CRD, CWD, Name);
			}
		}
	}
}

int main() {
	float WarriorHealth = 80;
	float RogueHealth = 50;
	float WarriorDamage = 21;
	float RogueDamage = 14;
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

			Fighter WARRIOR(80, 20, "Halberd");
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

			Fighter ROGUE(50, 14, "Rapier");
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