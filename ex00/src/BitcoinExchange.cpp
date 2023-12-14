/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:38:26 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/14 22:53:38 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string& dataBaseFile) {
  checkDataBaseIntegrity(dataBaseFile);
  parseDataBaseFile(dataBaseFile);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  _dataBaseString = other._dataBaseString;
  _dataBase = other._dataBase;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    _dataBaseString = other._dataBaseString;
    _dataBase = other._dataBase;
  }
  return (*this);
}

void  BitcoinExchange::checkDataBaseIntegrity(std::string& dataBaseFile) {
  std::ifstream inFile(dataBaseFile.c_str());
  if (!inFile.is_open())
    throw DataBaseFileAccessException();

  std::string lineContent;
  int         lineNum = 0;
  while (getline(inFile, lineContent)) {
    if (checkFormat(lineContent)) {
      inFile.close();
      throw DataBaseFileCorruptedException(lineNum);
    }
    if (checkDate(lineContent)) {
      inFile.close();
      throw InvalidDBDateException(lineNum);
    }
    if (checkExchangeRate(lineContent)) {
      inFile.close();
      throw InvalidConversionRateException(lineNum);
    }
    lineNum++;
  }
}

bool  BitcoinExchange::checkFormat(std::string& line) {
  std::cout << line << std::endl;
  return (true);
}

bool  BitcoinExchange::checkDate(std::string& line) {
  std::cout << line << std::endl;
  return (true);
}

bool  BitcoinExchange::checkExchangeRate(std::string& line) {
  std::cout << line << std::endl;
  return (true);
}

void  BitcoinExchange::parseDataBaseFile(std::string& dataBaseFile) {
  std::cout << dataBaseFile << std::endl;
}
