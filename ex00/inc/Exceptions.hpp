/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:15:37 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/14 22:31:27 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>

class InputFileMissingException : public std::exception {
  const char* what() const throw();
};

class TooManyArgsException : public std::exception {
  const char* what() const throw();
};

class DataBaseFileAccessException : public std::exception {
  const char* what() const throw();
};

class DataBaseFileCorruptedException : public std::exception {
  private:
    int _lineNum;
  public:
    DataBaseFileCorruptedException(int& lineNum) : _lineNum(lineNum) {};
    const char* what(int _lineNum) const throw();
};

class InvalidDBDateException : public std::exception {
  private:
    int _lineNum;
  public:
    InvalidDBDateException(int& lineNum) : _lineNum(lineNum) {};
    const char* what(int _lineNum) const throw();
};

class InvalidConversionRateException : public std::exception {
  private:
    int _lineNum;
  public:
    InvalidConversionRateException(int& lineNum) : _lineNum(lineNum) {};
    const char* what(int _lineNum) const throw();
};

#endif