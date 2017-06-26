#C compiler
CC=arm-none-eabi-gcc
LANG_STD = gnu11

#Target processor options
ARM_FAMILY = cortex-m3
ARCHITECTURE = armv7-m
INSTRUCTION_SET = thumb
ENDIANNESS = little-endian

TARGET_FLAGS = -mcpu=$(ARM_FAMILY) -march=$(ARCHITECTURE) -m$(INSTRUCTION_SET) -m$(ENDIANNESS)

#Optimization options
OPTYMIZATION_LEVEL = o3
OPTYMIZATION_FLAGS = -$(OPTYMIZATION_LEVEL) -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections

#Debugging options
DEBUG_LEVEL = g3
DEBUG_FORMAT = gdb
DEBUG_FLAGS = -$(DEBUG_LEVEL) -g$(DEBUG_FORMAT)

#
# Pathes to directories
#

# Path to source dir
SRC_DIR = ../src

# Path to build dir
BUILD_DIR = ../build

# Path to objects dir
OBJ_DIR = $(BUILD_DIR)/obj

# WOLFSSL cryptolib header files dirs
WOLFSSL_CRYPTOLIB_INC_DIR = "../../../libs/wolfssl-3.9.10"

# WOLFSSL cryptolib libs dirs
WOLFSSL_CRYPTOLIB_LIB_DIR = "../../../libs/wolfssl-3.9.10/src/.libs"

#WOLFSSL_CRYPTOLIB_LIB = wolfssl


# HAL library directories
HAL_INC_DIR = "../../../libs/Drivers/STM32F2xx_HAL_Driver/Inc"
HAL_SRC_DIR = ../../../libs/Drivers/STM32F2xx_HAL_Driver/Src

# HAL library directories
CMSIS_INC_DIR = "../../../libs/Drivers/CMSIS/Include"
CMSIS_DEVICE_INC_DIR = "../../../libs/Drivers/CMSIS/Device/ST/STM32F2xx/Include"

CMSIS_STARTUP_DIR = ../../../libs/Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc
CMSIS_STARTUP_FILE = startup_stm32f217xx

STD_PERIPH_INC = ../../../libs/Drivers/STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc
STD_PERIPH_SRC = ../../../libs/Drivers/STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/src

# Semihosting options
# uncomment to choose
# 	-with semihoting
SPECS_FLAG = --specs=rdimon.specs -lc -lrdimon
# 	-without semihoting
#SPECS_FLAG = --specs=nosys.specs

# Linker scripts dir
LD_SCRIPTS_DIR = "../ldscripts"

# Include paths flags
# (all includes dires)
INC_FLAGS = -I$(CMSIS_INC_DIR) -I$(CMSIS_DEVICE_INC_DIR) -I$(HAL_INC_DIR) -I$(STD_PERIPH_INC) -I$(WOLFSSL_CRYPTOLIB_INC_DIR)

# Cross asembler flags
CROSS_ASSEMBLER_FLAGS = -x assembler-with-cpp

#Linker flags
LINKER_SEARCH_PATH_FLAGS = -L$(LD_SCRIPTS_DIR) -L$(WOLFSSL_CRYPTOLIB_LIB_DIR)
LINKER_SCRIPTS_FLAGS = -T mem.ld -T sections.ld

LINKER_FLAGS = $(TARGET_FLAGS) -Xlinker --gc-sections $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(LINKER_SEARCH_PATH_FLAGS) $(LINKER_SCRIPTS_FLAGS) $(SPECS_FLAG) 


# ALL target
all: create_dirs $(BUILD_DIR)/dlaTestow.hex
#all: create_dirs $(OBJ_DIR)/main.o system timer_module ecc_module rsa_module rng_module sha_module hmac_module hal dlaTestow

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(OBJ_DIR)/main.o $(SRC_DIR)/main.c


#HAL drivers
#HAL sources used in project
#stm32f2xx_hal_cortex.c stm32f2xx_hal_rcc.c stm32f2xx_hal_tim_ex.c stm32f2xx_hal_tim.c stm32f2xx_hal.c
HAL_OBJ_DIR = $(OBJ_DIR)/hal

hal: $(HAL_OBJ_DIR)/stm32f2xx_hal_cortex.o $(HAL_OBJ_DIR)/stm32f2xx_hal_rcc.o $(HAL_OBJ_DIR)/stm32f2xx_hal_tim_ex.o $(HAL_OBJ_DIR)/stm32f2xx_hal_tim.o $(HAL_OBJ_DIR)/stm32f2xx_hal.o 

