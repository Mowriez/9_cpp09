/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:09:49 by mtrautne          #+#    #+#             */
/*   Updated: 2024/01/02 14:23:33 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MyExceptions.hpp"

const char* MyBasicException::what() const throw() {
  return ("Error.\n");
}

WrongFormatException::WrongFormatException(const int& charNum, std::string& input) {
  std::stringstream ss;
  ss << "Error: Wrong input: " << "char no. " << charNum << input[charNum] << std::endl;
  _errorMessage = ss.str();
}

const char* WrongFormatException::what() const throw() {
  return (_errorMessage.c_str());
}
