/* 1-1.c */
#include <stdio.h>

struct S1 {
	char c;
	int i;
	long l;
};

struct S2 {
	char c;
	int i;
	long long l;
} __attribute__((packed));

int main() {
	struct S1 s1;
	struct S1 s2;
	printf("%zu %zu\n", sizeof(s1), sizeof(s2));
	
}
