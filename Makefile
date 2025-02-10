.PHONY: all clean fclean re f fclear c clear libft bonus

NAME			=	pipex
B_NAME			=	pipex_bonus
CC				=	cc
CFLAGSS			=	-Wall -Wextra -Werror -MMD -MP
CFLAGS			=	-Weverything -Wno-padded
RM				=	rm -fr


#############################################################################################
#																							#
#										Directories											#
#																							#
#############################################################################################


# Directories
D_SRC			=		src/
D_OBJ			=		object/
D_INC			=		inc/

D_INC_B			=		inc_b/

# Source Directories
D_MANDA		=		mandatory/
D_BONUS		=		bonus/
D_UTILS		=		utils/


#############################################################################################
#																							#
#										SOURCE												#
#																							#
#############################################################################################


INC				=		ft_pipex.h

SRC				=		main.c		\
						ft_fork.c


SRC_UTILS		=		ft_find_access_exec.c	\
						ft_open_file.c			\
						utils.c


#############################################################################################
#																							#
#										OBJECT												#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(addprefix $(D_SRC)$(D_MANDA), $(SRC))					\
						$(addprefix $(D_SRC)$(D_MANDA)$(D_UTILS), $(SRC_UTILS))

# Changing all source directories to object directories
OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS:.c=.o))
D_OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS))
DEPS			=		$(SRCS:%.c=%.d)


INCS			=		$(addprefix $(D_INC), $(INC))

#############################################################################################
#																							#
#										LIBFT												#
#																							#
#############################################################################################


D_INC_LIBFT		=		./libft/inc/


NAME_LIB		=		./libft/libft.a


#############################################################################################
#																							#
#										COMPILATION											#
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
#											BONUS											#
#############################################################################################


#############################################################################################
#																							#
#										SOURCE BONUS										#
#																							#
#############################################################################################


B_INC			=		ft_pipex_bonus.h

B_SRC			=		main_bonus.c					\
						ft_here_doc_bonus.c				\
						ft_fork_bonus.c


B_SRC_UTILS		=		ft_find_access_exec_bonus.c		\
						ft_open_file_bonus.c			\
						utils_bonus.c

#############################################################################################
#																							#
#										OBJECT BONUS										#
#																							#
#############################################################################################


# All src in his Src Directories
B_SRCS			=		$(addprefix $(D_SRC)$(D_BONUS), $(B_SRC))					\
						$(addprefix $(D_SRC)$(D_BONUS)$(D_UTILS), $(B_SRC_UTILS))

# Changing all source directories to object directories
B_OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(B_SRCS:.c=.o))
B_D_OBJS		=		$(subst $(D_SRC), $(D_OBJ), $(B_SRCS))
B_DEPS			=		$(B_SRCS:%.c=%.d)


B_INCS			=		$(addprefix $(D_INC), $(B_INC))

#############################################################################################
#																							#
#										COMPILATION	BONUS									#
#																							#
#############################################################################################


bonus				: libft $(B_NAME)


$(B_NAME)			:	$(B_OBJS)
			$(CC) $(CFLAGS) $(B_OBJS) $(NAME_LIB) -o $(B_NAME)


$(D_OBJ_B)%.o			:	$(D_SRC)%.c Makefile $(B_INCS)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(D_INC) -I $(D_INC_LIBFT)


#############################################################################################
#																							#
#										CLEAN FCLEAN RE										#
#																							#
#############################################################################################


clean			:
			$(RM) $(D_OBJ)
			$(MAKE) -C libft clean


fclean			:
			$(RM) $(D_OBJ)
			$(RM) $(NAME)
			$(RM) $(B_NAME)
			$(MAKE) -C libft fclean

re				:	 fclean all


#############################################################################################
#																							#
#										Allias												#
#																							#
#############################################################################################


c				:	clear
clear			:	clean

f				:	fclean
fclear			:	fclean


 -include $(DEPS) $(B_DEPS)
# debug-pierre-copyright :
# 	$(MAKE) --no-print-directory $(NAME) CFLAGS="$(CFLAGS_MORE)" CC="clang"
