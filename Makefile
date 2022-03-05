NAME = philo

CC = clang 
CFLAGS = -Wall -Werror -Wextra -g

HEADER = $(addprefix $(INCLUDES_PATH)/, philo.h)

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
LINK = -pthread

SOURCES_FILES =	main.c \
				utils.c \
				setup.c \
				print_functions.c \
				time_functions.c \
				start_banquet.c \
				monitor.c

SOURCES = $(addprefix $(SOURCES_PATH)/, $(SOURCES_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/, $(subst .c,.o,$(SOURCES_FILES)))

SAFE_MAKEDIR = mkdir -p
REMOVE = rm -rf 

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(CC) -g $(LINK) $(OBJECTS)  -o $(NAME) -I $(INCLUDES_PATH) -fsanitize=address 

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	$(SAFE_MAKEDIR) $(OBJECTS_PATH)
	$(CC) -g $(LINK) $(CFLAGS) -I $(INCLUDES_PATH) -o $@ -c $< -fsanitize=address 

re: fclean all 

clean: 
	$(REMOVE) $(OBJECTS_PATH)

fclean: clean
	$(REMOVE) $(NAME)

.PHONY: all re clean fclean 