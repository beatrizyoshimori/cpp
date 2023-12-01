

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");
	FragTrap	d("D");

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.attack("D");
	d.takeDamage(b.getAttackDamage());
	d.highFivesGuys();
	b.beRepaired(1);
	c.guardGate();

	a.getStatus();
	b.getStatus();
	c.getStatus();
}