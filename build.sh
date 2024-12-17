#!/bin/bash

export OUTPUT_DIR="$(pwd)/bin"

rm -rf bin
mkdir bin

cd BareMetal
./build.sh
cd ..

cd Pure64
./build.sh
cd ..

mv "Pure64/bin/bios.sys" "${OUTPUT_DIR}/bios.sys"
mv "Pure64/bin/pure64-bios.sys" "${OUTPUT_DIR}/pure64-bios.sys"
mv "Pure64/bin/pure64-bios-debug.txt" "${OUTPUT_DIR}/pure64-bios-debug.txt"
mv "BareMetal/bin/kernel.sys" "${OUTPUT_DIR}/kernel.sys"
mv "BareMetal/bin/kernel-debug.txt" "${OUTPUT_DIR}/kernel-debug.txt"

echo "Going to hell!"

cd src
gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -o main.o main.c
gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -o libBareMetal.o ../BareMetal/api/libBareMetal.c
ld -T linker.ld -o ${OUTPUT_DIR}/main.sys main.o libBareMetal.o
cd ..
echo "Escaped hell with great success :)"

cd bin
cat pure64-bios.sys kernel.sys main.sys > software.sys

echo "Gave Tibi purpose (bin/tibi.img)"
dd if=/dev/zero of=bmfs.img count=128 bs=1048576 status=none
dd if=/dev/zero of=fat32.img count=128 bs=1048576 status=none

dd if=bios.sys of=fat32.img bs=1 count=3 conv=notrunc status=none
dd if=bios.sys of=fat32.img bs=1 skip=90 seek=90 count=356 conv=notrunc status=none
dd if=bios.sys of=fat32.img bs=1 skip=510 seek=510 count=2 conv=notrunc status=none
dd if=software.sys of=bmfs.img bs=4096 seek=2 conv=notrunc status=none

cat fat32.img bmfs.img > tibi.img

cd ..

echo "Hell has been compacted (bin/tibi.img)"
echo "Run: qemu-system-x86_64 -drive format=raw,file=bin/tibi.img"

if [[ $1 = "run" ]]; then
  qemu-system-x86_64 -drive format=raw,file=bin/tibi.img
fi

rm src/*.o
