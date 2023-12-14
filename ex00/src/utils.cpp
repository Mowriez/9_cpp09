/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:56:26 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/14 22:22:12 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/utils.hpp"
#include "../inc/Exceptions.hpp"

void  checkInput(int argc) {
  if (argc <= 1)
    throw InputFileMissingException();
  if (argc > 2)
    throw TooManyArgsException();
  
}
