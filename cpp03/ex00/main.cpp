

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");

	a.getStatus();
	b.getStatus();
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);

	a.getStatus();
	b.getStatus();
}