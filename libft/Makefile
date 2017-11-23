NAME = libft.a
OBJDIR = obj
SRCDIR = srcs
SRCS=$(shell cat srclist)
INCDIR = -I ./includes/
OBJS=$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

EXE=test

yellow_error = @echo "\x1b[1;33m\#\#!!!$1!!!\#\#\x1b[0m"
red_delete = @echo "\x1b[1;31m"
green_create = @echo "\033[1;32m"
end_msg = printf "\033[0m"
CFLAGS = -Wall -Werror -Wextra
CC = gcc
AR = ar rc
RC = rc
RM = rm -rf
MAKE = make
TOTAL_FILE=$(shell cat srclist | wc -l)
O = -o

all: $(NAME) $(FIND)

$(OBJDIR):

	@mkdir -p "obj/libstruct" \
	"obj/libstd_ft" \
	"obj/libmalloc" \
	"obj/libparsing" \
	"obj/liberror" \

COUNT = 0


$(NAME): $(OBJDIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SKIP)"
	@echo "\033[1;32m100% DONE"
	@printf $(COUNT);\
	printf "   FILES TREATED / $(TOTAL_FILE) $(shell find srcs | grep "\.c" | wc -l) FILES IN SRCS\n";
RESULT=0
SKIP=\033[A

$(OBJDIR)/%.o: $(SRCDIR)/%.c

	$(eval RESULT = $(shell echo " scale=4; $(COUNT) * (100.0 / $(TOTAL_FILE))" | bc -l))
	$(eval COUNT = $(shell echo $$(( $(COUNT) + 1 ))))
	@$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<
	@$(call end_msg)
	@echo "$(SKIP)"
ifneq ($(COUNT),$(TOTAL_FILE))
	@printf "\033[1;31m%s"$(RESULT); \
	printf "%%";
else
	@printf "100%% DONE";
endif

clean:
ifeq ($(wildcard $(OBJS)),)
	@$(call yellow_error, "FILES MISSING...")
else
	@printf "\033[1;33m[CLEANING]"
	@for number in 1 2 3 ; do \
	printf "." ; \
	done
	@echo""
	@rm -rf $(OBJS)
	@echo "\033[1;32m[DIRECTORY CLEAN]\n\033[1;31m  -->$(OBJS)"
	@$(call end_msg)
	@ rm -rf $(OBJDIR)
endif

fclean:
ifeq ($(wildcard $(NAME)),)
	@$(call yellow_error, "FILE MISSING...")
else

	@printf "\033[1;33m[CLEANING ALL]"
	@for number in 1 2 3 ; do \
	printf "." ; \
	done
	@echo ""
	@make clean
	@rm -rf $(NAME) $(EXE)
	@echo "\033[1;32m[DELETION OF :\033[1;39m"$(NAME)" \033[1;32m]"
	@$(call end_msg)
endif

re: fclean all

.PHONY: clean fclean re all
