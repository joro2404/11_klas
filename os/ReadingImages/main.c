#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

void *read_image( const char *filepath );

int main( int argc, const char* argv[] ) {

	void *buff = read_image(argv[1]);
	void *whole_file = read_image(argv[1]);

	if(buff == NULL){

		printf("Unable to open file\n");
		return 0;
	}

	if(*(uint64_t*)buff != 0x0A1A0A0D474E5089){

		printf("Unable to parse file\n");
		return 0;
	}

	int file_length = 0;
	buff += 8;
	whole_file += 8;
	file_length += 8;


	while(1){

		uint32_t header_length = ntohl(*(uint32_t*)buff);
		buff += 4;
		uint32_t header_type = ntohl(*(uint32_t*)buff);
		buff += 4;
		
		if(header_type == 0x49484452){
			break;
		}

		buff += 4 + header_length;
	}

	while(1){

		uint32_t length_of_chunk = ntohl(*(uint32_t*)whole_file);
		whole_file += 4;
		file_length += 4;
		uint32_t last_header_type = ntohl(*(uint32_t*)whole_file);
		whole_file += 4;
		file_length += 4;

		if(last_header_type == 0x49454E44){
			
			file_length += 4;
			break;
		}

		whole_file += 4 + length_of_chunk;
		file_length += 4 + length_of_chunk;
		//printf("len of file size -> %d\n", length_of_chunk);
	}

	printf("PNG image width: %d\n", ntohl(*(uint32_t*)buff));
	buff +=4;
	printf("PNG image height: %d\n", ntohl(*(uint32_t*)buff));
	printf("PNG file size: %d\n", file_length);

	return 0;

}
