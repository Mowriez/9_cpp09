/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:45:10 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/21 14:34:04 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Exceptions.hpp"

// for Input checking
const char* InputFileMissingException::what() const throw() {
  return ("Error: Input File not specified.");
}

const char* TooManyArgsException::what() const throw() {
  return ("Error: Too many args in function call.");
}

//---
// for DataBase file validity checking
const char* DataBaseFileAccessException::what() const throw() {
  return ("Error: Cannot open database file.");
}

DataBaseFileCorruptedException::DataBaseFileCorruptedException(int& lineNum) {
  std::stringstream ss;
  ss << "Error: Database file corrupted - line: " << lineNum;
  _errorMessage = ss.str();
}

const char* DataBaseFileCorruptedException::what() const throw() {
  return (_errorMessage.c_str());
}


//---
// tbd
