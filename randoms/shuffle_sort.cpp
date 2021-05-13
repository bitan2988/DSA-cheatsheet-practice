/*                                  KNUTH-SHUFFLE     -  A variant of the Fisher–Yates shuffle, known as Sattolo's algorithm, may be used to generate random cyclic permutations of length n instead of random permutations.  
									------------- 

So, suppose you have a deck of cards, one of the things that you might want to try to do is to simply rearrange those cards into random order, that's called shuffling. 
Here's a way to get shuffling done using a sort, it seems like the opposite. The idea is just generate a random real number for every array entry, and then sort using those random numbers as the keys.
That's an effective way to get things shuffled. And it's possible to prove that that produces a uniformly random permutation of the input if there's no duplicate values,
assuming that you have real numbers that are generated uniformly at random.   


		for iterration I pick a random number R between 0 and I uniformly and randomly
		Swap a[I] and a[R]            */

int n = a.size();

for(int i=0; i < n; i++){

	int r = random.uniformly(i+1);

	swap(a[i], a[r]);
}

//With C++11 multiple other options have risen. One of which fits your requirements, for generating a random number in a range, pretty nicely: std::uniform_int_distribution. Here's an example:

	const int range_from  = 0;
	const int range_to    = 10;
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distr(range_from, range_to);

	std::cout << distr(generator) << '\n';


//And here's the running example.
	#include <iostream>
	#include <random>

	int main(int, char*[]) {
	    const int range_from  = 0;
	    const int range_to    = 10;
	    std::random_device                  rand_dev;
	    std::mt19937                        generator(rand_dev());
	    std::uniform_int_distribution<int>  distr(range_from, range_to);
	 
	    for (int i = 0; i < 10; ++i)
	        std::cout << distr(generator) << '\n';
	}

//Template function may help some:

	template<typename T>
	T random(T range_from, T range_to) {
	    std::random_device                  rand_dev;
	    std::mt19937                        generator(rand_dev());
	    std::uniform_int_distribution<T>    distr(range_from, range_to);
	    return distr(generator);
	}  



//Other random generators
//The <random> header offers innumerable other random number generators with different kind of distributions including Bernoulli, Poisson and normal.

//How can I shuffle a container?
//The standard provides std::shuffle, which can be used as follows:

	std::vector<int> vec = {4, 8, 15, 16, 23, 42};

	std::random_device random_dev;
	std::mt19937       generator(random_dev());

	std::shuffle(vec.begin(), vec.end(), generator);
//The algorithm will reorder the elements randomly, with a linear complexity.

//Boost.Random
//Another alternative, in case you don't have access to a C++11+ compiler, is to use Boost.Random. Its interface is very similar to the C++11 one.*/