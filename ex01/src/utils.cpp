/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:28:30 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/25 16:50:30 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"
#include "../inc/MyExceptions.hpp"

void  checkInput(std::string& input) {
  for(size_t i = 0; i < input.length(); i++) {
    if (!(isdigit(input[i]) || input[i] == '+' || input[i] == '-'
         || input[i] == '*' || input[i] == '/'  || input[i] == ' ')
         || !isdigit(input[0]))
      throw WrongFormatException(i, input);
  }

  size_t blockStart = 0;
  size_t blockEnd = 0;
  bool stop = false;
  while(1) {
    if (input.find(' ', blockStart) == std::string::npos) {
      stop = true;
      blockEnd = input.length();
    }
    else
      blockEnd = (input.find(' ', blockStart));
    std::string block = input.substr(blockStart , blockEnd - blockStart);
    std::cout << block << "|" << std::endl;
    checkBlock(block);
    if (stop)
      break;
    blockStart = blockEnd + 1;
  }
}

void  checkBlock(std::string& block) {
  for (size_t i = 0; i < block.length(); i++) {
    if ((block[i] == '+' || block[i] == '-'
         || block[i] == '*' || block[i] == '/')) {
        if (i != 0)
          throw WrongBlockFormatException(block);
      }
  }
}
