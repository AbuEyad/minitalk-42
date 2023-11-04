# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 15:20:17 by habu-zua          #+#    #+#              #
#    Updated: 2023/11/04 11:11:39 by habu-zua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM 			= rm -rf
INCLUDES	= -I./includes

CLIENT	= client
SERVER	= server

UTILS_SRC	= utils/ft_printf.c utils/ft_puthex.c utils/ft_putnbrs.c \
			  utils/ft_putchars.c utils/ft_atoi.c utils/ft_isdigit.c
UTILS_OBJ	= $(UTILS_SRC:.c=.o)

CLIENT_SRC 	= client.c 
SERVER_SRC 	= server.c 
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)
SERVER_OBJ	= $(SERVER_SRC:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SV_BONUS_SRC = bonus/server_bonus.c
CL_BONUS_SRC = bonus/client_bonus.c
SV_BONUS_OBJ = $(SV_BONUS_SRC:.c=.o)
CL_BONUS_OBJ = $(CL_BONUS_SRC:.c=.o)

all		 	: $(CLIENT) $(SERVER)
bonus		: $(CLIENT_BONUS) $(SERVER_BONUS)

$(SERVER) : $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(UTILS_OBJ) $(SERVER_SRC) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJ) $(UTILS_OBJ)
		$(CC) $(CFLAGS) $(INCLUDES) $(UTILS_OBJ) $(CLIENT_SRC) -o $(CLIENT)

$(SERVER_BONUS) : $(SV_BONUS_OBJ) $(UTILS_OBJ)
		$(CC) $(CFLAGS) $(INCLUDES) $(UTILS_OBJ) $(SV_BONUS_OBJ) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(CL_BONUS_OBJ) $(UTILS_OBJ)
		$(CC) $(CFLAGS) $(INCLUDES) $(UTILS_OBJ) $(CL_BONUS_OBJ) -o $(CLIENT_BONUS)

%.o : %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)
		$(RM) $(SV_BONUS_OBJ) $(CL_BONUS_OBJ)
		 
	
fclean : clean
		${RM} $(CLIENT) $(SERVER)
		${RM} $(CLIENT_BONUS) $(SERVER_BONUS)

re 		 : fclean all
re_bonus : fclean bonus

.PHONY 	 : all clean fclean re server client bonus
