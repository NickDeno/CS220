#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned long interleave(unsigned int i1, unsigned int i2)
{
	unsigned long result;
	unsigned char *pl1 = (unsigned char *)&i1;
	unsigned char *pl2 = (unsigned char *)&i2;
	unsigned char *pl3 = (unsigned char *)&result;
	for (int i = 0; i < sizeof(unsigned int); i++)
	{
		pl3[2 * i] = pl2[i];
		pl3[2 * i + 1] = pl1[i];
	}
	return result;
}

void print_raw_bytes(unsigned char *start, unsigned int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%p:0x%x\n", &start[i], (start[i]));
	}
}

void *allocate_heap(unsigned int size, int val)
{
	void *p = malloc(size);
	memset(p, val, size);
	return p;
}

int main()
{
	// 1
	unsigned int i1 = 0x12345678;
	unsigned int i2 = 0xdeadbeef;
	unsigned long il3 = interleave(i1, i2);
	printf("i1 = 0x%x, i2 = 0x%x, result = 0x%lx\n", i1, i2, il3);

	// 2
	unsigned int i = 0xc0de1234;
	print_raw_bytes((char *)&i, sizeof(i));

	// 3
	unsigned int size = 4;
	int value = 20;
	void *allocatedHeap = allocate_heap(size, value);
	print_raw_bytes(allocatedHeap, size);
	return 0;
}
