/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:30:35 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/14 22:32:49 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <map>
# include "../inc/Exceptions.hpp"
# include "../inc/utils.hpp"

class BitcoinExchange {
  private:
    std::string                   _dataBaseString;
    std::map<std::string, double> _dataBase;


  public:
    BitcoinExchange(std::string& dataBaseFile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    void  checkDataBaseIntegrity(std::string& dataBaseFile);
    bool  checkFormat(std::string& line);
    bool  checkDate(std::string& line);
    bool  checkExchangeRate(std::string& line);
    void  parseDataBaseFile(std::string& dataBaseFile);

};

#endif
