OBJ   = obj/main.o      \
		obj/my_lib.o    \
		obj/test.o      \

FLAGS = -lubsan -D NDEBUG -g -std=c++14 -fmax-errors=1              \
		-Wc++0x-compat -Wc++11-compat -Wc++14-compat                \
		-Wcast-qual -Wchar-subscripts -Wconditionally-supported     \
		-Wconversion  -Wctor-dtor-privacy -Wempty-body              \
		-Wfloat-equal -Wformat-nonliteral -Wformat-security         \
		-Wformat-signedness -Wformat=2 -Winline  -Wlogical-op       \
		-Wmissing-declarations  -Wnon-virtual-dtor -Wopenmp-simd    \
		-Woverloaded-virtual -Wpacked -Wpointer-arith               \
		-Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo	\
		-Wstack-usage=8192  -Wstrict-null-sentinel                  \
		-Wstrict-overflow=2 -Wsuggest-attribute=noreturn            \
		-Wsuggest-final-methods -Wsuggest-final-types               \
		-Wsuggest-override -Wswitch-default -Wswitch-enum           \
		-Wsync-nand -Wundef  -Wunreachable-code -Wunused            \
		-Wuseless-cast -Wvariadic-macros -Wno-literal-suffix        \
		-Wno-missing-field-initializers -Wno-narrowing              \
		-Wno-old-style-cast -Wno-varargs -fcheck-new                \
		-fsized-deallocation  -fstack-protector                     \
		-fstrict-overflow   -flto-odr-type-merging                  \
		-fno-omit-frame-pointer -fPIE -fsanitize=address            \
		-fsanitize=bool -fsanitize=bounds -fsanitize=enum           \
		-fsanitize=float-cast-overflow                              \
		-fsanitize=float-divide-by-zero                             \
		-fsanitize=integer-divide-by-zero -fsanitize=leak           \
		-fsanitize=nonnull-attribute -fsanitize=null                \
		-fsanitize=object-size -fsanitize=return                    \
		-fsanitize=returns-nonnull-attribute -fsanitize=shift       \
		-fsanitize=signed-integer-overflow -fsanitize=undefined     \
		-fsanitize=unreachable -fsanitize=vla-bound                 \


all: global

global: $(OBJ)
	g++ $(OBJ) -o my_lib -lm $(FLAGS)

obj/main.o: main.cpp test/test.h lib/my_lib.h
	g++ main.cpp -c -o obj/main.o $(FLAGS)

obj/test.o: test/test.cpp test/test.h lib/my_lib.h
	g++ test/test.cpp -c -o obj/test.o $(FLAGS)

obj/my_lib.o: lib/my_lib.cpp lib/my_lib.h 
	g++ lib/my_lib.cpp -c -o obj/my_lib.o $(FLAGS)

.PHONY: cleanup

cleanup:
	rm *.0 solve
