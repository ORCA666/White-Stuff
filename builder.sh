nasm -f elf decoder.asm &&  ld -m elf_i386 -s -o decoder decoder.o && for i in `objdump -d decoder | tr '\t' ' ' | tr ' ' '\n' | egrep '^[0-9a-f]{2}$' ` ;
do echo -n "\x$i" ;
done
