.PHONY: all clean fclean re f fclear c clear

NAME 			=		libft.a
CC				=		cc
CFLAGS			=		-Wall -Wextra -Werror -MMD -MP
RM				=		rm -fr
AR				=		ar -rcs


# Color
GREEN			=		\033[0;32m
BLUE			=		\033[0;34m
RED				=		\033[0;31m
YELLOW			=		\033[0;33m
RESET			=		\033[0m


#############################################################################################
#																							#
#										// Directories										#
#																							#
#############################################################################################


# Directories
D_SRC			=		src/
D_OBJ			=		object/
D_INC			=		./inc/

# Source Directories
D_IS			=		is/
D_LST			=		lst/
D_MEM			=		mem/
D_STRING		=		string/
D_PRINT			=		print/
D_UTILITY		=		utility/


#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


INC				=		libft.h


SRC_IS			=		ft_is_space.c		\
						ft_isalnum.c		\
						ft_isalpha.c		\
						ft_isascii.c		\
						ft_isdigit.c		\
						ft_isprint.c


SRC_LST			=		ft_lstadd_back.c	\
						ft_lstadd_front.c	\
						ft_lstclear.c		\
						ft_lstdelone.c		\
						ft_lstiter.c		\
						ft_lstlast.c		\
						ft_lstmap.c			\
						ft_lstnew.c			\
						ft_lstsize.c


SRC_MEM			=		ft_atoi_alloc.c		\
						ft_memchr.c			\
						ft_memcmp.c			\
						ft_memcpy.c			\
						ft_memmove.c		\
						ft_memset.c			\
						ft_bzero.c			\
						ft_calloc.c


SRC_PRINT		=		ft_printf.c			\
						ft_putchar_fd.c		\
						ft_putendl_fd.c		\
						ft_putnbr_fd.c		\
						ft_putstr_fd.c


SRC_STRING		=		ft_split.c			\
						ft_strchr.c			\
						ft_strdup.c			\
						ft_striteri.c		\
						ft_strjoin.c		\
						ft_strlcat.c		\
						ft_strlcpy.c		\
						ft_strlen.c			\
						ft_strmapi.c		\
						ft_strncmp.c		\
						ft_strnstr.c		\
						ft_strrchr.c		\
						ft_strtrim.c		\
						ft_substr.c			\
						get_next_line.c


SRC_UTILITY		=		ft_atoi.c			\
						ft_base.c			\
						ft_itoa.c			\
						ft_tolower.c		\
						ft_toupper.c


#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(addprefix $(D_SRC), $(SRC))						\
						$(addprefix $(D_SRC)$(D_IS), $(SRC_IS))				\
						$(addprefix $(D_SRC)$(D_LST), $(SRC_LST))			\
						$(addprefix $(D_SRC)$(D_MEM), $(SRC_MEM))			\
						$(addprefix $(D_SRC)$(D_STRING), $(SRC_STRING))		\
						$(addprefix $(D_SRC)$(D_PRINT), $(SRC_PRINT))		\
						$(addprefix $(D_SRC)$(D_UTILITY), $(SRC_UTILITY))

# Changing all source directories to object directories
OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS:.c=.o))
DEPS			=		$(SRCS:%.c=%.d)

INCS			=		$(addprefix $(D_INC), $(INC))


#############################################################################################
#																							#
#										// COMPILATION										#
#																							#
#############################################################################################


all				:	$(NAME) $(D_OBJ)


$(NAME)			:	$(OBJS)
			$(AR) $(NAME) $(OBJS)


$(D_OBJ)%.o		: 	 $(D_SRC)%.c $(INCS) Makefile
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(D_INC)


#############################################################################################
#																							#
#								    // CLEAN  FCLEAN  RE									#
#																							#
#############################################################################################


clean 			:
			$(RM) $(D_OBJ)


fclean 			:	clean
			$(RM) $(NAME)


re 				:	 fclean all


#############################################################################################
#																							#
#										Allias									#
#																							#
#############################################################################################


c				:	clear
clear			:	clean

f				:	fclean
fclear			:	fclean


#to see what variables did
debug			:
	@echo "Debug: $(all)"

-include $(DEPS)
