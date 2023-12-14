/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:45:10 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/14 21:47:34 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Exceptions.hpp"

const char* InputFileMissingException::what() const throw() {
  return ("Error: Input File not specified.");
}

const char* TooManyArgsException::what() const throw() {
  return ("Error: Too many args in function call.");
}

const char* DataBaseFileAccessException::what() const throw() {
  return ("Error: Cannot open database file.");
}

const char* DataBaseFileCorruptedException::what(int lineNum) const throw() {
  std::string ret = "Error: Database file corrupted - line: " + lineNum; 
  return (ret.c_str());
}

const char* InvalidDBDateException::what(int lineNum) const throw() {
  std::string ret = "Error: Invalid date in database - line: " + lineNum; 
  return (ret.c_str());
}

const char* InvalidConversionRateException::what(int lineNum) const throw() {
  std::string ret = "Error: Invalid conversion rate in database - line: " 
                    + lineNum; 
  return (ret.c_str());
}
