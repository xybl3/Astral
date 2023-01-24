FILE_WIN = ./game_win.exe

build_mac:
	clang++ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL ./lib/libraylib_mac.a src/*.cpp -o ./game -Wno-write-strings
build_win:
	@g++ ./astral/src/*.cpp -o game_win -L ./lib -lraylib -lopengl32 -lgdi32 -lwinmm -lkernel32 -Wno-write-strings
run_win:
	@$(FILE_WIN)