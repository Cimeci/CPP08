/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:46:39 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/14 10:49:02 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <algorithm>
# include <iterator>
# include <iostream>
# include <vector>
# include <ctime>
# include <cstdlib>

template <typename T>

typename T::iterator easyfind(T& container, int nb) {
    return std::find(container.begin(), container.end(), nb);
}
