boot-logo-png
=============

![It does show an image on boot, yup.](https://tensor.work/~drbig/boot-logo-png.png)

Quick and dirty replacement for the `boot-logo` (which apparently lives
[here](https://github.com/hi-ban/boot-logo)) that just shows a PNG image of
your choice for the amount of time of your choice.

As I got from nothing to it working in about ~3 evenings all here is a mess,
your mileage my vary.

I use [steward's toolchain](https://steward-fu.github.io/website/handheld/miyoo/review.htm)
and composed my logo in [Pinta](https://pinta-project.com/pintaproject/pinta/).

Build, roughly:
```
export PATH=/home/drbig/Projects/miyoo/toolchain/bin:$PATH
export TARGETMACH=arm-linux
export BUILDMACH=i686-pc-linux-gnu
export CROSS=arm-linux
export CC=${CROSS}-gcc
export LD=${CROSS}-ld
export AS=${CROSS}-as
export CXX=${CROSS}-g++
arm-linux-gcc -o boot-logo -lSDL -lSDL_image -lpng -L/home/drbig/Projects/miyoo/toolchain/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/lib -I/home/drbig/Projects/miyoo/toolchain/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/SDL main.c
```

And then editing the `/etc/main`, the relevant part is:
```
#if [ -e $BOOTLOGO ]
#then
#/mnt/boot-logo > /dev/null 2>&1 
#fi

# My boot logo
/mnt/drbig/boot-logo 5000 /mnt/drbig/logo.png
```

And the image that works fine for me is:
```
$ file /run/media/drbig/main/drbig/logo.png
/run/media/drbig/main/drbig/logo.png: PNG image data, 320 x 240, 8-bit/color RGBA, non-interlaced
```

So here ya go; assume a copyleft license really. Thanks to the people on the
GZNetwork discord for clues and generally just being nice.

_Have fun!_
