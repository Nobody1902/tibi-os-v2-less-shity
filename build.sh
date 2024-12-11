#!/bin/bash

rm -rf bin

cd BareMetal
./clean.sh
./build.sh
cd ..

cd Pure64
./clean.sh
./build.sh
cd ..

echo "Going to hell!"

mkdir -p bin

cd src
gcc -c main.c ../BareMetal/api/libBareMetal.c -mno-red-zone -fno-stack-protector -fomit-frame-pointer
ld -T linker.ld -o ../bin/main.sys main.o libBareMetal.o
cd ..
echo "Escaped hell with great success :)"

cp BareMetal/bin/kernel bin/kernel.sys
cp Pure64/bin/bios.sys bin/mbr.sys
cp Pure64/bin/pure64-bios.sys bin

cd bin
cat pure64-bios.sys kernel.sys main.sys > tibi.sys

echo "Gave Tibi purpose (bin/tibi.sys)"

dd if=/dev/zero of=disk.img count=128 bs=1048576
dd if=mbr.sys of=disk.img conv=notrunc
dd if=tibi.sys of=disk.img bs=512 seek=16 conv=notrunc

cd ..

echo "Hell has been compacted (bin/disk.img)"
echo "Run: qemu-system-x86_64 -drive format=raw,file=bin/disk.img"

rm src/*.o
