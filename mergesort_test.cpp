//Tyler Gunter - CS520
//Merge Sort Experiment

//This function tests mergesort to see how fast it is in practice.

//Libraries
#include <iostream> //For IO
#include <cstdlib> //For Random Numbers
#include <ctime> //To find out what time it is
using namespace std;

//These are called function prototypes.
//They tell the compiler and programmer what functions exists.
//The code for the functions is given after main.

//This function checks to see if an array is sorted.
//It returns 1 if the array is sorted.
//It returns 0 if the array is not sorted.
bool is_sorted(int* Array, int size);

//This function gives you a random array.
//It creates a new array of size given and returns the pointer to it.
//The array will be have random numbers in it.
int* random_array(int size);

//This function runs multiple tests for a specific size.
//It prints a summary of the results.
void test_size(int size, int num_of_tests);

//Merge Sort
//This is what we are actually tests
//It returns void because it changes the array in place
void mergesort(int* Array, int size);

int main()
{
	//A computer cannot get truely random numbers.
	//It can generate a sequence that looks random.
	//To start the sequence at an unpredicatable point, use current time
	srand(time(0));
	
	//How many random arrays to test at each size.
	int arrays_per_size=10;
	int current_size=8;
	int max_size=131072;
	
	//Loop over different sizes
	while(current_size <= max_size)
	{
		//Run Tests and print results
		test_size(current_size,arrays_per_size);
		//Set up for next test
		current_size=current_size*2;
	}
	
	//End the Main Function
	return 0;
}

//--------------Function Definitions Below This Line---------------
//Check if an array is sorted
bool is_sorted(int* Array, int size)
{
	int i=1;
	while(i < size)
	{
		if(Array[i] < Array[i-1])
			return false;//Not Sorted!
		i=i+1;
	}
	return true;
}
//Generate a Random Array
int* random_array(int size)
{
	//We need to ask the computer for memory
	int* Array = new int[size];
	int counter = 0;
	while(counter < size)
	{
		Array[counter] = rand();
		counter=counter+1;
	}
	return Array;
}

//Run tests
void test_size(int size, int num_of_tests)
{
	int tests_run=0;
	int tests_passed=0;
	clock_t start,end; //Clock Items for timing
	double time_used,total_time=0;//For computing average
	while(tests_run < num_of_tests)
	{
		//Generate a random array
		int* my_random_array = random_array(size);
		//RUN THE TEST
		start=clock();
		mergesort(my_random_array,size);
		end = clock();
		//END OF TEST RUN
		//How long did it take?
		time_used=((double) (end - start)) / CLOCKS_PER_SEC;
		total_time=total_time+time_used;
		//Did it actually sort?
		tests_passed=tests_passed+is_sorted(my_random_array,size);
		//Count that we ran a tests
		tests_run=tests_run+1;
		//Delete From Memory
		free(my_random_array);
		//Print out Results
	}
	printf("Test size: %d\n",size);
	printf("Tests Ran: %d\n",tests_run);
	printf("Tests Passed: %d\n",tests_passed);
	printf("Average Time to Sort: %lf seconds.\n",total_time/tests_run);
}

//-------------------------------------------------------
//-------------------Merge Sort--------------------------
//-------------------------------------------------------
void print_merge_array(int* Array){
	for(int i=0; i < sizeof(Array); i++){
		cout << Array + i << endl;
	}
}

int* copyPart(int* Array, int start, int stop, int* Aux){
	int counter = 0;
	for(int i = start; i <= stop; i++){
		Aux[counter] = Array[i];
		counter++;
	}
 return Aux;
}

void merge(int* Array, int start, int middle, int stop){
	int auxSize = stop - start + 1;
	int Auxxy [auxSize];
	int* Aux = copyPart(Array, start, stop, Auxxy);
	int auxMiddle = middle - start;
	int i = 0;
	int j = auxMiddle + 1;
	for (int k = start; k <= stop; k++){
		if (i > auxMiddle){
			Array[k] = Aux[j];
			j++;
		} else if (j > auxSize - 1){
			Array[k] = Aux[i];
			i++;
		} else if (Aux[j] > Aux[i]){
			Array[k] = Aux[i];
			i++;
		} else {
			Array[k] = Aux[j];
			j++;
		}
	}
}

void msort(int* Array, int start, int stop){
	if (start >= stop) {
		return;
	}
	int middle = start + ((stop - start) / 2);
	msort(Array, start, middle);
	msort(Array, middle + 1, stop);
	merge(Array, start, middle, stop);
}
void mergesort(int* Array, int size){
	msort(Array, 0, size - 1);
}
