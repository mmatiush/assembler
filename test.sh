echo "------"
./vm_champs/asm $1.s
echo "------"
mv $1.cor $1_orig.cor
echo "------"
./asm $1.s
echo "------"
diff $1.cor $1_orig.cor
echo "-----------------------------------------------------------------------------"
