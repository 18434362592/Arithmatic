#ifndef sort
#define sort
//fuctions of sort.c library
void exch(int* former, int *later);
void insertion_sort(int *nums,int start,int end);
void merge_sort(int* nums,int start,int end);
int test_sort(int *nums,int size);	//if return 0, false return 1 true.
#endif
