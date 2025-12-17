/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:47:10 by kmaeda            #+#    #+#             */
/*   Updated: 2025/12/17 12:06:43 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		bool	setField(int index, const std::string& value);
		int		valueCheck(int field, const std::string& value) const;
		std::string getField(int field) const;
		Contact(void);
		~Contact(void);
	
		enum Info {
			FirstName,
			LastName,
			NickName,
			PhoneNumber,
			DarkestSecret
		};

	private:
		static std::string	field_names[5];
		std::string			field_info[5];
};

#endif
