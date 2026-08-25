DED_FLAGS := -D _DEBUG -ggdb3 -std=c++17 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

all: object/main.o object/square_equation.o object/tehnical_fiches.o object/input_output.o object/testing_solving.o
	@g++ $(DED_FLAGS) object/main.o object/input_output.o object/square_equation.o object/tehnical_fiches.o object/testing_solving.o -o programm


object/main.o : src/main.cpp header/square_equation.h header/tehnical_fiches.h header/input_output.h header/testing_solving.h
	@g++ -c src/main.cpp -I header $(DED_FLAGS) -o object/main.o

object/square_equation.o : src/square_equation.cpp header/square_equation.h
	@g++ -c src/square_equation.cpp -I header $(DED_FLAGS) -o object/square_equation.o

object/tehnical_fiches.o : src/tehnical_fiches.cpp header/tehnical_fiches.h
	@g++ -c src/tehnical_fiches.cpp -I header $(DED_FLAGS) -o object/tehnical_fiches.o

object/input_output.o : src/input_output.cpp header/input_output.h
	@g++ -c src/input_output.cpp -I header $(DED_FLAGS) -o object/input_output.o

object/testing_solving.o : src/testing_solving.cpp header/testing_solving.h
	@g++ -c src/testing_solving.cpp -I header $(DED_FLAGS) -o object/testing_solving.o

clean:
	@rm -rf programm
	@rm -rf object/*.o





