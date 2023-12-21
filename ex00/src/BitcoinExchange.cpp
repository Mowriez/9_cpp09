/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:38:26 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/21 17:55:06 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string& inputFilePath)
  : _dataBaseFilePath("./db/data.csv"), _inputFilePath(inputFilePath) {
  checkDataBaseIntegrity();
  parseDataBaseFile();
  // printMap(_dataBase);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  _dataBaseFilePath = other._dataBaseFilePath;
  _dataBase = other._dataBase;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    _dataBaseFilePath = other._dataBaseFilePath;
    _dataBase = other._dataBase;
  }
  return (*this);
}

void  BitcoinExchange::checkDataBaseIntegrity() {
  std::ifstream dataBaseFile(_dataBaseFilePath.c_str());
  if (!dataBaseFile.is_open())
    throw DataBaseFileAccessException();

  std::string lineContent;
  int         lineNum = 1;
  while (getline(dataBaseFile, lineContent)) {
    if (lineContent == "date,exchange_rate") {
      lineNum++;
      continue;
    }
    if (!checkFormat(lineContent)) {
      dataBaseFile.close();
      throw DataBaseFileCorruptedException(lineNum);
    }
    if (!checkDate(lineContent)) {
      dataBaseFile.close();
      throw DataBaseFileCorruptedException(lineNum);
    }
    if (!checkExchangeRate(lineContent)) {
      dataBaseFile.close();
      throw DataBaseFileCorruptedException(lineNum);
    }
    std::cout << "line: " << lineNum << std::endl;
    lineNum++;
  }
  dataBaseFile.close();
}

void  BitcoinExchange::parseDataBaseFile() {
  std::ifstream inputFile(_dataBaseFilePath.c_str());

  if (!inputFile.is_open())
        throw DataBaseFileAccessException();

  std::string lineContent;
  int         date;
  double      conversionRate;
  while (getline(inputFile, lineContent)) {
    if (lineContent == "date,exchange_rate")
      continue;
    date = extractDate(lineContent);
    conversionRate = strtod(lineContent.substr(11, lineContent.length() - 11).c_str(), NULL);
    _dataBase[date] = conversionRate;
  }
}
