#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>
#include "sort.h"
#include "permutations.h"
#include "zhimi.h"
#include "firework.h"
#include "firework2.h"
void RandomArray(int* nums,int size,int max)
{
	int i=0;
	for(;i<size;i++)
	{
		nums[i]=rand()%max;
	}
}

void Print_Arrays(int* nums,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf(" %d ",nums[i]);
	}
	printf("\n");
}

/*#define N 1000
int main()
{
	int i,j;
	int arrays[N];
	RandomArray(arrays,N,N*2);
	Print_Arrays(arrays,N);
	//void merge_sort(int* nums,int start,int end);
	merge_sort(arrays,0,N-1);
	Print_Arrays(arrays,N);
	//int test_sort(int *nums,int size);
	if(test_sort(arrays,N)==1)
	{
		printf("The result is right!!!");
	}
	else printf("The result is false!!!");
}*/
static void activate (GtkApplication* app,gpointer user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_widget_show_all (window);
}

int main (int    argc,char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
 









