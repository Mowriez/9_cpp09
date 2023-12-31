/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:26:35 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/31 15:50:29 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <stack>
# include "../inc/MyExceptions.hpp"

void  checkInput(std::string& input);
void  checkBlock(std::string& block);
void  runRPNCalculation(std::string& input);
void  manipulateStack(std::stack<int>& RPNStack, std::string& block, int& result);

#endif
