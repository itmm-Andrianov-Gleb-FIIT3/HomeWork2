#include <iostream>
#include <stdio.h>
#include "conio.h"
#include <time.h>


class Fighter {

	
public:

	float Health;
	float Damage;
	std::string Weapon;
	int Name;

	Fighter(float _Health, float _Damage, std::string _Weapon, int _Name) {
		Health = _Health;
		Damage = _Damage;
		Weapon = _Weapon;
		Name = _Name;
	}

	float getHealth() { return Health; }
	float getDamage() { return Damage; }
	std::string getWeapon() { return Weapon; }
	int getName() { return Name; }
};


void Attack(Fighter& YOU, Fighter& ENEMY) {

	system("cls");

	int DG;
	int CRT;


	if (YOU.getName() == 1) {
		CRT = rand() % 20;
		if (CRT == 19) {
			ENEMY.Health = (ENEMY.Health - YOU.Damage);
			std::cout << "\n\n\t\t\t CRIT!" << "\n\nYOU HAVE DONE " << YOU.Damage << " DAMAGE";
		}
		else {
			ENEMY.Health = (ENEMY.Health - (YOU.Damage / 2));
			std::cout << "\n\n\t\t\t YOU HAVE DONE " << YOU.Damage / 2 << " DAMAGE";
		}
	}
	else if (YOU.Name == 2) {
		CRT = rand() % 20;
		DG = rand() % 3;
		if (DG != 1) {
			std::cout << "\n\n\t\t\t\t DODGE!";
		}
		else {
			if (CRT == 19) {
				ENEMY.Health = (ENEMY.Health - (YOU.Damage * 2));
				std::cout << "\n\n\t\t\t CRIT!" << "\n\nYOU HAVE DONE " << YOU.Damage * 2 << " DAMAGE";
			}
			else {
				ENEMY.Health = (ENEMY.Health - YOU.Damage);
				std::cout << "\n\n\t\t\t YOU HAVE DONE " << YOU.Damage << " DAMAGE";
			}
		}
	}

	_getch();

}

void Defence(Fighter& YOU, Fighter& ENEMY) {

	system("cls");

	int DG;

	if (YOU.Name == 1) {
		DG = rand() % 3;
		if (DG == 1) {
			YOU.Health = (YOU.Health - ENEMY.Damage);
			std::cout << "\n\n\t\t\t YOU HAVE TAKEN " << ENEMY.Damage << " DAMAGE";
		}
		else {
			std::cout << "\n\n\t\t\t\t DODGE!";
		}
	}
	else if (YOU.Name == 2) {
		YOU.Health = (YOU.Health - (ENEMY.Damage / 2));
		std::cout << "\n\n\t\t\t YOU HAVE TAKEN " << (ENEMY.Damage / 2) << " DAMAGE";
	}
	_getch();

}

void Pcw(float WarriorHealth,float WarriorDamage, std::string WarriorWeapon) {
	std::cout << "\n\n\t\t    HEALTH:" << WarriorHealth;
	std::cout << "\n\n\t\t    WEAPON:" << WarriorWeapon;
	std::cout << "\n\t\t    DAMAGE:" << WarriorDamage;
	std::cout << "\n\n\t\t    SPECIAL ABILITY:ARMOR";
	std::cout << "\n\t\t    ARMOR:A WARRIOR always block 50% of incoming damage.";
}

void Pcr(float RogueHealth, float RogueDamage, std::string RogueWeapon) {
	std::cout << "\n\n\t\t    HEALTH:" << RogueHealth;
	std::cout << "\n\n\t\t    WEAPON:Rapier ";
	std::cout << "\n\t\t    DAMAGE:" << RogueDamage;
	std::cout << "\n\n\t\t    SPECIAL ABILITY:DODGE";
	std::cout << "\n\t\t    DODGE: With a 67% chance, ROGUE can DODGE  his enemy's attack.";
	std::cout << "\n\t\t    ARMOR:A ROGUE always block 33% of incoming damage.";
}

