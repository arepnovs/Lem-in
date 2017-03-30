
NAME = lem-in

FLAGS =	-Wall -Wextra -Werror 

SRC =	main_read.c\
		validation.c\
		organize_info1.c\
		organize_info2.c\
		support_functions.c\
		build_matrix.c\
		dfs_algo.c\
		choose_paths.c\
		print_path.c\
		bonus.c\

LIBFT	= libft/libft.a

SRO  =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		@$(MAKE) -C ./libft
		@echo "-----------------------------------"
		@echo "Compiling lem-in"
		@gcc $(FLAGS) -c $(SRC)
		@gcc $(FLAGS) -o $(NAME) $(SRO) $(LIBFT)
		@echo "-----------------------------------"
		@echo "lem-in is ready"
clean:
	@rm -f $(SRO)
	@$(MAKE) clean -C ./libft
	@echo "-----------------------------------"
	@echo "Objects successfully removed"
fclean:	
	@make clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft
	@echo "-----------------------------------"
	@echo "lem-in successfully removed"

re: 
	@make fclean
	@make all