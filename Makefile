.PHONY: all clean fclean re f fclear c clear libft

NAME			=	pipex
CC				=	cc
FLAGS			=	-Wall -Wextra -Werror -MMD -MP -Ofast
CFLAGSS			=	-Weverything -Wno-padded
RM				=	rm -fr


#############################################################################################
#																							#
#										// Directories										#
#																							#
#############################################################################################


# Directories
D_SRC			=		src/
D_OBJ			=		object/
D_INC			=		inc/

# Source Directories
D_UTILS		=		utils/

#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


INC				=		ft_pipex.h

SRC				=		main.c					\
						ft_find_check_access.c

SRC_UTILS		=		ft_split_cmd.c

#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(addprefix $(D_SRC), $(SRC))					\
						$(addprefix $(D_SRC)$(D_UTILS), $(SRC_UTILS))

# Changing all source directories to object directories
OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS:.c=.o))
D_OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS))
DEPS			=		$(SRCS:%.c=%.d)

INCS			=		$(addprefix $(D_INC), $(INC))

#############################################################################################
#																							#
#										// LIBFT											#
#																							#
#############################################################################################


D_INC_LIBFT		=		./libft/inc/


NAME_LIB		=		./libft/libft.a


#############################################################################################
#																							#
#										// COMPILATION										#
#																							#
#############################################################################################


all : libft $(NAME)


$(NAME)			:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(NAME_LIB) -o $(NAME)


$(D_OBJ)%.o		:	$(D_SRC)%.c Makefile $(INCS)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(D_INC) -I $(D_INC_LIBFT)



libft			:
			$(MAKE) -C libft


#############################################################################################
#																							#
#								    // CLEAN  FCLEAN  RE									#
#																							#
#############################################################################################


clean			:
			$(RM) $(D_OBJ)
			$(MAKE) -C libft clean


fclean			:
			$(RM) $(D_OBJ)
			$(RM) $(NAME)
			$(MAKE) -C libft fclean

re				:	 fclean all


#############################################################################################
#																							#
#										Allias									#
#																							#
#############################################################################################


c				:	clear
clear			:	clean

f				:	fclean
fclear			:	fclean


 -include $(DEPS)

# debug-pierre-copyright :
# 	$(MAKE) --no-print-directory $(NAME) CFLAGS="$(CFLAGS_MORE)" CC="clang"
