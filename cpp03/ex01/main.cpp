

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");

	a.getStatus();
	b.getStatus();
	c.getStatus();
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);
	c.guardGate();

	a.getStatus();
	b.getStatus();
	c.getStatus();
}