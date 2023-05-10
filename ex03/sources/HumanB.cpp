/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:06:45 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/10 14:49:02 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
	std::cout << this->_name << " want to fight!" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " fled the fight..." << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attack with their " << this->_weapon->getType() << std::endl;
}
