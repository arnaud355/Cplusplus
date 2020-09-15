#ifndef H_RAND
#define H_RAND

#include <stdlib.h>
#include <time.h>

class Rand
{
	private:
		static int cnt;

		Rand();		
		~Rand();
		
		static void checkSeed();

	public:	
		static void newSeed(int s);
		static int randi();
		static int randi(int max);
		static double randf();
		static double randf(double a, double b);
};

#endif
