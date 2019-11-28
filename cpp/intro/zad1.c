#include <stdio.h>
#include <stdlib.h>

struct vector_t{
	int count;
	int *items;
};

void init(struct vector_t *vec) {
	vec->count = 0;
	vec->items = (int*)malloc(sizeof(int));
}

void resize(struct vector_t *vec, int new_size){

	vec->items = (int*)realloc(vec->items, new_size * sizeof(int));
}

void push(struct vector_t *vec, int item){
	resize(vec, vec->count + 1);
	vec->items[vec->count] = item;
	vec->count++;
}

void funkciq(int number){
	int n,i = 0,c;
	int arr[10];
	while(number != 0){
		n = number % 10;
		arr[i] = n;
		i++;
		number = number / 10;
	}
	for(c = i; c != 0; c--){
		printf("%d, ", arr[c-1]);
	}
}

int funkciq2(int number){
	if (number == 0)return 0;

	printf("%d,",number%10);
	number = number / 10;
	return(funkciq2(number));
}

int main(int argc, char **argv){
	
	int k = atoi(argv[1]);	
	struct vector_t vec;
	init(&vec);
	
	int *nums = malloc(k * sizeof(int));
	for(int i=0;i<k;i++){
		scanf("%d", &nums[i]);
	}
	
	for(int i=0;i<k;i++){
		push(&vec, nums[i]);
	}
	
	for(int i=0;i<k;i++){
		funkciq2(vec.items[i]);
		printf("\n");
	}	
}

