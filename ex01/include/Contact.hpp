/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:47:10 by kmaeda            #+#    #+#             */
/*   Updated: 2025/10/24 19:19:29 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		void	setField(int index, const std::string& value);
		int		valueCheck(int field, const std::string& value) const;
		Contact(void);
		~Contact(void);

	private:
		static std::string	field_names[5];
		std::string			field_info[5];
		int					index;
		
		enum Info {
			FirstName,
			LastName,
			NickName,
			PhoneNumber,
			DarkestSecret
		};
};

#endif
