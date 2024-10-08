# Jumper game OS for Pixel 2

Plan:

1. Build a custom Linux kernel or a minimal kernel from scratch.
2. Write a minimal game that directly interfaces with hardware (like the framebuffer for graphics).
3. Use a bootloader (like Fastboot or U-Boot) to load your OS.

## About Pixel 2
ARM64 architecture

## Let's begin
1. Cross compilation tools
```bash
sudo apt-get install gcc-aarch64-linux-gnu make qemu-system-arm flex bison
```
2. Download Linux Kernel Source
```bash
git clone https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
```
3. Configure kernel
```bash
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- defconfig
```
4. Build kernel - generate kernel image /linux/arch/arm64/boot/Image.gz
```bash
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -j4
```
5. Framebuffer direct pixel interaction

Write to /dev/fb0 to control display

To be continued...
