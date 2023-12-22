/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:21:19 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/22 14:41:15 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MyExceptions.hpp"

const char* MyBasicException::what() const throw() {
  return ("ERROR");
}

WrongFormatException::WrongFormatException(const int& charNum, std::string& input) {
  std::stringstream ss;
  ss << "Error: Wrong format. column " << charNum + 1 << " (char: " 
     << input[charNum] << ")" << std::endl;
  _errorMessage = ss.str();
}

const char* WrongFormatException::what() const throw() {
  return (_errorMessage.c_str());
}
