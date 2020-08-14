#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 8

long double arr[NUM_THREADS];
long double *arrPtr;

void* findE (void* threadNum) {
	unsigned long i = 100000000;
	unsigned long t_sum = 0;
	int pos = (int)threadNum;

	for (unsigned long n = 0; n < i; n++) {
		long double x = 0;
		unsigned long digits = 0;
		while (1) {
			x+=rand()/(long double)RAND_MAX;
			digits+=1;
			if (x > 1.0) {
                t_sum += (long double)digits;
                break;
            }
		}
	}
	// arr[pos] = (t_sum / (long double)i);
	*(arrPtr+pos) = (t_sum / (long double)i);
	return NULL;
}

int main(void){
	float avg = 0;
	float sum = 0;
	arrPtr = arr;

	srand(time(NULL)); // Initialization, should only be called once.
	pthread_t threads[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, findE, (void *)(i));
    }

	for (int i = 0; i < NUM_THREADS; i++) {
        void* res;
        pthread_join(threads[i], &res);
    }

	for(int n = 0; n < NUM_THREADS; n++) {
		printf("%Lf\n", arr[n]);
		sum = sum + arr[n];
	}
	printf("------\n");
	avg = sum / NUM_THREADS;
	printf("%.6f", avg);   
	// printf("%Lf\n", findE());
	return 0;
}



// extern crate rand;
// use rand::prelude::*;

// fn main() {
//     let i: i64 = 1000000000;
//     let mut t_sum: f64 = 0.0;
//     let mut rng = thread_rng();
//     for _n in 1..i {
//         let mut x: f64 = 0.0;
//         let mut digits: i32 = 0;
//         loop {
//             let r:f64 = rng.gen();
//             x += r;
//             digits += 1;
//             if x > 1.0 {
//                 t_sum += digits as f64;
//                 break;
//             }
//         }
//     }
//     println!("{}", t_sum / i as f64);
// }
