CC=/c/GNU_Tools_ARM_Embedded/4.9_2015q3/bin/arm-none-eabi-gcc
AR=/c/GNU_Tools_ARM_Embedded/4.9_2015q3/bin/arm-none-eabi-ar
RANLIB=/c/GNU_Tools_ARM_Embedded/4.9_2015q3/arm-none-eabi/bin/ranlib
LDFLAGS=" -lc -specs=nosys.specs"
CFLAGS="-mcpu=cortex-m3 -march=armv7-m -mthumb -mlittle-endian -DSTM32F2_HASH -DNO_ECC -DNO_WRITEV -DNO_HMAC -DNO_MD4 -DNO_RC4 -DNO_HC128 -DNO_PSK -DNO_PWDBASED -DNO_CHACHA -DNO_POLY1305 -DNO_DSA -DNO_ECC -DNO_RSA -I/c/Users/michal.stroka/Desktop/magisterka/libs/Drivers/CMSIS/Include -I/c/Users/michal.stroka/Desktop/magisterka/libs/Drivers/CMSIS/Device/ST/STM32F2xx/Include -I/c/Users/michal.stroka/Desktop/magisterka/libs/Drivers/STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/src -I/c/Users/michal.stroka/Desktop/magisterka/libs/Drivers/STM32F2xx_HAL_Driver/Inc -I/c/Users/michal.stroka/Desktop/magisterka/libs/Drivers/STM32F2xx_HAL_Driver/Src -I/c/Users/michal.stroka/Desktop/magisterka/libs/Drivers/STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc -DWOLFSSL_USER_IO -DWOLFCRYPT_ONLY"
./configure --host=arm-none-eabi CC=$CC AR=$AR RANLIB=$RANLIB LDFLAGS="$LDFLAGS" CFLAGS="$CFLAGS" --enable-des3