void VS(Fighter& YOU, Fighter& ENEMY) {
	
	system("cls");
	

	if (YOU.Name == 2) {
		if (YOU.Health >= (ENEMY.Health - 30)) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH << WARRIOR HEALTH";
		}
		else if ((YOU.Health < (ENEMY.Health - 30)) && YOU.Health > ENEMY.Health) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH < WARRIOR HEALTH";
		}
		else if (YOU.Health == ENEMY.Health) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH == WARRIOR HEALTH";
		}
		else if (YOU.Health < ENEMY.Health && (ENEMY.Health < (YOU.Health - 30))) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH > WARRIOR HEALTH";
		}
		else if ((ENEMY.Health >= (YOU.Health - 30))) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH >> WARRIOR HEALTH";
		}



		if (YOU.Damage >= (ENEMY.Damage * 4)) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE << WARRIOR DAMAGE";
		}
		else if ((YOU.Damage < (ENEMY.Damage * 4)) && YOU.Damage > ENEMY.Damage) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE < WARRIOR DAMAGE";
		}
		else if (YOU.Damage == ENEMY.Damage) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE == WARRIOR DAMAGE";
		}
		else if (YOU.Damage < ENEMY.Damage && (ENEMY.Damage < (YOU.Damage * 2))) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE > WARRIOR DAMAGE";
		}
		else if ((ENEMY.Damage >= (YOU.Damage * 2))) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE >> WARRIOR DAMAGE";
		}

	}else if (YOU.Name == 1) {

		if (ENEMY.Health >= (YOU.Health - 30)) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH << WARRIOR HEALTH";
		}
		else if ((ENEMY.Health < (YOU.Health - 30)) && ENEMY.Health > YOU.Health) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH < WARRIOR HEALTH";
		}
		else if (ENEMY.Health == YOU.Health) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH == WARRIOR HEALTH";
		}
		else if ((ENEMY.Health < YOU.Health) && (YOU.Health < (ENEMY.Health - 30))) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH > WARRIOR HEALTH";
		}
		else if ((YOU.Health >= (ENEMY.Health - 30))) {
			std::cout << "\n\n\t\t\t ROGUE HEALTH >> WARRIOR HEALTH";
		}



		if (ENEMY.Damage >= (YOU.Damage * 4)) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE << WARRIOR DAMAGE";
		}
		else if ((ENEMY.Damage < (YOU.Damage * 4)) && ENEMY.Damage > YOU.Damage) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE < WARRIOR DAMAGE";
		}
		else if (ENEMY.Damage == YOU.Damage) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE == WARRIOR DAMAGE";
		}
		else if ((ENEMY.Damage < YOU.Damage) && (YOU.Damage < (ENEMY.Damage * 2))) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE > WARRIOR DAMAGE";
		}
		else if ((YOU.Damage >= (ENEMY.Damage * 2))) {
			std::cout << "\n\n\t\t\t ROGUE DAMAGE >> WARRIOR DAMAGE";
		}

	}

	_getch();
}

void BattleStatsStart(Fighter& YOU, Fighter& ENEMY) {

	system("cls");

	int MV;

	while (YOU.Health > 0 && ENEMY.Health > 0) {


		if (YOU.Name == 2) {
			std::cout << "\n\n\t\t WARRIOR HEALTH:" << YOU.Health << "\tROGUE HEALTH:" << ENEMY.Health;
		}
		else if (YOU.Name == 1) {
			std::cout << "\n\n\t\t WARRIOR HEALTH:" << ENEMY.Health << "\tROGUE HEALTH:" << YOU.Health;
		}


		std::cout << "\n\n\t\t\t 1)ATTACK   2)DEFENCE";
		std::cout << "\n\t\t\t     YOUR MOVE:";
		std::cin >> MV;

		if (MV == 1) {
			Attack(YOU, ENEMY);
			Defence(YOU, ENEMY);
			system("cls");
		}
		else if (MV == 2) {
			Defence(YOU, ENEMY);
			system("cls");
		}
		else {
			system("cls");
			std::cout << "\n\n\n\n\t\t\t TRY AGAIN";
			_getch();
		}
	}

	system("cls");

	if (YOU.Health > 0 && ENEMY.Health <= 0) {
		std::cout << "\n\n\t\t\t   YOU WON!";
	}
	else if (YOU.Health <= 0 && ENEMY.Health > 0) {
		std::cout << "\n\n\t\t\t   YOU LOSE!";
	}

}

void FF(Fighter& YOU, Fighter& ENEMY) {


	while (true) {
		if (YOU.Name == 2) {
			while (YOU.Health > 0 && ENEMY.Health) {
				system("cls");

				VS(YOU,ENEMY);

				system("cls");

				BattleStatsStart(YOU, ENEMY);
				break;
			}
		}
		else if (YOU.Name == 1) {
			while (ENEMY.Health > 0 && YOU.Health > 0) {
				system("cls");

				VS(YOU, ENEMY);

				system("cls");

				BattleStatsStart(YOU, ENEMY);
				break;
			}
		}
	}

}

int main() {

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


			Fighter WARRIOR(80, 21, "Halberd",2);
			std::cout << "\n\n\n\t\t\t YOU CHOOSE WARRIOR";
			std::cout << "\n\n\t\t    PARAMETERS OF YOUR CHARACTER:";
			Pcw(WARRIOR.getHealth(), WARRIOR.getDamage(), WARRIOR.getWeapon());
			_getch();

			system("cls");

			Fighter ROGUE(50, 14, "Rapier",1);
			std::cout << "\n\n\n\t\t\t YOUR ENEMY:";
			std::cout << "\n\t\t\t  ROGUE";
			Pcr(ROGUE.getHealth(), ROGUE.getDamage(), ROGUE.getWeapon());
			_getch();

			system("cls");
			std::cout << "\n\n\n\t\t\t IT'S TIME TO FIGHT!";
			_getch();

			FF(WARRIOR,ROGUE);

			break;
		}
		else if (Name == 1) {
			system("cls");


			Fighter ROGUE(50, 14, "Rapier",1);
			std::cout << "\n\n\n\t\t\t YOU CHOOSE ROGUE";
			std::cout << "\n\n\t\t    PARAMETERS OF YOUR CHARACTER:";
			Pcr(ROGUE.getHealth(), ROGUE.getDamage(), ROGUE.getWeapon());
			_getch();

			system("cls");

			Fighter WARRIOR(80, 21, "Halberd",2);
			std::cout << "\n\n\n\t\t\t YOUR ENEMY:";
			std::cout << "\n\t\t\t  WARRIOR";
			Pcw(WARRIOR.getHealth(), WARRIOR.getDamage(), WARRIOR.getWeapon());
			_getch();

			system("cls");
			std::cout << "\n\n\n\t\t\t IT'S TIME TO FIGHT!";
			_getch();

			FF(ROGUE,WARRIOR);

			break;
		}
	}

	return 0;
}