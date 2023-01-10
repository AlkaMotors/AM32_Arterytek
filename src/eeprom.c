#include "eeprom.h"
#include <string.h>
#include "targets.h"

#ifdef MCU_ATF421
#include "at32f421_flash.h"
#endif
#ifdef MCU_AT415
#include "at32f415_flash.h"
#endif

#define page_size 0x400                   // 1 kb for f051


void save_flash_nolib(uint8_t *data, int length, uint32_t add){    ///todo
	
 //fmc_wscnt_set(2);

//fmc_prefetch_enable();
	
	
	uint32_t data_to_FLASH[length / 4];
	memset(data_to_FLASH, 0, length / 4);
		for(int i = 0; i < length / 4 ; i ++ ){
		data_to_FLASH[i] =  data[i*4+3] << 24 |data[i*4+2] << 16|data[i*4+1] << 8| data[i*4];   // make 16 bit
	}
	volatile uint32_t data_length = length / 4;

	// unlock flash

		flash_unlock();

	// erase page if address even divisable by 1024
	 if((add % 1024) == 0){

   flash_sector_erase(add);

	 }

	 volatile uint32_t write_cnt=0, index=0;
	 while(index < data_length)
			  {

	        flash_word_program(add + (index*4),data_to_FLASH[index]);
			flash_flag_clear(FLASH_PROGRAM_ERROR | FLASH_EPP_ERROR | FLASH_OPERATE_DONE);
				  index++;
		  }
	 flash_lock();
}




void read_flash_bin(uint8_t*  data , uint32_t add , int out_buff_len){
	//volatile uint32_t read_data;
	for (int i = 0; i < out_buff_len ; i ++){
		data[i] = *(uint8_t*)(add + i);
	}
}