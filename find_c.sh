# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_c.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbatz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 18:09:35 by kbatz             #+#    #+#              #
#    Updated: 2018/11/23 19:27:54 by kbatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ls -l | rev | cut -d ' ' -f 1 | rev | grep ".c$" | tr "\n" " " | rev | sed "s/ //" | rev > srcs
ls -l | rev | cut -d ' ' -f 1 | rev | grep ".c$" | tr "\n" " " | rev | sed "s/ //" | rev
