/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:21:29 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/04 15:03:43 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact(void);
		~Contact(void);

		void		setFirstName(void);
		void		setLastName(void);
		void		setNickname(void);
		void		setPhoneNumber(void);
		void		setDarkestSecret(void);
		void		printPhonebookContact(void);
		void		printContactInfo(void);
		std::string	truncateInfo(std::string info);
};

#endif