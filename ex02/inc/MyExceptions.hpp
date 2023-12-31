/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:09:22 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/01 22:42:44 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEXCEPTIONS_HPP
# define MYEXCEPTIONS_HPP

# include <exception>
# include <string>
# include <iostream>
# include <sstream>

class MyBasicException : public std::exception {
  public:
    const char* what() const throw();
};

class WrongFormatException : public std::exception {
  private:
    std::string _errorMessage;
  public:
    WrongFormatException(const int& charNum, std::string& input);
    ~WrongFormatException() throw () {};
    const char* what() const throw();
};

#endif