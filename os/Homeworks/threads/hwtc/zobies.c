#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define WALKING 3000
#define TRANSPORTING_MINERALS 2000
#define MINERAL_BLOCK_SIZE 500
#define MAX_WORKERS_AND_MARINES 200
#define TRAINING_WORKER_PRICE 50
#define MARINE_PRICE 50
#define TRAINING_WORKER_TIME 4000
#define TRAINING_MARINE_TIME 1000
#define MINED_MINERALS 8

int workers_count = 5;
pthread_t* workers;
int minerals_in_store = 0;
int marines_count = 0;
int mineral_blocks_count = 2;
int* mineral_blocks;

pthread_mutex_t training_workers;
pthread_mutex_t command_center_minerals;
pthread_mutex_t* mining_minerals;

void init(); //done
void destroy(); //done
void print_error(int); //done
void* mine(void*); //done
void build_marine(); //done
void train_worker(); //done
int check_if_mineral_blocks_empty(int[]); //done
void deliver(int); //done
void lock(pthread_mutex_t); //done
void unlock(pthread_mutex_t); //done

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		mineral_blocks_count = atoi(argv[1]);
	}

	init();

	while(1)
	{
		lock(command_center_minerals);
		if (marines_count >= 20 
			&& ((mineral_blocks_count * MINERAL_BLOCK_SIZE) == (marines_count * MARINE_PRICE + 
				minerals_in_store + (workers_count - 5) * TRAINING_WORKER_PRICE)))
		{
			unlock(command_center_minerals);
			break;
		}
		unlock(command_center_minerals);

		char command = getchar();
		switch(command)
		{
			case 'm':
				build_marine();
				break;
			case 's':
				train_worker();
				break;
		}
	}
	destroy();

	printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", 
		mineral_blocks_count * MINERAL_BLOCK_SIZE, minerals_in_store, workers_count, marines_count);

	return 0;
}

void* mine(void* args)
{
	int id = (int)args;
	int local_blocks[mineral_blocks_count];

	for (int i = 0; i < mineral_blocks_count; ++i)
	{
		local_blocks[i] = 0;
	}

	while(1)
	{
		sleep(WALKING);
		int block;
		for (block = 0; ; ++block, block %= mineral_blocks_count)
		{
			if (local_blocks[block] == 0 && pthread_mutex_trylock(&mining_minerals[block]) == 0)
			{
				break;
			}else{
                //for (int i = 0; i < mineral_blocks_count; ++i)
                // {
                //     if (local_blocks[i] == 0)
                //     {
                //         return 0;
                //     }
                // }
                // return 1;
				if(check_if_mineral_blocks_empty(local_blocks))
				{
					return 0;
				}
			}

			sleep(WALKING);
		}

		if (mineral_blocks[block] <= 0)
		{
			if (pthread_mutex_unlock(&mining_minerals[block]) != 0)
			{
				print_error(5);
			}

			local_blocks[block] = 1;
			continue;
		}

		printf("SCV %d is mining from mineral block %d\n", id+1, block+1);
		mineral_blocks[block] -= MINED_MINERALS;

		if (mineral_blocks[block] <= 0)
		{
			lock(command_center_minerals);
			minerals_in_store += mineral_blocks[block];
			unlock(command_center_minerals);

			mineral_blocks[block] = 0;

			local_blocks[block] = 1;
		}

		if (pthread_mutex_unlock(&mining_minerals[block]) != 0)
		{
			print_error(5);
		}

		deliver(id+1);
	}
}

void deliver(int id)
{
	printf("SCV %d is transporting minerals\n", id);
	sleep(TRANSPORTING_MINERALS);

	lock(command_center_minerals);
	minerals_in_store += MINED_MINERALS;
	unlock(command_center_minerals);

	printf("SCV %d delivered minerals to the Command center\n", id);
}

