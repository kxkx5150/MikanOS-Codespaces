TARGET = rpn

CPPFLAGS += -I.
CFLAGS += -fshort-wchar -O2 -Wall -g --target=x86_64-elf -ffreestanding
CXXFLAGS += -fshort-wchar -O2 -Wall -g --target=x86_64-elf -ffreestanding \
            -fno-exceptions -fno-rtti -std=c++17
LDFLAGS += -z separate-code --entry main -z norelro --image-base 0 --static

.PHONY: all
all: $(TARGET)

rpn: rpn.o Makefile
	ld.lld $(LDFLAGS) -o rpn rpn.o

%.o: %.cpp Makefile
	clang++ $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