$(HAL_OBJ_DIR)/stm32f2xx_hal_cortex.o: $(HAL_SRC_DIR)/stm32f2xx_hal_cortex.c
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(HAL_OBJ_DIR)/stm32f2xx_hal_cortex.o $(HAL_SRC_DIR)/stm32f2xx_hal_cortex.c

$(HAL_OBJ_DIR)/stm32f2xx_hal_rcc.o: $(HAL_SRC_DIR)/stm32f2xx_hal_rcc.c
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(HAL_OBJ_DIR)/stm32f2xx_hal_rcc.o $(HAL_SRC_DIR)/stm32f2xx_hal_rcc.c
	
$(HAL_OBJ_DIR)/stm32f2xx_hal_tim_ex.o: $(HAL_SRC_DIR)/stm32f2xx_hal_tim_ex.c
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(HAL_OBJ_DIR)/stm32f2xx_hal_tim_ex.o $(HAL_SRC_DIR)/stm32f2xx_hal_tim_ex.c

$(HAL_OBJ_DIR)/stm32f2xx_hal_tim.o: $(HAL_SRC_DIR)/stm32f2xx_hal_tim.c
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(HAL_OBJ_DIR)/stm32f2xx_hal_tim.o $(HAL_SRC_DIR)/stm32f2xx_hal_tim.c

$(HAL_OBJ_DIR)/stm32f2xx_hal.o: $(HAL_SRC_DIR)/stm32f2xx_hal.c
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(HAL_OBJ_DIR)/stm32f2xx_hal.o $(HAL_SRC_DIR)/stm32f2xx_hal.c


#SYSTEM files
SYSTEM_SRC_DIR = $(SRC_DIR)/system
SYSTEM_OBJ_DIR = $(OBJ_DIR)/system

system: $(SYSTEM_OBJ_DIR)/$(CMSIS_STARTUP_FILE).o $(SYSTEM_OBJ_DIR)/system_stm32f2xx.o $(SYSTEM_OBJ_DIR)/$stm32f2xx_cryp.o $(SYSTEM_OBJ_DIR)/$stm32f2xx_rcc.o

$(SYSTEM_OBJ_DIR)/$(CMSIS_STARTUP_FILE).o: $(SYSTEM_SRC_DIR)/$(CMSIS_STARTUP_FILE).s
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(CROSS_ASSEMBLER_FLAGS) -o $(SYSTEM_OBJ_DIR)/$(CMSIS_STARTUP_FILE).o $(SYSTEM_SRC_DIR)/$(CMSIS_STARTUP_FILE).s

$(SYSTEM_OBJ_DIR)/system_stm32f2xx.o: $(SYSTEM_SRC_DIR)/system_stm32f2xx.c 
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(SYSTEM_OBJ_DIR)/system_stm32f2xx.o $(SYSTEM_SRC_DIR)/system_stm32f2xx.c

$(SYSTEM_OBJ_DIR)/stm32f2xx_cryp.o: $(STD_PERIPH_SRC)/stm32f2xx_cryp.c
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(SYSTEM_OBJ_DIR)/stm32f2xx_cryp.o $(STD_PERIPH_SRC)/stm32f2xx_cryp.c

$(SYSTEM_OBJ_DIR)/stm32f2xx_rcc.o: $(STD_PERIPH_SRC)/stm32f2xx_rcc.c
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(SYSTEM_OBJ_DIR)/stm32f2xx_rcc.o $(STD_PERIPH_SRC)/stm32f2xx_rcc.c
	
$(SYSTEM_OBJ_DIR)/stm32f2xx_hash.o: $(STD_PERIPH_SRC)/stm32f2xx_hash.c
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(SYSTEM_OBJ_DIR)/stm32f2xx_hash.o $(STD_PERIPH_SRC)/stm32f2xx_hash.c
	
#TIMER module
TIMER_SRC_DIR = $(SRC_DIR)/timer
TIMER_OBJ_DIR = $(OBJ_DIR)/timer

timer_module: $(TIMER_OBJ_DIR)/timer.o

$(TIMER_OBJ_DIR)/timer.o: $(TIMER_SRC_DIR)/timer.c 
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(TIMER_OBJ_DIR)/timer.o $(TIMER_SRC_DIR)/timer.c


#RNG module
RNG_SRC_DIR = $(SRC_DIR)/rng
RNG_OBJ_DIR = $(OBJ_DIR)/rng

rng_module: $(RNG_OBJ_DIR)/rng.o

