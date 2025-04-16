/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:32:34 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/16 10:47:40 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "colors.hpp"
# include <iostream>

#ifdef HELP
    #define DEBUG_MODE 1
#else
    #define DEBUG_MODE 0
#endif

#if DEBUG_MODE
    # define DEBUG_CONTAINER(x) std::cout << "Container(" << UNDERLINE << x << RESET << "): "
	# define DEBUG_NB_SP(span) std::cout << span << std::endl << std::endl
	# define DEBUG_NB_RDN(nb) std::cout << nb << ", "
	# define DEBUG_DUPLICATE(nb) std::cout << "Span min : " << nb << " is duplicate" << std::endl
	# define DEBUG_SHORTEST(save1, save2) std::cout << "Span min :" << save1 << " and " << save2 << std::endl
	# define DEBUG_LONGEST(max, min) std::cout << "Span max :" << *max << " and " << *min << std::endl
#else
    #define DEBUG_CONTAINER(x)
	#define DEBUG_NB_SP(span)
	# define DEBUG_NB_RDN(nb)
	# define DEBUG_DUPLICATE(nb)
	# define DEBUG_SHORTEST(save1, save2)
	# define DEBUG_LONGEST(max, min)
#endif
