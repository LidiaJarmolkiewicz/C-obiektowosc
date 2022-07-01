#include <iostream>
#include"Uczelnia.hpp"
#include<string>

int main()
{
	University u;

	Professor janina("Janina", "Abacka", FormOfEmployment::Contract, 60);
	Professor jan("Jan", "Badulski", FormOfEmployment::ContractOfEmployment, 8700);
	Lecturer krzysztof("Krzysztof", "Powolski", FormOfEmployment::ContractOfEmployment, 6000);
	Lecturer karolina("Karolina", "Szybka", FormOfEmployment::ContractOfEmployment, 5700);
	Assistant hanna("Hanna", "Nowicjusz", FormOfEmployment::ContractOfMandate, 4500);
	Keeper tomasz("Tomasz", "Oliwny", FormOfEmployment::ContractOfMandate, 4000);
	Guard alicja("Alicja", "Strazacka", FormOfEmployment::Contract, 24);

	
	u.add(new Professor(janina));
	u.add(new Professor(jan));
	u.add(new Lecturer(krzysztof));
	u.add(new Lecturer(karolina));
	u.add(new Assistant(hanna));
	u.add(new Keeper(tomasz));
	u.add(new Guard(alicja));
	std::cout << "lista wszystkich pracownikow" << std::endl;
	u.printAllStaff();
	std::cout << "lista  pracownikow naukowych" << std::endl;
	u.printTeachingStaff();
	std::cout << "lista  wynagrodzen netto" << std::endl;
	u.printAllStaffNetIncomes();
	

	//std::cout << "Suma wynagrodzen: " << u.calculateEmployerCost() << std::endl;
	
	
	return 0;
}
	

