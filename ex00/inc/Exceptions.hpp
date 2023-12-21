/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:15:37 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/21 14:23:27 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>
# include <iostream>
# include <sstream>

class InputFileMissingException : public std::exception {
  public:
    const char* what() const throw();
};

class TooManyArgsException : public std::exception {
  public:
    const char* what() const throw();
};

class DataBaseFileAccessException : public std::exception {
  public:
    const char* what() const throw();
};

class DataBaseFileCorruptedException : public std::exception {
  private:
    std::string _errorMessage;
  public:

    DataBaseFileCorruptedException(int& lineNum);
    ~DataBaseFileCorruptedException() throw () {};
    const char* what() const throw();
};

#endif