void build_marine()
{
	lock(command_center_minerals);

	if (minerals_in_store >= MARINE_PRICE)
	{
		minerals_in_store -= MARINE_PRICE;

		unlock(command_center_minerals);

		sleep(TRAINING_MARINE_TIME);

		marines_count++;

		printf("You wanna piece of me, boy?\n");
	}else{
		unlock(command_center_minerals);

		printf("Not enough minerals.\n");
	}
}

void train_worker()
{
	lock(training_workers);
	lock(command_center_minerals);

	if (minerals_in_store >= TRAINING_WORKER_PRICE)
	{
		minerals_in_store -= TRAINING_WORKER_PRICE;

		unlock(command_center_minerals);
		sleep(TRAINING_MARINE_TIME);

		workers = realloc(workers, sizeof(pthread_t) * ++workers_count);
		if (workers == NULL)
		{
			print_error(8);
		}
		if (pthread_create(&workers[workers_count-1], NULL, mine, (void*)(workers_count-1)) != 0)
		{
			print_error(1);
		}

		printf("SCV good to go, sir.\n");
	}else{
		unlock(command_center_minerals);
		printf("Not enough minerals.\n");
	}

	unlock(training_workers);
}

void init()
{
	mineral_blocks = malloc(sizeof(int) * mineral_blocks_count);
	if (mineral_blocks == NULL)
	{
		print_error(7);
	}

	for (int i = 0; i < mineral_blocks_count; ++i)
	{
		mineral_blocks[i] = 500;
	}

	mining_minerals = malloc(sizeof(pthread_mutex_t) * mineral_blocks_count);
	if (mining_minerals == NULL)
	{
		print_error(7);
	}

	for (int i = 0; i < mineral_blocks_count; ++i)
	{
		if (pthread_mutex_init(&mining_minerals[i], NULL) != 0)
		{
			print_error(6);
		}
	}

	if (pthread_mutex_init(&training_workers, NULL) != 0)
	{
		print_error(6);
	}

	if (pthread_mutex_init(&command_center_minerals, NULL) != 0)
	{
		print_error(6);
	}
	
	workers = malloc(sizeof(pthread_t) * workers_count);
	if (workers == NULL)
	{
		print_error(7);
	}

	for (int i = 0; i < workers_count; ++i)
	{
		if (pthread_create(&workers[i], NULL, mine, (void*)i) != 0)
		{
			print_error(1);
		}
	}
}

void destroy()
{
	for (int i = 0; i < workers_count; ++i)
	{
		if (pthread_join(workers[i], NULL) != 0)
		{
			print_error(3);
		}
	}

	if (pthread_mutex_destroy(&training_workers) != 0)
	{
		print_error(4);
	}

	if (pthread_mutex_destroy(&command_center_minerals) != 0)
	{
		print_error(4);
	}

	for (int i = 0; i < mineral_blocks_count; ++i)
	{
		if (pthread_mutex_destroy(&mining_minerals[i]) != 0)
		{
			print_error(4);
		}
	}

	free(workers);
	free(mineral_blocks);
	free(mining_minerals);
}

int check_if_mineral_blocks_empty(int local_blocks[])
{
	
}

void lock(pthread_mutex_t mutex)
{
	if (pthread_mutex_lock(&mutex) != 0)
	{
		print_error(2);
	}
}

void unlock(pthread_mutex_t mutex)
{
	if (pthread_mutex_unlock(&mutex) != 0)
	{
		print_error(5);
	}
}

void print_error(int error)
{
	switch(error)
	{
		case 1:
			perror("pthread_create");
			break;
		case 2:
			perror("pthread_mutex_lock");
			break;
		case 3:
			perror("pthread_join");
			break;
		case 4:
			perror("pthread_mutex_destroy");
			break;
		case 5:
			perror("pthread_mutex_unlock");
			break;
		case 6:
			perror("pthread_mutex_init");
			break;
		case 7:
			perror("malloc");
			break;
		case 8:
			perror("realloc");
			break;
	}

	exit(-1);
}
