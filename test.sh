./vm_champs/asm $1.s
mv $1.cor orig_$1.cor
./asm $1.s
diff $1.cor orig_$1.cor
