echo "------"
./vm_champs/asm $1.s
echo "------"
mv $1.cor orig_$1.cor
echo "------"
./asm $1.s
echo "------"
diff $1.cor orig_$1.cor
echo "-----------------------------------------------------------------------------"