$(RNG_OBJ_DIR)/rng.o: $(RNG_SRC_DIR)/rng.c $(RNG_SRC_DIR)/rng.h
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(RNG_OBJ_DIR)/rng.o $(RNG_SRC_DIR)/rng.c

	#SHA module
SHA_SRC_DIR = $(SRC_DIR)/sha
SHA_OBJ_DIR = $(OBJ_DIR)/sha

sha_module: $(SHA_OBJ_DIR)/test_sha_oneshot.o $(SHA_OBJ_DIR)/test_sha.o

$(SHA_OBJ_DIR)/test_sha_oneshot.o: $(SHA_SRC_DIR)/test_sha_oneshot.c 
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(SHA_OBJ_DIR)/test_sha_oneshot.o $(SHA_SRC_DIR)/test_sha_oneshot.c

$(SHA_OBJ_DIR)/test_sha.o: $(SHA_SRC_DIR)/test_sha.c 
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(SHA_OBJ_DIR)/test_sha.o $(SHA_SRC_DIR)/test_sha.c

	
	#SHA-moje module
SHA-moje_SRC_DIR = $(SRC_DIR)/sha-moje
SHA-moje_OBJ_DIR = $(OBJ_DIR)/sha-moje

SHA-moje_module: $(SHA-moje_OBJ_DIR)/test_sha-moje.o 

$(SHA-moje_OBJ_DIR)/test_sha-moje.o : $(SHA-moje_SRC_DIR)/sha256-moje.c 
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(SHA-moje_OBJ_DIR)/test_sha-moje.o $(SHA-moje_SRC_DIR)/sha256-moje.c



	#AES module
AES_SRC_DIR = $(SRC_DIR)/aes
AES_OBJ_DIR = $(OBJ_DIR)/aes

aes_module: $(AES_OBJ_DIR)/test_aes.o

$(AES_OBJ_DIR)/test_aes.o: $(AES_SRC_DIR)/test_aes.c 
	$(CC) -c -std=$(LANG_STD) $(TARGET_FLAGS) $(OPTYMIZATION_FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) -o $(AES_OBJ_DIR)/test_aes.o $(AES_SRC_DIR)/test_aes.c

	
	
#Linking objects
dlaTestow: $(BUILD_DIR)/dlaTestow.elf $(BUILD_DIR)/dlaTestow.hex

#All objects
objects = $(OBJ_DIR)/main.o \
$(HAL_OBJ_DIR)/stm32f2xx_hal_cortex.o $(HAL_OBJ_DIR)/stm32f2xx_hal_rcc.o $(HAL_OBJ_DIR)/stm32f2xx_hal_tim_ex.o $(HAL_OBJ_DIR)/stm32f2xx_hal_tim.o $(HAL_OBJ_DIR)/stm32f2xx_hal.o \
$(SYSTEM_OBJ_DIR)/$(CMSIS_STARTUP_FILE).o $(SYSTEM_OBJ_DIR)/system_stm32f2xx.o $(SYSTEM_OBJ_DIR)/stm32f2xx_cryp.o $(SYSTEM_OBJ_DIR)/stm32f2xx_rcc.o $(SYSTEM_OBJ_DIR)/stm32f2xx_hash.o \
$(TIMER_OBJ_DIR)/timer.o \
$(SHA_OBJ_DIR)/test_sha.o \
$(AES_OBJ_DIR)/test_aes.o \
$(SHA-moje_OBJ_DIR)/test_sha-moje.o 



$(BUILD_DIR)/dlaTestow.elf: $(objects)
	$(CC) $(LINKER_FLAGS) -o $(BUILD_DIR)/dlaTestow.elf $(objects) -l$(WOLFSSL_CRYPTOLIB_LIB) 

$(BUILD_DIR)/dlaTestow.hex: $(BUILD_DIR)/dlaTestow.elf
	arm-none-eabi-objcopy -O ihex $(BUILD_DIR)/dlaTestow.elf  $(BUILD_DIR)/dlaTestow.hex
	arm-none-eabi-size --format=berkeley "$(BUILD_DIR)/dlaTestow.elf"


# Phony targets
.PHONY: all clean

clean: 
	rm -rf $(BUILD_DIR)
	@echo Clean done	

# Creating directories
create_dirs:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)
# System files dir
	mkdir -p $(OBJ_DIR)/system
# Hal drivers objects dirs
	mkdir -p $(OBJ_DIR)/hal
# Module objects dirs
	mkdir -p $(OBJ_DIR)/timer $(OBJ_DIR)/rng $(OBJ_DIR)/sha $(OBJ_DIR)/aes $(OBJ_DIR)/sha-moje
	